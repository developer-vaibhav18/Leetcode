#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class SORTracker {
    int i;
    ordered_set<pair<int,string>> s;    
public:
    SORTracker() 
	{ i = 0; }
    
    void add(string name, int score) 
	{ s.insert({-score,name}); }
    
    string get() 
	{ return s.find_by_order(i++)->second; }
};