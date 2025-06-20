/**
* @file key.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/20
* @description:
**/

#ifndef __KEY_H
#define __KEY_H

#include "main.h"
#include "hal_key.h"

extern uint8_t g_key_valuel;

void key1_short_press();
void key2_short_press();
void key3_short_press();
void key4_short_press();

void key1_long_press();
void key2_long_press();
void key3_long_press();
void key4_long_press();

void key1_dbclk_press();
void key2_dbclk_press();
void key3_dbclk_press();
void key4_dbclk_press();

void key_init();
void key_cb_register(uint8_t keyId, keyEvent_t event, void (*cb)(void));
uint8_t key_scan();


#endif //__KEY_H

