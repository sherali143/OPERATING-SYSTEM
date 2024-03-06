#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_EXPRESSION_LENGTH 100

int main() {
    int parent_to_child[2];
    int child_to_parent[2];

    if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
     
        close(parent_to_child[0]);
        close(child_to_parent[1]);

        char expression[] = "2+3";
        printf("Parent sending expression to child: %s\n", expression);
        write(parent_to_child[1], expression, sizeof(expression));

   
        char result[MAX_EXPRESSION_LENGTH];
        read(child_to_parent[0], result, sizeof(result));
        printf("Parent received result from child: %s\n", result);

        close(parent_to_child[1]);
        close(child_to_parent[0]);

        wait(NULL);
    } 

    else {
      
        close(parent_to_child[1]);
        close(child_to_parent[0]);

 
        char expression[MAX_EXPRESSION_LENGTH];
        read(parent_to_child[0], expression, sizeof(expression));
        printf("Child received expression from parent: %s\n", expression);

        int result;
        sscanf(expression, "%d", &result);

        char result_str[MAX_EXPRESSION_LENGTH];
        snprintf(result_str, sizeof(result_str), "%d", result+3);
        write(child_to_parent[1], result_str, sizeof(result_str));

     
        close(parent_to_child[0]);
        close(child_to_parent[1]);

    
        exit(EXIT_SUCCESS);
    }

    return 0;
}
