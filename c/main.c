#include <stdio.h>
#include<string.h>
#include "sf.h"
#include <unistd.h>  // for sleep()

int main()
{
    float t ;
    int p ;
    int stopflag=0 ;
    float D ;//定义电池容量参数D
    float SOC ;//定义当前电池百分比SOC
    //获取电池参数D与SOC值，并赋值
     float batterydata[2];  // 数组：batteryInfo[0] 存额定容量，batteryInfo[1] 存 SOC
     float d;               // 需要充电的度数

    // 调用函数获取数据
    readBatteryData(batterydata);

    // 从数组中取出 D 和 SOC
     D = batterydata[0];
     SOC = batterydata[1];

    // 计算需要充电的度数（假设 SOC 为百分比，范围 0~100）
    d = D * (100.0 - SOC) / 100.0;

    //根据计算出来的d选择执行算法

   while (stopflag != 1)//判断充电是否结束
    {
        stopflag = getChargeStopFlag();//获取充电结束标志位
        //如果充电结束，则执行充电停止指令
        if (stopflag == 1)
         {
            printf("发出充电停止的指令 \n");
            break;
         }
         //如果充电未结束，则执行充电功率调整指令
         t = getChargeTime();//获取当前充电时间0
         p = setChargePower2( d , t ) ;//根据当前充电时间计算应设置的充电功率
         printf ("发出设置当前电流为%d的指令 \n \n",p);
         printf("15秒后再次重新设置功率 \n");

         heartbeat_15s() ;   // 暂停 15 秒0
    }
    

return 0;

}