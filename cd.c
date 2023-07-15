#include<stdio.h>
#include<unistd.h>
#define NAME_MAX 100
int main(int argc, char *argv[])
{
char buf[NAME_MAX];
char *path = argv[1];
if(chdir(path) == -1)
{
fprintf(stderr,"Error: could not change directory %s\n",path);
return 1;
}
getcwd(buf,NAME_MAX);
printf("CWD is: %s\n",buf);
return 0;
}
