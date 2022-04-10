struct myComp {
    constexpr bool operator()(
        pair<int, pair<int, int>> const& a,
        pair<int, pair<int, int>> const& b)
        const noexcept
    {
        if(a.first==b.first)return a.second.first < b.second.first;
        return a.first > b.first;
    }
};
  
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, myComp> pq;
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> vis(n,vector<int>(k+1,false));
        for(auto i:v){
            adj[i[0]].push_back({i[1],i[2]});
        }
        for(auto i:adj[src]){
            pq.push({i.second,{k, i.first}});
        }
        vis[src][k]=1;
        int ans=-1;
        while(!pq.empty()){
            auto t=pq.top();pq.pop();
            int node=t.second.second,cur_k=t.second.first,cur_cost=t.first;
            if(node==dst){
                ans=t.first;
                break;
            }
            if(vis[node][cur_k] || cur_k==0)continue;
            vis[node][cur_k]=1;
            for(auto i:adj[node]){
                if(!vis[i.first][cur_k-1]){
                    pq.push({cur_cost+i.second, {cur_k-1, i.first}});
                }
            }
        }
        return ans;
    }
};