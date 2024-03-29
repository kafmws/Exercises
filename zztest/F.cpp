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

#if __cplusplus == 201703L
#define tst 132
#endif

int n = 0, m = 0;
char mm[53][53] = {0};


void print() {
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << mm[i][j];
      }
      cout << endl;
    }
}

int match(int i, int j) {
  int type = 0;
  mm[i][j] = 0;
  if (mm[i + 1][j] == '*') {
    mm[i + 1][j] = 0;
    if (mm[i + 1][j + 1] == '*') {
      mm[i + 1][j + 1] = 0;
      type = 1;
    } else if (mm[i][j + 1] == '*') {
      mm[i][j + 1] = 0;
      type = 4;
    } else if (mm[i + 1][j - 1] == '*') {
      mm[i + 1][j - 1] = 0;
      type = 2;
    }
  } else if (mm[i][j + 1] == mm[i + 1][j + 1] && mm[i][j + 1] == '*') {
    mm[i][j + 1] = mm[i + 1][j + 1] = 0;
    type = 3;
  }
  int ii = i - 1;
  int jj = j - 1;
  if (type == 2) jj--;
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      if (mm[ii + x][jj + y] == '*') {
        if (!(type == 3 && x == 3 && y == 0 || type == 4 && x == 3 && y == 3)) {
          type = 0;
          break;
        }
      }
    }
  }
  return type;
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    for(int i = 0; i <= n; i++) memset(mm[i], 0, sizeof(mm[i]));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> mm[i][j];
      }
    }
    // for(int i = 0; i <= n; i++) mm[i][m+1] = 0; 
    // for(int j = 0; j <= m; j++) mm[n+1][j] = 0;

    int res = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mm[i][j] == '*') {
          if (!match(i, j)) {
            res = 0;
            // print();
            goto label;
          }
        }
      }
    }
  label:
    cout << (res ? "YES" : "NO") << endl;
  }

  CHECKTIME
}