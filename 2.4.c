#include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include<sys/wait.h>
# include <unistd.h>
 
void childTask() {
    char name[4][21]={0};
    int iPick;
    printf("Enter the name of 4 child: \n\n");
    for(int x=0; x<4; x++){
    
    printf("Please Enter Name %d: ", x+1);
    scanf("%s", name[x]);
    printf("\n\nWould you like to add another name or view current names stored?\n");
    printf("1)\tAdd another name\n");
    printf("2)\tView names stored\n");
    scanf("%d", &iPick);
    system("clear");
     switch(iPick)
        {
            case 1: break;
            case 2:
            for(x=0;x<4;x++)
            {
                printf("\nName %d is %s\n",x+1, name[x]);
                
            } 
   
        } 
    }
}
 
void parentTask() {
  printf("JOB IS DONE \n");
}
 
int main(void) {
  pid_t pid = fork();
 
  if(pid == 0) {
    childTask();
    exit(EXIT_SUCCESS);
  }
  else if(pid > 0) {
    wait(NULL);
    parentTask();
  }
  else {
    printf("Unable to create child process.");
  }
 
  return EXIT_SUCCESS;
}
