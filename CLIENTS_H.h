#ifndef CLIENTS_H
#define CLIENTS_H

typedef struct client_prof *ClientProf;

ClientProf createCli( FILE* );
void destroyCli(ClientProf cProf);
char* getID(ClientProf cProf);
char* getName(ClientProf cProf);
char* getPhone(ClientProf cProf);
char* getEmail(ClientProf cProf);
void setID(ClientProf cProf, char* id);
void setName(ClientProf cProf, char* newName);
void setPhone(ClientProf cProf, char* newPhone);
void setEmail(ClientProf cProf, char* newEmail);
char* toStringCli(void* cProf);
#endif

