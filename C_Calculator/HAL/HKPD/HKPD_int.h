/*
 * HKPD_int.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_HKPD_HKPD_INT_H_
#define HAL_HKPD_HKPD_INT_H_

#define HKPD_PORT MDIO_PORTD

void HKPD_vInit(void);
u8 HKPD_u8GetPressedKey(void);

#endif /* HAL_HKPD_HKPD_INT_H_ */
