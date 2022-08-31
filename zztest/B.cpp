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
  int cases;
  cin >> cases;
  map<int, map<int, int>> m;
  int h, w, hl, wl, hh, wh;
  while (cases--) {
    int n, q;
    cin >> n >> q;
    m.clear();
    for (int i = 0; i < n; i++) {
      cin >> h >> w;
      m[h][w]++;
    }
    for (int i = 0; i < q; i++) {
      long long sum = 0;
      cin >> hl >> wl >> hh >> wh;
      auto from = m.upper_bound(hl);
      auto to = m.lower_bound(hh);
      for (auto it = from; it != to; ++it) {
        auto f = it->second.upper_bound(wl);
        auto t = it->second.lower_bound(wh);
        for (auto itt = f; itt != t; ++itt) {
            sum += it->first * itt->first * itt->second;
        }
      }
      cout << sum << endl;
    }
  }

  return 0;
}