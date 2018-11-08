#include <cstdio>
#include <vector>
#define MODULER 1234567
#define MAX_LENGTH 1000
#define BUTTON_COUNT 10

using namespace std;

void init(int (*before_state)[5]){
  for(int iter_x = 1; iter_x <= 3; iter_x++){
    for(int iter_y = 1; iter_y <= 3; iter_y++){
      before_state[iter_x][iter_y] = 1;
    }
  }
  before_state[4][1] = 1;
}

void calculate_next_state(int (*before)[5], int (*next)[5], int (*dir)[2]){
  for(int iter_x = 1; iter_x <= 3; iter_x++){
    for(int iter_y = 1; iter_y <= 3; iter_y++){
      for(int iter_dir = 0; iter_dir < 4; iter_dir++){
        next[iter_x][iter_y] += before[iter_x + dir[iter_dir][0]][iter_y + dir[iter_dir][1]];
      }
      next[iter_x][iter_y] = next[iter_x][iter_y] % MODULER;
    }
  }
  next[4][1] = before[3][1];
}

int swap_state_and_calculate_sum(int (*before)[5], int (*next)[5]){
  int result = 0;

  for(int iter_x = 1; iter_x <= 3; iter_x++){
    for(int iter_y = 1; iter_y <= 3; iter_y++){
      before[iter_x][iter_y] = next[iter_x][iter_y];
      result += next[iter_x][iter_y];
    }
  }
  before[4][1] = next[4][1];
  result += next[4][1];

  return result % MODULER;
}

vector<int> get_password_count(){
  vector<int> result;
  result.push_back(0);
  result.push_back(10);

  int before_state[5][5] = {0}, dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  init(before_state);

  for(int iter = 0; iter < MAX_LENGTH; iter++){
    int next_state[5][5] = {0};
    calculate_next_state(before_state, next_state, dir);
    int sum = swap_state_and_calculate_sum(before_state, next_state);
    result.push_back(sum);
  }

  return result;
}

int main(){
  vector<int> password_sol_count = get_password_count();

  int test_case = 0;
  scanf("%d", &test_case);
  for(int iter = 0; iter < test_case; iter++){
    int password_length = 0;
    scanf("%d", &password_length);

    printf("%d\n", password_sol_count[password_length]);
  }
  return 0;
}
