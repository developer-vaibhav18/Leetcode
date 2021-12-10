class Solution {
private:
    int getNumber(char c1,char c2){
        return (c1-'0')*10+(c2-'0');
    }

    bool check(int number){
        return number<=26 && number>=10;
    }
public:
    int numDecodings(string s) {
        int n = s.size(),i;
        
        // long long mod = ;

        long long last=1,sec_last=1;

        if(s[0] == '0')return 0;

        for(i=1;i<n;i++){
    
            long long cur = last;
            if(s[i] == '0')cur=0;
            int prevIndex = i-1;

            int temp = getNumber(s[prevIndex],s[i]);

            if(check(temp)){
                cur = (cur + sec_last);
            }
            else if(s[i] == '0')return 0;

        // cout<<last<<" "<<sec_last<<" "<<cur<<"    ";

            sec_last = last;
            last = cur;
        }

        return last;
    }
};