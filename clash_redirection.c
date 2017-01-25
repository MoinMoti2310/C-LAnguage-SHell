#include "headerFile.h"

char ** clash_redirection(char ** args) {
    int input_file, output_file, append_file, type = -1;
    int input_flag = 0, output_flag = 0, append_flag = 0;
    char input_stream[1024], output_stream[1024], append_stream[1024];
    for (size_t i = 0; args[i] != NULL; i++) {
        if (!strcmp(args[i], "<")) type = 0;
        else if (!strcmp(args[i], ">")) type = 1;
        else if (!strcmp(args[i], ">>")) type = 2;
        switch (type) {
            case 0:
                input_flag = 1;
                strcpy(input_stream, args[i+1]);
                args[i] = NULL;
                break;
            case 1:
                output_flag = 1;
                strcpy(output_stream, args[i+1]);
                args[i] = NULL;
                break;
            case 2:
                append_flag = 1;
                strcpy(append_stream, args[i+1]);
                args[i] = NULL;
                break;
            default:;
        }
        type = -1;
    }
    if (input_flag) {
        if ((input_file = open(input_stream, O_RDONLY, 0)) < 0) perror("clash: Unable to open the input file");
        if (dup2(input_file, 0) < 0) perror("clash: Redirection failure");
        close(input_file);
    }
    if (output_flag) {
        if ((output_file = creat(output_stream, 0644)) < 0) perror("clash: Unable to create the output file");
        if ((dup2(output_file, STDOUT_FILENO)) < 0) perror("clash: Redirection failure");
        close(output_file);
    }
    if (append_flag) {
        if ((append_file = open(append_stream, O_WRONLY | O_APPEND)) < 0) perror("clash: Unable to open the file");
        if ((dup2(append_file, STDOUT_FILENO)) < 0) perror("clash: Redirection Failure");
        close(append_file);
    }
    return args;
}