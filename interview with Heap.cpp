/* 


    >>> get_anagrams(["pastel", "staple", "banana", "kiwi", "late", "tale"])
    ["pastel", "staple", "late", "tale"]


*/


#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

struct node{
  string value;
  node* next;
  bool outputed = false;
};

bool compare(string a, string b){
  int counta[26];
  int countb[26];
  for(int i = 0; i < 26; i++){
    counta[i] = 0;
    countb[i] = 0;
  }
  bool flag = true;
  for(int i = 0; i < a.length(); i++){
    if(a.at(i) >= 'a' && a.at(i) <= 'z') counta[a.at(i)-'a']++;
    if(a.at(i) >= 'A' && a.at(i) <= 'Z') counta[a.at(i)-'A']++;
  }
  for(int i = 0; i < b.length(); i++){
    if(b.at(i) >= 'a' && b.at(i) <= 'z') countb[b.at(i)-'a']++;
    if(b.at(i) >= 'A' && b.at(i) <= 'Z') countb[b.at(i)-'A']++;
  }
  for(int i = 0; i < 26; i++){
    if(counta[i] != countb[i]){
      flag = false;
      break;
    }
  }
  return flag;
}

// To execute C++, please define "int main()"
int main() {
  int n;
  cout << "enter number of words: ";
  cin >> n;
  vector<string> s;
  string temporary;
  for(int i = 0; i < n; i++){
    cin >> temporary;
    s.push_back(temporary);
  }
  cout << "ok...";
  srand((unsigned int) time(NULL));
  int p = rand() % n;
  node* hx[p];
  int temp;
  vector<string> result;
  int count[p];
  
  for(int i = 0; i < p; i++){
    hx[i] = nullptr;
    count[i] = 0;
  }
  
  for(int i = 0; i < n; i++){
   temp = 0;
    for(int j = 0; j < s[i].length(); j++){
      temp += s[i].at(j);
    }
    temp = temp % p;
    node* t = hx[temp];
    node* add = new node;
    add->value = s[i];
    add->next = t;
    hx[temp] = add;
    count[temp]++;
  }
  
  for(int i = 0; i < p; i++){
    cout << "checking bucket " << i;
    for(node* pos = hx[i]; pos != nullptr; pos = pos->next) {
      if(pos->outputed == true){
        continue;
      }
      for (node* post = pos->next; post != nullptr; post = post->next) {
        if(post->outputed == true){
          continue;
        }
        bool t = compare(pos->value, post->value);
        if(t){
          if(!pos->outputed) result.push_back(pos->value);
          result.push_back(post->value);
          pos->outputed = true;
          post->outputed = true;
        }
      }
    }
  }
  
  cout << "done\n";
  
  for(int i = 0; i < result.size(); i++){
    cout << result[i] << ",\t";
  }
  return 0;
}

