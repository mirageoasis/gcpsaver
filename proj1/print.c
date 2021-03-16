#include "function.h"

char* helpList[10] = {"h[elp]", "d[ir]", "q[uit]", "hi[story]", "du[mp] [start, end]", "e[dit] address, value", "f[ill] start, end, value", "reset", "opcode mnemonic", "opcodelist"};

void printDir(){
	DIR *pdir = opendir(".");
	if(!pdir) {
		printf("error!\n");
		closedir(pdir);
		return;
	}
//	printf("debug sucess\n");
	//for(int i =0; i < 5; i++) readdir(pdir);

//	printf("sasagaeo!\n");

	while(1){
	 	struct dirent *temp;
		char* dirFile; // used to store directory + file
		struct stat buf;
		int status;

		if((temp = readdir(pdir)) == NULL) break;
		//printf("%s\n", temp->d_name);	
	
		lstat(temp->d_name, &buf);
		if(temp->d_name[0] == '.') {
			printf("%s\n", temp->d_name);	
		}else if(buf.st_mode == 16893){// directory
			printf("%s", temp->d_name);
			printf("/\n");
		}else{ // file
			printf("%s", temp->d_name);
			printf("*\n");
		}
		
		//printf("%d\n", buf.st_mode);
	
	}	
	closedir(pdir);
}

void printHelp(){
	for(int i = 0; i < 10; i++) printf("%s\n", helpList[i]);
}
