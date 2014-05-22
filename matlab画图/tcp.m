clear
close all
clc

x = 10:10:50;
y1 = [19160 36869 50063 62717 99788];
y2 = [861730 1716591 2435127 3384203 4108862];

semilogy(x,y1,'-o',x,y2,'-*');
xlabel('测试文件大小（M）');
ylabel('耗费时间（ms）');
title('TCP发包时间');
legend('仅读文件','发送数据');



grid on


