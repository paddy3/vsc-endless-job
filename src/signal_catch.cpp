#include <iostream>
#include <fstream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>

std::ofstream OUTFILE("signal_caught.txt");

void my_handler(int s){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

           OUTFILE << "Caught signal " << s
        		   << " at "
				   << (now->tm_year + 1900) << '-'
        	       << (now->tm_mon + 1) << '-'
        	       <<  now->tm_mday << ' '
				   <<  now->tm_hour << ':'
				   <<  now->tm_min << ':'
				   <<  now->tm_sec
				   << std::endl;
}

int main(int argc,char** argv)
{

   for (int i=1;i<=64;++i)
	   signal(i, my_handler);

   while(1);

   return 0;
}
