class Solution {
    void rotate(string &s, int start, int end){
        int i = start;
        while(i < end){
            swap(s[i], s[end]);
            ++i;
        }
    }
public:
    string getPermutation(int n, int k) {
        string a = "";
        for(int i = 1; i <= n; ++i){
            char ch = i + '0';
            a.push_back(ch);
        }
        // while(--k && next_permutation(a.begin(), a.end()));
        // return a;
        --k;
        while(k){
            int fact = 1, i = 1;
            while(fact <= k){
                ++i;
                fact *= i;
            }
            fact/=i;
            int cnt = k/fact;
            rotate(a, a.size() - i, a.size() - i + cnt);
            k%=fact;
        }
        return a;
        
    }
};