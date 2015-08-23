#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_handler(int s){
           printf("Caught signal %d\n",s);
}

int main(int argc,char** argv)
{

   struct sigaction sigIntHandler;

   sigIntHandler.sa_handler = my_handler;
   sigemptyset(&sigIntHandler.sa_mask);
   sigIntHandler.sa_flags = 0;

   for (int i=1;i<32;++i)
	   sigaction(i, &sigIntHandler, NULL);

   while(1);

   return 0;
}
