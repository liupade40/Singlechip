#ifndef __KEY__H
#define __KEY__H
#include "stm32f10x.h"                  // Device header
typedef enum 
{
    None,
    Up,
    Down,
    Left,
    Right
} Direction;
void KEY_Init(void);
Direction Key_GetDirection();

#endif