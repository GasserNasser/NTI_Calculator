/*
 * HSSD_int.h
 *
 *  Created on: Jun 10, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_HSSD_HSSD_INT_H_
#define HAL_HSSD_HSSD_INT_H_

#define HSSD_COM_ANODE   1
#define HSSD_COM_CATHODE 2

#define HSSD1_CONTROL_PORT	MDIO_PORTB
#define HSSD2_CONTROL_PORT	MDIO_PORTB

#define HSSD1_CONTROL_PIN	MDIO_PIN0
#define HSSD2_CONTROL_PIN	MDIO_PIN1

typedef struct{
	u8 SSD_Port;
	u8 SSD_Type;
	u8 SSD_Number;
}SSD_t;
void HSSD_vInit(SSD_t* A_xSSD);
void HSSD_vDisplayNum(SSD_t* A_xSSD);
void HSSD_vTurnOff(SSD_t* A_xSSD);
void HSSD_Display2Num(SSD_t* A_xSSD1,SSD_t* A_xSSD2,u8 A_u8Number );
#endif /* HAL_HSSD_HSSD_INT_H_ */
