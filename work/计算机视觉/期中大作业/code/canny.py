# coding=utf-8
import cv2
import numpy as np

img = cv2.imread("./Lenna.jpg", 0)

img0 = cv2.GaussianBlur(img, (3, 3), 0)
# canny0 = cv2.Canny(img0, 50, 150)
# cv2.imwrite('./cannyLena.png', canny0)

canny = cv2.Canny(img, 50, 200)  # 最大最小阈值

cv2.imshow('Canny', canny)
cv2.waitKey(0)
cv2.destroyAllWindows()
