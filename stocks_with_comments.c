#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stocks.h"

//Definition of Stock object.

struct stock_tag {
    char symbol[6];
    double price;
};

//Function printStock() prints the Stock object's symbol and price.
//
//PRE: Function takes void type object() and prints its attributes.
//
//POST: none

void printStock(void* theStock) {
	//double* price = (getStockPrice(theStock));

    printf("%s, %lf", getStockSymbol(theStock), getStockPrice(theStock));
}

//Function getStockSymbol() is passed a Stock object and returns its Symbol
//
//PRE: Function takes a Stock object
//
//POST: Returns the Stock object's symbol.

char* getStockSymbol(Stock theStock) {
    
    return theStock->symbol;
}

//Function getStockPrice() takes a Stock object in and returns its price attribute. 
//
//PRE: Function takes Stock object.
//
//POST: Function returns price attribute.

double getStockPrice(Stock theStock) {
	
    return theStock->price;
}

//Function setStockSymbol() takes a Stock object and a char array as parameters and replaces
//the Stock object's symbol attribute.
//
//PRE: Function takes a Stock object and a char array as parameters
//
//POST: Function changes the Stock objects symbol attribute to the entered char array parameter.

void setStockSymbol(Stock theStock, char theNewString[]) {
    strcpy(theStock->symbol, theNewString);
}

//Function setStockPrice() takes a Stock object and a double as parameters and replaces
//the Stock object's price attribute.
//
//PRE: Function takes a Stock object and a double (representing a dollar amount) as parameters.
//
//POST: Function changes the Stock objects price attribute to the entered entered dollar amount.

void setStockPrice(Stock theStock, double theNewPrice) {
    theStock->price = theNewPrice;
}

//Function clearValues() takes in a Stock object and clears the Symbol and price.
//
//PRE: Function takes in a Stock object.
//
//POST: Fuction clears the Stock object's symbol and price attributes.

void clearValues(Stock theStock) {
    strcpy(theStock->symbol, "");
    theStock->price = 0.0;
	//free(theStock);
	//theStock = NULL;
}
//Function createStock() generates a new Stock object from information provided by the input file.
//
//PRE: Function takes in a pointer to a file.
//
//POST: Function produces a Stock object with data taken from the inpt file.

Stock createStock(FILE* theFilePointer) {
    Stock stockPointer = malloc(sizeof(struct stock_tag));
    if (stockPointer != NULL) {
        fscanf(theFilePointer, " %[^ ,] ,%lf", stockPointer->symbol, &stockPointer->price);
		//stockPointer->symbol[strlen(stockPointer->symbol)] = '\0';
    }
	
    return stockPointer;
}

