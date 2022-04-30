#include <stdio.h>
#include <time.h>
#define IMAX 100000000
int A[IMAX];

int main(){
  printf("size[%lf]\n",(double)sizeof(A)/1024/1024);
  FILE * input = fopen("input.txt","r");
  int T;fscanf(input,"%d",&T);
  int error=0;
  for(int tc=0;tc<T;tc++){
    for(int i=0;i<IMAX;i++) A[i]=0;
    int N, S;
    long long O; 
    fscanf(input,"%d%d%lld",&N,&S,&O);
    for(int i=0;i<N;i++){
      int idx,v;
      fscanf(input,"%d%d",&idx,&v);
      A[idx]=v;
    }
    long long ans=0;
    for(int i=0;i<S;i++){
      int idx;
      fscanf(input,"%d",&idx);
      ans += A[idx];
    }
    if(O != ans) error++;
  }
  printf("error[%d] ",error);
  fclose(input);
  double t = (double)clock()/CLOCKS_PER_SEC;
  printf("%lf\n",t);
}