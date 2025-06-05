
#include "MagneticSensorSPI.h"

#define SENSOR_DEFAULT_SPI  hspi1
#define SPI_CS_0()	    MT6816_CS_GPIO_Port->BSRR = ((uint32_t)MT6816_CS_Pin << 16U)
#define SPI_CS_1()		MT6816_CS_GPIO_Port->BSRR = MT6816_CS_Pin

uint16_t MA6818_Registers[2] = {0x8300, 0x8400};

/** Typical configuration for the 14bit MonolithicPower MA730 magnetic sensor over SPI interface */
MagneticSensorSPIConfig_s MA6818_SPI = {
	.spi_handle = &SENSOR_DEFAULT_SPI,
	.bit_resolution = 14,
	.angle_register = MA6818_Registers,
	.register_number = 2,
	.no_mag_warning_bit = 1,
	.command_parity_bit = 0,
};


/**
 * @brief
 * @param config
 */
MagneticSensorSPI::MagneticSensorSPI(MagneticSensorSPIConfig_s config){
	spi = config.spi_handle;
	// angle read register of the magnetic sensor

	angle_registers = config.angle_register ? config.angle_register : nullptr;
	register_num = config.register_number;
	// register maximum value (counts per revolution)
	cpr = _powtwo(config.bit_resolution);
	bit_resolution = config.bit_resolution;

	command_parity_bit = config.command_parity_bit; // for backwards compatibilty
	command_rw_bit = config.command_rw_bit; // for backwards compatibilty
}

void MagneticSensorSPI::init(){
	// spi = _spi;
	this->Sensor::init(); // call base class init
}

//  Shaft angle calculation
//  angle is in radians [rad]
float MagneticSensorSPI::getSensorAngle(){
  // return (getRawCount() / (float)cpr) * _2PI;
}

// function reading the raw data of the magnetic sensor
void MagneticSensorSPI::getRawData(){
	// return (int)MagneticSensorSPI::read(angle_register);
}

// SPI functions 
/**
 * Utility function used to calculate even parity of word
 */
uint8_t MagneticSensorSPI::spiCalcEvenParity(uint16_t value){
	uint8_t cnt = 0;
	uint8_t i;

	for (i = 0; i < 16; i++)
	{
		if (value & 0x1) cnt++;
		value >>= 1;
	}
	return cnt & 0x1;
}

  /*
  * Read a register from the sensor
  * Takes the address of the register as a 16 bit word
  * Returns the value of the register
  */
uint16_t MagneticSensorSPI::read(uint16_t angle_register){

	uint16_t command = angle_register;
}


/**
 * Closes the SPI connection
 * SPI has an internal SPI-device counter, for each init()-call the close() function must be called exactly 1 time
 */
void MagneticSensorSPI::close(){
	// spi->end();
}


