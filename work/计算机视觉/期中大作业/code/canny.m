%% =============== Part 0: 读取图像 ================
apple = imread('./tree.png');
apple_gray = double(rgb2gray(apple));
figure(1);
subplot(3,3,1);
imshow(uint8(apple_gray));
title('原图')

%% =============== Part 1: 高斯平滑处理 ================
% 生成高斯模版
H = gaussian_filter(5, 0.8);
apple_filter = imfilter(apple_gray, H, 'replicate');
subplot(3,3,2);
imshow(uint8(apple_filter));
title('高斯平滑')

%% =============== Part 2: 索贝尔算子计算梯度值及方向 ================
[grad, grad_direction] = compute_grad(apple_filter);
subplot(3,3,3);
imshow(uint8(grad));
title('sobel')

%% =============== Part 3: 非极大值抑制 ================
canny1 = non_maximum_restrain(grad, grad_direction);
subplot(3,3,4);
imshow(uint8(canny1));
title('非极大值抑制 论文法')
canny2 = non_maximum_restrain_improvement(grad, grad_direction);
subplot(3,3,7);
imshow(uint8(canny2));
title('非极大值抑制 插值法')

%% =============== Part 4: 双阈值检测 ================
canny11 = dual_threshold_detection(canny1, 50, 100);
subplot(3,3,5);
imshow(uint8(canny11));
title('双阈值检测 论文法')
canny22 = dual_threshold_detection(canny2, 50, 100);
subplot(3,3,8);
imshow(uint8(canny22));
title('双阈值检测 插值法');

%% ==================== Part 5: 储存 ============================
imwrite(uint8(apple_filter), "cannyGuassianTree.png");
imwrite(uint8(grad), "cannySobelTree.png");
imwrite(uint8(canny1), "cannySuppressionPaperTree.png");
imwrite(uint8(canny2), "cannySuppressionInterpolationTree.png");
imwrite(uint8(canny11), "cannyThresholdPaperTree.png");
imwrite(uint8(canny22), "cannyThresholdInterpolationTree.png");

%% ================ function ========================
function gaussian_matrix = gaussian_filter(size, sigma)
    gaussian_matrix = zeros(size, size);
    coef = 1 / (2 * 3.14159265 * sigma * sigma);
    total_sum = 0;
    for i = 1:size
        for j = 1:size
            x2 = (j - (size + 1)  / 2)^2;
            y2 = (i - (size + 1)  / 2)^2;
            gaussian_matrix(i, j) = coef * exp(-(x2 + y2) / (2 * sigma * sigma));
            total_sum = total_sum + gaussian_matrix(i, j);
        end
    end
    % 使得矩阵中所有元素和为1
    gaussian_matrix = gaussian_matrix / total_sum;
end

function [grad, grad_direction] = compute_grad(img_filter)
    % 索贝尔算子
    sobel = [-1.0 0.0 1.0;-2.0 0.0 2.0;-1.0 0.0 1.0];

    % 计算图像的sobel水平梯度 
    gradx=conv2(img_filter, sobel, 'same');
%     gradx = imfilter(apple_filter, sobel, 'replicate');

    % 计算图像的sobel垂直梯度 
    grady=conv2(img_filter, sobel', 'same');
%     grady = imfilter(apple_filter, sobel', 'replicate');

    % 得到图像的sobel梯度以及方向, 使用绝对值代替平方开方
    grad=sqrt(gradx.^2+grady.^2);
    grad_direction = atan(grady./gradx);
end

function canny = non_maximum_restrain(grad, grad_direction)
    [m, n] = size(grad_direction);
    sector = zeros(m, n);
    canny = zeros(m, n);
    % 构造
    % 2 1 0
    % 3 x 3
    % 0 1 2
    for i=1:m
        for j=1:n
            angle = grad_direction(i, j);
            if (angle < 3*pi/4) && (angle >= pi/4)
                sector(i, j) = 0;    
            elseif (angle < pi/4) && (angle >= -pi/4)
                sector(i, j) = 3;    
            elseif (angle < -pi/4) && (angle >= -3*pi/4)
                sector(i, j) = 2;    
            else
                sector(i, j) = 1;    
            end    
        end
    end
    % 判断没一点像素的梯度方向，并和该方向上的数值进行比较
    for i=2:m-1
        for j=2:n-1
            if (sector(i, j) == 0) % 45度
                if ((grad(i, j) > grad(i - 1, j + 1) && grad(i, j) > grad(i + 1, j - 1)) || (grad(i, j) > grad(i, j + 1) && grad(i, j) > grad(i, j - 1)) || (grad(i, j) > grad(i - 1, j) && grad(i, j) > grad(i + 1, j)))
                    canny(i,j) = grad(i, j);
                else
                    canny(i, j) = 0;
                end
            end
            if (sector(i, j) == 1) % 90度
                if (grad(i, j) > grad(i - 1, j) && grad(i, j) > grad(i + 1, j))
                    canny(i,j) = grad(i, j);
                else
                    canny(i, j) = 0;
                end
            end
            if (sector(i, j) == 2) % 135度
                if ((grad(i, j) > grad(i - 1, j - 1) && grad(i, j) > grad(i + 1, j + 1))|| (grad(i, j) > grad(i, j + 1) && grad(i, j) > grad(i, j - 1)) || (grad(i, j) > grad(i - 1, j) && grad(i, j) > grad(i + 1, j)))
                    canny(i,j) = grad(i, j);
                else
                    canny(i, j) = 0;
                end
            end
            if (sector(i, j) == 3) % 180度
                if (grad(i, j) > grad(i, j + 1) && grad(i, j) > grad(i, j - 1))
                    canny(i,j) = grad(i, j);
                else
                    canny(i, j) = 0;
                end
            end
        end
    end
end

function canny = non_maximum_restrain_improvement(grad, grad_direction)
    [m, n] = size(grad_direction);
    canny = zeros(m, n);
    for i=2:m-1
        for j=2:n-1
            angle = grad_direction(i, j);
            if (angle > 0 && angle <= pi/4)
                % 通过差值求的亚像素（实际上不存在）
               right_top_pixel = tan(angle) * grad(i-1, j+1);
               right_pixel = (1 - tan(angle)) * grad(i, j+1);
               pixel1 = right_top_pixel + right_pixel;
               left_bottom_pixel = tan(angle) * grad(i+1, j-1);
               left_pixel = (1 - tan(angle)) * grad(i, j-1);
               pixel2 = left_bottom_pixel + left_pixel;
               if (grad(i, j) > pixel1 && grad(i, j) > pixel2)
                   canny(i, j) = grad(i, j);
               else
                   canny(i, j) = 0;
               end
            elseif (angle > pi/4 && angle < pi/2)
                right_top_pixel = 1 / tan(angle) * grad(i-1, j+1);
                top_pixel = (1 - 1 / tan(angle)) * grad(i-1, j);
                pixel1 = right_top_pixel + top_pixel;
                left_bottom_pixel = 1 / tan(angle) * grad(i+1, j-1);
                bottom_pixel = (1 - 1 / tan(angle)) * grad(i+1, j);
                pixel2 = left_bottom_pixel + bottom_pixel;
                if (grad(i, j) > pixel1 && grad(i, j) > pixel2)
                   canny(i, j) = grad(i, j);
                else
                   canny(i, j) = 0;
                end
            elseif (angle > -pi/2 && angle <= -pi/4)
                left_top_pixel = -1/tan(angle) * grad(i-1, j-1);
                top_pixel = (1+1/tan(angle)) * grad(i-1, j);
                pixel1 = left_top_pixel + top_pixel;
                right_bottom_pixel = -1/tan(angle) * grad(i+1, j+1);
                bottom_pixel = (1+1/tan(angle)) * grad(i+1, j);
                pixel2 = right_bottom_pixel + bottom_pixel;
                if (grad(i, j) > pixel1 && grad(i, j) > pixel2)
                   canny(i, j) = grad(i, j);
                else
                   canny(i, j) = 0;
                end
            elseif (angle > -pi/4 && angle <= 0)
                left_top_pixel = -tan(angle) * grad(i-1, j-1);
                left_pixel = (1+tan(angle)) * grad(i, j-1);
                pixel1 = left_top_pixel + left_pixel;
                right_bottom_pixel =  -tan(angle) * grad(i+1, j+1);
                right_pixel = (1+tan(angle)) * grad(i, j+1);
                pixel2 = right_bottom_pixel + right_pixel;
                if (grad(i, j) > pixel1 && grad(i, j) > pixel2)
                   canny(i, j) = grad(i, j);
                else
                   canny(i, j) = 0;
                end
            elseif (angle == pi/2 || angle == -pi/2)
                top_pixel = grad(i-1, j);
                bottom_pixel = grad(i+1, j);
                if (grad(i, j) > top_pixel && grad(i, j) > bottom_pixel)
                   canny(i, j) = grad(i, j);
                else
                   canny(i, j) = 0;
                end
            end    
        end
    end
end

function canny2 = dual_threshold_detection(canny, low_th, high_th)
    [m, n] = size(canny);
    canny2 = zeros(m, n);
    for i=2:m-1
        for j=2:n-1
            if (canny(i, j) < low_th)
                canny2(i,j) = 0;
            elseif (canny(i, j) > high_th)
                canny2(i, j) = canny(i, j);
            else
                neighbor_matrix = [canny(i-1, j-1), canny(i, j-1), canny(i+1, j-1);...
                                   canny(i-1, j), canny(i, j), canny(i+1, j);...
                                   canny(i-1, j+1), canny(i, j+1), canny(i+1, j+1);];
                max_neighbour = max(neighbor_matrix);
                if (max_neighbour > high_th)
                    canny2(i, j) = canny(i, j);
                else
                    canny2(i,j) = 0;
                end
            end
        end
    end
end
