/*************************************************************************
Copyright: 2020, Innovem Tech. Co., Ltd.
File Name: Analytic.h
************************************************************************/
//Create Date: 2018-3-4
//Author: Charming
//File: Analytic.h
//Directions: 表达式解析库头文件
//Last edit Date: 2018-3-6
 
#ifndef __ANALYTIC_H_
#define __ANALYTIC_H_
#define const_mode const
 
#define USESTRINGLIB 1
#define STRINGLIB_standard 1
 
#ifndef NULL
#define NULL 0
#endif
 
#define Exprlen 100
#define Polishlen 180
#define SymbolMax 80
#define NumberMax 50
 
typedef signed char a_size_t;
typedef signed short w_size_t;
 
typedef enum//初始化枚举类型
{
	Init_Expression,
	Init_Polish_Notation,
	Init_Ok,
	Init_Error
}Init_type;
 
typedef enum
{
	Conv_to_Polish,
	Calc_Results,
	Conv_Ok,
	Conv_MathError,
	Conv_OverFlow, 
	Conv_Exception
}Analytic_type;
 
Init_type Analytic_Init(Init_type type, char *address);
Analytic_type Analytic(Analytic_type type);
char *Analytic_Simplification(char *str);
double Get_Answer(); 
#endif
