#ifndef MAGNETICSENSORSPI_LIB_H
#define MAGNETICSENSORSPI_LIB_H


// #include "Arduino.h"
// #include <SPI.h>
#include "main.h"
#include "spi.h"
#include "../Common/BaseClass/Sensor.h"
#include "../common/foc_utils.h"
#include "../common/time_utils.h"

struct MagneticSensorSPIConfig_s  {
  SPI_HandleTypeDef *spi_handle;
  uint8_t bit_resolution;
  uint16_t *angle_register;
  uint8_t  register_number;
  uint8_t no_mag_warning_bit;
  uint8_t command_parity_bit;
  int command_rw_bit;  // rev
};
// typical configuration structures
extern MagneticSensorSPIConfig_s AS5147_SPI,AS5048_SPI,AS5047_SPI, MA730_SPI;

class MagneticSensorSPI: public Sensor{
 public:
    /**
     *  MagneticSensorSPI class constructor
     * @param config   SPI config
     */
    MagneticSensorSPI(MagneticSensorSPIConfig_s config);

    /** sensor initialise pins */
    void init();

    // implementation of abstract functions of the Sensor class
    /** get current angle (rad) */
    float getSensorAngle() override;



  private:
    float cpr; //!< Maximum range of the magnetic sensor
    // spi variables
    uint16_t* angle_registers; //!< SPI angle register to read
    uint8_t   register_num; //!< SPI angle register to read
    uint8_t   raw_data[10];
    // spi functions
    /** Stop SPI communication */
    void close(); 
    /** Read one SPI register value */
    uint16_t read(uint16_t angle_register);
    /** Calculate parity value  */
    uint8_t spiCalcEvenParity(uint16_t value);


    /**
     * Function getting current angle register value
     * it uses angle_register variable
     */
    void getRawData();
    
    int bit_resolution; //!< the number of bites of angle data
    int command_parity_bit; //!< the bit where parity flag is stored in command
    int command_rw_bit; //!< the bit where read/write flag is stored in command

    SPI_HandleTypeDef* spi;

};


#endif
