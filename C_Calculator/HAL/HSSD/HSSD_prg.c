/*
 * HSSD.c
 *
 *  Created on: Jun 10, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/MDIO/MDIO_int.h"

#include "../../HAL/HSSD/HSSD_int.h"
#include <util/delay.h>
static const u8 CGS_u8SSD_Nums[10]={(0b00111111)
		,(0b00000110)
		,(0b01011011)
		,(0b01001111)
		,(0b01100110)
		,(0b01101101)
		,(0b01111101)
		,(0b00000111)
		,(0b01111111)
		,(0b01101111)};


void HSSD_vInit(SSD_t* A_xSSD){
	MDIO_vSetPortDir(A_xSSD->SSD_Port,0xFF);
}
void HSSD_vDisplayNum(SSD_t* A_xSSD){
	switch(A_xSSD->SSD_Type){
	case HSSD_COM_ANODE: MDIO_vSetPortVal(A_xSSD->SSD_Port,~CGS_u8SSD_Nums[A_xSSD->SSD_Number]);
	break;
	case HSSD_COM_CATHODE: MDIO_vSetPortVal(A_xSSD->SSD_Port,CGS_u8SSD_Nums[A_xSSD->SSD_Number]);
	break;
	}
}
void HSSD_vTurnOff(SSD_t* A_xSSD){
	switch(A_xSSD->SSD_Type){
	case HSSD_COM_ANODE: MDIO_vSetPortVal(A_xSSD->SSD_Port,0xFF);
	break;
	case HSSD_COM_CATHODE: MDIO_vSetPortVal(A_xSSD->SSD_Port,0);
	break;
	}
}
void HSSD_Display2Num(SSD_t* A_xSSD1,SSD_t* A_xSSD2,u8 A_u8Number ){
		//SET Control PINS for Two SSD
		MDIO_vSetPinDir(HSSD1_CONTROL_PORT,HSSD1_CONTROL_PIN,MDIO_OUTPUT);
		MDIO_vSetPinDir(HSSD2_CONTROL_PORT,HSSD2_CONTROL_PIN,MDIO_OUTPUT);

		A_xSSD1->SSD_Number=A_u8Number%10;
		HSSD_vDisplayNum(A_xSSD1);
		MDIO_vSetPinVal(HSSD1_CONTROL_PORT,HSSD1_CONTROL_PIN,0);
		MDIO_vSetPinVal(HSSD2_CONTROL_PORT,HSSD2_CONTROL_PIN,1);
		_delay_ms(60);
		A_xSSD2->SSD_Number=A_u8Number/10;
		HSSD_vDisplayNum(A_xSSD2);
		MDIO_vSetPinVal(HSSD1_CONTROL_PORT,HSSD1_CONTROL_PIN,1);
		MDIO_vSetPinVal(HSSD2_CONTROL_PORT,HSSD2_CONTROL_PIN,0);
		_delay_ms(60);
}

