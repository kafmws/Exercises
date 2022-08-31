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
#define CHECKTIME tam.stop();
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

  CHECKTIME
}