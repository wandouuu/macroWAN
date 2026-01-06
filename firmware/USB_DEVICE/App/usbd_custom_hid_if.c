/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */
#include "string.h"
#include "stdbool.h"
/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* ------------------------------------------------- */
  /* REPORT ID 1: Standard Keyboard (Simulates a real keyboard) */
  /* ------------------------------------------------- */
  0x05, 0x01,        /* USAGE_PAGE (Generic Desktop)    */
  0x09, 0x06,        /* USAGE (Keyboard)                */
  0xa1, 0x01,        /* COLLECTION (Application)        */
  0x85, 0x01,        /* REPORT_ID (1)                 */
  
  0x05, 0x07,        /* USAGE_PAGE (Keyboard)         */
  0x19, 0xe0,        /* USAGE_MINIMUM (Keyboard LeftControl) */
  0x29, 0xe7,        /* USAGE_MAXIMUM (Keyboard Right GUI)   */
  0x15, 0x00,        /* LOGICAL_MINIMUM (0)           */
  0x25, 0x01,        /* LOGICAL_MAXIMUM (1)           */
  0x75, 0x01,        /* REPORT_SIZE (1)               */
  0x95, 0x08,        /* REPORT_COUNT (8)              */
  0x81, 0x02,        /* INPUT (Data,Var,Abs)          */ /* Modifiers byte */
  
  0x95, 0x01,        /* REPORT_COUNT (1)              */
  0x75, 0x08,        /* REPORT_SIZE (8)               */
  0x81, 0x03,        /* INPUT (Cnst,Var,Abs)          */ /* Reserved byte */
  
  0x95, 0x06,        /* REPORT_COUNT (6)              */
  0x75, 0x08,        /* REPORT_SIZE (8)               */
  0x15, 0x00,        /* LOGICAL_MINIMUM (0)           */
  0x25, 0x65,        /* LOGICAL_MAXIMUM (101)         */
  0x05, 0x07,        /* USAGE_PAGE (Keyboard)         */
  0x19, 0x00,        /* USAGE_MINIMUM (Reserved (no event indicated)) */
  0x29, 0x65,        /* USAGE_MAXIMUM (Keyboard Application) */
  0x81, 0x00,        /* INPUT (Data,Ary,Abs)          */ /* Key arrays (6 bytes) */
  0xc0,              /* END_COLLECTION                  */

  /* ------------------------------------------------- */
  /* REPORT ID 2: Consumer Control (Rotary Encoder)    */
  /* ------------------------------------------------- */
  0x05, 0x0c,        /* USAGE_PAGE (Consumer Devices)   */
  0x09, 0x01,        /* USAGE (Consumer Control)        */
  0xa1, 0x01,        /* COLLECTION (Application)        */
  0x85, 0x02,        /* REPORT_ID (2)                 */
  
  0x09, 0xe9,        /* USAGE (Volume Increment)      */
  0x09, 0xea,        /* USAGE (Volume Decrement)      */
  0x09, 0xe2,        /* USAGE (Mute)                  */
  0x15, 0x00,        /* LOGICAL_MINIMUM (0)           */
  0x25, 0x01,        /* LOGICAL_MAXIMUM (1)           */
  0x75, 0x01,        /* REPORT_SIZE (1)               */
  0x95, 0x03,        /* REPORT_COUNT (3)              */
  0x81, 0x02,        /* INPUT (Data,Var,Abs)          */ /* 3 bits for Vol+, Vol-, Mute */
  
  0x95, 0x01,        /* REPORT_COUNT (1)              */
  0x75, 0x05,        /* REPORT_SIZE (5)               */
  0x81, 0x03,        /* INPUT (Cnst,Var,Abs)          */ /* 5 bits padding to finish the byte */
  0xc0,              /* END_COLLECTION                  */

  /* ------------------------------------------------- */
  /* REPORT ID 3: Vendor Defined (OLED Data from PC)   */
  /* ------------------------------------------------- */
  0x06, 0x00, 0xff,  /* USAGE_PAGE (Vendor Defined Page 1) */
  0x09, 0x01,        /* USAGE (Vendor Usage 1)             */
  0xa1, 0x01,        /* COLLECTION (Application)           */
  0x85, 0x03,        /* REPORT_ID (3)                    */
  
  /* Output Report: PC -> STM32 (Your Python Script) */
  0x15, 0x00,        /* LOGICAL_MINIMUM (0)              */
  0x26, 0xff, 0x00,  /* LOGICAL_MAXIMUM (255)            */
  0x75, 0x08,        /* REPORT_SIZE (8)                  */
  0x95, 0x08,        /* REPORT_COUNT (8)                 */
  0x09, 0x01,        /* USAGE (Vendor Usage 1)           */
  0x91, 0x02,        /* OUTPUT (Data,Var,Abs)            */
  0xc0               /* END_COLLECTION                     */
};
/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */
extern uint8_t current_volume;
extern bool volume_flag;
/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */
  UNUSED(state);
  UNUSED(event_idx);

  USBD_CUSTOM_HID_HandleTypeDef *hhid = (USBD_CUSTOM_HID_HandleTypeDef*)hUsbDeviceFS.pClassData;

  uint8_t report_id = hhid->Report_buf[0];
  
  if(report_id == 0x03){
    current_volume = hhid->Report_buf[1];
    volume_flag = true;
  }

  /* Start next USB packet transfer once data processing is completed */
  if (USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS) != (uint8_t)USBD_OK)
  {
    return -1;
  }

  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

