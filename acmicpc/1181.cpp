#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(const string &a, const string &b){
  int alen = a.length();
  int blen = b.length();
  if(alen < blen){
    return true;
  }
  else if(alen == blen){
    for(int i = 0; i < alen; i++){
      if(a.at(i) < b.at(i)){
        return true;
      }
      else if(a.at(i) > b.at(i)){
        return false;
      }
    }
    return false;
  }
  else{
    return false;
  }
}

int main(){
  int n = 0;
  vector<string> words;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    string tem;
    char sentem[51];
    scanf("%s", sentem);
    tem = sentem;
    words.push_back(tem);
  }
  sort(words.begin(), words.end(), cmp);

  for(int i = 0; i < n; i++){
    if(i != 0){
      if(words[i].compare(words[i-1]) == 0){
        continue;
      }
    }
    cout << words[i] << '\n';
  }

  return 0;
}
