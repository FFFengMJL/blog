# coding=utf-8
import cv2
import numpy as np

img = cv2.imread("./Lenna.jpg", 0)

for i in range(0, 5):
    _img = cv2.GaussianBlur(img, (2 * i * i + 1, 2 * i * i + 1), 0)
    _canny = cv2.Canny(_img, 50, 150)
    cv2.imwrite('./cannyLena%d.png' % (i), _canny)


# img = cv2.GaussianBlur(img, (3, 3), 0)
canny = cv2.Canny(img, 50, 150)  # 最大最小阈值
cv2.imwrite('cannyLena.png', canny)
cv2.imshow('Canny', canny)
cv2.waitKey(0)
cv2.destroyAllWindows()
