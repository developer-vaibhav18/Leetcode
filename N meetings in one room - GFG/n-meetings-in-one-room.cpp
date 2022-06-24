// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int dp[n + 1];
        dp[0] = 0;
        vector<pair<int, int>> v(n);
        
        for(int i = 0; i < n; ++i){
            v[i] = {end[i], start[i]};
        }
        
        sort(v.begin(), v.end());
        
        for(int i = 0; i < n; ++i){
            start[i] = v[i].second;
            end[i] = v[i].first;
        }
        
        for(int i = 1; i <= n; ++i){
            int prevIndex = i - 1;
            int startPointer = lower_bound(end, end + n, start[prevIndex]) - end;
            dp[i] = max(dp[prevIndex], dp[startPointer] + 1);
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends