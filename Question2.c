#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int fd_read;
    int fd_write;

   

    if(argc < 3) {
        printf("\n Not enough inputs given (2 inputs required) \n");
        return 1; 
    }
    if(argc > 3) {
        printf("\n Too many inputs (2 inputs required \n");
        return 1; 
    }


    char* buffer = malloc(10*sizeof(char));

   

    fd_read = open(argv[1], O_RDONLY);
    if(fd_read == -1){
        printf("\n File did not open \n");
        perror("Error Opening");
        return 1; 
    }

	//read the file source.txt which is stored in the buffer and can be written to destination.txt
    read(fd_read, buffer, 1315);
    if(fd_read == -1){
        printf("\n Reading file failed \n");
        perror("Error Reading");
        return 1; 
    }


    close(fd_read);
    if(fd_read == -1){
        printf("\n File could not be closed \n");
        perror("Error Closing");
        return 1; 
    }

	// now opening destination file
    fd_write = open(argv[2], O_WRONLY);
    if(fd_write == -1){
        printf("\n File did not open \n");
        perror("open");
        return 1; 
    }

    
    write(fd_write, buffer, 1314);
    if(fd_write == -1){
        printf("\n Writing file failed \n");
        perror("Error Writing");
        return 1; 
    }

    

    close(fd_write);
    if(fd_write == -1){
        printf("\n File could not be closed \n");
        perror("Error closing");
        return 1; 
    }
 //file contents should be transfered over
return 0;
}
