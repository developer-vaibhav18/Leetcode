class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n=v.size(),i,j;
        
        for(i=0;i<n/2;i++){
            for(j=i;j<n-i-1;j++){
                swap(v[i][j],v[j][n-i-1]);
                swap(v[i][j],v[n-i-1][n-j-1]);
                swap(v[i][j],v[n-j-1][i]);
            }
        }
        
        
    }
};