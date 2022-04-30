#include <stdio.h>
#include <time.h>
#include <algorithm>
int A[1000000],N;
int main(){
  FILE *input = fopen("../input1000000.txt","r");
  FILE *output = fopen("sort_std_sort_out.txt","w");
  fscanf(input,"%d",&N);
  for(int i=0;i<N;i++){
    fscanf(input,"%d",A+i);
  }
  std::sort(A,A+N);
  for(int i=0;i<N;i++){
    fprintf(output,"%d\n",A[i]);
  }
  double t = (double)clock()/CLOCKS_PER_SEC;
  fprintf(output,"%lf\n",t);
  printf("%lf\n",t);
  fclose(input);
  fclose(output);
}