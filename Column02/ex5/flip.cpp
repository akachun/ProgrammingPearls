#include <stdio.h>
#include <string.h>
#include <time.h>
#define LMAX 5000000
char str[LMAX+10], tmp[LMAX+10];
void flip(int s, int e, int m){
  for(int i=s;i<m;i++) tmp[i]=str[i];
  int idx=s;
  for(int i=m;i<=e;i++) str[idx++] = str[i];
  for(int i=s;i<m;i++) str[idx++] = tmp[i];
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("mysol.txt","w",stdout);
  int N;
  scanf("%d",&N);
  for(int tc=0,rpt1,rpt2;tc<N;tc++){
    scanf("%s%d%d",str,&rpt1,&rpt2);
    int len = strlen(str);
    int lenA = rpt1;
    int lenB = rpt2-rpt1;
    int lenC = len-rpt2;
    // printf("len[%d] rpt1[%d] rpt2[%d] lenA[%d] lenB[%d] lenC[%d] sum[%d]\n",len,rpt1,rpt2,lenA,lenB,lenC,lenA+lenB+lenC);
    flip(0,lenA+lenB-1,lenA);
    flip(lenB,len-1,lenB+lenA);
    flip(0,lenB+lenC-1,lenB);
    printf("%s\n",str);
  }
  printf("[%.3lf]\n",(double)clock()/CLOCKS_PER_SEC);
  return 0;
}