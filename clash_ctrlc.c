#include "headerFile.h"

void clash_ctrlc() {
    signal(SIGINT, clash_ctrlc);
    printf("\n");
    clash_print_prompt();
    fflush(stdout);
}
