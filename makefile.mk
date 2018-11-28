a.out:	3des_client.o 3des.o
		gcc 3des_client.o 3des.o -lm -lrt
3des_client.o: 3des_client.c 3des.h
		gcc -c 3des_client.c 3des.h
3des.o: 3des.c 3des.h
		gcc -c 3des.c 3des.h
