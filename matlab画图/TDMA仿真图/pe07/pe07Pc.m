clear
close all
clc
load '1.mat'
y1=Pc(1:1,1:40);
load '2.mat'
y2=Pc(2:2,1:40);

x=1:1:40;
plot(x,y1,'-o',x,y2,'-*');


xlabel('时隙数目（M）');
ylabel('平均冲突概率');
legend('位置信息辅助多路访问','随机访问');

grid on
