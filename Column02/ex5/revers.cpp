#include <stdio.h>
#include <string.h>
#include <time.h>
#define LMAX 10000000
char str[LMAX+10];
void reverse(int s, int e){
  while(s<e){
    char tmp = str[s];
    str[s] = str[e];
    str[e] = tmp;
    s++;e--;
  }
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("reverse_sol.txt","w",stdout);
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int rpt1,rpt2;
    scanf("%s%d%d",str,&rpt1,&rpt2);
    int len = strlen(str);
    int lenA = rpt1;
    int lenB = rpt2-rpt1;
    int lenC = len-rpt2;
    reverse(0,lenA+lenB-1);
    reverse(lenB,len-1);
    reverse(0,lenB+lenC-1);
    printf("%s\n",str);
  }
  printf("reverse [%.3lf]\n",(double)clock()/CLOCKS_PER_SEC);
}