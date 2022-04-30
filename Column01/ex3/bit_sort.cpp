#include<stdio.h>
#include<time.h>
#define BIT_SIZE 64
#define SHIFT 6
typedef unsigned long long ull;
ull bit[156250];
void setBit(int b){
  bit[b>>SHIFT] |= ((ull)1)<<(b&(BIT_SIZE-1));
}
void clearBit(int b){
  bit[b>>SHIFT] &= ~(((ull)1)<<(b&(BIT_SIZE-1)));
}
int getBit(int b){
  return (bit[b>>SHIFT] & ((ull)1)<<(b&(BIT_SIZE-1))) != 0;
}
int main(){
  FILE * input = fopen("../input1000000.txt","r");
  FILE * output = fopen("bit_sort_out.txt","w");
  printf("size[%lf] ",(double)sizeof(bit)/1024/1024);
  for(int i=0;i<156250;i++) bit[i]=0;
  int N;
  fscanf(input,"%d",&N);
  for(int i=0,v;i<N;i++){
    fscanf(input,"%d",&v);
    setBit(v);
  }
  for(int i=0;i<10000000;i++){
    if(getBit(i)) fprintf(output,"%d\n",i);
  }
  double t = (double)clock()/CLOCKS_PER_SEC;
  printf("%lf\n",t);
  fprintf(output,"%lf\n",t);
  fclose(input);
  fclose(output);
}