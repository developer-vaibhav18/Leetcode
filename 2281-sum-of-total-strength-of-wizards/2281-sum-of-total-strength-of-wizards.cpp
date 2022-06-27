class Solution {
private:
    vector<long long> prePre, pre, sufSuf, suf;
    long long mod = 1000000007;
    long long queryP(long long i, long long j){
        if(i > j)return 0;
        long long ans = (prePre[j]-prePre[i-1])%mod;
        if(ans < 0)ans += mod;
        (ans -= pre[i-1]*(j-i+1))%=mod;
        if(ans < 0)ans += mod;
        return ans;
    }
    
    long long queryS(long long i, long long j){
        if(i > j)return 0;
        long long ans = (sufSuf[i] - sufSuf[j + 1])%mod;
        if(ans < 0)ans += mod;
        
        (ans -= suf[j + 1]*(j - i + 1))%=mod;
        if(ans < 0)ans += mod;
        
        return ans;
    }
    
    void fillPre(vector<long long> &pre, vector<long long> &v, int n, bool b){
        for(int i = 1; i <= n; ++i){
            pre[i] = (pre[i - 1] + v[i - 1 + b])%mod;
        }
    }
    
    void fillSuf(vector<long long> &suf, vector<long long> &v, int n){
        
        for(int i = n - 1 ; i >= 0 ; --i){
            suf[i] = (suf[i + 1] + v[i])%mod;
        }
    }
    
public:
    int totalStrength(vector<int>& v2) {
        int n = v2.size();
        vector<long long> v(n);
        
        for(int i = 0; i < n; ++i){
            v[i] = v2[i];
        }
        
        prePre.resize(n + 1, 0);
        pre.resize(n + 1, 0);
        suf.resize(n + 1, 0);
        sufSuf.resize(n + 1, 0);
        
        fillSuf(suf, v, n);
        fillSuf(sufSuf, suf, n);
        fillPre(pre, v, n, false);
        fillPre(prePre, pre, n, true);
        
        long long ans = 0;
        
        stack<long long> st;
        
        for(long long i = 1; i <= n; ++i){
            while(!st.empty() && v[st.top() - 1] >= v[i - 1]){
                long long t = st.top();st.pop();
                long long mn = v[t - 1];
                long long l1 = t + 1;
                long long r1 = i - 1;
                long long q1 = queryP(l1, r1);
                
                long long l2 = st.empty() ? 0 : st.top();
                long long r2 = t - 2;
                long long q2 = queryS(l2, r2);
                
                (ans += (((q1 * (r2 - l2 + 2)) % mod + q2 * (r1 - l1 +2) % mod) % mod) * mn % mod )%= mod;
                // cout << ans << '\n';
                
                (ans += ((mn * mn)%mod * ((r2 - l2 + 2) * (r1 -l1 + 2)) %mod) % mod)%=mod;
            }
            st.push(i);
        }
        long long i = n + 1;
        while(!st.empty()){
            long long t = st.top();st.pop();
            long long mn = v[t - 1];
            long long l1 = t + 1;
            long long r1 = i - 1;
            long long q1 = queryP(l1, r1);
            // (ans += (q1 * mn) % mod)%=mod;

            long long l2 = st.empty() ? 0 : st.top();
            long long r2 = t - 2;
            long long q2 = queryS(l2, r2);

            (ans += (((q1 * (r2 - l2 + 2)) % mod + q2 * (r1 - l1 +2) % mod) % mod) * mn % mod )%= mod;
            (ans += ((mn * mn)%mod * ((r2 - l2 + 2) * (r1 -l1 + 2)) %mod) % mod)%=mod;
        }
        
        return ans;
    }
};