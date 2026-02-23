// sf.h - 头文件：函数声明（工业级规范写法）
#ifndef SF_H // 防止头文件被重复包含（必须加）
#define SF_H
#include<stdio.h>
#include <stdbool.h>    // 引入函数依赖的头文件（如bool类型）

// 函数声明：和定义的返回值、参数列表完全一致，末尾加;
int setChargePower2(float d,float t);
int getChargeStopFlag(void);
float getChargeTime(void);
void heartbeat_15s() ;
void readBatteryData(float data[]);
// 其他函数的声明
//void setChargePower(float power);

#endif // CHARGE_CALC_H