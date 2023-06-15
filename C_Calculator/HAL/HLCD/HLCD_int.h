/*
 * HLCD_int.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_HLCD_HLCD_INT_H_
#define HAL_HLCD_HLCD_INT_H_

//u8 G_u8LCD_pattern0[8]={0, 10, 21, 17, 10, 4, 0, 0};//Heart
//u8 G_u8LCD_pattern1[8]={0, 28, 2, 1, 63, 0, 8, 0};//G
//u8 G_u8LCD_pattern2[8]={8, 8, 8, 8, 15, 0, 0, 0};//A
//u8 G_u8LCD_pattern3[8]={0, 0, 21, 21, 63, 0, 0, 0};//S
//u8 G_u8LCD_pattern4[8]={0, 0, 0, 0, 3, 4, 24, 0};//R
//u8 G_u8LCD_pattern5[8]={6, 1, 15, 9, 63, 0, 0, 0};//H
//u8 G_u8LCD_pattern6[8]={0, 0, 42, 34, 63, 0, 0, 0};//N
//u8 G_u8LCD_pattern7[8]={0, 0, 10, 21, 17, 10, 4, 0};

#define LCD_CTRL_PORT MDIO_PORTA
#define HLCD_CTRL_PORT MDIO_PORTA
#define HLCD_DATA_PORT MDIO_PORTC

#define HLCD_RS_PIN    MDIO_PIN0
#define HLCD_RW_PIN    MDIO_PIN1
#define HLCD_EN_PIN    MDIO_PIN2

#define HLCD_CLEAR     0b00000001

void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vPrintString(u8* A_u8PtrToStr);
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vPrintFloatNumber(f64 A_f64Number);

void HLCD_vSetCursorPosition(u8 A_u8RowNo,u8 A_u8ColNo);
void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_8CustomCharData[]);
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex);


#endif /* HAL_HLCD_HLCD_INT_H_ */
