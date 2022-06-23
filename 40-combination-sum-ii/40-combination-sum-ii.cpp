class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int tar) {
        sort(v.begin(),v.end());
        vector<vector<int>> res;
        vector<int> t;
        aux(v,res,t,tar);
        return res;
    }
private:
    void aux(vector<int> &v,vector<vector<int>> &res,vector<int> &t,int tar,int i=0){
        if(tar==0){
            res.push_back(t);
            return;
        }
        int j;
        for(j=i;j<v.size();j++){
            if(tar-v[j]<0){
                return;
            }
            if(j!=i && v[j]==v[j-1]){
                continue;
            }
            t.push_back(v[j]);
            aux(v,res,t,tar-v[j],j+1);
            t.pop_back();
        }
    }
};