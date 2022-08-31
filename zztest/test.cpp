#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    string s;
    string name("Timur");
    sort(name.begin(), name.end());
    // cout << name;
    while (n--) {
      cin >> t >> s;
      sort(s.begin(), s.end());
      if (strcmp(s.c_str(), name.c_str()) == 0)
        puts("YES");
      else puts("NO");
    }
    return 0;
}