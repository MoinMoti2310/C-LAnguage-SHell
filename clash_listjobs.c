#include "headerFile.h"

int clash_listjobs(int size) {
    int flag = 0;
    for (int i = 1; i <= size; i++) {
        if (jobs[i]->pid != -1) {
            printf("[%d] %s [%d]\n", i, jobs[i]->name, jobs[i]->pid);
            flag = 1;
        }
    }
    if (flag == 0) printf("No jobs to show\n");
    return 1;
}