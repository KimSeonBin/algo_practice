#include <cstdio>
#include <cstdlib>
#include <vector>

#define WEIGHTS_MAX 40000

using namespace std;

void get_input(int count, vector<int> *input){
  for(int i = 0; i < count; i++){
    int temp;
    scanf("%d", &temp);
    (*input).push_back(temp);
  }
}

void scale_sol(vector<int> *weights, vector<int> *targets){
  bool is_available_weight[WEIGHTS_MAX+1] = {false};
  bool temp[WEIGHTS_MAX+1] = {false};

  for(int i = 0; i < (*weights).size(); i++){
    for(int j = 0; j < WEIGHTS_MAX; j++){
      if(is_available_weight[j]){
        if(j + (*weights)[i] <= WEIGHTS_MAX){
          temp[j + (*weights)[i]] = true;
        }

        temp[abs(j - (*weights)[i])] = true;
      }
    }

    for(int j = 0; j <= WEIGHTS_MAX; j++){
      is_available_weight[j] |= temp[j];
    }

    is_available_weight[(*weights)[i]] = true;
  }

  for(int i = 0; i < (*targets).size(); i++){
    if(is_available_weight[(*targets)[i]])
      printf("Y ");
    else
      printf("N ");
  }
}

int main(){
  int weight_count = 0, target_count = 0;
  vector<int> weights, targets;
  scanf("%d", &weight_count);
  get_input(weight_count, &weights);

  scanf("%d", &target_count);
  get_input(target_count, &targets);

  scale_sol(&weights, &targets);
  return 0;
}
