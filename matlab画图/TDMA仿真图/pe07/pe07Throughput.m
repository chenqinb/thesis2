clear
close all
clc



load '(N = 50,M = 1,1,50,p = 0.7,GN = 200000).mat'
y1=Throughput(1:1,1:40);
load '2.mat'
y2=Throughput(2:2,1:40);
x=1:1:40;
plot(x,y1,'-o',x,y2,'-*');

xlabel('ʱ϶��Ŀ��M��');
ylabel('��������Mbps��');
legend('λ����Ϣ������·����','�������');

grid on
