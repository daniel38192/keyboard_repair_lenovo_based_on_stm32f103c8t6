//
// Created by Daniel Nuñez Villegas on 28/05/25.
//


/*
 *
 *
 *
 *
 *
#include "usbd_hid.h"
*extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct
{
  uint8_t MODIFIER;
  uint8_t RESERVED;
  uint8_t KEYCODE1;
  uint8_t KEYCODE2;
  uint8_t KEYCODE3;
  uint8_t KEYCODE4;
  uint8_t KEYCODE5;
  uint8_t KEYCODE6;
}subKeyBoard;

subKeyBoard keyBoardHIDsub = {0,0,0,0,0,0,0,0};



keyBoardHIDsub.KEYCODE1=0x04;  // Press A key
    keyBoardHIDsub.MODIFIER=0x02;  // To press shift key
    keyBoardHIDsub.KEYCODE2=0x05;  // Press B key
    keyBoardHIDsub.KEYCODE3=0x06;  // Press C key
    USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
    HAL_Delay(50); 		       // Press all key for 50 milliseconds
    keyBoardHIDsub.MODIFIER=0x00;  // To release shift key
    keyBoardHIDsub.KEYCODE1=0x00;  // Release A key
    keyBoardHIDsub.KEYCODE2=0x00;  // Release B key
    keyBoardHIDsub.KEYCODE3=0x00;  // Release C key
    USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
    HAL_Delay(1000); 	       // Repeat this task on every 1 second
 */