class Solution {
    void helper(vector<vector<int>> &res, vector<int>& v, int tar,int idx, vector<int> &cur){
        if(tar == 0){
            res.push_back(cur);
            return;
        }
        if(idx >= v.size() || tar<0){
            return;
        }
        cur.push_back(v[idx]);
        helper(res, v, tar - v[idx], idx, cur);
        cur.pop_back();
        
        helper(res, v, tar, idx + 1, cur);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(res, candidates, target, 0, cur);
        return res;
    }
};