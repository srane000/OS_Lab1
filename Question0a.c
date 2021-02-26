#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main (int argc, char* argv[])
{  
char* filepath = argv[1];
int returnval;  
// Check file existence  
returnval = access (filepath, F_OK);  

if (returnval == 0)    
printf ("\n %s exists\n", filepath);  

else  
{    
if (errno == ENOENT)      
printf ("%s does not exist\n", filepath);    
else if (errno == EACCES)      
printf ("%s is not accessible\n", filepath);     
 return 0;  
 }  
 
 returnval = access(filepath, R_OK);
 
 if(returnval == 0){
 printf("%s File is readable\n", filepath);
 }
 
 else if(returnval == -1){
 printf("%s File is not readable\n", strerror(errno));
 }
 
 returnval = access(filepath, W_OK);
 
 if(returnval == 0){
 printf("%s File is writeable\n", filepath);
 }
 else if(returnval = -1){
 printf("%s File isn't writeable\n", strerror(errno));
 }
  

 return 0;}
 
