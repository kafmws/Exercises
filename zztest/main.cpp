//
// Created by kafm on 2022/4/26.
//
#include <string>
#include <iostream>
#include <map>
#include <cassert>
#include <cmath>

//std::map<int, std::string, std::greater<>> Solution::m = Solution::initMap();

#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>> &graph) {
        int n = graph.size();
        std::vector<int> flags = std::vector<int>(n, 2);
        std::queue<int> queue = std::queue<int>();
        for (int i = 0; i < n; i++) queue.push(i);
        while (!queue.empty()) {
            int node = queue.front();
            if (flags[node] == 2) flags[node] = 0;
            queue.pop();
            for (int i: graph[node]) {
                if (flags[i] == 2) {
                    flags[i] = !flags[node];
                    queue.push(i);
                } else if (flags[i] == flags[node]) return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution = Solution();
    std::vector<std::vector<int>> v = std::vector<std::vector<int>>() = {
            {1},
            {0, 3},
            {3},
            {1, 2},
    };
    std::cout << solution.isBipartite(v);
    return 0;
}