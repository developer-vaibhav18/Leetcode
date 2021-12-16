
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long l = primes.size();
        vector<long long>dp(n,0);
        dp[0]=1;
        priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>>pq;
       
        for(int i=0;i<l;i++){
            pq.push({primes[i],{0,i}});
        }
        
        for(int i=1;i<n;i++)
        {
            auto x = pq.top();
            pq.pop();
            dp[i]=x.first;
            x.second.first++;
            x.first=dp[x.second.first]*primes[x.second.second];
            pq.push(x);
            if(dp[i]==dp[i-1])i--;
        }
        
        // for(auto k:dp)
        // {
        //     cout<<k<<" ";
        // }
        
        return dp[n-1];
        
        
    }
    
};