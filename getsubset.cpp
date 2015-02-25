#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<string>> GetSubSet(vector<string> v) {
  if (v.empty()) return {{""}};
  auto last = v.back();
  v.pop_back();
  
  auto without = GetSubSet(v);
  auto with = vector<vector<string>>{};
  for (auto& s : without) {
    with.push_back(s);
    with.back().push_back(last);
  }
  
  without.insert(without.end(), with.begin(), with.end());
  
  return without;
}

int main(void) {
  auto result = GetSubSet({"foo", "bar", "haha"});
  
  for (auto& i : result) {
    for (auto& j : i) {
      cout << j << "\t";
    }
    cout << endl;
  }
  
  return 0;

}


