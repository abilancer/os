Parent and Child Process
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
if (fork() == 0)
printf("Hello from Child!\n");
else
printf("Hello from Parent!\n");
}

Zombie Process
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{
pid_t child_pid = fork();
if(child_pid > 0)
{
}
else
sleep(5);
system("ps -eo pid,ppid,stat,cmd");
exit(0);
}


Orphan Process
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{
int pid = fork();
if (pid > 0)
{
printf("in parent process:%d\n",getpid());
sleep(3);
}
else if (pid == 0)
{
printf("in child process:%d\n",getpid());
printf("in parent process:%d\n",getppid());
sleep(3);
printf("in child process:%d\n",getpid());
printf("in parent process:%d\n",getppid());
}
}


Threads
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *myThreadFun(void *vargp)
{
sleep(1);
printf("From Thread
\n"); return NULL;
}
int main()
{
pthread_t thread_id;
printf("Before
Thread\n");
pthread_create(&thread_id, NULL, myThreadFun, NULL);
pthread_join(thread_id, NULL);
printf("AfterThread\n");
exit(0);
}
