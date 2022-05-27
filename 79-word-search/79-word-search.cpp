class Solution {
private:
    bool isValidRowAndColumn(int cur, int limit){
        return cur>=0 && cur<limit;
    }
    vector<vector<bool>> vis;
    bool helper(vector<vector<char>> &v, string &s, int cur_row, int cur_col, int cur_pos){
        if(cur_pos>=s.size())return true;
        if(!isValidRowAndColumn(cur_row, v.size()) || !isValidRowAndColumn(cur_col, v[0].size())){
            return false;
        }
        
        if(vis[cur_row][cur_col])return false;
        if(s[cur_pos]!=v[cur_row][cur_col]){
            return false;
        }
        vis[cur_row][cur_col]=true;
        if(helper(v,s,cur_row,cur_col+1,cur_pos+1) || helper(v,s,cur_row+1,cur_col,cur_pos+1)
           || helper(v,s,cur_row,cur_col-1,cur_pos+1) || helper(v,s,cur_row-1,cur_col,cur_pos+1))
            return true;
        vis[cur_row][cur_col]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        vis.resize(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(helper(board,word,i,j,0))return true;
            }
        }
        
        return false;
    }
};