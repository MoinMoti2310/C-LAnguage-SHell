#include "headerFile.h"

char **clash_read_line() {
	char * delim = ";";
	int buf_size = 64;
	char **commands = malloc(buf_size*sizeof(char*));
	char ** commands_backup;
	char * command;
	char * line = NULL;
	size_t len = 0;

	if (!commands) {
		fprintf(stderr, "clash: allocation error\n");
		exit(EXIT_FAILURE);
	}

	if (getline(&line, &len, stdin) == -1) exit(0); // it includes EOF(ctrl+Z) functionality
	int i = 0;
	command = strtok(line, delim);
	while (command != NULL) {
		commands[i++] = command;
		if (i >= buf_size) {
			buf_size += 64;
			commands_backup = commands;
			commands = realloc(commands, buf_size * sizeof(char*));
			if (!commands) {
				free(commands_backup);
				fprintf(stderr, "clash: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		command = strtok(NULL, delim);
	}
	commands[i] = NULL;
	return commands;
}
