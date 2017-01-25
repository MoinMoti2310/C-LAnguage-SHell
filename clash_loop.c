#include "headerFile.h"

void clash_loop(void) {
	char **lines;
	char **args;
	int status;
	do {
		clash_print_prompt();
		int i = 0;
		lines = clash_read_line();
		do {
			args = clash_split_line(lines[i++]);
			status = clash_piping_handler(args);
			if (!status) status = (args[0]) ? clash_execute(args) : 1;
			free(args);
		} while (lines[i] && status);
		free(lines);
	} while (status);
}
