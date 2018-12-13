---
layout: default
title: 笔记：网络（未上完
---
# Network and WWW（网络与万维网）

## 1. Goals

1. Core Issues related to computer networks
2. Types of networks and characteristics
3. Open System
4. Home Internet Connections
5. Packet Switching（包交换）
6. Protocols（协议）
7. Hostnames and IP Addresses (域名与IP地址)
8. Domain Name

 2.Networking

## Goal:  
1. Communicate（交流）
2. Share resources（分享资源）

### Method:  
1. Physical wires or cables（五类线，超五类线，双绞线）
2. Wireless（WI-FI，蓝牙，LI-FI）

### 术语
1. Node/Host（节点/主机）
2. Data Transfer Rate（数据传输速度）：**B**its **P**er **S**econd（用字节换算的话需要除以8）
    * **传输速度**和**距离**是计算机网络研究的**核心问题**（光纤减衰减）

## Client/Server Model

### 1. File Server（文件服务器）
* FTP 协议
* FTP 服务器
* FTP 客户端

### 2. Web Server（网页服务器）
* 服务器
* 本地客户端——浏览器（IE, chrome, Safari, FireFox）
* HTTP 协议（浏览器默认会加）

### 3. 点拨服务器

### 4. 各种各样的应用服务器

## Types of Network

### 1. Local-area Network（LAN，局域网）

1. 大小：一般不会超过256个
2. 拓扑图：
    * Ring topology（环状）
    * Star topology（星型）
    * Bus topology（类似于计算机的总线，结构简单，可靠性强——一节点坏，不影响其他节点；只能共享，分时段使用）：Ethernet（以太网）

### 2. Wide-area Network（WAN，广域网）

1. **Gateway**（**网关**）：将局域网和其他局域网**连接**在一起（例如，路由器）
2. 广域网内地址分配是允许重复的，但是局域网内不允许

### 3. Metropolitan-area Network（MAN，城域网）

### 4. Internet Backbone（骨干网）

1. 方式：一般使用**环状**
2. These networks are provided by companies such as CISCO, 华为, AT&T, GTE, and IBM

### 5. **I**nternet **S**ervice **P**rovider（互联网服务提供商）

1. 中国进出口负责：中国电信，中国联通
2. 常见接入方式：DSL

### 6. 接入方式

1. Phone Modem：使用**电话线**，打电话时会被占用
2. Digital Subscriber Line（DSL）：使用**电话线**的**数字通道**
3. Cable Modem：光纤

> 三网融合：**电视网**（机顶盒可当路由器用），**计算机网**，**电话网**融合

> IP电话：使用网络来打电话；以前使用**模拟信号通讯**，现在都是**数字信号通讯**（IP电话）

### 7. Broadband（带宽）

1. 定义：A connection in which transfer speeds are **faster than 128K bps**
2. 上传速度和下载速度**不对等**（避免占用过多）

## Packet Switching（包交换）

1. 作用：提高信息交换的可靠性与效率
2. 描述：将信息分成若干个片段（包）分开传输
    * 由于物理原因，信息传递会有**出错**的概率-->减少出错所造成的危害，加快传输效率
    * 大型域网交换信息的时候，传输的**路径**不一定一样，在**传输速度较慢**的时候，发送和接受的**顺序**不一定相同（视频缓冲，语音/电话）

## Open System（开放系统）

### 发展

1. Proprietary System（私人系统）：A system that uses technologies kept private by a particular commercial vendor
2. Interoperability（出现接口）
3. Open Systems

### OSI（Open Systems）

1. 定义方：ISO
2. 内容：7层协议
    1. 物理层
    2. 数据层
    3. 网络层
    4. 传输层
    5. Session layer
    6. Presentation layer
    7. Application layer