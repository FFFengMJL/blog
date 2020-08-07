# 我的博客

## 关于软导

1. <a href="001(forlab01">用-乌龟git-更加简单地clone代码仓库</a>

2. <a href="002(forlab07">使用vbox新建winXP来打开-辣个CPU模拟界面-</a>

3. <a href="003(forlab10">硬核安装 Python 以及 numpy 和 sympy 中的常用函数</a>

4. <a href="004(forlab15">没那么硬核的 Ubuntu 18.04 虚拟机安装指引</a>

## 小玩意儿

1. [av 号与 BV 互转](./AvToBv/atb.html)

## Matrix 入门相关

[Matrix 线上分享：Web入门基础](work/matrix/share_online/web入门基础)

1. Web入门：`2020-3-3`
  - [X] [第一个网页](./work/matrix/step1/001/tmnt.html)
2. 学习HTML：`2020-3-5`
  - [X] [标记信件](./work/matrix/step1/002/001/letter.html)
  - [X] [构建出有内容的网页](./work/matrix/step1/002/002/index.html)
  - [X] [Mozilla 醒目页面](./work/matrix/step1/002/003/index.html)
  - [X] [构建行星数据](./work/matrix/step1/002/004/blank-template.html)
  - [X] [仿制中山大学 APP / 中山大学微信企业号提供的学生健康申报表单中“个人基本信息”部分的 HTML 结构](./work/matrix/step1/002/005/index.html)
     1. 不使用外部 CSS 库和 UI 库；可按需引入 JavaScript 库。
     2. 不要求仿制界面样式，自己看着办~
     3. 原表单中固定的表单项（如姓名、学院等）改为适合的可输入组件。
     4. 表单项“填报人联系方式”、“紧急联系人手机号”加入适当的验证（按中国内地手机号码匹配）。
     5. 表单项“培养层次”改为使用下拉框，或者在原基础上加入自动建议功能。参考值为本科生、研究生和博士生。
     6. 表单项“籍贯”仅实现单选框部分，不需要实现省市区选择。
     7. 加入表单项“曾到访省份”，使用复选框实现，可选值包括 广东省、湖北省、浙江省、河南省 这四个。
     8. 每个表单项均设置合理的 name 和 value。
3. 学习CSS：`2020-3-7`
  - [X] [CSS first steps: Using your new knowledge](./work/matrix/step1/003/001/index.html)
  - [X] [CSS building blocks: CSS 基本了解](./work/matrix/step1/003/002/index.html)
  - [X] [CSS building blocks: 设计漂亮的信头信笺](./work/matrix/step1/003/003/index.html)
  - [X] [CSS building blocks: 一个炫酷的盒子](./work/matrix/step1/003/004/index.html)
  - [X] [排版社区大学首页](./work/matrix/step1/002/005/index.html)
  - [X] [Fundamental layout comprehension](./work/matrix/step1/003/006/index.html)
4. 学习JS：`2020-3-9`
  - [X] [傻瓜故事产生器](./work/matrix/step1/004/001/index.html)
  - [X] [图库](./work/matrix/step1/004/002/index.html)
  - [X] [为弹跳球展示新增功能](./work/matrix/step1/004/003/index.html)
  - [X] [使用星球大战 API（https://swapi.co/）制作一个搜索 Widget](./work/matrix/step1/004/004/index.html)
     1. 页面上需要有一个文本框 / 搜索框
     2. CSS 库可按需引入，不可引入 JS 库
     3. 当用户在文本框中键入时，读取文本框中用户输入的内容，向 `https://swapi.co/api/people/?search=xxxx` 发送请求，其中 xxxx 需要替换为文本框内容
     4. 使用 Promise / async await 来处理发送请求与读取响应内容的逻辑
     5. 服务器将返回一个 json，具体格式见 `https://swapi.co/api/people`
     6. 在收到服务器响应后，根据响应内容，在文本框下方展示一个自动完成列表（使用 name 来填充）
     7. 为了避免向服务器过度请求，你需要 debounce（防抖）500ms ——也就是在用户键入之后的 500ms 内，如果用户没有再次键入，才发送请求

管理员权限优化
1. [ ] 用户管理
   - [ ] 搜索
   - [x] 分页
   - [x] 批处理（我想先留着，毕竟做了这么久）
     - [x] 选中
     - [ ] 删除
     - [ ] 确认窗口
     - [ ] http 请求
   - [ ] 相关信息（用户总量+周活）
     - [ ] 信息显示
       - [x] 用户总数
       - [ ] 周活
       - [ ] http 请求（周活。。。）
       - [ ] 数据处理（周活。。。）
   - [ ] 编辑用户
     - [x] 单行触发
     - [ ] 编辑界面（存在bug，暂时不想修）
       - [ ] 新增选项（需要权限分层）
       - [ ] 修 bug
   - [ ] 单个用户删除
   - [ ] 筛选
     - [ ] 权限的筛选
2. [ ] 课程管理
   - [ ] 搜索
   - [ ] 批处理
     - [x] 选中
     - [ ] 删除
     - [ ] 确认窗口
     - [ ] http 请求
   - [ ] 编辑
     - [ ] 单行触发
   - [ ] 相关信息（课程总数）
   - [x] 分页
   - [ ] 单个删除
   - [ ] 课程创建
     - [ ] 新页面
     - [ ] 页面跳转
   - [x] 课程修改（好像是已经做好的）
     - [x] 页面跳转
     - [x] 其他页面显示
3. [ ] 题库管理
   - [ ] 创建题库
     - [ ] 按钮
     - [ ] 页面跳转
   - [ ] 搜索
   - [ ] 批处理
     - [ ] 选中
     - [ ] 删除
     - [ ] 确认窗口
     - [ ] http 请求
   - [ ] 相关信息（题库总数）
   - [x] 分页
   - [ ] 单个删除
   - [ ] 编辑
     - [ ] 单行触发
4. [ ] 考试管理
   - [ ] 新页面
   - [ ] 筛选（状态）
   - [ ] 搜索
   - [ ] 相关信息（考试总数）
   - [ ] 分页
5. [x] 定时任务（无）
6. [x] 提交系统
   - [x] 分页
   - [ ] 信息显示
     - [ ] 课程提交总数
     - [ ] 考试提交总数
7. [x] 系统通知
   - [x] 分页
   - [ ] 单个删除
8.  [x] ip 组管理
    - [x] 分页
    - [ ] 单个删除
9.  [ ] 历史记录
    - [ ] 新页面（需要超级管理员权限）
    - [ ] 权限提示（“你已是超级管理员，所有操作将被实名录入数据库，请谨慎操作”）
    - [ ] 历史记录显示
    - [ ] 分页

## 当我无聊的时候我在干什么

- [我的记忆](data/000) 更新至2020.1.20
- [作业](data/homework)


## 笔记

### 信号与系统

- [作业列表](work/信号系统/作业列表)
- [2020.4.25：第一周作业](work/信号系统/第一周作业)

### Web 2.0

- [2019.8.27：第一节课](note/web2.0/2019.8.27)
- [2019.9.3：第二节课](note/web2.0/2019.9.3/note)

### 概统

- [2019.8.26：第一节课](note/概统/2019.8.26)
- [2019.8.28：第二节课](note/概统/2019.8.28)
- [2019.9.2：第三节课](note/概统/2019.9.2)
- [2019.9.4：第四节课](note/概统/2019.9.4/note)

### 数值计算

- [2019.8.26：第一节课](note/数值计算方法/2019.8.26)
- [2019.8.28：第二节课](note/数值计算方法/2019.8.26)
- [2019.9.2：第三节课](note/数值计算方法/2019.9.2/note)
- [2019.9.4：第四节课](note/数值计算方法/2019.9.4/note)

### 数据结构

- [2019.8.28：第一节课](note/数据结构/2019.8.28)
- [2019.8.30：第二节课](note/数据结构/2019.8.30)
- [2019.9.4：第三节课](note/数据结构/2019.9.4)

### C++ 程序设计

1. <a href="note/CPUmanagement">CPU 进程管理</a>
2. <a href="note/Network_and_WWW">网络</a>
3. <a href="note/SEreview">软件工程综述</a>

## 项目

1. <a href="work/svg/readme"> svg 项目</a>

#### Web 2.0

- <a href="work/Web/001/pie.html" target="_blank">第二周</a>

## 数电

1. <a href="DigitalFundamentals/proteus"> Proteus 的安装 </a>

## 志愿相关资料

- <a href="gaokao/2019年">2019年广东ssl报考相关参考</a>
