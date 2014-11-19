# Bell-LaPadula

This programs is simple implementation of Bell-LaPadula Access Control mechanism. Its written in C programming language and implemented using text files for user levels and file access levels. 

It supports both rules of Bell-LaPadula

  - The Simple Security Property - a subject at a given security level may not read an object at a higher security level (no read-up).
  - The ★-property (read "star"-property) - a subject at a given security level must not write to any object at a lower security level (no write-down).

There are two implementations of evaluating access control mechanism. First one is regular file system which associates each file with each user to describe access rights. 

For firt implementation, following C files can be seen: 

 - myread.c
 - mywrite.c

### Instructions for compiling and running

I believe you already have a C compiler and some text / code editor installed. Please note that this implementation was done using Ubuntu Linux machine and the linux system user ID is used to create the application. 

1. Compile userid.c and run it to know your user ID
```sh
$ ./userid
```

2. Edit the file permissions.txt to manually assign access rights. Fields are separated by #. Last two fields specify read and write access flags. 
3. Compile myread.c and mywrite.c. Then you can run myread program like shown below. assignment.txt is the sample file. You can add more files and add access rules in permissions.txt to test the application. 
```sh
$ ./myread assignment.txt
```

### San Francisco State University
Please note that this program was written as part of course work in Computer Science Department of San Francisco State University for course CSC650 - Secure Network Systems.


