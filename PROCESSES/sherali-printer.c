
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2)
   {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) 
    {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) 
    {
        execlp("cat", "cat", argv[1], NULL);
        perror("Error in exec");
        exit(EXIT_FAILURE);
    }

     else 
    {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) 
     {
            execlp("more", "more", argv[1], NULL);
            perror("Error in exec");
            exit(EXIT_FAILURE);
      } 
    else 
    {
            fprintf(stderr, "Child process did not terminate successfully\n");
            exit(EXIT_FAILURE);
     }

    }

    return 0;
}

