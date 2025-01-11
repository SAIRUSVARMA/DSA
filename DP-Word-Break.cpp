bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}
//TC:O(N^2)
//SC:O(N) or O(N+K)[ N is the size of dp array and K is the total length of all the words in the dictionary].
//Problem:https://leetcode.com/problems/word-break/description/
