#include "headerFile.h"

int clash_sendsig(char ** args) {
    if (args[1] == NULL) {
        fprintf(stderr, "No pid mentioned\n");
        exit(EXIT_FAILURE);
    } else {
        int i = atoi(args[1]);
        int signal = atoi(args[2]);
        if (jobs[i]->pid != -1) {
            if(kill(jobs[i]->pid, signal)) perror("clash: Unable to kill the process");
            else jobs[i]->pid = -1;
        } else {
            perror("Invalid job id");
        }
    }
    
    return 1;
}