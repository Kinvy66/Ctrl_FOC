#ifndef __FOC_ALG_H
#define __FOC_ALG_H

#define FOC_ALG_SOFTWARE_VERSION               "V1.0.0"


#include "usr_config.h"
#include "pid.h"
#include "foc.h"
#include "mc_fsm.h"
#include "pwm_curr.h"
#include "encoder.h"
#include "calibration.h"

void foc_alg_init(void);
void USR_CONFIG_print_config(void);

#endif //__FOC_ALG_H
