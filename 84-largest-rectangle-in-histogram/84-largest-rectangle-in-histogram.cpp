class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int area=0,n=v.size(),i;
        stack<int> s;
        for(i=0;i<n;i++){
            while(!s.empty() && v[s.top()]>v[i]){
                int t=s.top();
                s.pop();
                area=max(area,(i-1-(s.empty()?-1:s.top()))*v[t]);
            }
            s.push(i);
        }
        i=n;
        // cout<<s.size();
        while(!s.empty()){
            int t=s.top();s.pop();
            area=max(area,(n-1-(s.empty()?-1:s.top()))*v[t]);
            if(!s.empty() && v[s.top()]==v[t])continue;
        }
        return area;
    }
};