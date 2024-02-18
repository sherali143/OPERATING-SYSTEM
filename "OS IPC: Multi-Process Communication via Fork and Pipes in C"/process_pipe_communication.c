`#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe_p1_p2[2], pipe_p2_p3[2], pipe_p3_p4[2];

    if (pipe(pipe_p1_p2) == -1 || pipe(pipe_p2_p3) == -1 || pipe(pipe_p3_p4) == -1) {
        perror("Pipe creation failed");
        return 1;
    }
    
    
    //process 1
    if (fork() == 0)
    {   
        close(pipe_p1_p2[0]);
        close(pipe_p2_p3[0]);
        close(pipe_p2_p3[1]);
        close(pipe_p3_p4[0]);
        close(pipe_p3_p4[1]);

        char filename[50];
        printf(" PLease Enter the File name : ");
        scanf("%s",filename);

        write(pipe_p1_p2[1], filename, sizeof(filename));

        close(pipe_p1_p2[1]);
        exit(0);
    }

    //process 2
    if (fork() == 0)
    {
        close(pipe_p1_p2[1]);
        close(pipe_p2_p3[0]);
        close(pipe_p3_p4[0]);
        close(pipe_p3_p4[1]);
  
        char buffer_p1[50];
        char filename[50];

        strcpy(buffer_p1 , filename);
        read(pipe_p1_p2[0], buffer_p1, sizeof(buffer_p1));
        strcat(buffer_p1, " transcoded ");

        printf("Content of buffer_p1 is: %s\n", buffer_p1);

        close(pipe_p1_p2[0]);

        write(pipe_p2_p3[1], buffer_p1, sizeof(buffer_p1));

        close(pipe_p2_p3[1]);
        exit(0);
    }

    //process3
    if (fork() == 0) 
    {
     
        close(pipe_p1_p2[0]);
        close(pipe_p1_p2[1]);
        close(pipe_p2_p3[1]);
        close(pipe_p3_p4[0]);
      
        char buffer_p2[50];
        char buffer_p1[50];

        strcpy(buffer_p2, buffer_p1);
        read(pipe_p2_p3[0], buffer_p2, sizeof(buffer_p2));
        strcat(buffer_p2, " QC_Passed ");

        printf("Content of buffer_p2 is: %s\n", buffer_p2);
        close(pipe_p2_p3[0]);

        write(pipe_p3_p4[1], buffer_p2, sizeof(buffer_p2));
         
        close(pipe_p3_p4[1]);
        exit(0);
    }

    //process4
    if (fork() == 0)
    {
        
        close(pipe_p1_p2[0]);
        close(pipe_p1_p2[1]);
        close(pipe_p2_p3[0]);
        close(pipe_p2_p3[1]);
        close(pipe_p3_p4[1]);

        char buffer_p3[50];
        char buffer_p2[50];

        strcpy(buffer_p3, buffer_p2);
        read(pipe_p3_p4[0], buffer_p3, sizeof(buffer_p3));
        close(pipe_p3_p4[0]);

        printf("PROCESS 4 RECIEVED: %s\n", buffer_p3);

        close(pipe_p3_p4[0]);
        exit(0);
    }

   
    for (int i = 0; i < 4; ++i) 
    {
        wait(NULL);
    }

    return 0;
}
