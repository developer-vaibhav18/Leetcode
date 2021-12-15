class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) { 
        int n = nums.size(),i,j,mx=1,ans=1;
        vector<int> cnt(n,1),lis(n,1);
        for(i=1;i<n;i++){
            for(j=i-1;j>=0;j--){
                if(nums[i]>nums[j] && lis[i]<lis[j]+1){
                    lis[i]=lis[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(nums[i]>nums[j] && lis[i]==lis[j]+1){
                    cnt[i]+=cnt[j];
                }
            }
            // cout<<lis[i]<<" "<<cnt[i]<<"\n";
            if(mx<lis[i]){
                mx=lis[i];
                ans=cnt[i];
            }
            else if(mx==lis[i]){
                ans+=cnt[i];
            }
            // cout<<ans<<" ";
        }
        return ans;
        // vector<int> temp;
//         int ans=1,c=1,i,n=nums.size(),j,idx=0,size=1;
//         int pre[n],lis[n];
//         pre[0]=0;
//         lis[0]=1;
//         for(i=1;i<n;i++){
//             pre[i]=i;
//             lis[i]=1;
            
//             for(j=i-1;j>=0;j--){
//                 if(nums[i]>nums[j] && lis[i]<=lis[j]+1){
//                     pre[i]=j;
//                     lis[i]=lis[j]+1;
//                 }
//             }
            
//             if(lis[i]>size){
//                 size = lis[i];
//                 idx = i;
//             }
//         }
//         // cout<<size;
//         i = n-1;
//         j = pre[idx];
//         // cout << idx << " " << j << "\n";
//         while(i>=0){
//             if(i==j){
//                 j = pre[j];
//                 ans*=c;
//                 c=1;
//             }
//             else if(nums[i]>=nums[j]){
//                 c++;
//             }
//             i--;
//         }
//         return ans;
        
        
    }
};