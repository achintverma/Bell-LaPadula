#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    
    int i; 
    
    i = getuid();
    printf("Your User ID: %d\n",i);
    
    return 0;
    
}
