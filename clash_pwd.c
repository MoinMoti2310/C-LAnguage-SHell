#include "headerFile.h"

int clash_pwd() {
	char curr_dir[1024];
	if (!getcwd(curr_dir,1024)) {
		perror("null returned");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", curr_dir);
	return 1;
}