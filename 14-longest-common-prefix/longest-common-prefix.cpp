#include <string>
#include <vector>
#include <algorithm>

// All code above (includes) is to get rid of errors + follow LeetCode's desired input

/*
// Given Code

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
    }
};

*/

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        std::string commonPrefix = "";
        std::string first = strs[0], last = strs[strs.size() - 1];
        
        std::sort(strs.begin(), strs.end()); // Sort strings


        return commonPrefix;
    }
};