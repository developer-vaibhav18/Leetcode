class Solution {
private:
    int fun(char op){
        if(op=='+' || op=='-')return 0;
        return 1;
    }
    long long fun2(long long n1,long long n2,char op){
        if(op=='+')return n1+n2;
        if(op=='-')return n1-n2;
        if(op=='*')return n1*n2;
        if(op=='/')return n1/n2;
        return 0;
    }
public:
    int calculate(string s) {
        stack<long long> st;
        stack<char> op;
        long long i,n=s.size(),num=0;
        for(i=0;i<=n;i++){
            if(i<n && s[i]==' ')continue;
            if(i<n && isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            else{
                st.push(num);
                while(!op.empty() && (i==n || fun(s[i])<=fun(op.top()))){
                    long long t1=st.top();st.pop();
                    long long t2=st.top();st.pop();
                    st.push(fun2(t2,t1,op.top()));
                    op.pop();
                }
                if(i<n)op.push(s[i]);
                num=0;
            }
        }
        return st.top();
    }
};