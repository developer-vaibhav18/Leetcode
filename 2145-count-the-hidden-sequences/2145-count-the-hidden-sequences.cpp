class Solution {
public:
    int numberOfArrays(vector<int>& v, int l, int r) {
        int n=v.size(),i,pre=l,mx=l;
        for(i=0;i<n;i++){
            int cur=pre+v[i];
            if(cur<l){
                mx+=(l-cur);
                cur=l;
            }
            mx=max(mx,cur);
            pre=cur;
            if(mx>r)return 0;
        }
        return r-mx+1;
    }
};