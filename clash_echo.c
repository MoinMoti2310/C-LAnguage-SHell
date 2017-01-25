#include "headerFile.h"

int clash_echo(char **args) {
	int i = 0;
	printf("%s", args[++i]);
	while(args[++i]) {
		printf(" %s", args[i]);
	}
	printf("\n");
	return 1;
}