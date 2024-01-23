/*
 * Author:
 * Date:Muxtorov Abdulaziz
 * Name:
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int task_3 () {
    Solution sol;

    string s1 = "newuzbekistan";
    vector<string> wordDict1 = {"new", "uzbekistan"};
    cout << boolalpha << sol.wordBreak(s1, wordDict1) << endl;

    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << boolalpha << sol.wordBreak(s2, wordDict2) << endl;

    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << boolalpha << sol.wordBreak(s3, wordDict3) << endl;

    return 0;
}
