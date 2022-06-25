// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    private:
        static bool comparator(const Job &j1, const Job &j2){
            return j1.dead < j2.dead;
        }
        // struct pqComparator {
        //     bool operator()(Job const& j1, Job const& j2)
        //     {
        //         // return "true" if "p1" is ordered
        //         // before "p2", for example:
        //         return j1.profit < j2.profit;
        //     }
        // };
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, comparator);
        
        priority_queue<int> pq;
        
        int ptr = n - 1;
        int mx = arr[n - 1].dead;
        vector<int> ans = {0, 0};
        while(mx>0){
            while(ptr>=0 && arr[ptr].dead == mx){
                pq.push(arr[ptr].profit);
                --ptr;
            }
            if(!pq.empty()){
                ++ans[0];
                ans[1]+=pq.top();
                pq.pop();
            }
            --mx;
        }
        
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends