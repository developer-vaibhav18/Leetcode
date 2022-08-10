class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> f;
        int left = 0;
        int n = s.size(), ans = 0;
        
        for (int right = 0; right < n; ++right) {
            int pos = s[right] - 'a';
            f[pos]++;
            if (f[pos] == 2) {
                while (left < right) {
                    int pos = s[left] - 'a';
                    f[pos]--;
                    ++left;
                    if (s[left - 1] == s[right])break;
                }
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};