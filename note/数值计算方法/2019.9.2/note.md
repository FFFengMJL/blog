# 2019.9.2

> 课前回顾
>
> - 霍纳算法
> - 有效位数
> - Big Oh（复杂度）

## 有效位数

$\hat{p}$ 被称作**近似**（***approximate***）  
$$
\frac{|p - \hat{p}}{|p|} < \frac{10^{1 - d}}{2}
\text{其中 $d$ 是 $\hat{p}$ the largest nonnegative integer }
$$

## Big Oh $O(h^n)$ Order of Approximation

> 纯粹的数学，并不实际；实际的数学，并不实际。 --爱因斯坦

1. 定义

$$
\frac{|f(h) - p(h)|}{|h^n|} \leq M
\text{for sufficiently small $h$}
$$

$p(h)$ approxiamtes $f(h)$: $f(h) = p(h) + \bf{O}(h^n)$

2. 相关运算

假设 $f(h) = p(h) + \bf{O}(h^n)$ 、 $g(h) = q(h) + \bf{O}(h^m)$ $r = \text{min} {m, n}$，那么

$$
f(h) + g(h) = p(h) + q(h) + \bf{O}(h^r) \\
f(h)g(h) = p(h))q(h) + \bf{O}(h^r) \\
\frac{f(h)}{g(h)} = \frac{p(h)}{q(h)} + \bf{O} (h^r)
$$

> $C$ 代表 *Continous* 例如，$C^{n+1}[a, b]$

3. 泰勒展开

![泰勒定理](./images/taylor.jpg)
