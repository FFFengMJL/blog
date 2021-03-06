# Review

## 1

发展趋势：
- 语言交流功能越来越完美
- 各种动作的完美化
- *外形越来越酷似人类
- 逻辑分析能力越来越强
- 具备越来越多样化功能

分类
- 按照应用类型分类
  - 工业机器人
  - 特种机器人
  - 服务型机器人
- 按照控制方式分类
  - 操作机器人：由主、从机械手两部分组成，可实现*远距离操作*的机器人
  - 程序机器人：程序机器人按*预先给定*的程序、条件、位置进行作业
  - 示教再现机器人：将所教的操作过程自动记录在磁盘、磁带等*存储器*中，当需要再现操作时, 可重复所教过的动作过程
    - 手把手示教
    - 有线示教
    - 无线示教
  - 智能机器人：不仅可以进行预先设定的动作，还可以按照工作环境的变化改变动作
  - 综合机器人：由操作机器人、示教再现机器人、智能机器人组合而成的机器人
- 按照坐标形式分类
  - 直角坐标型：*3个线性关节*，通常还带有附加的*旋转关节*
  - 圆柱坐标型：由*两个滑动关节和一个旋转关节*来确定部件的位置, 再附加*一个旋转关节*来确定部件的姿态
  - 球坐标型：*一个滑动关节和两个旋转关节*来确定部件的位置, 再用*一个附加的旋转关节*确定部件的姿态
  - 关节坐标型：关节*全都是旋转*的
  - 平面关节型：只有平行的肩关节和肘关节，关节轴线共面，再用*一个附加的滑动关节*做垂直运动。
- 按照承载能力分类
  - 微型
  - 小型
  - 中型
  - 大型
  - 重型

基本组成：
- 3大部分：
  - 机械部分
  - 传感部分
  - 控制部分
- 6子系统：
  - 驱动系统：
    - 电气
    - 液压
    - 气动
    - 机械
    - 混合
  - 机械结构系统：
    - 基座
    - 手臂
    - 末端执行器
  - 感受系统：
    - 内部传感器模块
    - 外部传感器模块
  - 机器人-环境交互系统
    - 相互联系和协调的系统
  - 人机交互系统：
    - 指令给定装置
    - 信息显示装置
  - 控制系统

技术参数：
- 自由度
- 重复定位
- 精度
- 工作范围
- 最大工作速度
- 承载能力
- 速度

## 2

### 第一节

1. 总体设计步骤
   1. 系统分析
      1. 明确任务/目的
      2. 分析工作环境
      3. 分析工作要求
   2. 技术设计
      1. 确定基本参数
      2. 选择运动形式
      3. 拟定检测传感系统框图
      4. 确定控制系统
      5. 设计机械结构
   3. 仿真分析
      1. 运动学计算
      2. 动力学计算
      3. 动态仿真
      4. 性能分析
      5. 修改方案和参数
2. 设计主体结构
3. 选择传动方式
   - 直接连接传动
   - 远距离连接传动
   - 间接传动
   - 直接驱动
4. 设计模块化结构
   - 经济性
   - 灵活性
5. 选择本体材料
   1. 强度
   2. 弹性模量
   3. 重量
   4. 阻尼
   5. 材料价格
6. 设计平衡系统

### 第二节

1. 机器人驱动结构
   1. 直线驱动
      1. 齿轮齿条装置
      2. 普通丝杠
      3. 滚珠丝杠
      4. 液压传动
      5. 气压传动
   2. 旋转驱动
      1. 齿轮链
      2. 同步皮带
      3. 谐波齿轮
2. 传动部件设计
   1. 关节
   2. 传动件的定位和消隙
3. 驱动装置
   1. 电动驱动
   2. 液压驱动
   3. 气动驱动
   4. 新型驱动
      1. 磁伸缩驱动
      2. 形状记忆合金
      3. 静电驱动器
      4. 超声波电机
      5. 气动肌肉

### 第三节

1. 机身结构
   1. 横梁
   2. 立柱
   3. 机座
   4. 屈伸

## 移动机器人

分类：
- 运动轨迹
  - 固定轨迹
  - 无固定轨迹
- 工作环境
  - 结构环境
  - 非结构环境

### 轮式移动机器人

轮胎：
- 行驶地面：
  - 充气轮胎（室外）
  - 实心轮胎（室内）
  
> 麦克纳姆轮（全向移动）

### 履带式机器人

主体结构：
- 履带形状
- 支承轮
- 履带板
- 驱动轮和向轮
- 履带张紧装置
- 履带架

### 足式机器人

> 平衡问题

腿部结构：
- 开链足式
- 闭链足式

### 混合结构

- 轮足
- 履带足式

## 多指灵巧手

结构设计：
- 单轴关节
- 双轴关节
- 三轴关节

驱动方式：
- 电驱动
- 气压驱动
- 液压驱动
- SMA
- 压电陶瓷
- PMA

传动方式：
- 绳加滑轮传动
- 连杆机构传动
- 齿轮传动
- 带传动
- 链传动

设计：
1. 关节截面形式和材料
2. 选择和布置传感器
3. 设计关节尺寸和转角范围

## 并联机器人

并联机器人（Parallel Manipulator）由动平台、定平台以及连接它们的两个或者两个以上的独立运动支链组成，末端定平台具有两个或两个以上自由度的可控执行器。

应用：
- 并联机床
- 动态模拟
- 医疗器械
- 工业机器人
- 微纳操作
- 力与力矩传感器

典型并联机构：
- Stewart 平台
- Delta 并联机器人
- Tricept 机器人

位置正解数值方法：
- 迭代法
- 解析法
- 同伦算法
- 数学机械化方法

## 传感器

分类：
- 检测状态：
  - 内部传感器
  - 外部传感器
- 工作原理
  - 应变式
  - 压电式
  - 压阻式
  - 热点式检测器件

性能指标：
1. 灵敏度
2. 线性度
3. 测量范围
4. 精度
5. 重复性
6. 分辨率
7. 响应时间
8. 抗干扰能力

发展趋势：
1. 研发新型传感器
2. 开发新材料
3. 采用新工艺
4. 面向集成化、多功能化
5. 面向智能化

位置传感器：
- 接触式
- 接近式

视觉系统：
1. 图像输入
2. 图像处理
3. 图像理解
4. 图像储存
5. 图像输出

触觉传感器：
- 压阻式触觉传感器
- 压电式触觉传感器
- 光电式触觉传感器

## 控制系统

机器人完成任务的四个过程：
1. 示教过程
2. 计算与控制
3. 伺服驱动
4. 传感与检测

控制系统组成：
- 软件组成：
  - 控制软件，它包括*运动轨迹规划算法*和*关节伺服控制算法*及相应的动作程序
- 硬件组成
  - 中心控制器
  - 传感器
  - 驱动放大器
  - 执行机构
  - 电源

分类：
- 控制方式
  - 集中控制
  - 分散控制
  - 主从控制
- 运动控制方式
  - 位置控制
    - 点位控制
    - 连续轨迹
  - 速度控制
  - 力/力矩控制
  - 智能
  - 控制

要求和基本特点：
- 一般要求：控制系统应该满足记忆、示教、与外围设备联系、坐标设置、人机接口、传感器接口、位置伺服、故障诊断安全保护等基本功能

关节坐标的控制：
1. 位置控制问题
2. 基于关节坐标的控制

基于作业空间的控制：


机器人智能控制系统：
- 递阶控制系统
- 专家控制系统（专家控制器）
- 模糊控制系统（模糊控制器）
- 学习控制系统
  1. 模式识别
  2. 迭代学习
  3. 连接主义学习控制，包括强化学习控制
  4. 基于规则的学习控制，包括模糊学习控制
  5. 拟人自学习控制
  6. 状态学习控制
- 神经控制系统
  1. 对信息快速并行处理，适用于实时控制和动力学控制
  2. 非线性控制
  3. 可通过训练获得学习能力
  4. 有很强的的自适应能力和信息综合能力
- 进化控制系统
