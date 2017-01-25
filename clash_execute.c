#include "headerFile.h"

int clash_execute(char **args) {
	strcpy(process_name, args[0]);

	if (strcmp(args[0], "cd") == 0) return clash_cd(args);
	if (strcmp(args[0], "pwd") == 0) return clash_pwd();
//	if (strcmp(args[0], "echo") == 0) return clash_echo(args);
	if (strcmp(args[0], "pinfo") == 0) return clash_pinfo(args);		 			 
	if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) return clash_exit();
	if (strcmp(args[0], "listjobs") == 0) return clash_listjobs(next);
	if (strcmp(args[0], "killallbg") == 0) return clash_killallbg(next);
	if (strcmp(args[0], "sendsig") == 0) return clash_sendsig(args);
	if (strcmp(args[0], "fg") == 0) return clash_fg(args, next);
	pid_t pid;
	int status;
	int args_len = 0;

	while(args[args_len]) args_len++;
	//printf("%d\n", args_len);
	pid = fork();
	curr_pid = pid;
	if (args[0][strlen(args[0])-1] == '&') {
		//printf("background process detected\n");
//		signal(SIGCHLD,clash_signal);
		if (pid == 0) {
			args[0][strlen(args[0])-1] = '\0';
			// Child process
			if (execvp(args[0], args) == -1) {
				perror("clash");
			}
			exit(EXIT_FAILURE);
		} else if (pid < 0) {
			// Error forking
			perror("clash");
		} else {
			signal(SIGCHLD, clash_signal);
			jobs[++next] = (job*)malloc(sizeof(job));
			strcpy(jobs[next] -> name, args[0]);
			jobs[next] -> pid = pid;
			next2 = next;
		}
	} else if (strcmp(args[args_len-1],"&") == 0) {
		// background process detected
		signal(SIGCHLD, clash_signal);
		if (pid == 0) {
			args[args_len-1] = NULL;
			// Child process
			if (execvp(args[0], args) == -1) {
				perror("clash");
			}
			exit(EXIT_FAILURE);
		} else if (pid < 0) {
			// Error forking
			perror("clash");
		} else {
			signal(SIGCHLD, clash_signal);			
			jobs[++next] = (job*)malloc(sizeof(job));
			strcpy(jobs[next] -> name, args[0]);
			jobs[next] -> pid = pid;
			next2 = next;
		}
	} else {
		if (pid < 0) perror("clash"); // Error in forking
		else if (pid == 0) {
			// Child process
			args = clash_redirection(args);
			if (execvp(args[0], args) == -1) {
				perror("clash");
			}
			exit(EXIT_FAILURE);
		} else {
			// Parent process
			waitpid(pid, &status, WCONTINUED);
		}
	}

	return 1;
}
