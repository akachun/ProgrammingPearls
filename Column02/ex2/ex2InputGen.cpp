#include <stdio.h>
#include <set>
#define NMAX 540000000
#define MASK ((1<<29)-1)
int ans[NMAX];
static unsigned int rndint(void)
{
	static unsigned long long seed = 5;
	return ((unsigned int)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}

int main(){
  FILE * output = fopen("input.txt","w");
  unsigned int N = NMAX;
  int ansCnt=0;
  std::set<int> mySet;
  fprintf(output,"%d",N);
  for(int i=0;i<N;i++) {
    int v = rndint()&MASK;
    fprintf(output," %d",v);
    if(mySet.find(v) != mySet.end()) {
      ans[ansCnt++] = v;
    } else mySet.insert(v);
  }
  fclose(output);
  
  FILE * sol = fopen("output.txt","w");
  fprintf(sol,"%d",ansCnt);
  for(int i=0;i<ansCnt;i++) fprintf(sol," %d",ans[i]);
  fclose(sol);
}