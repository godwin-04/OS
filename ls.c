#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
main(int argc, char * argv[])
{
char cwd[1024];
char dirname[10];
DIR *p;
struct dirent *d;
if(getcwd(cwd,sizeof(cwd))!= NULL)
fprintf(stdout,"Current working directory: %s\n",cwd);
else
perror("getcwd() error");
p = opendir(cwd);
if(p == NULL)
{
perror("Canoot find directory");
exit(-1);
}
while(d = readdir(p))
printf("%s\t",d->d_name);
return 0;
}
