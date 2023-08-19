//Code for Client//
/* Client chat process - climsg.c */
#include &lt;sys/msg.h&gt;
#include &lt;sys/ipc.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;string.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
struct mesgq
{
long type;
char text[200];
} mq;
main()
{
int msqid, len;
key_t key = 2013;
if ((msqid = msgget(key, 0644)) == -1)
{
printf(&quot;Server not active\n&quot;);
exit(1);
}
printf(&quot;Client ready :\n&quot;);
while (msgrcv(msqid, &amp;mq, sizeof(mq.text), 1, 0) != -1)
{
printf(&quot;From Server: \&quot;%s\&quot;\n&quot;, mq.text);
fgets(mq.text, sizeof(mq.text),stdin);
len = strlen(mq.text);
if (mq.text[len-1] == &#39;\n&#39;)
mq.text[len-1] = &#39;\0&#39;;
msgsnd(msqid, &amp;mq, len+1, 0);
}
printf(&quot;Server Disconnected\n&quot;);
}

//Code for server//
/* Server chat process - srvmsg.c */
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;sys/ipc.h&gt;
#include &lt;sys/msg.h&gt;
#include &lt;stdio.h&gt;
struct mesgq
{
long type;
char text[200];
} mq;
main()
{
int msqid, len;
key_t key = 2013;
if((msqid = msgget(key, 0644|IPC_CREAT)) == -1)
{
perror(&quot;msgget&quot;);
exit(1);
}
printf(&quot;Enter text, ^D to quit:\n&quot;);
mq.type = 1;
while(fgets(mq.text, sizeof(mq.text), stdin) != NULL)
{
len = strlen(mq.text);
if (mq.text[len-1] == &#39;\n&#39;)
mq.text[len-1] = &#39;\0&#39;;
msgsnd(msqid, &amp;mq, len+1, 0);
msgrcv(msqid, &amp;mq, sizeof(mq.text), 1, 0);
printf(&quot;From Client: \&quot;%s\&quot;\n&quot;, mq.text);
}
msgctl(msqid, IPC_RMID, NULL);
}
