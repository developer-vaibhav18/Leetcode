class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n = p.size(), i, ans=0;
        double mx = 0.0;
        vector<pair<int, int> > v(n);
        for(i = 0;i < n; i++){
            v[i].first = p[i];
            v[i].second = s[i];
        }
        
        sort(v.begin(), v.end());
        for(i=n-1; i>=0; i--){
            double pos = v[i].first, speed = v[i].second;
            double time = (((double)target) - pos)/speed;
            if(time > mx){
                mx = time;
                ans++;
            }
        }
        return ans;
    }
};