FileName	= file10M
ResultName	= Result10M
DeviceName	= wlan0
all:
	gcc  main.c -o speedtest -lpcap -Wall
clean:
	-rm speedtest
run:
	sudo ./speedtest $(DeviceName) $(FileName)
run1:
	-rm $(ResultName)
	for((i= 1;i< 65536;i++))
	do
		sudo ./speedtest $(DeviceName) $(FileName) >> $(ResultName)
	done
