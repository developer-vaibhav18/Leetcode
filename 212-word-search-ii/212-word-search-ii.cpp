class trie{
public:
    bool isEnd;
    trie* child[26];
    int c;
    trie(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        c=0;
    }
};

class Solution {
private:
    vector<string> ans;
    vector<vector<char>> board;
    vector<vector<bool>> vis;
    int n,m,i,j;
    void addWord(trie *root, string &s){
        for(auto c:s){
            int pos=c-'a';
            if(root->child[pos]==NULL){
                root->child[pos]=new trie(); 
            }
            root->child[pos]->c++;
            root=root->child[pos];
        }
        root->isEnd=true;
    }
    int dfs(trie* root,int i,int j,string &cur){
        int ret=0;
        if(root->isEnd){
            ans.push_back(cur);
            ret=1;
            root->isEnd=false;
        }
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j])return ret;
        int pos=board[i][j]-'a';
        if(root->child[pos] && root->child[pos]->c){
            vis[i][j]=true;
            cur+=board[i][j];
            ret+=dfs(root->child[pos],i,j+1,cur)+
                dfs(root->child[pos],i+1,j,cur)+
                dfs(root->child[pos],i,j-1,cur)+
                dfs(root->child[pos],i-1,j,cur);
            root->c-=ret;
            vis[i][j]=false;
            cur.pop_back();
        }
        // cout<<i<<" "<<j<<' '<<ret<<'\n';
        return ret;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& v) {
        this->board=board;
        trie* root=new trie();
        for(auto s:v){
            addWord(root,s);
        }
        n=board.size(),m=board[0].size();
        vis.resize(n,vector<bool>(m,false));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                string cur="";
                dfs(root,i,j,cur);
            }
        }
        return ans;
    }
};