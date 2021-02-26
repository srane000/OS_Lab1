#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int readfd;
    int writefd;
    int count = 0;
    char buffer[1];
    char xyz[3] = {'X', 'Y', 'Z'};



if(argc < 3) {
   printf("\n Not enough inputs given \n");
   return 1; 
}

if(argc > 3) {
   printf("\n More than 2 inputs are not accepted \n");
   return 1; 
}



readfd = open(argv[1], O_RDONLY);
if(readfd == -1){
    printf("\n File has failed \n");
    perror("Error Opening");
    return 1; 
}

     

writefd = open(argv[2], O_WRONLY);
if(writefd == -1){
    printf("\n File could not be opened \n");
    perror("Error Opening");
return 1; 
}


while(read(readfd, buffer, 1)){

count+=1;


if(readfd == -1){
     printf("\n File could not be read \n");
     perror("Error Reading");
     return 1; 
}

//Setting the conditions to change 5 into A
if(buffer[0] == '5') {
buffer[0] = 'A';
}


write(writefd, buffer, 1);
if(writefd == -1){
     printf("\n File could not be written to \n");
     perror("Error Writing");
     return 1; 
}



if(count == 50){
     write(writefd, xyz, 3);
     
if(writefd == -1){
   printf("\n File could not be written to \n");
   perror("Error Writing");
   return 1; 
  }
  //counter is reset every 50 counts
  count = 0;
  }
}
    


close(writefd);
close(readfd);


if(writefd == -1){
    printf("\n File could not be closed \n");
    perror("Error Closing");
    return 1; 
}

if(readfd == -1){
     printf("\n File could not be closed \n");
     perror("Error Closing");
     return 1; 
}

return 0;
}
