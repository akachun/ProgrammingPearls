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
    int rpt;
    scanf("%s%d",str,&rpt);
    int len = strlen(str);
    reverse(0,rpt-1);
    reverse(rpt,len-1);
    reverse(0,len-1);
    printf("%s\n",str);
  }
  printf("reverse [%.3lf]\n",(double)clock()/CLOCKS_PER_SEC);
}