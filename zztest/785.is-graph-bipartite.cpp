/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
 bool isBipartite(std::vector<std::vector<int>> &graph) {
   int n = graph.size();
   std::vector<int> flags = std::vector<int>(n, 2);
   std::queue<int> queue = std::queue<int>();
   while (true) {
     for (int i = 0; i < n; i++) {
       if (flags[i] == 2) {
         queue.push(i);
         flags[i] = 0;
         if (graph[i].size()) break;
       }
     }
     if (queue.empty()) break;
     while (!queue.empty()) {
       int node = queue.front();
       if (flags[node] == 2) flags[node] = 0;
       queue.pop();
       for (int i : graph[node]) {
         if (flags[i] == 2) {
           flags[i] = !flags[node];
           queue.push(i);
         } else if (flags[i] == flags[node])
           return false;
       }
     }
   }
   return true;
 }
};
// @lc code=end

