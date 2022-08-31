/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    if (nums.size() == 1) return nums.back();
    multiset<int, greater<int>> s = multiset<int, greater<int>>();
    s.emplace(nums[0]);
    for (int i = 1; i < k; i++) {
      nums[i] += *s.begin();
      s.emplace(nums[i]);
    }
    for (int i = k; i < nums.size(); i++) {
      nums[i] += *s.begin();
      s.erase(nums[i - k]);
      s.emplace(nums[i]);
    }
    return nums[nums.size() - 1];
  }
};
// @lc code=end

