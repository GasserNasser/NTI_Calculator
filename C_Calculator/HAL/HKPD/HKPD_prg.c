/*
 * HKPD_prg.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/MDIO/MDIO_int.h"
#include"HKPD_int.h"
#include <util/delay.h>

u8 G_u8KeyPad[4][4]={{'7','8','9','/'}
			 	 	,{'4','5','6','*'}
					,{'1','2','3','-'}
					,{'C','0','=','+'}};

void HKPD_vInit(void){
	MDIO_vSetPortDir(HKPD_PORT,0x0F);
	MDIO_vSetPortVal(HKPD_PORT,0xFF);/* PULL UP  Resistors Activation    Deactivation for the coulumns */
}
u8 HKPD_u8GetPressedKey(void){
	u8 L_Pressedkey='F';
	for(u8 col=0;col<4;col++){

		MDIO_vSetPinVal(HKPD_PORT,col,MDIO_LOW);

		for(u8 row=0;row<4;row++){

			if(MDIO_u8GetPinVAl(HKPD_PORT,row+4) == 0){

				L_Pressedkey = G_u8KeyPad[row][col];

				while(MDIO_u8GetPinVAl(HKPD_PORT,row+4)==0){

				}
				_delay_ms(10);
			}

		}
		/*Deactivate The Column*/
		MDIO_vSetPinVal(HKPD_PORT,col,MDIO_HIGH);
	}

	return L_Pressedkey;
}
