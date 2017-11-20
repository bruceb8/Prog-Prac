#include <stdio.h>
#include "CLIENTS_H.h"
#include <string.h>
#include <stdlib.h>
#include "listADTgen.h"
#include "stocks.h"
int compareID(void* num1, void* num2){
	return strcmp(getID(num1), getID(num2));
	
}
int compareStock(void* s1, void* s2) {
	return strcmp(getStockSymbol(s1), getStockSymbol(s2));
}
int main() {
	FILE* infile = fopen("clients.txt", "r");
	FILE* inStock = fopen("stocks.csv", "r");
	FILE* stCli = fopen("stock_client.txt", "r");
	FILE* out = fopen("summary.csv", "w");
	char buffer[400];	
	fscanf(inStock, " %[^\n]",buffer);

	ClientProf temp = createCli(infile);	
	Stock tempStock = createStock(inStock);

	ListType stockList = create(16, compareStock);
	ListType cliList = create(24, compareID);
	
	while (!feof(inStock)) {
		
		push(stockList, tempStock);
		tempStock = createStock(inStock);
	}
	
	//printl(stockList, printStock);
	while (!feof(infile)) {
		
		
		push(cliList, temp);
		temp = createCli(infile);
		//toStringCli(temp);
	}
	
	char cliID[10];
	int stockNum;
	char stockSym[20];
	int stockAmount;
	fscanf(stCli, "%s %d \n ", cliID, &stockNum);
	//printf("%s %d", cliID, stockNum);
	int i = 0;	
	int searchRes = -1;
	int cliSize = size_is(cliList);
	int stockSize = size_is(stockList);
	while(!feof(stCli)) {
		searchRes = -1;
		for(i = 0; i < cliSize; i++) {
			if(strcmp(cliID, getID(getEl(cliList, i))) == 0) {
				searchRes = 1;
				char* strBuffer = toStringCli(getEl(cliList, i));
				fprintf(out, "%s",strBuffer);
				free(strBuffer);
			}
		}
		double totalPrice = 0;
		for(i = 0; i < stockNum; i++) {
			fscanf(stCli, "%s %d", stockSym, &stockAmount);
			fprintf(out, "%s,%d", stockSym, stockAmount);
			int j = 0;
			
			for(j = 0; j < stockSize && searchRes > 0; j++) {
		
				//printf("%s", getStockSymbol(getEl(stockList, j)));
				if(strcmp(stockSym, getStockSymbol(getEl(stockList, j))) == 0) {
					double temp = getStockPrice(getEl(stockList, j));
					totalPrice = totalPrice + temp * stockAmount;
					fprintf(out, ",%.2lf,\n,", temp);
				}
				
			}
			
		}
	fprintf(out, "%.2lf,,,\n", totalPrice);
	
	fscanf(stCli, "%s %d \n ", cliID, &stockNum);
	}

	



	
	for(i = 0; i <cliSize; i++) {
		destroyCli(getEl(cliList, i));
	}
	
	
	for(i = 0; i < stockSize; i++) {
		clearValues(getEl(stockList, i));
	}
	
	destroy(cliList);
	destroy(stockList);
	fclose(infile);
	fclose(inStock);
	fclose(stCli);
	fclose(out);
	return 0;
}




















