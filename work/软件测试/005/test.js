"use strict";

const n1 = 11,
  N1 = 22,
  n2 = 13,
  N2 = 22;

const size = 4;

function main() {
  const n = n1 + n2,
    N = N1 + N2;

  let N_wedge =
    (n1 * Math.log(n1)) / Math.log(2) + (n2 * Math.log(n2)) / Math.log(2);

  let V = (N * Math.log(n)) / Math.log(2);

  let L_wedge = ((2 / n1) * n2) / N2;

  let D = 1 / L_wedge;

  let E = V * D;

  let L_pie = L_wedge ** 2 * V;

  const S = 60 * 60,
    f = 18;
  let T_wedge = E / (S * f);

  let avgSize = N / size;

  let B = V / 3000;

  console.log(`复杂度度量：
不同操作符个数：${n1}
不同操作数个数：${n2}
不同操作数总数：${N1}
不用操作符总数：${N2}

程序词汇长度：${n}
程序长度：${N}
程序预测长度：${N_wedge.toFixed(4)}
程序体积：${V.toFixed(4)}
程序级别：${L_wedge.toFixed(4)}
程度难度：${D.toFixed(4)}
编程工作量：${E.toFixed(4)}
语言级别：${L_pie.toFixed(4)}
编程时间：${T_wedge.toFixed(4)}
平均语句大小：${avgSize.toFixed(4)}
错误预测值：${B.toFixed(4)}
`);
}

main();
