class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int idx=max_element(nums.begin(),nums.end())-nums.begin();
        int j=idx-1,n=nums.size();
        if(j<0)j=n-1;
        vector<int> ans(n);
        ans[idx]=-1;
        stack<int> st;
        st.push(nums[idx]);
        while(j!=idx){
            while(!st.empty() && st.top()<=nums[j]){
                st.pop();
            }
            if(st.empty()){
                ans[j]=-1;
            }
            else{
                ans[j]=st.top();
            }
            st.push(nums[j]);
            j--;
            if(j<0)j=n-1;
        }
        return ans;
    }
};

// 3,1,2,3,4