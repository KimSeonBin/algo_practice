#include <stdio.h>
#include <vector>
using namespace std;

bool pcheck[10000001];
vector<int> primes;

int main(){
  for(int i = 2; i <= 3163; i++){
    if(pcheck[i])
      continue;
    primes.push_back(i);
    for(int j = i+i; j <= 10000000; j+= i)
      pcheck[j] = true;
  }
  for(int i = 3164; i <= 10000000; i++){
    if(!pcheck[i])
      primes.push_back(i);
  }

  int k = 0;
  scanf("%d", &k);
  printf("%d\n", primes[k-1]);

}
