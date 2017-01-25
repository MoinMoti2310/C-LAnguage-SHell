#include "headerFile.h"

void clash_ctrlz() {
    jobs[++next] = (job*)malloc(sizeof(job));
    strcpy(jobs[next] -> name, process_name);
    jobs[next] -> pid = curr_pid;
    kill(curr_pid, 20);
    kill(curr_pid, 18);
}