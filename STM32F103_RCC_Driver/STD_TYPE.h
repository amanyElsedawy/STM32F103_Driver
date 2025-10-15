/**
 ******************************************************************************
 * @file           : STD_TYPE.h
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 14-10-2025
 * @brief          :  Standard type definitions (u8, u16, u32, etc)
 * @note           : Built for MCU
 ******************************************************************************
 */
#ifndef STDTYPE_H
#define STDTYPE_H

// Standard Types
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
typedef signed long int s32;

typedef  float f32;
typedef double f64;
#define STD_OK  1
#define STD_NOK  0
#define NULL  ((void*)0)
#define  DATA_READY        0
#define  DATA_NOT_READY    1
#endif //
