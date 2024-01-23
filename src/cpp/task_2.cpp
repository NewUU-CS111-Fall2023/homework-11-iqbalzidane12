/*
 * Author:
 * Date:abdulaziz
 * Name:
 */

#include <vector>

class task_2 {
public:
    bool canPartition(std::vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        if (total_sum % 2 != 0) {
            return false;
        }

        int subset_sum = total_sum / 2;
        std::vector<bool> dp(subset_sum + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int _sum = subset_sum; _sum >= num; --_sum) {
                dp[_sum] = dp[_sum] || dp[_sum - num];
                if (dp[subset_sum]) {
                    return dp[subset_sum];
                }
            }
        }

        return dp[subset_sum];
    }
};
