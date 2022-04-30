#include <stdio.h>
#include <time.h>
#define NMAX 1000000000
#define MAX_BIT 29
#define CHUNK 50000000
int A[CHUNK];
int Z[CHUNK], O[CHUNK];
int main(){
  FILE * input = fopen("../input.txt","r");
  int fileIdx=0;
  char fileName[2][20];
  int ret=0;
  for(int i=MAX_BIT;i>=0;i--){
    int zCnt=0;
    int oCnt=0;
    int mask = 1<<i;
    sprintf(fileName[0],"temp%02d.txt",fileIdx++);
    sprintf(fileName[1],"temp%02d.txt",fileIdx++);
    FILE * zero = fopen(fileName[0],"w");
    FILE * one = fopen(fileName[1],"w");
    int rCnt;
    while((rCnt=fread(A,sizeof(int),CHUNK,input))>0){
      int oc=0, zc=0;
      for(int j=0;j<rCnt;j++){
        if(A[j]&mask) O[oc++] = A[j]; 
        else Z[zc++] = A[j]; 
      }
      fwrite(Z,sizeof(int),zc,zero);
      fwrite(O,sizeof(int),oc,one);
      oCnt+=oc;
      zCnt+=zc;
    }
    fclose(input);
    fclose(zero);
    fclose(one);

    if(zCnt < oCnt){
      if(zCnt == 0) break;
      input = fopen(fileName[0],"r");
    } else {
      input = fopen(fileName[1],"r");
      ret |= mask;
      if(oCnt == 0) break;
    }
    printf("ret[%d] mask[%d] %s : [%d] %s : [%d]\n",ret,mask,fileName[0],zCnt,fileName[1],oCnt);
  }
  printf("ans[%d] %lf\n",ret,(double)clock()/CLOCKS_PER_SEC);
  int found=0,rCnt;
  FILE * output = fopen("output.txt","r");
  while((rCnt=fread(A,sizeof(int),CHUNK,output)) > 0 && !found) {
    for(int i=0;i<rCnt && !found;i++) found = (A[i] == ret);
  }
  fclose(output);
  printf("found[%d] %lf\n",found,(double)clock()/CLOCKS_PER_SEC);
}