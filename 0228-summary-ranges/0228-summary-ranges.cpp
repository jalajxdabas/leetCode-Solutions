#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        if (nums.empty()) {
            return result;
        }

        for (int i = 0; i < nums.size();) {
            int start = nums[i];
            int j = i;
            // Expand the range as long as elements are consecutive
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) {
                j++;
            }

            // Format the range string
            if (nums[j] == start) {
                result.push_back(std::to_string(start));
            } else {
                result.push_back(std::to_string(start) + "->" + std::to_string(nums[j]));
            }
            
            // Move to the next potential start of a range
            i = j + 1;
        }
        return result;
    }
};