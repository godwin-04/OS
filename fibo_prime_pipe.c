/* Fibonacci and Prime using pipe - fibprime.c */
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;unistd.h&gt;
#include &lt;sys/types.h&gt;
main()
{
pid_t pid;
int pipefd[2];
int i,j,flg,f1,f2,f3;
static unsigned int ar[25],br[25];
if(pipe(pipefd) == -1)
{
printf(&quot;Error in pipe&quot;);
exit(-1);
}
pid=fork();
if (pid == 0)
{
close(pipefd[0];
printf(&quot;Child process generates Fibonacci series\n&quot; );
f1 = -1;
f2 = 1;
for(i = 0;i &lt; 25; i++)
{
f3 = f1 + f2;
//printf(&quot;%d\t&quot;,f3);
f1 = f2;
f2 = f3;
ar[i] = f3;
}
write(pipefd[1],ar,25*sizeof(int));

}
else if (pid &gt; 0)
{
close(pipefd[1];
wait(NULL);
read(pipefd[0], br, 25*sizeof(int));
printf(&quot;\nParent prints Fibonacci that are Prime\n&quot;);
for(i = 0;i &lt; 25; i++)
{
flg = 0;
if (br[i] &lt;= 1)
flg = 1;
for(j=2; j&lt;=br[i]/2; j++)
{
if (br[i]%j == 0)
{
flg=1;
break;
}
}
if (flg == 0)
printf(&quot;%d\t&quot;, br[i]);

}
printf(&quot;\n&quot;);
}
else
{
printf(&quot;Process creation failed&quot;);
exit(-1);
}
}
