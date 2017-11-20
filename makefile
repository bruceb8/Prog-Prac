pr4: main.o client_profile.o listADTgen.o stocks.o
	gcc -o pr4 main.o client_profile.o listADTgen.o stocks.o
main.o: main.c CLIENTS_H.h listADTgen.h stocks.h
	gcc -c main.c
client_profile.o: client_profile.c CLIENTS_H.h
	gcc -c client_profile.c
listADTgen.o: listADTgen.c listADTgen.h
	gcc -c listADTgen.c
stocks.o: stocks.c stocks.h
	gcc -c stocks.c

