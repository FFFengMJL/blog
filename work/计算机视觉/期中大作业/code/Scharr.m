clear all; 
close all;
imag = imread('./Lenna.jpg');  %读取关键帧
imag = rgb2gray(imag);        %转化为灰度图
subplot(231);imshow(imag);title("原图"); 
[high,width] = size(imag);   % 获得图像的高度和宽度
F2 = double(imag);        
U = double(imag);       
uSobel = imag;
uSobelX = imag;
uSobelY = imag;
for i = 2:high - 1   %sobel边缘检测
    for j = 2:width - 1
        Gx = (3*U(i+1,j-1) + 10*U(i+1,j) + 3*F2(i+1,j+1)) - (3*U(i-1,j-1) + 10*U(i-1,j) + 3*F2(i-1,j+1));
        Gy = (3*U(i-1,j+1) + 10*U(i,j+1) + 3*F2(i+1,j+1)) - (3*U(i-1,j-1) + 10*U(i,j-1) + 3*F2(i+1,j-1));
        uSobelX(i, j) = Gx;
        uSobelY(i, j) = Gy;
        uSobel(i,j) = sqrt(Gx^2 + Gy^2); 
    end
end 
subplot(232);imshow(im2uint8(uSobelX));title('边缘检测后X');  %画出边缘检测后的图像
subplot(233);imshow(im2uint8(uSobelY));title('边缘检测后Y');  %画出边缘检测后的图像
subplot(234);imshow(im2uint8(uSobel));title('边缘检测后');  %画出边缘检测后的图像
imwrite(im2uint8(uSobel), 'lenaScharr.png');
imwrite(im2uint8(uSobelX), 'lenaScharrX.png');
imwrite(im2uint8(uSobelY), 'lenaScharrY.png');
% Matlab自带函数边缘检测
% K为获取得到的关键帧的灰度图
BW3 = edge(imag,'sobel');
subplot(235);imshow(BW3,[]);title('Matlab自带函数边缘检测');