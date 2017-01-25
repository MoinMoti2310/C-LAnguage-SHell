#include "headerFile.h"

char **clash_split_line(char *line) {	
	int buf_size = 64;
	
	int bufsize = buf_size;
	char **tokens = malloc(bufsize * sizeof(char*));
	
	if (!tokens) {
		fprintf(stderr, "clash: allocation error\n");
		exit(EXIT_FAILURE);
	}

	char *token, **tokens_backup;
	char * delim = " \t\r\n\a";
	token = strtok(line, delim);
	int position = 0;
	while (token != NULL) {
		
		if (position >= bufsize) {
			bufsize += buf_size;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				free(tokens_backup);
				fprintf(stderr, "clash: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		tokens[position++] = token;

		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return tokens;
}
