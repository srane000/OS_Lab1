#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

int fd;
char buffer[1001];

if(argc < 2) {
printf("\n No file given \n");
return 1;
}

if(argc > 2){
printf("\n Must use one input file \n");
return 1;
}

fd = open(argv[1], O_RDONLY);


if(fd == -1){
printf("\n Error opening file \n");
perror("Error Opening");
return 1; 
}
    
read(fd, buffer, sizeof(buffer));




if(fd < 0){
printf("\n File could not be read \n");
perror("Error Reading");
return 1; 
}

close(fd);

fd = open(argv[1], O_WRONLY);

write(fd, "Hello World", 11);

if(fd > 2){
printf("\n File has been rewritten \n");
}

printf("\n %s \n", buffer);
close(fd);



if (fd<0){
printf("\n File could not be closed");
perror("Error Closing");
return 1;
}

return 0;
}
