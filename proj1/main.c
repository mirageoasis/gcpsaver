#include "function.h"

// todo 
//	make struct history
//	
// make virtual memory
//
// make hex to dec function
//
// make hash table
// 

cmdEnum CODEalloc(char* cmdString){
	
	cmdEnum ret;

	char* s = (char*)calloc(strlen(cmdString) + 1, sizeof(char));
	for(int i = 0; i < strlen(cmdString); i++){
		s[i] = cmdString[i];
		if(cmdString[i] == '\0' || cmdString[i] == ' '){
			s[i] = 0;
			break;
		}
	}

	//printf("%s\n", s);

	if(!strcmp(cmdString, "q") || !strcmp(cmdString, "quit")) {
		ret = CODE_QUIT;
	}else if(!strcmp(cmdString, "h") || !strcmp(cmdString, "help")){
		ret = CODE_HELP;
	}else if(!strcmp(cmdString, "d") || !strcmp(cmdString, "dir")){
		ret = CODE_DIR;
	}else if(!strcmp(cmdString, "hi") || !strcmp(cmdString, "history")){
		ret = CODE_HISTORY;
	}else if(!strcmp(s, "du") || !strcmp(s, "dump")){
		ret = CODE_DUMP;
	}else if(!strcmp(s, "e") || !strcmp(s, "edit")){
		ret = CODE_EDIT;
	}else if(!strcmp(s, "f") || !strcmp(s, "fill")){
		ret = CODE_FILL;
	}else if(!strcmp(s, "du") || !strcmp(s, "dump")){
		ret = CODE_DUMP;
	}else if(!strcmp(cmdString, "opcode mnemonic")){
		ret = CODE_OPMEN;
	}else if(!strcmp(cmdString, "opcodelist")){
		ret = CODE_OPLIST;
	}else{
		ret = CODE_ERR;
	}
	
	free(s);
	return ret;
}

void quit(historia* head){

	historia* prev = head;
	while(head){
		prev = head;
		head = head -> next;
		free(prev->record);
		free(prev);
	}

}

char* inputTaker(FILE *fp){
	char *str;
	int ch;
	int len = 0;
	int inputSize = 10;
	str = realloc(NULL ,inputSize*sizeof(*str));//first input by placing in the null make every element into null which makes failure safe
	
	if(!str) return str;

	while(((ch = fgetc(fp))) != EOF && ch != '\n'){ //want to use buffer
		str[len++] = ch;//increase letter one by one
		if(len == inputSize){
			str = realloc(str, sizeof(*str)*(inputSize += 16));
			if(!str)return str;
		}
		//printf("%c", ch);
	}
	str[len++] = '\0';

	return realloc(str, sizeof(*str)*len);
}

int main(){
	
	historia* head;
	historia* tail;

	head = (historia*)malloc(sizeof(historia));
	head-> num = 0;
	head-> next = NULL;

	tail = head;
		
	while(1){
		char* commandString;
		cmdEnum cmd = CODE_ERR;
		
		printf("sicsim> ");
		if((commandString = inputTaker(stdin)) == NULL) continue;
		cmd = CODEalloc(commandString); 

		if(cmd != CODE_QUIT &&  cmd != CODE_ERR) historyMaker(head, &tail, commandString);

		//printf("%d\n", cmd);
		//printf("%s\n", inputTaker(stdin));
		//printf("%s\n", commandString);
		switch(cmd){
			case CODE_HELP:
				printHelp();
				break;
			case CODE_DIR :
				printDir();
				break;
			case CODE_QUIT:
				quit(head);
				break;
			case CODE_HISTORY :
				printHistory(head);
				break;
			case CODE_DUMP:
				printf("dump not yet!\n");
				break;
			case CODE_EDIT:
				printf("edit not yet!\n");
				break;
			case CODE_FILL:
				printf("fill not yet!\n");
				break;
			case CODE_RESET:
				printf("reset not yet!\n");
				break;
			case CODE_OPMEN:
				printf("opcode mnemonic not yet!\n");
				break;
			case CODE_OPLIST:
				printf("opcodelist not yet!\n");
				break;
			default :
				printf("choose right command!\n");
				free(commandString);
				break;
		}
		
		if(cmd == CODE_QUIT) break;
	}
	return 0;
}
