#include "data.h"


cmdEnum CODEalloc(char* cmdString);



char* inputTaker(FILE *fp);

void historyMaker(historia* head, historia ** tail, char* commandString);
void printDir();
void printHelp();
void printHistory(historia* head);
void quit(historia* head);
