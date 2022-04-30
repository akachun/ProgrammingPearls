#include<stdio.h>
#include<unordered_set>
#include<time.h>
#define NMAX 1000000000
#define CHUNK 50000000
int A[CHUNK],B[CHUNK];
int main(){
  FILE * output = fopen("output.txt","w");
  int totcnt=0;
  for(int i=0;i<NMAX;i+=CHUNK){
    std::unordered_set<int> mySet;
    int maxV = i+CHUNK;
    printf("start %d %d \n",i,maxV);
    FILE * input = fopen("../input.txt","r");
    int loop=0;
    int rCnt;
    while((rCnt=fread(A,sizeof(int),CHUNK,input))>0){
      for(int j=0;j<rCnt;j++){
        if(i<=A[j] && A[j] < maxV){
          mySet.insert(A[j]);
        }
      }
    }
    printf("setSize[%d]\n",mySet.size());
    int cnt=0;
    for(int j=i;j<maxV;j++){
      if(mySet.find(j) == mySet.end()){
        B[cnt++] = j;
      }
    }
    fwrite(B,sizeof(int),cnt,output);
    printf("cnt[%d] ",cnt);
    printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    fclose(input);
  }
  printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
  fclose(output);
}