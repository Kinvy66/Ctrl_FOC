/**
* @file key.cpp
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/20 11:04
* @description: 
**/
#include "key.h"

typedef enum
{
    NONE_KEY,
    KEY1_CLICKED,
    KEY1_DBLCLICKED,
    KEY1_LONGCLICKED,
    KEY2_CLICKED,
    KEY2_DBLCLICKED,
    KEY2_LONGCLICKED,
    KEY3_CLICKED,
    KEY3_DBLCLICKED,
    KEY3_LONGCLICKED,
    KEY4_CLICKED,
    KEY4_DBLCLICKED,
    KEY4_LONGCLICKED,
} KeyValue ;

uint8_t g_key_value = NONE_KEY;

keyCategory_t keys[KEY_NUM] = {
    [KEY1] = {
        .fsm.keyGpio.keyPort = KEY1_GPIO_Port,
        .fsm.keyGpio.keyPin = KEY1_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_RESET,
        .func.ShortPressCb = key1_short_press,
        .func.longPressCb = key1_long_press,
        .func.dbclPressCb = key1_dbclk_press,
    },
    [KEY2] = {
        .fsm.keyGpio.keyPort = KEY2_GPIO_Port,
        .fsm.keyGpio.keyPin = KEY2_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_RESET,
        .func.ShortPressCb = key2_short_press,
        .func.longPressCb = key2_long_press,
        .func.dbclPressCb = key2_dbclk_press,
    },
    [KEY3] = {
        .fsm.keyGpio.keyPort = KEY3_GPIO_Port,
        .fsm.keyGpio.keyPin = KEY3_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_RESET,
        .func.ShortPressCb = key3_short_press,
        .func.longPressCb = key3_long_press,
        .func.dbclPressCb = key3_dbclk_press,
    },
    [KEY4] = {
        .fsm.keyGpio.keyPort = KEY4_GPIO_Port,
        .fsm.keyGpio.keyPin = KEY4_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_RESET,
        .func.ShortPressCb = key4_short_press,
        .func.longPressCb = key4_long_press,
        .func.dbclPressCb = key4_dbclk_press,
    },
};

__weak void key1_short_press()
{
    g_key_value = KEY1_CLICKED;
}
__weak void key2_short_press()
{
    g_key_value = KEY2_CLICKED;
}

__weak void key3_short_press()
{
    g_key_value = KEY3_CLICKED;
}

__weak void key4_short_press()
{
    g_key_value = KEY4_CLICKED;
}

__weak void key1_long_press()
{
    g_key_value = KEY1_LONGCLICKED;
}

__weak void key2_long_press()
{
    g_key_value = KEY2_LONGCLICKED;
}

__weak void key3_long_press()
{
    g_key_value = KEY3_LONGCLICKED;
}

__weak void key4_long_press()
{
    g_key_value = KEY4_LONGCLICKED;
}
__weak void key1_dbclk_press()
{
    g_key_value = KEY1_DBLCLICKED;
}
__weak void key2_dbclk_press()
{
    g_key_value = KEY2_DBLCLICKED;
}
__weak void key3_dbclk_press()
{
    g_key_value = KEY3_DBLCLICKED;
}
__weak void key4_dbclk_press()
{
    g_key_value = KEY4_DBLCLICKED;
}

/**
 * @brief 按键初始化
 */
void key_init()
{
    keyParaInit(keys);
}

/**
 * @brief 按键扫描，读取键值
 * @return 当前键值
 */
uint8_t key_scan()
{
    return g_key_value;
}

void key_cb_register(uint8_t keyId, keyEvent_t event, void (*cb)(void))
{
    switch (event){
    case NULL_Event:
        keyTable[keyId].func.nullPressCb = cb;
        break;
    case SHORT_Event:
        keyTable[keyId].func.ShortPressCb = cb;
        break;
    case DOWN_Event:
        keyTable[keyId].func.downPressCb = cb;
        break;
    case DBCL_Event:
        keyTable[keyId].func.dbclPressCb = cb;
        break;
    case LONG_Event:
        keyTable[keyId].func.longPressCb = cb;
        break;
    case LAST_Event:
        keyTable[keyId].func.lastPressCb = cb;
        break;
    default:
        break;
    }
}

