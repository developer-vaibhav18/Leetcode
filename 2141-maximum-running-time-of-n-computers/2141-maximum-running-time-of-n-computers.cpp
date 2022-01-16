class Solution {
public:
    long long maxRunTime(int n, vector<int>& v) {
        // sort(v.begin(),v.end());
        long long m=v.size(),i,l=1,r=1000000000000000,ans=0,mid,sum=0;
        while(l<=r){
            mid=(l+r)/2;sum=0;
            for(i=0;i<m;i++){
                if(v[i]>mid){
                    sum+=mid;
                }
                else{
                    sum+=v[i];
                }
            }
            if(sum/n>=mid){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};