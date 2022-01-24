class Solution {
private:
    string s;
    string rec(int &j){
        int num=0;
        string ans="";
        while(j<s.size()){
            if(isdigit(s[j])){
                num=num*10+s[j]-'0';
            }
            else if(s[j]=='['){
                j++;
                string temp=rec(j);
                while(num--){
                    ans+=temp;
                }
                num=0;
            }
            else if(s[j]==']'){
                return ans;
            } 
            else{
                ans+=s[j];
            }
            // cout<<ans<<"\n";
            j++;
        }
        return ans;
    }
public:
    string decodeString(string s) {
        this->s=s;
        int i=0;
        return rec(i);
    }
};
