class Solution {
public:
    int nthUglyNumber(int n) {
        
        
    
        set<long long int>st1;
        set<long long int>st2;
        
        st1.insert(1);
        st2.insert(1);
        
        
        while(st2.size()<=1690)
        {
            long long int x = *st1.begin();
            st1.erase(st1.begin());
            for(auto i:{2,3,5})
            {
                long long int t=i*x;
                if(t<=INT_MAX){
                    st1.insert(t);
                    st2.insert(t);
                }
            }   
        }
        
        int count=1;
        int ans;
        while(count<n)
        {
            // cout<<pq.top()<<" "<<count<<endl;
            st2.erase(st2.begin());
            count++;
        }
        
        return *st2.begin();;
    }
};