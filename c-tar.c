#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_NAME 100

void printReminder(){
  
    printf("This assumes you have already cd'ed into the directory with\n");
    printf(" files to compress. If you have not, ctrl-c now and do that.\n");
    printf("\n");
}

int main(int argc, char *argv[]){

    char filename[CMD_NAME];
    char tarcmd[CMD_NAME];
    char op[2];
    int count = 0;

    strcpy(op, argv[1]);

    if(argc < 2){
      printf("No argument supplied\n");
      printf("For help, use -h\n");
      return EXIT_SUCCESS;
    }else{

      

      if(strcmp(op, "-c") == 0){

	printReminder();
	printf("Compression\n");

	printf("enter tarball name:\n");
	scanf("%s", filename);

	strcpy(tarcmd, "tar -zcvf ");
	strcat(tarcmd, filename);
	strcat(tarcmd, ".tar.gz .");

	system(tarcmd);
    
      }else if(strcmp(op, "-x") == 0){

	printReminder();
	printf("Decompression\n");

	printf("Name of tarball to de-compress:\n");
	scanf("%s", filename);
	strcpy(tarcmd, "tar -zxvf ");
	strcat(tarcmd, filename);
	strcat(tarcmd, ".tar.gz");

	system(tarcmd);
      
      }else if(strcmp(op, "-h") == 0){

	printf("\n");
	printf("Only operates in the current directory, for now\n");
      
	printf("usage: ctar\t-[cxh]\n");
	printf("however, you can only use one argument,");
	printf("because doing them at once would be dumb\n");
	printf("\n");
      
	printf("-c\t|\t");
	printf("takes in a name for a tarball to be made");
	printf(" then makes it\n");

	printf("-x\t|\t");
	printf("decompresses a given tarball\n");

	printf("-h\t|\t");
	printf("opens this help dialogue\n");

	printf("\n");
      }

    
    }

    return EXIT_SUCCESS;
}
