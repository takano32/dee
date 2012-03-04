#include "nes.h"

long long timer()
{
	 struct timeval *tv;
	 if(gettimeofday(tv, 0)){
		  perror("gettimeofday");
		  exit(1);
	 }
	 return ((long long)tv->tv_sec) * 1000000ll + ((long long)tv->tv_usec);
}

void byte2binary(byte x, char* c)
{
	 int bit = 1;
	 int i;
	 int bitsize = sizeof(c);

	 for (i = bitsize-1; i >= 0; i--) {
		  if (x & bit){
			   c[i] = '1';
		  }else{
			   c[i] = '0';
		  }
		  bit <<= 1;
	 }
}
