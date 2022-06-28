class Solution {
    int findPos(char c){
        return c-'a';
    }
    
    vector<int> findCount(string &s){
        vector<int> ans(26);
        for(auto c:s){
            int pos = findPos(c);
            ans[pos]++;
        }
        return ans;
    }
    
    int findAllNonZeros(vector<int> &cnt){
        int ans=0 ;
        for(auto i:cnt){
            ans+=(i>0);
        }
        
        return ans;
    }
public:
    int numSplits(string s) {
        int ans = 0;
        vector<int> cnt = findCount(s);
        vector<int> temp(26);
        int uniqueRight = findAllNonZeros(cnt);
        int uniqueLeft = 0;
        
        bool pos = false;
        for(auto c:s){
            int pos = findPos(c);
            --cnt[pos];temp[pos]++;
            if(cnt[pos]==0)uniqueRight--;
            if(temp[pos]==1)uniqueLeft++;
            if(uniqueLeft == uniqueRight)++ans;
        }
        
        return ans;
    }
};