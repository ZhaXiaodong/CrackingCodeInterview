#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> GetPermutation(const string& s) {
  if (s.empty() || s.length() == 1) return {s};
  
  auto result = vector<string>{};
  for (auto i = 0; i < s.length(); ++i) {
    auto permutation = s;
    auto tmp = permutation[0];
    permutation[0] = permutation[i];
    permutation[i] = tmp;

    auto sub_permutation = GetPermutation(permutation.substr(1, permutation.length() - 1));
    for (auto& sub : sub_permutation) {
      result.push_back(string(permutation[0] + sub));
    }
  }
  
  return result;
}

int main(void) {
  auto p = GetPermutation("abcd");
  for (auto& s : p) {
    cout << s << endl;
  }
  return 0;
}
