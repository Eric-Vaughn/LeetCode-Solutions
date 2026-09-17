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

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string> &strs)
    {
        // Sort the strings (alphabetically)
        std::sort(strs.begin(), strs.end());
        // Get our potentially smallest (first) and potentially largest (last) strings
        std::string first = strs[0], last = strs[strs.size() - 1];
        // Variable to store our result
        std::string commonPrefix = "";

        // Go over whichever string is smallest's full length
        for (int i = 0; i < std::min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                // The common prefix has ended
                return commonPrefix;
            }

            // Update common prefix
            commonPrefix += first[i];
        }

        // No matter what, return the common prefix, even if it's and empty string
        return commonPrefix;
    }
};