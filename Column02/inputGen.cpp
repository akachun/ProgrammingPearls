#include <stdio.h>
#include <time.h>
#define NMAX 1000000000
#define CHUNK 50000000
#define MASK ((1<<30)-1)
int A[CHUNK];
static unsigned int rndint(void)
{
	static unsigned long long seed = 5;
	return ((unsigned int)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}

int main(){
  FILE * output = fopen("input.txt","w");
  unsigned int N = NMAX;
  for(int i=0;i<N;i+=CHUNK) {
    for(int j=0;j<CHUNK;j++) A[j]=rndint()&MASK;
    fwrite(A,sizeof(int),CHUNK,output);
  }
  fclose(output);
  printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
}