#ifndef GENERIC_SENSOR_LIB_H
#define GENERIC_SENSOR_LIB_H

#include "foc_utils.h"
#include "time_utils.h"
#include "Sensor.h"


class GenericSensor: public Sensor{
public:
    using readCallback = float (*)();
    using initCallback = void (*)();

    /**
    GenericSensor class constructor
     * @param read_callback pointer to the function reading the sensor angle
     * @param init_callback pointer to the function initialising the sensor
    */
    explicit GenericSensor(readCallback read_callback = nullptr, initCallback init_callback = nullptr);

    readCallback m_read_callback = nullptr; //!< function pointer to sensor reading
    initCallback m_init_callback = nullptr; //!< function pointer to sensor initialisation

    void init() override;

    // Abstract functions of the Sensor class implementation
    /** get current angle (rad) */
    float getSensorAngle() override;

};


#endif
