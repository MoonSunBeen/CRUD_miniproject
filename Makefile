delivery : main.c manager.o
	gcc -o delivery main.c manager.o

clear : 
	rm *.o delivery
