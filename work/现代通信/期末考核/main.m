% 主函数
function main()
    Ps = [1, 10, 1e2, 1e3, 1e4]; % 横坐标
    avarageRate = [0, 0, 0, 0, 0]; % 纵坐标，平均速率
    H_nums = 100; % 100个独立的矩阵

    for P_index = 1:5
        P = Ps(P_index);

        for H_index = 1:H_nums
            [~, ~, A, ~] = generateMatrix(); % 生成矩阵
            A_ = sum(A); % 得到对角线的元素
            A__ = sort(A_); % 进行排序

            maxR = 0; % 最大速率

            % 分情况讨论并计算 B
            for index = 1:4
                [lambda, B_] = getLambda(A_, P, index);

                % 如果 lambda 值有效，那么计算速率并更新最大值
                if (lambda ~= -1)
                    R = caculateRate(A__, B_);
                    maxR = max(R, maxR); % 更新最大值
                end

            end

            avarageRate(P_index) = avarageRate(P_index) + maxR; % 累加求平均值
        end

    end

    avarageRate = avarageRate / 100;

    avarageRate

    % 画图

    semilogx(Ps, avarageRate, '-*b');
    axis([0, 1e4, 0, 55]);
    set(gca, 'XTick', Ps);
    set(gca, 'YTick', [0:10:55]);
    xlabel('P')
    ylabel('R')

end

% 生成矩阵
function [H, U, A, V] = generateMatrix()
    H = randn(4, 4); % 以标准正态分布生成 4*4 的矩阵
    [U, A, V] = svd(H); % 进行 SVD 分解
end

% 获取不同情况下的 lambda 和对应的 B
function [lambda, B_] = getLambda(A_, P, index)
    % 分情况进行讨论，index 与 lambda <= a_index 对应

    A__ = sort(A_); % 进行排序，方便讨论情况

    switch index
        case 4 % a3 < lambda <= a4
            lambda = 1 / (P + 1 / (A__(4)^2));

            if ~(A_(3) < lambda && lambda <= A_(4))
                lambda = -1;
            end

        case 3 % a2 < lambda <= a3
            lambda = 2 / (P + 1 / (A__(4)^2) + 1 / (A__(3)^2));

            if ~(A_(2) < lambda && lambda <= A_(3))
                lambda = -1;
            end

        case 2 % a1 < lambda <= a2
            lambda = 3 / (P + 1 / (A__(4)^2) + 1 / (A__(3)^2) + 1 / (A__(2)^2));

            if ~(A_(1) < lambda && lambda <= A_(2))
                lambda = -1;
            end

        case 1 % lambda <= a1
            lambda = 4 / (P + 1 / (A__(4)^2) + 1 / (A__(3)^2) + 1 / (A__(2)^2) + 1 / (A__(1)^2));

            if ~(lambda <= A_(1))
                lambda = -1;
            end

        otherwise % 其他情况
            lambda = -1;
    end

    B_ = [0 0 0 0]; % 基础的 B

    % 如果 lambda 有效，那么计算对应的 b_i
    if ~(lambda == -1)

        for index = 1:4
            B_(index) = max(1 / lambda - 1 / (A__(index)^2), 0);
        end

    end

end

% 计算信息速率
function R = caculateRate(A_, B_)
    AB_ = (A_.^2) .* B_ + 1;
    R = sum(log2(AB_));
end
