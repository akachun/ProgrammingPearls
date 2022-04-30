#include <stdio.h>
#include <time.h>
#define IMAX 100000000
int A[IMAX];
int from[IMAX],to[IMAX],topIdx;
void fase_init(int idx){
  if(from[idx] < topIdx && to[from[idx]] == idx) return;
  from[idx] = topIdx;
  to[topIdx++] = idx;
  A[idx]=0;
}
int main(){
  printf("size[%lf]\n",(double)sizeof(A)/1024/1024);
  FILE * input = fopen("input.txt","r");
  int T;fscanf(input,"%d",&T);
  int error=0;
  
  for(int tc=0;tc<T;tc++){
    topIdx=0;
    int N, S;
    long long O; 
    fscanf(input,"%d%d%lld",&N,&S,&O);
    for(int i=0;i<N;i++){
      int idx,v;
      fscanf(input,"%d%d",&idx,&v);
      fase_init(idx);
      A[idx]=v;
    }
    long long ans=0;
    for(int i=0;i<S;i++){
      int idx;
      fscanf(input,"%d",&idx);
      fase_init(idx);
      ans += A[idx];
    }
    if(O != ans) error++;
  }
  printf("error[%d] ",error);
  fclose(input);
  double t = (double)clock()/CLOCKS_PER_SEC;
  printf("%lf\n",t);
}