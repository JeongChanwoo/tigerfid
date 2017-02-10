/*******************************************************************************
* @file     i2c_ee.h
* @author   imoware
* @version  V3.4.0
* @date     04/13/12
********************************************************************************
* @version history    Description
* ----------------    -----------
* v2.5.0              LSI Clock Enable for RTC (deprecated with 2.7 release)
* v2.6.0              LSI Clock Calibration (deprecated with 2.7 release)
* v2.7.0              LSE Clock Enable for RTC
* v2.8.0              (1) Tag Version, (2) Last Packet Reserved
* v3.0.0              Tamper Switch Debounce Handler
* v3.1.0              Tamper Switch Debounce Handler WITHOUT Timer2
* v3.2.0              Battery Low Voltage History is Updated when Timer is on only
* v3.3.0              on/off
* v3.4.0              Corrected command handling for Factory Reset,
*                     Corrected interrupt handling for Band tamper
*******************************************************************************/

#ifndef __I2C_EE_H
#define __I2C_EE_H

#include "types.h"
#include "error_code.h"

#ifdef I2C_FAST_MODE
#define I2C_SPEED 400000  // 400kHz
#else
#define I2C_SPEED 100000  // 100kHz
#endif

#define I2C_RETRY 50

#define EEPROM_USER_ADDRESS         (uint8_t)0xA6
#define EEPROM_SYSTEM_ADDRESS       (uint8_t)0xAE

void i2cInit(void);

void i2cPowerOff(void);
void i2cPowerOn(void);

ErrorCode i2cReadBuffer(uint8_t *pBuffer, uint16_t ReadAddr, uint8_t NumByteToRead, uint8_t eepromAddress);
ErrorCode i2cWriteBuffer(const uint8_t *pBuffer, uint16_t WriteAddr, uint8_t NumByteToWrite, uint8_t eepromAddress);
#endif
/*************************** END OF FILE **************************************/


