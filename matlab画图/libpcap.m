clear
close all
clc

x = 10:10:50;
y1 = [17160 34320 47480 68640 85800];
y2 = [8538.7 17077.4 24616.1 34154.8 42693.5];

semilogy(x,y1,'-o',x,y2,'-*');
xlabel('�����ļ���С��M��');
ylabel('�ķ�ʱ�䣨ms��');
title('libpcap����ʱ��');
legend('�����ļ�','��������');



grid on


