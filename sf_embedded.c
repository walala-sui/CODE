#include<stdio.h>
#include <unistd.h>  // for sleep()
//功率计算函数
int setChargePower2(float d,float t)
 {
    int a;

    //当计算充电容量小于40；
    if (d > 0 && d <= 40)
    {
        a = 8 ;
    }
    
    //计算大于40小于60
    else if (d > 40 && d <= 60)
    {
        if (t > 0 && t <= 1.5) 
     {
        a = 32;
     }
     else if (t > 1.5 && t <= 6)
     {
        // 使用浮点除法 (16.0/3.0)，并明确转换为 int（截断）
        a = -(16.0 / 3.0) * t + 40;
     }
     else
     {  // 对应 t > 6 的情况
        a = 8;
     }
    }

     //计算大于60小于等于100
      else if (d > 60 && d <= 100)
    {
        if (t > 0 && t <= 4) 
      {
        a = 32;
      }
     else if (t > 4 && t <= 14)
      {
        // 使用浮点除法 (16.0/3.0)，并明确转换为 int（截断）
        a = -(12.0 / 5.0) * t + (208.0 / 3.0);
      }
     else
      {  // 对应 t > 6 的情况
        a = 8;
      }
     }

    //其他剩余情况
    else
     {
        a = 32 ;
     }

    return a;
}

//获取充电停止标志位函数
int getChargeStopFlag(void) {
    static int count = 0;
    printf("获取充电停止标志位为：\n");
    scanf("%d",&count);
    // 获取充电停止标志位
    return (count);
}

//获取当前充电时间含税
float getChargeTime(void) {
     float time = 0;
    printf("获取当前充电时间为：\n");
    scanf("%f",&time);
    // 获取充电停止标志位
    return (time);
}
//15秒心跳
void heartbeat_15s() 
{
    for (int i = 1; i <= 5; i++)
     {
        printf("第 %d 秒\n", i);
        fflush(stdout);      // 立即刷新输出缓冲区，确保实时显示
        sleep(1);         // 暂停 1000 毫秒 = 1 秒
    }
    printf("开始执行充电功率调节 \n");
}
//从目标地址获取D与SOC的值
void readBatteryData(float data[])
 {
    printf("请输入电池额定容量 (kWh) 和当前 SOC (百分比，如 45.5)，用空格或回车分隔：\n");
    // 同时读取两个 double 值，直接存入数组的两个元素
    scanf("%f %f", &data[0], &data[1]);
}