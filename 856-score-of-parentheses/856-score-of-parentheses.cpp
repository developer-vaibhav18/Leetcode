class Solution {
private:
    string s;
    int rec(int &i){
        int c=0,ans=0;
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                if(s[i]==')'){
                    ans+=1;
                    continue;
                }
                ans+=(2*rec(i));
            }
            else{
                if(i+1<s.size() && s[i+1]=='('){
                    i++;
                    return ans+rec(i);
                }
                i++;
                return ans;
            }
        }
        return ans;
    }
public:
    int scoreOfParentheses(string s) {
        this->s=s;
        int i=0;
        return rec(i);
    }
};