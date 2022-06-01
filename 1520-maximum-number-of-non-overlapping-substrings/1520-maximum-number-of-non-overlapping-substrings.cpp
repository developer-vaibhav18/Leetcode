class Solution {
    string s;
    void fill_start(vector<int> &a){
        for(int i=0;i<26;i++){
            for(int j=0;j<s.size();j++){
                if(s[j]==i+'a'){
                    a[i]=j;
                    break;
                }
            }
        }
    }
    
    void fill_end(vector<int> &a){
        for(int i=0;i<26;i++){
            for(int j=s.size()-1;j>=0;j--){
                if(s[j]==i+'a'){
                    a[i]=j;
                    break;
                }
            }
        }
    }
    
    bool condition(vector<pair<int,int>> &v, vector<pair<int,int>> &v2, int left, int right){
        if(v.size())return false;
        if(v2.size()==0)return true;
        if(v2[0].first<=right)return false;
        return true;
    }
    
    void fill_main_range(int &a, int &b, vector<int> &st, vector<int> &end,int i){
        a=st[i];
        b=end[i];
        int t1=a,t2=b;
        for(int i=t1;i<=t2;i++){
            a=min(a,st[s[i]-'a']);
            b=max(b,end[s[i]-'a']);
        }
        while(t1!=a || t2!=b){
            int x=t1,y=t2;
            t1=a;t2=b;
            for(int i = t1; i < x; i++){
                a = min(a, st[s[i]-'a']);
                b = max(b, end[s[i]-'a']);
            }
            
            for(int i = y; i < t2; i++){
                a = min(a, st[s[i]-'a']);
                b = max(b, end[s[i]-'a']);
            }
        }
    }
    
    vector<pair<int,int>> calc(int i, int j, vector<int> &a, vector<int> &b, 
                               char prev,vector<vector<int>> &mp){
        vector<pair<int,int>> best;
        for(int k = i; k < j; k++) {
            if(s[k] == prev){
                return best;
            }
            int left = a[s[k]-'a'];
            int right = b[s[k]-'a'];
            if(left >= i && right < j){
                if(mp[s[k]-'a'].size()==1){
                    // cout<<i<<' '<<j<<' '<<s[k]<<'\n';
                    best.push_back({k,k});
                    continue;
                }
                
                int nxt = 1;
                
                vector<pair<int,int>> v;
                while(nxt < mp[s[k]-'a'].size()){
                    vector<pair<int,int>> t = calc(mp[s[k]-'a'][nxt-1]+1, mp[s[k]-'a'][nxt], a, b, s[k], mp);
                    v.insert(v.end(), t.begin() , t.end());
                    nxt++;
                }
                
                vector<pair<int,int>> v2 = calc(mp[s[k]-'a'][nxt-1]+1, j, a, b, s[k], mp);
                if(condition(v, v2, left, right)){
                    best.push_back({left, right});
                }
                best.insert(best.end(), v.begin(), v.end());                
                best.insert(best.end(), v2.begin(), v2.end());
                return best;
            }
        }
        return best;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        this->s=s;
        vector<int> st(26,-1),end(26,-1);
        fill_start(st);
        fill_end(end);
        
        vector<int> a(26),b(26);
        for(int i=0;i<26;i++){
            if(st[i]==-1)continue;
            fill_main_range(a[i],b[i],st,end,i);
        }
        
        vector<vector<int>> mp(26);
        for(int i = 0; i < s.size(); i++){
            mp[s[i]-'a'].push_back(i);
        } 
        
        vector<pair<int,int>> temp = calc(0,s.size(),a,b,' ',mp);
        
        vector<string> ans;
        for(auto i: temp){
            ans.push_back(s.substr(i.first, i.second-i.first+1));
        }
        return ans;
    }
};