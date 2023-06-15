/*
 * DIO_int.h
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_MDIO_MDIO_INT_H_
#define MCAL_MDIO_MDIO_INT_H_

#define MDIO_PORTA  0
#define MDIO_PORTB  1
#define MDIO_PORTC  2
#define MDIO_PORTD  3

#define MDIO_PIN0   0
#define MDIO_PIN1   1
#define MDIO_PIN2   2
#define MDIO_PIN3   3
#define MDIO_PIN4   4
#define MDIO_PIN5   5
#define MDIO_PIN6   6
#define MDIO_PIN7   7


#define MDIO_OUTPUT 1
#define MDIO_INPUT  0

#define MDIO_HIGH   1
#define MDIO_LOW    0

void MDIO_vSetPinDir(u8 A_u8PortNO,u8 A_u8PinNo,u8 A_u8Dir);
void MDIO_vSetPinVal(u8 A_u8PortNO,u8 A_u8PinNo,u8 A_u8Val);
u8 MDIO_u8GetPinVAl(u8 A_u8PortNO,u8 A_u8PinNo);
void MDIO_vSetPortDir(u8 A_u8PortNO,u8 A_u8Dir);
void MDIO_vSetPortVal(u8 A_u8PortNO,u8 A_u8Val);
void MDIO_vTogPinVal(u8 A_u8PortNO,u8 A_u8PinNo);



#endif /* MCAL_MDIO_MDIO_INT_H_ */
