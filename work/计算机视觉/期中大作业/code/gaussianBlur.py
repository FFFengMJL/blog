#coding=utf-8
import cv2
import numpy as np  
 
img = cv2.imread("./eye.png", 0)
 
gaussian = cv2.GaussianBlur(img,(9,9),0) #用高斯平滑处理原图像降噪。

cv2.imshow('origin', img)
cv2.imshow('Gaussian', gaussian)
cv2.imwrite('./origin.png', gaussian)
cv2.waitKey(0)
cv2.destroyAllWindows()