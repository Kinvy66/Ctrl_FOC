#include "GenericSensor.h"


/*
  GenericSensor( float (*readCallback)() )
  - readCallback - pointer to the function which reads the sensor angle.
*/

GenericSensor::GenericSensor(readCallback read_callback ,
                             initCallback init_callback){
    // if function provided add it to the
    if(read_callback != nullptr) this->m_read_callback = read_callback;
    if(init_callback != nullptr) this->m_init_callback = init_callback;
}

void GenericSensor::init(){
    // if init callback specified run it
    if(m_read_callback != nullptr) this->m_init_callback();
    this->Sensor::init(); // call base class init
}

/*
    Shaft angle calculation
*/
float GenericSensor::getSensorAngle(){
    return this->m_read_callback();
}