#include "headerFile.h"

int clash_killallbg(int size) {
    for (int i = 1; i <= size; i++) {
        if (jobs[i]->pid != -1) {
            if (kill(jobs[i]->pid, 9)) perror("clash: unable to kill the process");
        }
    }
    return 1;
}