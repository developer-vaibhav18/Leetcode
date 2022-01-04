class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size(), i;
        vector<int> dp1(10005),dp2(10005);
        for(i=0;i<n;i++){
            dp1[v[i][0]]++;
            dp1[v[i][1]+1]--;
            dp2[v[i][1]]++;
        }
        for(i=1;i<=10002;i++){
            dp1[i]+=dp1[i-1];
            if(i<=8){
                // cout<<dp1[i]<<" "<<dp2[i]<<'\n';
            }
        }
        vector<vector<int>> ans;
        // bool inInt = false;
        int st = -1;
        for(i=0;i<=10002;i++){
            if(dp1[i]==dp2[i] && st!=-1){
                ans.push_back({st,i});
                st=-1;
            }
            else if(dp1[i]>0 && dp1[i]==dp2[i]){
                ans.push_back({i,i});
            }
            else if(dp1[i]>0 && st==-1){
                st=i;
            }
        }
        return ans;
    }
};