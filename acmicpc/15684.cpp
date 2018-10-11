#include <cstdio>
#include <vector>

using namespace std;

typedef struct line{
  int x, y;
};

vector<line> possible;
int bridge[71][71] = {0};//0: empty, 1: 입력 값

bool addpossible(vector<line> v){
  for(int i = 0; i < v.size(); i++){
    if(bridge[v[i].x][v[i].y] == 1)
      return false;
    bridge[v[i].x][v[i].y] = 1;
    if(bridge[v[i].x][v[i].y+2] == 1)
      return false;
    bridge[v[i].x][v[i].y+2] = 1;
    bridge[v[i].x][v[i].y+1] = 1;
  }

  return true;//기존의 bridge와 겹치는 possible이 없다.
}

void restore(vector<line> v){
  for(int i = 0; i < v.size(); i++){
    bridge[v[i].x][v[i].y] = 0;
    bridge[v[i].x][v[i].y+1] = 0;
    bridge[v[i].x][v[i].y+2] = 0;
  }
}

bool isvalid(vector<line> v, int h, int n){
  bool check = true;
  check = addpossible(v);

  if(!check){
    restore(v);
    return check;
  }

  for(int i = 1; i <= n; i++){
    int sx = 1, sy = i*2;
    while(sx <= h){
      if(bridge[sx][sy] == 1){
        if(bridge[sx][sy+1] == 1)
          sy += 2;
        else
          sy -= 2;
      }
      sx++;
    }
    if(sy != i*2){
      check = false;
      break;
    }
  }

  restore(v);
  return check;
}

int bruteforce(vector<line> v, int index, int h, int n){
  int result = 4, temp = 0;

  if(isvalid(v, h, n))
    return v.size();

  //v.size()가 3이라면 이후에 push를 해도 3을 넘기에 -1 return
  if(v.size() == 3)
    return 4;

  for(int i = index+1; i < possible.size(); i++){
    v.push_back(possible[i]);
    temp = bruteforce(v, i, h, n);
    if(result > temp)
      result = temp;
    v.pop_back();
  }
  return result;
}

int main(){
  int n = 0, m = 0, h = 0, answer = -1;
  scanf("%d %d %d", &n, &m, &h);

  for(int i = 0; i < m; i++){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    bridge[a][b*2+2] = 1;
    bridge[a][b*2+1] = 1;
    bridge[a][b*2] = 1;
  }

  // 새로운 bridge 가능한 곳 모으기
  for(int i = 1; i <= h; i++){
    for(int j = 1; j < n; j++){
      if(bridge[i][j*2] != 0 || bridge[i][j*2+2] != 0)
        continue;
      line temp;
      temp.x = i; temp.y = j * 2;
      possible.push_back(temp);
    }
  }

  vector<line> temp;
  answer = bruteforce(temp, -1, h, n);

  if(answer == 4)
    answer = -1;
  printf("%d\n", answer);
  return 0;
}
