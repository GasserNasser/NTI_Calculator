/*
 * main.c
 *
 *  Created on: Jun 10, 2023
 *      Author: Gasser Abdelasser
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/MDIO/MDIO_int.h"
#include "../HAL/HSSD/HSSD_int.h"
#include "../HAL/HKPD/HKPD_int.h"
#include "../HAL/HLCD/HLCD_int.h"
#include <util/delay.h>

int main (void){
	u8 operationcount=0;
	u8 flag=1;
	u8 L_u8Key;
	u8 NegativeCount=0;
	u8 N1isNegative=0;
	u8 N2isNegative=0;
	s32 N1=0,N2=0,ANS=0;
	f64 ANS2=0;
	u8 operation=0;
	HLCD_vInit();
	HKPD_vInit();

	while(1){
		L_u8Key=HKPD_u8GetPressedKey();
		switch(L_u8Key){
		case 'F':break;
		case '+':HLCD_vSendChar('+');
				 flag=2;
				 operation='+';
				 operationcount++;
				 break;
		case '-':HLCD_vSendChar('-');
				 NegativeCount++;
				 if(flag==1&&NegativeCount==1&&operationcount==0&&!N1){
					 N1isNegative++;
				 }
				 else if(NegativeCount==2&&operationcount==0){
					 flag=2;
					 operation='-';
				 }
				 else if(flag==2&&operationcount==1){
					 N2isNegative++;
				 }else{
					 flag=2;
					 operation='-';
				 }
				 break;
		case '/':HLCD_vSendChar('/');
				 operation='/';
				 flag=2;
				 operationcount++;
				 break;
		case '*':HLCD_vSendChar('*');
				 operation='*';
				 flag=2;
				 operationcount++;
				 break;
		case 'C':HLCD_vSendCommand(HLCD_CLEAR);
		 	 	 N1=0;
		 	 	 N2=0;
		 	 	 ANS=0;
		 	 	 flag=1;
		 	 	 N1isNegative=0;
		 	 	 N2isNegative=0;
		 	 	 NegativeCount=0;
		 	 	 operationcount=0;
				 break;
		case '=':HLCD_vSendChar('=');
				 HLCD_vSetCursorPosition(1,0);
				 HLCD_vPrintString("ANS : ");
				 if(N1isNegative){
					 N1=N1 * (-1);
				 }
				 if(N2isNegative){
					 N2=N2 * (-1);
				 switch(operation){
				 case '+':ANS=N1+N2;
				 	 	  HLCD_vPrintNumber(ANS);
				 	 	  break;
				 case '-':ANS=N1-N2;
				 	 	  HLCD_vPrintNumber(ANS);
						  break;
				 case '/':ANS2=N1/(f64)N2;
				 	 	 HLCD_vPrintFloatNumber(ANS2);
					 	  break;
				 case '*':ANS=N1*N2;
				 	 	  HLCD_vPrintNumber(ANS);
					 	  break;
				 }
				 break;
		default:HLCD_vPrintNumber(L_u8Key-'0');
				if(flag==1){
					N1=N1*10+(L_u8Key-'0');
				}
				if(flag==2){
					N2=N2*10+(L_u8Key-'0');
				}
		}
	}
}
