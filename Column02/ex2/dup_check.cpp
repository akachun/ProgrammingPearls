#include <stdio.h>
#define NMAX 540000000
#define SHIFT 29
int main(){
  FILE * input = fopen("input.txt","r");
  int N;fprintf(input,"%d",&N);
  int ret=0;
  char fileName[2][20];
  int fileCnt=0;
  for(int i=SHIFT-1;i>=0;i--){
    int mask = 1<<i;
    int zCnt=0;
    int oCnt=0;
    sprintf(fileName[0],"temp%02d.txt",fileCnt++);
    sprintf(fileName[1],"temp%02d.txt",fileCnt++);
    FILE * zero = fopen(fileName[0],"w");
    FILE * one = fopen(fileName[1],"w");
    int v;
    while(fscanf(input,"%d",&v)!=EOF){
      if(v&mask){
        fprintf(one,"%d ",v);oCnt++;
      } else {
        fprintf(zero,"%d ",v);zCnt++;
      }
    }
    fclose(one);
    fclose(zero);
    if(mask < zCnt) {
      input = fopen(fileName[0],"r");
    } else {
      input = fopen(fileName[1],"r");
      ret |= mask;
    }
  }
  fclose(input);

  FILE * output = fopen("output.txt","r");
  fscanf(output,"%d",&N);
  int found=0;
  for(int i=0;i<N&&!found;i++) {
    int v;fscanf(output,"%d",&v);
    found = (v == ret);
  }
  printf("found[%d] %lf\n",found,(double)clock()/CLOCKS_PER_SEC);
  fclose(output);
}