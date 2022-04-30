#include <stdio.h>
#include <time.h>
#include <set>
int A[1000000],N;
int main(){
  FILE *input = fopen("../input1000000.txt","r");
  FILE *output = fopen("sort_set_out.txt","w");
  std::set<int> mySet;
  fscanf(input,"%d",&N);
  for(int i=0;i<N;i++){
    fscanf(input,"%d",A+i);
    mySet.insert(A[i]);
  }
  for(int a : mySet){
    fprintf(output,"%d\n",a);
  }
  double t = (double)clock()/CLOCKS_PER_SEC;
  fprintf(output,"%lf\n",t);
  printf("%lf\n",t);
  fclose(input);
  fclose(output);
}