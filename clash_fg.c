#include "headerFile.h"

int clash_fg(char ** args, int size) {
    int status;
    int job_id = atoi(args[1]);
    if (args[1] == NULL) perror("No pid mentioned\n");
    else if(job_id > size || jobs[job_id]->pid == -1) perror("Invalid Job Id");
    else {
        if(kill(jobs[job_id]->pid, SIGCONT)) perror("clash: Unable to bring the process in foreground");
        waitpid(jobs[job_id]->pid, &status, WCONTINUED);
    }
    return 1;
}