import usb.core
import usb.util
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
import math


def read_volume():
    device = AudioUtilities.GetSpeakers()
    volume = device.EndpointVolume.QueryInterface(IAudioEndpointVolume)

    return math.floor(volume.GetMasterVolumeLevelScalar()*100)

def send_HID_report():
    
    
    
    return

def main():
    # dev = usb.core.find(idVendor = 1155, idProduct = 22315)

    # if dev is None:
    #     raise ValueError("Device non-existent")
    
    print(read_volume())
    
if __name__ == "__main__":
    main()


