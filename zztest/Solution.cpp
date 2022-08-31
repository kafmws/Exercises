#include <bits/stdc++.h>
#ifdef _KAFM_
#include <windows.h>
// split to make windows.h before psapi.h
#include <psapi.h>
#endif
#define all(a) std::begin(a), std::end(a)
#define rall(a) std::rbegin(a), std::rend(a)
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) {
  return __comp(a, b) ? a = b, true : false;
}
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) {
  return __comp(b, a) ? a = b, true : false;
}
#define YESNO(condition) cout << condition ? "YES\n" : "NO\n";

using namespace std;
auto tam = [] {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef _KAFM_
#define CHECKTIME tam.stop()
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  struct TIME_AND_MEMORY {
    static auto GetMicroSecond() {
      static FILETIME ft;
      GetSystemTimeAsFileTime(&ft);
      return ft.dwLowDateTime;
    };
    static auto GetMemory() {
      PROCESS_MEMORY_COUNTERS pmc;
      GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
      return pmc.WorkingSetSize;
    }
    uint32_t t0, t1;
    TIME_AND_MEMORY() : t0(GetMicroSecond()) {}
    void stop() {
      t1 = GetMicroSecond();
      cout << "\ntime cost = " << (t1 - t0) / 10000.0
           << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
      t0 = t1;
    }
    ~TIME_AND_MEMORY() { stop(); }
  };
  return TIME_AND_MEMORY();
#else
#define CHECKTIME
  return 0;
#endif
}();

#if __cplusplus == 201703L
#define tst 132
#endif

class Solution {
  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int opt[201][201] = {0};  // 0 1 pacific
    int m = heights.size(), n = heights[0].size();
    queue<pair<int, int>> q = queue<pair<int, int>>();
    vector<vector<int>> ret;
    for (int j = 0; j < n; j++) q.push({0, j});
    for (int i = 1; i < m; i++) q.push({i, 0});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      opt[p.first][p.second] = 1;
      for (auto &dir : dirs) {
        int x = p.first + dir[0];
        int y = p.second + dir[1];
        if (x >= 0 && x < m && y >= 0 && y < n && !opt[x][y] &&
            heights[x][y] >= heights[p.first][p.second]) {
          q.push({x, y});
        }
      }
    }
    for (int i = 0; i < m; i++) q.push({i, n - 1});
    for (int j = n - 2; j >= 0; j--) q.push({m - 1, j});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (opt[p.first][p.second] == 1) {
        ret.emplace_back(vector<int>{p.first, p.second});
      }
      opt[p.first][p.second] = 2;
      for (auto dir : dirs) {
        int x = p.first + dir[0];
        int y = p.second + dir[1];
        if (x >= 0 && x < m && y >= 0 && y < n && opt[x][y] != 2 &&
            heights[x][y] >= heights[p.first][p.second]) {
          q.push({x, y});
        }
      }
    }
    return ret;
  }

  Solution() {}
};

int main() {
  Solution s;
  vector<vector<int>> v{{1, 2, 2, 3, 5},
                        {3, 2, 3, 4, 4},
                        {2, 4, 5, 3, 1},
                        {6, 7, 1, 4, 5},
                        {5, 1, 1, 2, 4}};
  auto ret = s.pacificAtlantic(v);
  for (auto &r : ret) cout << '[' << r[0] << ',' << r[1] << ']' << ',';
  cout << "\b " << endl;

  CHECKTIME;
}