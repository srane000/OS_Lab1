#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int fd;
    
//argc take arguments from command line. If more than one argument, return an error
if(argc > 2) { 
  printf("\n Too many arguments supplied \n");
  return 1; 
}


//argv is a pointer to the argument passed in the program
if(argc == 1) {
    fd = open("destination.txt", O_RDONLY | O_CREAT );
}else{
    fd = open(argv[1],  O_RDONLY| O_CREAT );
}

printf("fd = % d\n", fd);


//if file descriptor is less than 0 or in this case -1, the file was not opened
if(fd < 0){
  printf("\n File could not be opened \n");
  perror("Error");
  return 1; 
}

else {
  printf("\n File is created and opened successfully \n");
}

// Closes file and output error message otherwise

close(fd);

if (fd<0){
   printf("\n Error closing file \n");
   perror("close");
   return 1;
}
else
   printf("\n File closed Successfully \n");


return 0;
}
