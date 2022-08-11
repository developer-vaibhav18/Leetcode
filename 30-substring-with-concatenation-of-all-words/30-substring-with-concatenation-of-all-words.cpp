class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int n = words.size();
        
        unordered_map<string, int> mp, mp2;
        for (int i = 0; i < n; ++i) {
            mp[words[i]]++;
        }
        mp2 = mp;
        vector<int> ans;
        for (int start = 0; start < wordLength; ++start) {
            // cout << 1 << '\n';
            int c = 0;
            for (int i = start; i < s.size(); i += wordLength) {
                string temp = s.substr(i, wordLength);
                
                if (mp2[temp]==0) {
                    while (c > 0) {
                        string temp2 = s.substr(i - c * wordLength, wordLength);
                        mp2[temp2]++;
                        c--;
                        if (temp2 == temp) break;
                    }
                }
                if (mp.find(temp) == mp.end()) continue;
                c++;
                
                mp2[temp]--;
                if (c == n) {
                    ans.push_back(i - (n - 1) * wordLength);
                    string temp = s.substr(i - (n - 1) * wordLength, wordLength);
                    c--;
                    mp2[temp]++;
                }
            }
            mp2 = mp;
        }
        
        return ans;
    }
};