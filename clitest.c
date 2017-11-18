#include <stdio.h>
#include "CLIENTS_H.h"
#include <string.h>
#include <stdlib.h>
#include "listADTgen.h"
#include "stocks.h"
int compareID(void* num1, void* num2){

}
int compareStock(void* s1, void* s2) {

}
int main() {
	FILE* infile = fopen("clients.txt", "r");
	FILE* inStock = fopen("stocks.csv", "r");

	char buffer[200];	
	fscanf(inStock, "%[^\n]",buffer);

	ClientProf temp = createCli(infile);	
	Stock tempStock = createStock(inStock);

	ListType stockList = create(12 + sizeof(char) * 6, compareStock);
	ListType cliList = create(24, compareID);
	
	while (!feof(inStock)) {
		printf("STILL STOCKING\n");	
		push(stockList, tempStock);
		tempStock = createStock(inStock);
	}

	printl(stockList, printStock);
	while (!feof(infile)) {
		printf("STILL READING\n");
		
		push(cliList, temp);
		temp = createCli(infile);
		//toStringCli(temp);
	}
	toStringCli(getEl(cliList, 1));
	printl(cliList, toStringCli);
	fclose(infile);
	return 0;
}
