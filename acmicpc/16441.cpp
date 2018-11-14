#include <cstdio>
#include <vector>
#include <queue>
#define GREEN '.'
#define ICE '+'
#define WALL '#'
#define WOLF 'W'
#define PIG 'P'

using namespace std;

typedef struct pos{
  int x, y;
};
/*
7 6
######
#W#.##
#.+++#
#.####
#+.W##
#.####
######

7 7
#######
#..+..#
###+###
#+W+++#
#+++#.#
##++++#
#######
*/
void print_answer(vector<vector<char>> pig_map, bool (*is_reachable)[101]){
  for(int i = 0; i < pig_map.size(); i++){
    for(int j = 0; j < pig_map[i].size(); j++){
      if(!is_reachable[i][j]){
        if(pig_map[i][j] == GREEN)
          printf("%c", PIG);
        else
          printf("%c", pig_map[i][j]);
      }
      else
        printf("%c", pig_map[i][j]);
    }
    printf("\n");
  }
}

void get_pos_wolf(vector<vector<char>> *pig_map, queue<pos> *bfs, bool (*is_reachable)[101]){
  for(int i = 0; i < (*pig_map).size(); i++){
    for(int j = 0; j < (*pig_map)[i].size(); j++){
      if((*pig_map)[i][j] == WOLF){
        pos pos_wolf;
        pos_wolf.x = i, pos_wolf.y = j;

        (*bfs).push(pos_wolf);
        is_reachable[i][j] = true;
      }
    }
  }
}

void sol(vector<vector<char>> pig_map){
  bool is_reachable[101][101] = {false};
  int dirr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  queue<pos> bfs;

  get_pos_wolf(&pig_map, &bfs, is_reachable);

  while(!bfs.empty()){
    pos now_pos_wolf = bfs.front();
    bfs.pop();

    for(int i = 0; i < 4; i++){
      int nextx = now_pos_wolf.x + dirr[i][0], nexty = now_pos_wolf.y + dirr[i][1];
      pos next_pos;
      next_pos.x = nextx;
      next_pos.y = nexty;

      if(nextx < 0 || nexty < 0 || nextx >= pig_map.size() || nexty >= pig_map[0].size())
        continue;
      if(pig_map[nextx][nexty] == WALL)
        continue;
      else if(pig_map[nextx][nexty] == GREEN){
      }
      else if(pig_map[nextx][nexty] == ICE){
        while(pig_map[nextx][nexty] == ICE){
          nextx += dirr[i][0];
          nexty += dirr[i][1];
        }

        if(pig_map[nextx][nexty] == WALL){
          nextx -= dirr[i][0];
          nexty -= dirr[i][1];
        }

        next_pos.x = nextx;
        next_pos.y = nexty;
      }

      if(is_reachable[nextx][nexty])
        continue;

      is_reachable[nextx][nexty] = true;
      bfs.push(next_pos);
    }
  }

  print_answer(pig_map, is_reachable);
}

int main(){
  int n, m;
  vector<vector<char>> pig_map;

  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    vector<char> map_row;
    for(int j = 0; j < m; j++){
      char temp;
      scanf(" %c", &temp);
      map_row.push_back(temp);
    }
    pig_map.push_back(map_row);
  }

  sol(pig_map);
  return 0;
}
