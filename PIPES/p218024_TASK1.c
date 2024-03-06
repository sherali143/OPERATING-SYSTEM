#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    pid_t child_pid;
    char qualifications[100];

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) 

    {
        close(pipe_fd[0]); 

        printf("Enter your educational qualifications: ");
        fgets(qualifications, sizeof(qualifications), stdin);

        write(pipe_fd[1], qualifications, sizeof(qualifications));

        close(pipe_fd[1]);
        exit(EXIT_SUCCESS);
    } 

    else 

    {
        close(pipe_fd[1]); 

        read(pipe_fd[0], qualifications, sizeof(qualifications));

     
        printf("Stored Educational Qualifications: %s", qualifications);

        close(pipe_fd[0]); 
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    return 0;
}

