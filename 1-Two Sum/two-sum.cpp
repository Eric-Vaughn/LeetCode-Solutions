// Orignally done on: Oct 28, 2023

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        int num_a, num_b;

        for (int i = 0; i < nums.size(); i++) {
            if (i != nums.size() - 1) {
                num_a = nums[i];

                for (int j = i + 1; j < nums.size(); j++) {
                    num_b = nums[j];

                    if (num_a + num_b == target) {
                        result.push_back(i);
                        result.push_back(j);
                        return result; // Assumed that each input has exactly ONE solution
                    }
                }
            }
        }
        return result;
    }
};