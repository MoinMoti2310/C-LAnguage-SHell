#include "headerFile.h"

int clash_piping_handler(char ** args){
	// File descriptors
	int odd_pipe[2]; // pos. 0 output, pos. 1 input of the pipe
	int even_pipe[2];
	
	int num_cmds = 0;
	
	char *command[256];
    char ** new_command;
	
	pid_t pid;
	
	int err = -1;
	int end = 0;
	
	// Variables used for the different loops
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	
	// First we calculate the number of commands (they are separated
	// by '|')
	while (args[l]){
		if (!strcmp(args[l],"|")) num_cmds++;
		l++;
	}
	num_cmds++;
	
	// Main loop of this method. For each command between '|', the
	// pipes will be configured and standard input and/or output will
	// be replaced. Then it will be executed
    if (num_cmds > 1) {
        while (args[j] != NULL && end != 1){
            k = 0;
            // We use an auxiliary array of pointers to store the command
            // that will be executed on each iteration
            while (strcmp(args[j],"|")){
                command[k] = args[j];
                j++;	
                if (args[j] == NULL){
                    // 'end' variable used to keep the program from entering
                    // again in the loop when no more arguments are found
                    end = 1;
                    k++;
                    break;
                }
                k++;
            }

            command[k] = NULL;
            j++;		

            if (pipe((i % 2) ? odd_pipe : even_pipe) == -1) perror("clash: Error in piping");
            
            pid=fork();
            
            if(pid==-1){			
                if (i != num_cmds - 1){
                    close((i % 2) ? odd_pipe[1] : even_pipe[1]);
                }			
                printf("Child process could not be created\n");
                return 0;
            }
            if(pid==0){

                if (i == 0) dup2(even_pipe[1], STDOUT_FILENO);
                else if (i == num_cmds - 1) dup2((num_cmds % 2) ? odd_pipe[0] : even_pipe[0], STDIN_FILENO);
                else{ // for odd i
                    if (i % 2 != 0){
                        dup2(even_pipe[0],STDIN_FILENO); 
                        dup2(odd_pipe[1],STDOUT_FILENO);
                    }else{ // for even i
                        dup2(odd_pipe[0],STDIN_FILENO); 
                        dup2(even_pipe[1],STDOUT_FILENO);					
                    } 
                }
                
                new_command = clash_redirection(command);
                if (execvp(new_command[0],new_command)==err){
                    kill(getpid(),SIGTERM);
                }		
            }
                    
            // CLOSING DESCRIPTORS ON PARENT
            if (i == 0) close(even_pipe[1]);
            else if (i == num_cmds - 1) close((num_cmds % 2) ? odd_pipe[0] : even_pipe[0]);
            else{
                if (i % 2 != 0){					
                    close(even_pipe[0]);
                    close(odd_pipe[1]);
                }else{					
                    close(odd_pipe[0]);
                    close(even_pipe[1]);
                }
            }
                    
            waitpid(pid,NULL,0);
                    
            i++;	
        }
        return 1;
    }
    return 0;
}