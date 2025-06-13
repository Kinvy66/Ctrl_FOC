#ifndef __MC_FSM_H
#define __MC_FSM_H

// Motor controler state
typedef enum eFSMState {
    BOOT_UP     = 0,
    IDLE        = 1,
    RUN         = 2,
    M_ERR       = 3
} tFSMState;

/* 提供给其他C文件调用的函数 */
void MCT_init(void);
tFSMState MCT_get_state(void);
int MCT_set_state(tFSMState state);
void MCT_high_frequency_task(void);



#endif //__MC_FSM_H
