class Solution {
private:
    bool valid(string &s){
        int c=0,i,n=s.size();
        for(i=0;i<n;i++){
            if(s[i]=='('){
                c++;
            }
            else if(s[i]==')'){
                c--;
                if(c<0)return false;
            }
        }
        return c==0;
    }
    set<string> ans;
    int mx;
    string s;
    void rec(int i,char last,stack<int> &st,string &cur){
        if(i==s.size()){
            if(cur.size()==mx && valid(cur))ans.insert(cur);
            return;
        }
        if(s[i]!='(' && s[i]!=')'){
            cur+=s[i];
            rec(i+1,last,st,cur);
            cur.pop_back();
            return;
        }
        rec(i+1,s[i],st,cur);
        if(s[i]==')'){
            if(!st.empty()){
                // if(last!=')'){
                    int t=st.top();st.pop();
                    cur+=s[i];
                    rec(i+1,last,st,cur);
                    cur.pop_back();
                    st.push(t);
                // }
            }
            return;
        }
        // if(last!='('){
            st.push(i);
            cur+=s[i];
            rec(i+1,last,st,cur);
            cur.pop_back();
            st.pop();
        // }
    }
public:
    vector<string> removeInvalidParentheses(string str) {
        int n=str.size(),c=0,i;
        s=str;
        mx=0;
        for(i=0;i<n;i++){
            if(str[i]=='('){
                c++;
            }
            else if(str[i]==')'){
                if(c){
                    mx+=2;
                    c--;
                }
            }
            else{
                mx++;
            }
        }
        // cout<<mx<<"\n";
        stack<int> st;
        string cur="";
        rec(0,'a',st,cur);
        return vector(ans.begin(),ans.end());
    }
};

 