# 2019.9.3

[老师的网站](http://http://my.ss.sysu.edu.cn/wiki/display/WEB)

> 科学、技术、工程、管理  
>
> 科学是客观的  
> 技术服务于人，依赖客观世界的存在，技术背后有科学的存在

## Web Server & Browser

Web Server (Software):

- Apache
- IIS

Browser:

- IE
- FireFoxx
- Chrome

## Domain Name System (DNS)

A set of servers that map written names to IP address

- 域名 => IP
- using Windows command **nslookup**
- IDN ccTLD Fast Track

Many system mantain a local cache, *host file*

- Windows
- Mac
- Linux

> - DNS 劫持：可以修改 host file解决
> - 人为组织域名解析

[//]: # (就你个Windows用的反斜杠)

## Uniform Resource Locator (URL) 统一资源定位符

protocal + host + path

在浏览器输入URL后：

1. 浏览器向DNS服务器发送请求获得IP地址
2. 与IP建立连接
3. 获取相应的信息

[//]: # (4.没听到)

> 可以使用`锚点`进行**页面内定位**

## HyperText Transport Portocol (HTTP)

- GET
- POST
- PUT
- DELETE
- HEAD
- OPTIONS

error code:

|number|meaning|
|:-:|:-:|
|200|ok|

## Web1.0 Vs Web2.0

- Web1.0 is about **publishing**
- Web2.0 is about **interaction**
  - allows users to interact with other users or to change website content
  - Information sharing, interoperability, user-centered design and collaboration
  - hosted services, web applications, social-networking sites, video-sharing sites, wikis, blog
  - And so on

## HyperText Markup Language (HTML)

- 1993: submittted ti the **IETF**
- 1995: HTML 2
- 1996-1997: HTML 3.2
- 1997: HTML 4
- 1999: HTML 4.01
- 2001: HTML, HTML based on XML
- 2014: HTML5

特点：

- describes the **content** and **structure** of information on a Web page
- surround text context with with opening and closing **tags**
- 每个 tag 的名字叫 **element** 元素
- 空白没有意义

HTML coding convention: HTML 的结构是一棵**树**

- indent nested elements
- separate ...

### 段落

代码

```html
<!-- My web page, by Tim Student SS 12345, Spring 2048 -->
<p>SS courses are <!-- NOT --> a lot of fun!</p>
```

输出：

<!-- My web page, by Tim Student SS 12345, Spring 2048 -->
<p>SS courses are <!-- NOT --> a lot of fun!</p>

```html
<!DOCTYPE html>
<html>
    <head>
        Information about the page
        <meta name="description" content="introduction of SYSU" /><!-- 元信息，描述网页信息 -->
        <meta http-equiv="Content-Type" content="text/html;charset=gbk" /><!-- 目前常用 utf-8 -->
        <title>
            This is title
        </title>
    </head>
    <body></body>
</html>
```

字符集：字符编码有很多种，当`储存`和`读取`的时候使用了两种编码方式，就会出现**乱码**  
常见的字符编码：变长与定长

- 定长
  - ASCII
  - iso-8859-1/latin-1
  - GB2312
- 定长
  - Unicode (本质上是一种编码方案，用于映射)
  - UCS

block 与 inline：

- block 必定占一行
- inline 能占多少占多少

### 换行 \<br /\>

代码

```html
<p>a <br /> b <br /> c <br /> d</p>
```

输出

<p>a <br /> b <br /> c <br /> d</p>

### 标题 \<h num\>

代码：

```html
<h1>Sun Yat-Sen University</h1>
<h2>Sun Yat-Sen University</h1>
<h3>Sun Yat-Sen University</h1>
<h4>Sun Yat-Sen University</h1>
```

输出：

<h1>Sun Yat-Sen University</h1>
<h2>Sun Yat-Sen University</h2>
<h3>Sun Yat-Sen University</h3>
<h4>Sun Yat-Sen University</h4>

> 标题描述语义上的结构，样式可用过 CSS 调整

### 链接 \<a\>

代码

```html
<p>
    <a href="http://fffengmjl.github.io/blog" target="_blank">我的主页</a>
</p>
```

输出

<p>
    <a href="http://fffengmjl.github.io/blog" target="_blank">我的主页</a>
</p>

### 图片 \<img\>

### 增强表达元素 \<em\> \<strong\>

em **Vs** i, strong **Vs** b: 前者表达语义，后者表达形状，因此选用第一种

## Basic CSS

作用：引入**外观**与**布局**

### 引入CSS

1. 内嵌（不推荐）
2. link 引入外部工程文件

### font

font-family

- 可以使用多种字体
- 最后一个选项一般是一类字体
  - serif
  - sans-serif
  - monospace
  - cursive

font-size

- px
- pt

## 继续HTML

### \<meta\>

### 表格 \<table\>, \<tr\>, \<td\>, \<th\>, \<caption\>

### 引用 \<blockqoute\>, \<q\> (在行内)

### 字符实体

```html
&lt; &gt;
&amp;<!-- and so on -->
```

### \<code\>

### \<pre\>

## More CSS

选择符`,`

### 文本

text-align:

- justify
- center
- left
- right

text-decoration:

- overline
- line-through
- underline

list: have many styles
