/*
 Author: fieca191
 A simple c script for running the tar commands for compression / decompression
 because I keep forgetting the options and would always have to refer to my
 cheat sheet / notes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


#define CMD_NAME 100
#define DIR_LEN 1000


/*
 Prints the help dialouge
*/
void help(){   
    printf("\nusage: ctar -[cxh] [filename]\n");
    printf("however, you can only use one argument,");
    printf("because doing them at once would be dumb\n\n");
    printf("During excecution you will be asked if the file\n");
    printf("is in another directory, if it ");
    printf("is somehwere else then the working directory is \n");
    printf("changed temporarily using chdir\n\n");

    printf("-c\t|\t");
    printf("takes in a name for a tarball to be made ");
    printf("then makes it\n");
    printf("-x\t|\t");
    printf("decompresses a given tarball\n");

    printf("-h\t|\t");
    printf("opens this help dialogue\n\n");
}

int main(int argc, char *argv[]){

    char filename[CMD_NAME];
    char tarcmd[CMD_NAME];
    char op[2];
    char dir[DIR_LEN];
    
    int count = 0;

    if(argc < 2){
      printf("No argument supplied\n");
      printf("For help, use -h\n");
      return EXIT_SUCCESS;
    }else{
        
      strcpy(op, argv[1]);
      if(strcmp(op, "-h") == 0){

	   help();
       return EXIT_SUCCESS;
      }
      
      //ask the user to enter the directory where the files are
      
      printf("Please enter directory where the file(s) to compress ");
      printf("or tarball(s) to decompress are\n");
      scanf("%s", dir);
      
     

      chdir(dir);//change the working directory for the rest of excecution
      if(errno != 0){//check for errors
          perror("Error: ");
          return EXIT_FAILURE;
      }

      //continue with excecution of script
      if(strcmp(op, "-c") == 0){

	printf("Compression\n");

	printf("enter tarball name:\n");
	scanf("%s", filename);

	strcpy(tarcmd, "tar -zcvf ");
	strcat(tarcmd, filename);
	strcat(tarcmd, ".tar.gz .");

	system(tarcmd);
    
      }else if(strcmp(op, "-x") == 0){

	printf("Decompression\n");

	printf("Name of tarball to de-compress:\n");
	scanf("%s", filename);
	strcpy(tarcmd, "tar -zxvf ");
	strcat(tarcmd, filename);
	strcat(tarcmd, ".tar.gz");

	system(tarcmd);
      
      }

    
    }

    return EXIT_SUCCESS;
}
