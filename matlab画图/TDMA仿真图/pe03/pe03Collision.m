clear
close all
clc
load 'N = 50,M = 1,1,25,p = 0.3,GN = 80000.mat'
x=m(1:20);
y1=Pc(1:1,1:20);
y2=Pc(2:2,1:20);
plot(x,y1,'-o',x,y2,'-*');


xlabel('时隙数目（M）');
ylabel('平均冲突概率');
legend('位置信息辅助多路访问','随机访问');

grid on
