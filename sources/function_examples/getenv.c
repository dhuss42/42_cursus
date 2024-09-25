#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *env[])
{
    char    *home;

    home = getenv("TERM");
    if (home != NULL)
        printf("%s\n", home);
    else
        printf("Does not exist\n");

}


