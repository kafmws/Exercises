三、
1.
拟合直线 $y=bx+a$，令题中 $n_i$ 为  $x_i$ ， $x_i$ 为  $y_i$ ，
$$ a=\frac{\sum_{i=1}^n x_i \sum_{i=1}^n x_i y_i - \sum_{i=1}^n y_i \sum_{i=1}^n {x_i}^2}{(\sum_{i=1}^n x_i)^2 - n\sum_{i=1}^n {x_i}^2} $$
$$ b=\frac{\sum_{i=1}^n x_i \sum_{i=1}^n y_i - n\sum_{i=1}^n x_i y_i}{(\sum_{i=1}^n x_i)^2 - n\sum_{i=1}^n {x_i}^2} $$
由题，
$\sum_{i=1}^5 x_i = 10 + 20 + 30 + 40 + 50 = 150$，
$\sum_{i=1}^5 y_i = 0.1 + 0.2 + 0.3 + 0.4 + 0.5 = 1.5$，
$\sum_{i=1}^5 x_i y_i= 10*0.1 + 20* 0.2 + 30*0.3 + 40*0.4 + 50*0.5 = 1.5$，
$(\sum_{i=1}^n x_i)^2=150*150=22500$，$\sum_{i=1}^5 {x_i}^2 = 10^2 + 20^2 + 30^2 + 40^2 + 50^2 = 5500$
所以，$a = \frac{150*55-1.5*5500}{22500-5*5500} = 0$，$b = \frac{150*1.5 - 5*55}{22500-5*5500} = 0.01$
即有拟合直线为 $y = 0.01x$，即 $x_i = 0.01 n_i$，
$\Delta x_i = 0.1$，$ \Delta n_i = 10 $，灵敏度为 $\frac{\Delta x_i}{\Delta n_i} = 0.01$
拟合精度 $\sigma = \sqrt{\frac{\sum_{i=1}^n {v_i}^2}{n-m}}$，其中 $m$ 为未知数个数，$n$ 为测量列长度，即$m = 2, n = 5$
$v_i  = y_i - \frac{\Delta x_i}{\Delta n_i}x_i$，有$\sum_{i=1}^n {v_i}^2 = 0$，即 $\sigma = 0$.

2.
绝对误差 = 测量值 - 实际值 = 40.05 - 40 = 0.05A
相对误差 = (测量值 - 实际值)/实际值 * 100% = (40.05 - 40)/40 * 100% = 0.125%
引用误差 = 绝对误差/满量程值 * 100% = 0.05/100 * 100% = 0.05%
即仪表精度等级为0.05级。

3.
$\bar{x} = \frac{1}{10} \sum^{10}_{i=1}x_i = 90.194$，$\delta_s = \sqrt{\frac{\sum_{i=1}^n {v_i}^2}{n-1}} = 0.03565$
则数据应在 $\bar{x} \pm 3\delta_s$ 之间，即(90.08705, 91.2635)，故无粗大误差。
$\delta = \frac{\delta_s}{\sqrt{n}} = \frac{0.03565}{\sqrt{10}} = 0.01127$，故测量结果为 $90.194 \pm 3\times0.01127 cm$，$(P_a = 0.9973) $

四、
(1)传感器类型：应变片传感器
(2)示意图略。
(3)工作原理说明：当给弹性版施加力时，4个应变片的阻值同时发生变化，4个应变片作为电桥的四个桥臂且相邻位置的变化相反，即与差动全桥电路对应。系统输出$U_0 = E \frac{\Delta R}{R}$，通过测量 $U_0$ 的大小反映电阻变化，从而度量应变片的受力程度及加速度的大小。
(4)系统特点：①该电路无非线性误差。②温度变化时，四个应变片电阻同时变化，即无温度误差。③灵敏度为$E$，能够明显地反映加速度及其变化。