#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

typedef enum cmdList{
	CODE_ERR = -1,
	CODE_HELP,
	CODE_DIR,
	CODE_QUIT,
	CODE_HISTORY,
	CODE_DUMP,
	CODE_EDIT,
	CODE_FILL,
	CODE_RESET,
	CODE_OPMEN,
	CODE_OPLIST
}cmdEnum; // command status

typedef struct historia{
	int num;
	char *record; // where command is saved!
	struct historia* next;
}historia;
