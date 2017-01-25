#include "headerFile.h"

void clash_signal() {
    pid_t pid;
    int i = 0;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    if (pid <= 0) {
        perror("clash");
    } else {
        while (jobs[++i] -> pid != pid);
        jobs[i] -> pid = -1;
        if (WIFEXITED(status))
            printf("\nChild exited normally with exit status %d\n", WEXITSTATUS(status));
        if (WIFSIGNALED(status))
            printf("\nChild exited on signal %d %s\n", WTERMSIG(status), strsignal((WTERMSIG(status))));
       // if (WIFEXITED(status) || WIFSIGNALED(status)) fprintf(stderr,"\nProcess with pid %d exited normally\n", pid);
    }
}