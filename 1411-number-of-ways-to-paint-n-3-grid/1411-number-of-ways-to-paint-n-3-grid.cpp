#define ll long long int

ll mod = 1000000007;

class Solution {
private:
    vector<vector<long long>> tri;
    void gen(){
        for(int first=0;first<3;first++){
            for(int second=0;second<3;second++){
                if(first==second)continue;
                for(int third=0;third<3;third++){
                    if(third==second)continue;
                    tri.push_back({first,second,third});
                }
            }
        }
    }
    
    bool isValid(vector<long long> &a,vector<long long> &b){
        if(a[0]==b[0] || a[1]==b[1] || a[2]==b[2])return false;
        return true;   
    }
public:
    int numOfWays(int n) {
        gen();
        int sz=tri.size();
        vector<ll> dp1(sz,1);
        for(int row=2;row<=n;row++){
            vector<ll> dp2(sz,0);
            for(int pre=0;pre<sz;pre++){
                for(int cur=0;cur<sz;cur++){
                    if(isValid(tri[pre],tri[cur])){
                        dp2[cur]=(dp2[cur]+dp1[pre])%mod;
                    }
                }
            }
            dp1=dp2;
        }
        return accumulate(dp1.begin(),dp1.end(),0L)%mod;
    }
};