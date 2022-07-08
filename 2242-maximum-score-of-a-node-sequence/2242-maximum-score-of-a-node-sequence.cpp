class Solution {
private:
    vector<vector<int>> maxThree;
    vector<vector<int>> adj;
    vector<vector<int>> edges;
    vector<int> scores;
    int numberOfNodes;
    int smallest = -1; 
    
    void fillAdj(){
        adj.resize(numberOfNodes);
        
        for(auto &edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            
            adj[node2].push_back(node1);
            adj[node1].push_back(node2);
        }
    }
    
    void fillMaxThree(){
        maxThree.resize(numberOfNodes, vector<int>(3, smallest));
        
        for(int node = 0; node < numberOfNodes; ++node){
            vector<int> &neighbours = adj[node];
            vector<int> &maxThreeOfNode = maxThree[node];
            for(auto neighbour:neighbours){
                // cout << neighbour << ' ';
                if(maxThreeOfNode[0] == -1 || scores[neighbour] > scores[maxThreeOfNode[0]]){
                    maxThreeOfNode[2] = maxThreeOfNode[1];
                    maxThreeOfNode[1] = maxThreeOfNode[0];
                    maxThreeOfNode[0] = neighbour;
                }
                else if(maxThreeOfNode[1] == -1 || scores[neighbour] > scores[maxThreeOfNode[1]]){
                    maxThreeOfNode[2] = maxThreeOfNode[1];
                    maxThreeOfNode[1] = neighbour;
                }
                else if(maxThreeOfNode[2] == -1 || scores[neighbour] > scores[maxThreeOfNode[2]]){
                    maxThreeOfNode[2] = neighbour;
                }
            }
        }
        
    }
    
    int aux(int node1, int node2, vector<int> &maxThreeOfNode1, vector<int> &maxThreeOfNode2){               set<int> notToBeTaken = {node1, node2};
        int ans = 0;                                                                                    
        for(int i = 0; i < 3; ++i){
            int cur = maxThreeOfNode1[i];
            if(notToBeTaken.find(cur) != notToBeTaken.end())continue;
            
            if(cur == -1)return -1;
            ans += scores[cur];
            notToBeTaken.insert(cur);
            break;
        }
        for(int i = 0; i < 3; ++i){
            int cur = maxThreeOfNode2[i];
            if(notToBeTaken.find(cur) != notToBeTaken.end())continue;
            
            if(cur == -1)return -1;
            ans += scores[cur];
            break;
        } 
        return ans;
        
    }
    
    int getMaxPossible(int node1, int node2){
        vector<int> &maxThreeOfNode1 = maxThree[node1];
        vector<int> &maxThreeOfNode2 = maxThree[node2];
        int ans = scores[node1] + scores[node2];

        int t = max(aux(node1, node2, maxThreeOfNode1, maxThreeOfNode2), aux(node2, node1, maxThreeOfNode2, maxThreeOfNode1));
        if(t == -1)return -1;
        return ans + t;
    }
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        numberOfNodes = scores.size();
        this->scores = scores;
        this->edges = edges;
        fillAdj();
        fillMaxThree();
        
        int ans = smallest;
        for(auto &edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            
            ans = max(ans, getMaxPossible(node1, node2));
            // cout << node1 << ' ' << node2 << ' ' << getMaxPossible(node1, node2) << '\n';
        }
        
        return ans;
    }
};