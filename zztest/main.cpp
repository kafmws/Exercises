//
// Created by kafm on 2022/4/26.
//
#include <string>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

class Solution {

private:
    int romanValue(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }

public:
    int romanToInt(string s) {
        s.push_back(' ');
        int result = romanValue(s[0]);
        for (int i = 1; i < s.length() - 1; ++i) {
            int cur = romanValue(s[i]);
            if (cur < s[i + 1]) {
                result -= cur;
            } else result += cur;
        }
        return result;
    }

    static map<int, string, greater<int>> getRomanMap() {
        static map<int, string, greater<int>> m = map<int, string, greater<int>>();
        m[1000] = string("M");
        m[900] = string("CM");
        m[500] = string("D");
        m[400] = string("CD");
        m[100] = string("C");
        m[90] = string("XC");
        m[50] = string("L");
        m[40] = string("XL");
        m[10] = string("X");
        m[9] = string("IX");
        m[5] = string("V");
        m[4] = string("IV");
        m[1] = string("I");
        return m;
    }

    string intToRoman(int num) {
        string result;
        for (auto &it: m) {
            while (num >= it.first) {
                num -= it.first;

            }
        }
    }

    Solution() = default;
};

int main() {
    auto solution = Solution();
    assert(solution.romanToInt(solution.intToRoman(1994)) == "MCMXCIV");
    assert(solution.romanToInt("MCMXC") == 1990);
    assert(solution.romanToInt("MCM") == 1900);

}