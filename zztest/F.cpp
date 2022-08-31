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

int n = 0, m = 0;
char mm[53][53] = {0};

// int match(int i, int j) {
//   int type = 0;
//   if (mm[i][j] == '*' && i + 1 < n && j + 1 < m && mm[i + 1][j] == '*' &&
//       mm[i + 1][j + 1] == '*') {
//     mm[i][j] = mm[i + 1][j] = mm[i + 1][j + 1] = '.';
//     type = 1;
//   } else if (mm[i][j] == '*' && i + 1 < n && j - 1 >= 0 &&
//              mm[i + 1][j] == '*' && mm[i + 1][j - 1] == '*') {
//     mm[i][j] = mm[i + 1][j] = mm[i + 1][j - 1] = '.';
//     type = 2;
//   } else if (mm[i][j] == '*' && i + 1 < n && j + 1 < m && mm[i][j + 1] == '*'
//   &&
//              mm[i + 1][j + 1] == '*') {
//               mm[i][j] = mm[i][j+1] = mm[i+1][j+1] = '.';
//     type = 3;
//   } else if (mm[i][j] == '*' && i + 1 < n && j + 1 < m && mm[i+1][j] == '*'
//   && mm[i][j+1] == '*') {
//       mm[i][j] = mm[i+1][j] = mm[i][j+1] = '.';
//     type = 4;
//   }
//   int ii = i - 1, jj = j - 1;
//   if(type == 2) --ii;
//   for(int p = 0; p < 4; p++) {
//     for(int q = 0; q < 4; q++) {
//       if()
//     }
//   }
//   return type;
// }


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

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
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

  return 0;
}