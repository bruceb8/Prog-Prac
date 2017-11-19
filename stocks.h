#ifndef STOCKS_H
#define STOCKS_H


typedef struct stock_tag *Stock;

Stock createStock(FILE* filePtr);
void displayStocks(Stock stocks[], int sCount);
void printStock(void *theStock);
char* getStockSymbol(Stock);
double getStockPrice(Stock);
void setStockSymbol(Stock stock, char[]);
void setStockPrice(Stock stock, double);
void destroyStock(Stock *theStockArray);
void clearValues(Stock theStock);

#endif

