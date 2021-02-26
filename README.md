Each file corresponds to the Lab questions

0. (a) Extend code snippet 1 to check for read and write access permissions of a given file.
(b) Write a C program where ​open ​system call creates a new file (say, ​destination.txt​) and then opens it. (Hint: use the bitwise OR flag)

1. UNIX ​cat ​command has three functions with regard to text files: displaying them, combining copiesof them and creating new ones. Write a C program to implement a command called​ printcontent that takes a (text) filename as argument and displays its contents. Report an appropriate message if the file does not exist or can’t be opened (i.e.the file doesn’t have read permission).You are to use​ open()​,​read()​,​write()​andclose() ​system calls.

2. The ​cp ​command copies the source file specified by the SourceFile parameter to the destination filespecified by the DestinationFile parameter. Write a C program that mimics the​ cp​command using​ open()​ system call to open ​source.txt​ file in read-only mode and copy the contents of it to ​destination.txt ​using ​read() ​and ​write() ​system calls.

3. Repeat part 2 (by writing a new C program) as per the following procedure:(a) Read the next 50 characters from ​source.txt​, and among characters read, replace each character ’5’ with character ‘A’’ and all characters are then written in ​destination.txt.
(b) Write characters "XYZ" into file ​destination.txt​(c) Repeat the previous steps until the end of file ​source.txt​. The last read step may not have 50 characters.

