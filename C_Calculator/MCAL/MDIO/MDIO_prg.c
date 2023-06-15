/*
 * DIO_prg.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "MDIO_int.h"
#include "MDIO_prv.h"
void MDIO_vSetPinDir(u8 A_u8PortNO,u8 A_u8PinNo,u8 A_u8Dir){


	if(A_u8Dir== MDIO_OUTPUT){

		switch(A_u8PortNO)
		{
		case MDIO_PORTA : SET_BIT(DDRA,A_u8PinNo);
		break;
		case MDIO_PORTB : SET_BIT(DDRB,A_u8PinNo);
		break;
		case MDIO_PORTC : SET_BIT(DDRC,A_u8PinNo);
		break;
		case MDIO_PORTD : SET_BIT(DDRD,A_u8PinNo);
		break;
		}
	}
	else if (A_u8Dir==MDIO_INPUT){
		switch(A_u8PortNO)
		{
		case MDIO_PORTA : CLR_BIT(DDRA,A_u8PinNo);
		break;
		case MDIO_PORTB : CLR_BIT(DDRB,A_u8PinNo);
		break;
		case MDIO_PORTC : CLR_BIT(DDRC,A_u8PinNo);
		break;
		case MDIO_PORTD : CLR_BIT(DDRD,A_u8PinNo);
		break;
		}
	}



}
void MDIO_vSetPinVal(u8 A_u8PortNO,u8 A_u8PinNo,u8 A_u8Val){

	if(A_u8Val== MDIO_HIGH){

		switch(A_u8PortNO)
		{
		case MDIO_PORTA : SET_BIT(PORTA,A_u8PinNo);
		break;
		case MDIO_PORTB : SET_BIT(PORTB,A_u8PinNo);
		break;
		case MDIO_PORTC : SET_BIT(PORTC,A_u8PinNo);
		break;
		case MDIO_PORTD : SET_BIT(PORTD,A_u8PinNo);
		break;
		}
	}
	else if (A_u8Val==MDIO_LOW){
		switch(A_u8PortNO)
		{
		case MDIO_PORTA : CLR_BIT(PORTA,A_u8PinNo);
		break;
		case MDIO_PORTB : CLR_BIT(PORTB,A_u8PinNo);
		break;
		case MDIO_PORTC : CLR_BIT(PORTC,A_u8PinNo);
		break;
		case MDIO_PORTD : CLR_BIT(PORTD,A_u8PinNo);
		break;
		}
	}

}
u8 MDIO_u8GetPinVAl(u8 A_u8PortNO,u8 A_u8PinNo){

	u8 L_u8PinVal=0;

	switch(A_u8PortNO)
	{
	case MDIO_PORTA : L_u8PinVal = GET_BIT(PINA,A_u8PinNo);
	break;
	case MDIO_PORTB : L_u8PinVal = GET_BIT(PINB,A_u8PinNo);
	break;
	case MDIO_PORTC : L_u8PinVal = GET_BIT(PINC,A_u8PinNo);
	break;
	case MDIO_PORTD : L_u8PinVal = GET_BIT(PIND,A_u8PinNo);
	break;
	}

	return L_u8PinVal;


}
void MDIO_vSetPortDir(u8 A_u8PortNO,u8 A_u8Dir){
	switch(A_u8PortNO)
	{
	case MDIO_PORTA : DDRA = A_u8Dir;
	break;
	case MDIO_PORTB : DDRB = A_u8Dir;
	break;
	case MDIO_PORTC : DDRC = A_u8Dir;
	break;
	case MDIO_PORTD : DDRD = A_u8Dir;
	break;
	}

}
void MDIO_vSetPortVal(u8 A_u8PortNO,u8 A_u8Val){
	switch(A_u8PortNO)
	{
	case MDIO_PORTA : PORTA = A_u8Val;
	break;
	case MDIO_PORTB : PORTB = A_u8Val;
	break;
	case MDIO_PORTC : PORTC = A_u8Val;
	break;
	case MDIO_PORTD : PORTD = A_u8Val;
	break;
	}

}
void MDIO_vTogPinVal(u8 A_u8PortNO,u8 A_u8PinNo){
	switch(A_u8PortNO)
	{
	case MDIO_PORTA : TOG_BIT(PORTA,A_u8PinNo);
	break;
	case MDIO_PORTB : TOG_BIT(PORTB,A_u8PinNo);
	break;
	case MDIO_PORTC : TOG_BIT(PORTC,A_u8PinNo);
	break;
	case MDIO_PORTD : TOG_BIT(PORTD,A_u8PinNo);
	break;
	}

}
