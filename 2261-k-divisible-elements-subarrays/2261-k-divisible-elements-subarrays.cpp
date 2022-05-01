class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size(),i,j,ans=0,x;
        set<vector<int>> s;
        for(i=0;i<n;i++){
            int c=0;
            vector<int> v;
            for(j=i;j<n;j++){
                if(nums[j]%p==0)c++;
                if(c>k)break;
                v.push_back(nums[j]);
                s.insert(v);
            }
        }
        return s.size();
    }
};