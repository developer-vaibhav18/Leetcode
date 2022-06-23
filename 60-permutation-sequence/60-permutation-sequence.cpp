class Solution {
public:
    string getPermutation(int n, int k) {
        string a = "";
        for(int i = 1; i <= n; ++i){
            char ch = i + '0';
            a.push_back(ch);
        }
        while(--k && next_permutation(a.begin(), a.end()));
        return a;
//         while(k){
//             int fact = 1, i = 1;
//             while(fact < k){
//                 ++i;
//                 fact *= i;
//             }
            
//             if(fact == k){
//                 reverse(a.end() - i, a.end());
//                 return a;
//             }
//             fact/=i;
//             --i;
//             int cnt = k/fact;
//             k%=fact;
//         }
        
    }
};