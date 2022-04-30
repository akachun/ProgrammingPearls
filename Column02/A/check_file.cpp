#include <stdio.h>
#include <time.h>
#define ANS 740650108
#define CHUNK 50000000
int A[CHUNK];
int main(){
  FILE * input = fopen("../input.txt","r");
  // FILE * input = fopen("output.txt","r");
  int cnt;
  int found=0;
  while((cnt=fread(A,sizeof(int),CHUNK,input))>0 && !found){
    for(int i=0;i<cnt && !found;i++){
      if(A[i] == ANS) found++;
    }
  }
  printf("cnt[%d] time[%lf]\n",found,(double)clock()/CLOCKS_PER_SEC);
  fclose(input);
}