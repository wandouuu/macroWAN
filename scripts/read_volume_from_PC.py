import usb.core
import usb.util
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
import math
import time


def read_volume():
    device = AudioUtilities.GetSpeakers()
    volume = device.EndpointVolume.QueryInterface(IAudioEndpointVolume)

    return math.floor(volume.GetMasterVolumeLevelScalar()*100)

def send_HID_report(dev):
    
    volume = read_volume()
                  # ID
    hid_report = [0x03, volume, 0, 0, 0, 0, 0, 0, 0]

    try:
        dev.write(0x01, hid_report)
        return True
    except usb.core.USBError as e:
        print(f"Write failed: {e}")
        return False


def init_usb():
    
    return usb.core.find(idVendor = 1155, idProduct = 22315)
        
    

def main():
    
    dev = None
    previous_volume = -1

    while True:

        dev = init_usb()

        if dev is None:
            time.sleep(1)
            continue
        
        current_volume = read_volume()

        if previous_volume == current_volume:
            time.sleep(1)
            continue
        else:
            if send_HID_report(dev):
                previous_volume = current_volume
            else:
                dev = None
                
            time.sleep(1)
        
        
    return
    
if __name__ == "__main__":
    main()


