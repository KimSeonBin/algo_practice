#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;
vector<int> rr;
int main() {
	int n = 0;
	scanf("%d", &n);

	int temp = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		card.push_back(temp);
	}
	sort(card.begin(), card.end());

	int t = 0;
	scanf("%d", &t);
	int left = 0, right = 0, mid = 0, k = 0;

	for (int i = 0; i < t; i++) {
		scanf("%d", &temp);
		left = 0; right = n - 1; mid = (left + right) / 2;
    int lowers = 0, lowere = n, uppers = 0, uppere = n;
    int lower = 0, upper = 0;
		k = 0;

		//lower bound
    while(lowere - lowers > 0){
      mid = (lowers + lowere) / 2;
      if(card[mid] < temp){
        lowers = mid+1;
      }
      else{
        lowere = mid;
      }
    }
    //upper bound
    while(uppere - uppers > 0){
      mid = (uppers + uppere) / 2;
      if(card[mid] <= temp){
        uppers = mid+1;
      }
      else{
        uppere = mid;
      }
    }

    lower = lowere + 1;
    upper = uppere + 1;

    if(n == 1){
      if(temp == card[0]){
        rr.push_back(1);
      }
      else{
        rr.push_back(0);
      }
    }
    else{
      rr.push_back(upper-lower);
    }
	}

	for (int i = 0; i < t; i++) {
		printf("%d ", rr[i]);
	}
	printf("\n");
	return 0;
}
