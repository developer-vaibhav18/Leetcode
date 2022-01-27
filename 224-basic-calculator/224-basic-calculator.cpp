class Solution {
private:
    string s;
    int rec(int &i){
        int j,ans=0,n=0,sign=1,pre=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            if(s[i]=='('){
                i++;
                n=rec(i);
                continue;
            }
            else if(s[i]==')'){
                i++;
                ans+=sign*n;
                return ans;
            }
            else if(isdigit(s[i])){
                n=n*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                ans+=sign*n;
                sign=1;
                n=0;
            }
            else{
                ans+=sign*n;
                n=0;
                sign=-1;
            }   
            i++;
        } 
        ans+=sign*n;
        return ans;
    }
public:
    int calculate(string s) {
        this->s=s;
        int i=0;
        return  rec(i);
    }
};