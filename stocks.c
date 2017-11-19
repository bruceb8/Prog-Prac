#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stocks.h"


struct stock_tag {
    char symbol[6];
    double price;
};


void displayStocks(Stock theStocks[], int theCount) {
	int i;

    for (i = 0; i < theCount; i++) {
        printStock(theStocks[i]);
        printf("\n");
    }
}
void printStock(void* theStock) {
	//double* price = (getStockPrice(theStock));

    printf("%s, %lf", getStockSymbol(theStock), getStockPrice(theStock));
}

char* getStockSymbol(Stock theStock) {
    
    return theStock->symbol;
}

double getStockPrice(Stock theStock) {
	double thePrice = theStock->price;
    return thePrice;
}
void setStockSymbol(Stock theStock, char theNewString[]) {
    strcpy(theStock->symbol, theNewString);
}
void setStockPrice(Stock theStock, double theNewPrice) {
    theStock->price = theNewPrice;
}
void destroyStock(Stock *theStockArray) {
    int i;    
    for (i = 0; i < sizeof(theStockArray); i++) {
        clearValues(theStockArray[i]);
    }
}
void clearValues(Stock theStock) {
    strcpy(theStock->symbol, "");
    theStock->price = 0.0;
	//free(theStock);
	//theStock = NULL;
}
Stock createStock(FILE* theFilePointer) {
    Stock stockPointer;
    stockPointer = (Stock)malloc(sizeof(double) + 10);
    if (stockPointer != NULL) {
        fscanf(theFilePointer, " %[^ ,] ,%lf", stockPointer->symbol, &stockPointer->price);
		stockPointer->symbol[strlen(stockPointer->symbol)] = '\0';
    }
	
    return stockPointer;
}



