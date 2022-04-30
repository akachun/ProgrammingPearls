#include <stdio.h>
#define IMAX 100000000
static unsigned int rndint(void)
{
	static unsigned long long seed = 5;
	return ((unsigned int)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}
int A[IMAX];
int I[100000], V[100000], SI[100000];
int main(){
  FILE * output = fopen("input.txt","w");
  int T = 100;
  fprintf(output,"%d\n",T);
  for(int tc=0;tc<T;tc++){
    for(int i=0;i<IMAX;i++) A[i]=0;
    int N = 10000 + rndint()%90000;
    int S = 10000 + rndint()%90000;
    long long O = 0;
    for(int i=0;i<N;i++){
      I[i] = rndint()%IMAX;
      V[i] = rndint()%100000;
      A[I[i]] = V[i];
    }
    for(int i=0;i<S;i++){
      int idx = rndint()%IMAX;
      SI[i] = idx;
      O += A[idx];
    }
    fprintf(output,"%d %d %lld\n",N,S,O);
    for(int i=0;i<N;i++) fprintf(output,"%d %d\n",I[i],V[i]);
    for(int i=0;i<S;i++) fprintf(output,"%d ",SI[i]);fprintf(output,"\n");
  }
  fclose(output);
}