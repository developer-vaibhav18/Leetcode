class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size(),i,j;
        bool firstRow=false,firstColumn=false;
        
        for(i=0;i<m;i++){
            if(v[0][i]==0){
                firstRow=true;
                break;
            }
        }
        
        for(i=0;i<n;i++){
            if(v[i][0]==0){
                firstColumn=true;
                break;
            }
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(v[i][j]==0){
                    v[0][j]=0;
                    v[i][0]=0;
                }
            }
        }
        
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(v[0][j]==0 || v[i][0]==0){
                    v[i][j]=0;
                }
            }
        }
        
        if(firstRow){
            for(i=0;i<m;i++){
                v[0][i]=0;
            }
        }
        
        if(firstColumn){
            for(i=0;i<n;i++){
                v[i][0]=0;
            }
        }
    }
};