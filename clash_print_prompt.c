#include "headerFile.h"

void clash_print_prompt() {
    char host_name[1024];
	char str_dir[1024];
    gethostname(host_name, 1024);
    char curr_dir[1024] = "~";
    getcwd(str_dir, 1024);
    if (strncmp(str_dir, home_dir, strlen(home_dir)) == 0) {
        if (strcmp(str_dir, home_dir) != 0) strcat(curr_dir, str_dir+strlen(home_dir));
    } else {
        strcpy(curr_dir, str_dir);
    }
    printf("%s@%s:%s>",getlogin(),host_name,curr_dir);
}
