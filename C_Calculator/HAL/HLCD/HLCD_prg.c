/*
 * HLCD_prg.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/MDIO/MDIO_int.h"
#include "../HLCD/HLCD_int.h"
#include <util/delay.h>
void HLCD_vInit(void){
	MDIO_vSetPortDir(HLCD_DATA_PORT,0xFF);                		// SET LCD_DATA_PORT AS OUTPUT
	MDIO_vSetPinDir(HLCD_CTRL_PORT,HLCD_RS_PIN,MDIO_OUTPUT);	// SET RS RW EN AS OUTPUT PINS
	MDIO_vSetPinDir(HLCD_CTRL_PORT,HLCD_RW_PIN,MDIO_OUTPUT);
	MDIO_vSetPinDir(HLCD_CTRL_PORT,HLCD_EN_PIN,MDIO_OUTPUT);

	/*Initialization Sequence*/
	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);//Function Set Command
	_delay_ms(1);
	HLCD_vSendCommand(0b00001100);//DISPLAY ON/OFF CONTROL Command
	_delay_ms(1);
	HLCD_vSendCommand(0b00000001);//DISPLAY CLEAR Command
	_delay_ms(3);
	HLCD_vSendCommand(0b00000110);//ENTRY MODE SET Command
	_delay_ms(1);

}

void HLCD_vSendCommand(u8 A_u8Command){
	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_RS_PIN,MDIO_LOW);//RS
	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_RW_PIN,MDIO_LOW);//RW
	MDIO_vSetPortVal(HLCD_DATA_PORT,A_u8Command);//SEND COMMAND

	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_EN_PIN,MDIO_HIGH);//EN
	_delay_ms(1);
	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_EN_PIN,MDIO_LOW);//EN
	_delay_ms(1);
}

void HLCD_vSendChar(u8 A_u8Char){
	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_RS_PIN,MDIO_HIGH);//RS
	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_RW_PIN,MDIO_LOW);//RW

	MDIO_vSetPortVal(HLCD_DATA_PORT,A_u8Char);//SEND CHAR

	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_EN_PIN,MDIO_HIGH);//EN
	_delay_ms(1);
	MDIO_vSetPinVal(HLCD_CTRL_PORT,HLCD_EN_PIN,MDIO_LOW);//EN
	_delay_ms(1);
}

void HLCD_vPrintString(u8* A_u8PtrToStr){
	u8 l_u8counter=0;
	while(A_u8PtrToStr[l_u8counter]!='\0'){
		HLCD_vSendChar(A_u8PtrToStr[l_u8counter]);
		l_u8counter++;
	}
}

void HLCD_vPrintNumber(s32 A_s32Number){

	s8 count=0;
	u8 arr[20]={0};
	if(A_s32Number==0){
		HLCD_vSendChar('0');

	}
	if(A_s32Number<0){
		HLCD_vSendChar('-');
		A_s32Number=~(A_s32Number)+1;
	}
	while(A_s32Number!=0){
		arr[count]=A_s32Number%10;

		A_s32Number=A_s32Number/10;
		count++;
	}
	count--;
	while(count>=0){

		HLCD_vSendChar(arr[count]+'0');
		count--;
	}

}
void HLCD_vPrintFloatNumber(f64 A_f64Number){
	s8 count=0;
	u8 arrint[20]={0};

	s32 integer_part, digit;
	f64 decimal_part;
	integer_part = (s32) A_f64Number;
	decimal_part = A_f64Number - integer_part;
	while(integer_part!=0){
		arrint[count]=integer_part%10;

		integer_part=integer_part/10;
		count++;
	}
	count--;
	while(count>=0){

		HLCD_vSendChar(arrint[count]+'0');
		count--;
	}
	count=2;
	HLCD_vSendChar('.');
    while (decimal_part != 0 && count>0) {

        decimal_part *= 10;
        digit = (int)decimal_part;
		HLCD_vSendChar(digit+'0');
        decimal_part -= digit;
        count--;
    }

}

void HLCD_vSetCursorPosition(u8 A_u8RowNo,u8 A_u8ColNo){
	u8 L_u8DDRAMAdress;

	if(A_u8RowNo<=1&& A_u8ColNo<=15){
		if(A_u8RowNo==0){
			L_u8DDRAMAdress = 0x00 + A_u8ColNo;
		}else{
			L_u8DDRAMAdress=  0x40 + A_u8ColNo;
		}
		HLCD_vSendCommand(L_u8DDRAMAdress+0x80);
	}

}

void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_8CustomCharData[]){

	/*SET CGRAM ADDRESS*/
	HLCD_vSendCommand( 0b01000000 +((A_u8CgramIndex) * 8));

	/*Send Custom Char Data*/


	for(u8 L_u8Index=0;L_u8Index<8;L_u8Index++){
		HLCD_vSendChar(A_8CustomCharData[L_u8Index]);

	}
	/*Set DDRAM Address*/
	HLCD_vSendCommand(0x80);
}

void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex){

	if(A_u8CgramIndex<8){
		HLCD_vSendChar(A_u8CgramIndex);
	}

}
