/*
 This is a test script for the chdir command for use in lazy-mans-lar
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define DIR_LEN 1000

int main(int argc, char *argv[]){

    char dir[DIR_LEN];
    
    printf("Please enter directory path: \n");
    scanf("%s", dir);

    printf("Is this your directory path? %s\n", dir);


    chdir(dir);
    
    if(errno != 0){
        printf("error number: %i\n", errno);
        perror("Error printed by perror");
    }
    return EXIT_SUCCESS;
}
