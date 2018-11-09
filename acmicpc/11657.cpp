#include <stdio.h>
#include <vector>
#define MAXV 999999999
#define min(a,b) (((a) > (b)) ? (b) : (a))

using namespace std;

typedef struct {
	int from, to, cost;
}bfnode;

vector<bfnode> bfv;
int dist[501] = { 0 };

void init(){
	for (int i = 1; i <= 500; i++)
		dist[i] = MAXV;
}

bool is_available_road(int index){
  if(dist[index] == MAXV)
    return false;
  return true;
}

int main() {
  init();

	int N = 0, M = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
    bfnode temp;
		scanf("%d %d %d", &temp.from, &temp.to, &temp.cost);
		bfv.push_back(temp);

    if(temp.from == 1)
      dist[1] = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[bfv[j].from] == MAXV)
				continue;
			if (dist[bfv[j].from] + bfv[j].cost < dist[bfv[j].to])
				dist[bfv[j].to] = dist[bfv[j].from] + bfv[j].cost;
		}
	}

  bool is_minus_cycle = false;
  for (int j = 0; j < M; j++) {
    if (dist[bfv[j].from] == MAXV)
      continue;
    if (dist[bfv[j].from] + bfv[j].cost < dist[bfv[j].to]){
      is_minus_cycle = true;
      break;
    }
  }

	if (is_minus_cycle){
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		if (!is_available_road(i))
			printf("-1\n");
    else
		  printf("%d\n", dist[i]);
	}
	return 0;
}
