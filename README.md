# 气压计和陀螺仪小模块——PILOT-BEST-HLEPER

#### 前言：出于之后项目的需要，我做了一个集成气压计和陀螺仪的小模块，这个仓库目前发布的是这个小模块的第一版固件，硬件部分暂不开源。

#### 一、核心器件

##### 		1、BMI055：六轴惯性传感器（三轴陀螺仪+三轴加速度计），性能略逊于BMI088，但是远强于MPU6050和MPU6500等，买的淘宝全新原装，价格6RMB

##### 		2、SPL06-001：高精度气压计，介绍说短时精度在5cm以内，实际测试确实能达到这种程度（未做恒温）

##### 		3、STM32F030C6T6：淘宝买的主控板，一块多钱，选型没啥特别的，主要便宜，有串口就行，性能都是够的。



#### 二、功能描述

##### 1、采用定时器时间片轮询进行任务管理，目前运行的任务有SPL06数据处理任务、BMI055数据处理任务

##### 2、实现了气压计原始数据读取，气压计数据一阶低通滤波，气压计高度解算等，数据精度在5CM以内，可以根据需求更改低通滤波器带宽，当然存在长时间缓慢漂移

##### 3、实现了惯性单元六轴原始数据读取，卡尔曼姿态解算（pitch and roll），偏航角（yaw）用的是积分 + 零漂死区的方法处理，静态零漂完美抑制（放着不动或者加入高频震动一点也不漂），动态零漂抑制效果不显著，会存在运动之后坐标轴不重合的现象



#### 三、正在解决的问题

##### 1、添加用户服务任务（user_task），用于对外的数据输出

##### 2、加速度数据解算，输出世界坐标系下的加速度数据

##### 3、加速度计和气压计高度融合，输出速度和高度（绝对高度）

##### 4、温控抑制动态零漂



#### 四、实物展示



![正面](E:\git_test\正面.jpg)

![背面](E:\git_test\背面.jpg)
