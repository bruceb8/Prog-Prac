#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLIENTS_H.h"

struct client_prof {
	char* id;
	char* name;
	char* phone;
	char* email;
	int nameSize;
	int emailSize;
};
ClientProf createCli(FILE* ptrF) {
	//use getchar or something to snag letters until a new line
	//then store it in the appropriate field.  Do this 4 times.
	ClientProf cProf = malloc(sizeof(struct client_prof));
	char* tempStr = calloc(100, sizeof(char));
	cProf->id = calloc(100, sizeof(char));
	cProf->name= calloc(100, sizeof(char));
	//char* tempName = calloc(100,sizeof(char));
	cProf->phone = calloc(100, sizeof(char));
	cProf->email = calloc(100, sizeof(char));	
//char* tempEmail = calloc(100, sizeof(char));
	fgets(tempStr,100,ptrF);
	if(cProf != NULL && cProf->id != NULL && cProf->name != NULL && cProf->phone != NULL && cProf->email !=NULL && !feof(ptrF)) {
		strcpy(cProf->id,tempStr );
		int temp = strlen(cProf->id) - 2;
		
		cProf->id[temp] = '\0'; 

		strcpy(cProf->name, fgets(tempStr,100,ptrF));
		temp = strlen(cProf->name) - 2;
		
		cProf->name[temp] = '\0'; 

		strcpy(cProf->phone, fgets(tempStr,100,ptrF));
		temp = strlen(cProf->phone) - 2;
		
		cProf->phone[temp] = '\0';
 
		strcpy(cProf->email, fgets(tempStr,100,ptrF));
		temp = strlen(cProf->email) - 2;
		
		cProf->email[temp] = '\0'; 
	
	}
	free(tempStr);
	return cProf;
}

void destroyCli(ClientProf cProf){
	free(cProf->id);
	free(cProf->name);
	free(cProf->phone);
	free(cProf->email);
	//free(cProf);
}

char* getID(ClientProf cProf) {
	char* temp = calloc(100, sizeof(char));
	strcpy(temp, cProf->id);
	return temp;
}

char* getName(ClientProf cProf) {
	char* temp = calloc(strlen(cProf->name) + 1, sizeof(char));
	strcpy(temp, cProf->name);
	return temp;
}

char* getPhone(ClientProf cProf) {
	char* temp = calloc(20 , sizeof(char));
	strcpy(temp, cProf->phone);
	return temp;
}

char* getEmail(ClientProf cProf) {
	char* temp = calloc(strlen(cProf->email)  + 1, sizeof(char));
	strcpy(temp, cProf->email);
	return temp;
}
void setID(ClientProf cProf, char* newID){
	strcpy(cProf->id, newID);
}

void setName(ClientProf cProf, char* newName){
	strcpy(cProf->name, newName);
}
void setPhone(ClientProf cProf, char* newPhone){
	strcpy(cProf->phone, newPhone);
}
void setEmail(ClientProf cProf, char* newEmail){
	strcpy(cProf->email, newEmail);
}

char* toStringCli (void* cProf) {
	
	char* tempID = getID(cProf);
	char* tempName = getName(cProf);
	char* tempPhone = getPhone(cProf);
	char* tempEmail = getEmail(cProf);
	char* buffer = calloc(400, sizeof(char));
    sprintf(buffer, "%s,%s,,%s,%s\n,", tempID, tempName, tempPhone, tempEmail);
	free(tempID);
	free(tempName);
	free(tempPhone);
	free(tempEmail);
	return buffer;
}	












