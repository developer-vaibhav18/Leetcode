class Solution {
public:
    
    long long m = 1e9+7;
    
    int sumSubarrayMins(vector<int>& v) {
        
        long long n = v.size(),ans=0,i;

        stack<long long>st;
        for(i=0;i<=n;i++){
            while(!st.empty() && (i==n || v[i]<=v[st.top()])){
                long long t=st.top();
                st.pop();
                long long l=t-(st.empty()?-1:st.top()),r=i-t;
                ans=(ans+(v[t]*((l*r)%m))%m)%m;
            }
            st.push(i);
        }
        return ans;
        
    }
};

