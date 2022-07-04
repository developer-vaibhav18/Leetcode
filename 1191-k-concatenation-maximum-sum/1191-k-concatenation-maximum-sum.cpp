class Solution {
private:
    const int mod = 1e9+7;
    
    long long kadane(vector<int> &arr){
        long long ans=0, tillNow=0;
        
        for(auto i:arr){
            tillNow = tillNow + (long long)i;
            if(tillNow<0)tillNow = 0;
            ans = max(ans, tillNow);
        }

        return ans;
    }
    
    long long pre(vector<int> &arr){
        long long ans = 0, s = 0;
        for(auto i:arr){
            s+=i;
            ans = max(ans, s);
        }
        
        return ans;
    }
    
    long long suf(vector<int> &arr){
        long long ans = 0, s = 0;
        for(int i=arr.size() - 1;i >= 0;i--){
            s+=arr[i];
            ans=max(ans, s);
        }
        
        return ans;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(k==1){
            return kadane(arr);
        }
        int sum = accumulate(arr.begin(), arr.end(), 0);
        long long ans = ((long long)sum * (long long)k);
        
        if(k>3)
            ans = max(ans, pre(arr) + suf(arr) + (k - 2)*((long long)sum));
        arr.insert(arr.end(), arr.begin(), arr.end());
        
        ans = max(ans, kadane(arr));
        // cout << ans << ' ';
        // cout << pre(arr) << ' ' << suf(arr) << '\n';
        
        return ans%mod;
    }
};