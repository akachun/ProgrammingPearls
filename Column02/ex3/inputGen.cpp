#include <stdio.h>
#include <time.h>
#define MINL 500000
#define LMAX 5000000
char str[LMAX+10], sol[LMAX+10];
static unsigned int rndint(void)
{
	static unsigned long long seed = 5;
	return ((unsigned int)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}

int main(){
  FILE * input = fopen("input.txt","w");
  FILE * output = fopen("output.txt","w");
  int N=100;
  fprintf(input,"%d\n",N);
  for(int i=0;i<N;i++){
    int len = MINL + rndint()%(LMAX-MINL);
    int rpt = rndint()%len + 1;
    for(int j=0;j<len;j++) str[j] = 'a'+rndint()%26;
    sol[len]=str[len]=0;
    int idx=0;
    for(int j=rpt;j<len;j++) sol[idx++] = str[j];
    for(int j=0;j<rpt;j++) sol[idx++] = str[j];
    fprintf(input,"%s %d\n",str,rpt);
    fprintf(output,"%s\n",sol);
  }
  fclose(input);
  fclose(output);
  return 0;
}