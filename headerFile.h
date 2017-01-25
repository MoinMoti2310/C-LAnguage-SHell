#ifndef headerFile
#define headerFile

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <signal.h>
char home_dir[1024];
typedef struct job {
	char name[64];
	pid_t pid;
}job;
job * jobs[1024];
int next2;
int next;
char process_name[64];
pid_t curr_pid;
void clash_loop(void);
void clash_print_prompt();
int clash_cd(char **args);
int clash_killallbg(int size);
int clash_sendsig(char ** args);
int clash_listjobs(int size);
int clash_fg(char** args, int size);
int clash_exit();
int clash_pwd();
int clash_pinfo(char ** args);
int clash_echo(char **args);
int clash_execute(char **args);
void clash_signal();
void clash_ctrlz();
void clash_ctrlc();
char ** clash_read_line();
char ** clash_split_line(char * line);
int clash_piping_handler(char ** args);
char ** clash_redirection(char ** args);


#endif