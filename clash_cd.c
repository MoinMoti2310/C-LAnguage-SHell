#include "headerFile.h"

int clash_cd(char **args)
{
	char str_dir[1024];
	if (args[1] == NULL) {
		args[1] = "~";
	}
	if (args[1][0] == '~') {
		strcpy(str_dir, home_dir);
		strcat(str_dir, args[1]+1);
		if (chdir(str_dir) != 0) {
			perror("clash: error in changing directory");
		}
	} else if (chdir(args[1]) != 0) {
		perror("clash: no directory mentioned for changing");
	}
	return 1;
}