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
void rtrim(char*  cmdString){//from right
	
	int end = strlen(cmdString) - 1;
	
	while(isspace(cmdString[end])){
		end--;
	}

	end++;
	printf("no!");	
	realloc(cmdString, end);
	cmdString[end] = '\0';
}

void ltrim(char* cmdString){//from left
	
	char* temp = (char*)malloc(sizeof(char) * strlen(cmdString));
	strcpy(temp, cmdString);

}


cmdEnum CODEalloc(char* cmdString){
	
	cmdEnum ret;
	int count = 0;

	char* saver[3] ={NULL, };
	char* s = (char*)calloc(strlen(cmdString) + 1, sizeof(char));
	strcpy(s, cmdString);	

	char* ptr = strtok(s, " \t");
	
	while(ptr != NULL){//일단 space 기준으로만 check
		saver[count++] = ptr;
		printf("%s\n", ptr);
		ptr = strtok(NULL, " \t");
		if(count == 2) break;
	}
//	printf("strtok pass!\n");

//	for(int i=0; i < count; i++) printf("%s\n", saver[i]);

//	for(int i = 0; i < strlen(cmdString); i++){
//		s[i] = cmdString[i];
//		if(cmdString[i] == '\0' || cmdString[i] == ' '){
//			s[i] = 0;
//			break;
//		}
//	}//strtok change! not this way! 
	// for function like q h d hi if there are any string other than itself print the result wrong!

	//printf("%s\n", s);

	if((!strcmp(saver[0], "q") || !strcmp(saver[0], "quit")) && saver[1] == NULL) {
		ret = CODE_QUIT;
	}else if((!strcmp(saver[0], "h") || !strcmp(saver[0], "help")) && saver[1] == NULL){
		ret = CODE_HELP;
	}else if((!strcmp(saver[0], "d") || !strcmp(saver[0], "dir")) && saver[1] == NULL){
		ret = CODE_DIR;
	}else if((!strcmp(saver[0], "hi") || !strcmp(saver[0], "history")) && saver[1] == NULL){
		ret = CODE_HISTORY;
	}else if(!strcmp(saver[0], "du") || !strcmp(saver[9], "dump")){
		ret = CODE_DUMP;
	}else if(!strcmp(saver[0], "e") || !strcmp(saver[0], "edit")){
		ret = CODE_EDIT;
	}else if(!strcmp(saver[0], "f") || !strcmp(saver[0], "fill")){
		ret = CODE_FILL;
	}else if(!strcmp(saver[0], "opcode") && !strcmp(saver[1], "mnemonic") && saver[2] == NULL){
		ret = CODE_OPMEN;
	}else if(!strcmp(saver[0], "opcodelist") && saver[1] == NULL){
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
		//printf("code alloc is fine!\n");

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
				dump();
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
