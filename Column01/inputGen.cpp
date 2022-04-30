#include <stdio.h>
#include <set>

static unsigned int rndint(void)
{
	static unsigned long long seed = 5;
	return ((unsigned int)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}

int main(){
  FILE * output = fopen("input1000000.txt","w");
  std::set<int> mySet;
  int N = 1000000;
  fprintf(output,"%d\n",N);
  for(int i=0;i<N;i++){
    int a;
    do{
      a = rndint()%10000000;
    } while(mySet.find(a) != mySet.end());
    mySet.insert(a);
    fprintf(output,"%d\n",a);
  }
  fclose(output);
}