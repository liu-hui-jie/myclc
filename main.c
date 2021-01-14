
/*************************************************************************
Copyright: 2020, Innovem Tech. Co., Ltd.
File Name: main.c
************************************************************************/

//Create Date: 2018-3-4
//Author: Charming
//File: Analytic.c
//Version: 1.7.2
//Last edit Date: 2018-3-15
//Directions: 测试源文件

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Analytic.h"

char E_String[Exprlen] = { 0 };
char P_String[Polishlen] = { 0 };

void DtoHex(int num)
{
    int a = num;
    unsigned b;
    if(a < 0) {
        unsigned tmp = abs(a);
        unsigned tmp1 = (~tmp) + 1;
        b = tmp1;
    } else {
        b = a;
    }
    printf("8:\t%o\n", b);
    printf("10:\t%d\n", num);
    printf("16:\t%X\n", b);
}

void BtoD(char *n)
{
    int size = strlen(n);
    int res = 0;
    for(int i = 0; i < size; ++i) {
        if(n[i] == '1') {
            res += pow(2.0, size - i - 1);
        }
    }
    DtoHex(res);
}
int main(int argc, char *argv[])
{
    if(argc < 2) {
        return 0;
    }
    int num = 0;
    if(strstr(argv[1], "0d")) {
        num = atoi(argv[1] + 2);
        DtoHex(num);
        return 0;
    } else if(strstr(argv[1], "0b")) {
        BtoD(argv[1] + 2);
        return 0;
    } else if(strstr(argv[1], "0x")) {
        sscanf(argv[1] + 2, "%x", &num);
        DtoHex(num);
        return 0;
    }
    Analytic_type res;
    Analytic_Init(Init_Expression, E_String);
    Analytic_Init(Init_Polish_Notation, P_String);
    memcpy(E_String, argv[1], strlen(argv[1]));
    if(strncmp(E_String, "exit", 4) == 0)
        return 0;
    Analytic_Simplification(E_String);
    if((res = Analytic(Conv_to_Polish)) == Conv_Ok)
        res = Analytic(Calc_Results);
    switch(res) {
    case Conv_Ok:
        printf("res:%g\n", Get_Answer());
        break;
    case Conv_MathError:
        printf("\r\n数学错误！\r\n\r\n");
        break;
    case Conv_OverFlow:
        printf("\r\n堆栈溢出！\r\n\r\n");
        break;
    case Conv_Exception:
        printf("\r\n系统异常！\r\n\r\n");
        break;
    default:
        break;
    }
    return 0;
}

