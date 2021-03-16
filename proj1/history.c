#include "function.h"

void historyMaker(historia* head, historia ** tail, char* commandString){

	historia *new = (historia*)malloc(sizeof(historia));

	new -> num = ((*tail) -> num) + 1;
	new -> record = commandString;
	new -> next = NULL;

	(*tail)-> next = new;
	
	*tail = new;
}

void printHistory(historia* head){
	head = head -> next;

	while(head){
		printf("		%d		%s\n", head -> num, head -> record);
		head = head -> next;
	}
}

