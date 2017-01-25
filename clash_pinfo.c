#include "headerFile.h"

int clash_pinfo(char ** args) {
    pid_t curr_process;
    char s_pid[1024];
    if (args[1]) {
        printf("pid : %s\n",args[1]);
        strcpy(s_pid,args[1]);
    } else {
        curr_process = getpid();
        printf("pid : %d\n",curr_process);
        sprintf(s_pid,"%d",curr_process);
    }
    char name[1024] = "ps -o comm= ";
    char status[1024] = "ps -o stat= ";
    char memory[1024] = "ps -o vsz= ";
    char exe_path[1024] = "/proc/";
    char buffer[1024];
    strcat(name, s_pid);
    strcat(memory, s_pid);
    strcat(status, s_pid);
    strcat(exe_path, s_pid);
    strcat(exe_path, "/exe");
    char ** tokens;
    tokens = clash_split_line(name);
    printf("Name : ");
    fflush(stdout);
    clash_execute(tokens);
    tokens = clash_split_line(memory);
    printf("Memory : ");
    fflush(stdout);
    clash_execute(tokens);
    tokens = clash_split_line(status);
    printf("status : ");
    fflush(stdout);
    clash_execute(tokens);
    readlink(exe_path, buffer, sizeof(buffer));
    printf("Executable Path : %s\n",buffer);
    return 1;
}