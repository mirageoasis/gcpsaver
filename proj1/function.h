#include "data.h"

cmdEnum CODEalloc(char* cmdString);
void printDir();
void printHelp();
void quit(historia* head);
void historyMaker(historia* head, historia ** tail, char* commandString);
void printHistory(historia* head);
char* inputTaker(FILE *fp);
