---
layout: default
title: 笔记：CPU进程管理
---

# CPU 管理

1. 进程在执行**I/O操作**时，操作系统会让其让出CPU
2. 有些时候，操作系统严格设置进程执行实现，运行这个时间后强行打断并让出CPU（给其他程序）

## 进程控制块（process control block）

1. 将中断前的**现场数据**（缓存可以不保存，但是寄存器中的都会储存）储存

2. 在该进程**运行开始前**，将块中的数据（寄存器的数据）载入

3. 这种**信息的交换**被称作 **contest switch**

> CPU小于一个值（比如说80)的时候，尽量减少使用的核的数量

## CPU 调度与策略

### CPU 调度

1. **非抢占式**调度：不打断其CPU调度，直到有指令命令其让出/退出（一般用于不经常与人交互的系统）
2. **抢占式**调度：在更加紧急的进程需要使用CPU时，将当前占用CPU的进程打断将CPU让位给它，The operating system decides to favor another process, preempting the currently executing process
3. 时间片：**分配时间段**，给进程各一段运行的时间

### CPU 策略

1. 排队服务策略，**F**irst-**C**ome,**F**irst-**S**erved
2. 最短时间优先，**S**hortest **J**ob **N**ext
3. 分时循环，**R**ound **R**obin（抢占式调度）

