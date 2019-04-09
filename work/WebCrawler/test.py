#!/usr/bin/python
# -*- coding: UTF-8 -*-
import requests
import urllib
from bs4 import BeautifulSoup
url = "http://sdcs.sysu.edu.cn/news/notice"
html_doc = requests.get(url)

html_doc = urllib2.Request(url)
#模拟Mozilla浏览器进行爬虫
html_docs.add_header("user-agent","Mozilla/5.0")
html_doc = urllib2.urlopen(request)
# print(html_doc)

#创建一个BeautifulSoup解析对象
soup = BeautifulSoup(html_doc.text,"html.parser")
print(html_doc.text)
#获取所有的链接
links = soup.find_all('a')
print("\n所有的链接")
for link in links:
    print(link.name,link['href'],link.get_text())