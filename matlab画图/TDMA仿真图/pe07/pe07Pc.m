clear
close all
clc
load '1.mat'
y1=Pc(1:1,1:40);
load '2.mat'
y2=Pc(2:2,1:40);

x=1:1:40;
plot(x,y1,'-o',x,y2,'-*');


xlabel('ʱ϶��Ŀ��M��');
ylabel('ƽ����ͻ����');
legend('λ����Ϣ������·����','�������');

grid on
