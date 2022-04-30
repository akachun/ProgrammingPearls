#include <stdio.h>
#include <string.h>
#include <time.h>
#define LMAX 10000000
int gcd(int a, int b){return b?gcd(b,a%b):a;}
char str[LMAX+10];
int main(){
  freopen("input.txt","r",stdin);
  freopen("mysol.txt","w",stdout);
  int N;
  scanf("%d",&N);
  for(int i=0,rpt,len,g;i<N;i++){
    scanf("%s%d",str,&rpt);
    len = strlen(str);
    g = gcd(rpt,len);
    for(int j=0,cur;j<g;j++){
      char tmp = str[j];
      cur = j;
      while(true){
        int k = cur + rpt;
        if(k>=len) k -= len;
        if(k == j) break;
        str[cur] = str[k];
        cur = k; 
      }
      str[cur] = tmp;
    }
    printf("%s\n",str);
  }
  printf("juggling [%.3lf]\n",(double)clock()/CLOCKS_PER_SEC);
}
