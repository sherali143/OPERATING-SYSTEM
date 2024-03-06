#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {

        int n;
        printf("Enter a positive integer: ");
        scanf("%d", &n);

        if (n < 0) {
            printf("Please enter a positive integer.\n");
            exit(EXIT_FAILURE);
        }

        int partial_result = factorial(n);

        printf("Child process with process id %d and calculated factorial(%d) = %d\n", getpid(), n, partial_result);
    } else {
      
        wait(NULL);

        printf("Parent process with PID %d waited for the child.\n", getpid());
    }

    return 0;
}

// Sir I made a factorial calculator, but can't figure out using files to share the result between parent and child processes. I have Tried ChatGPT's suggestion, but it's confusing. The code works for factorials, So that why i am submitting only this code"

