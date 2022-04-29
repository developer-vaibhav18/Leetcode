bool cmp(const vector<int> &v1, const vector<int> &v2){
    return v1[1]<v2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        
        int i=0,j=0,ans=0,n=v.size();
        while(i<n){
            while(i<n && v[i][0]<=v[j][1])i++;
            ans++;
            j=i;
        }
        return ans;
    }
};