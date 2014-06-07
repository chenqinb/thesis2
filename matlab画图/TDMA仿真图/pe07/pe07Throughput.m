clear
close all
clc



load '(N = 50,M = 1,1,50,p = 0.7,GN = 200000).mat'
y1=Throughput(1:1,1:40);
load '2.mat'
y2=Throughput(2:2,1:40);
x=1:1:40;
plot(x,y1,'-o',x,y2,'-*');

xlabel('时隙数目（M）');
ylabel('吞吐量（Mbps）');
legend('位置信息辅助多路访问','随机访问');

grid on
