class BookMyShow {
private:
    long long int n,m,y=0;
    long long int t[200013],a[100000],t2[200013];
    void build(long long int a[], long long int v, long long int tl, long long int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            long long int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    long long int sum(long long int v, long long int tl, long long int tr, long long int l, long long int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        long long int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
               + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    void update(long long int v, long long int tl, long long int tr, long long int pos, long long int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            long long int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
     void build2(long long int a[], long long int v, long long int tl, long long int tr) {
        if (tl == tr) {
            t2[v] = a[tl];
        } else {
            long long int tm = (tl + tr) / 2;
            build2(a, v*2, tl, tm);
            build2(a, v*2+1, tm+1, tr);
            t2[v] = max(t2[v*2], t2[v*2+1]);
        }
    }
    long long int query(long long int v, long long int tl, long long int tr, long long int l, long long int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t2[v];
        }
        long long int tm = (tl + tr) / 2;
        return max(query(v*2, tl, tm, l, min(r, tm))
               , query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    void update2(long long int v, long long int tl, long long int tr, long long int pos, long long int new_val) {
        if (tl == tr) {
            t2[v] = new_val;
        } else {
            long long int tm = (tl + tr) / 2;
            if (pos <= tm)
                update2(v*2, tl, tm, pos, new_val);
            else
                update2(v*2+1, tm+1, tr, pos, new_val);
            t2[v] = max(t2[v*2], t2[v*2+1]);
        }
    }
public:
    BookMyShow(int n, int m) {
        this->n=n;
        this->m=m;
        y=0;
        for(int i=0;i<n;i++){
            a[i]=m;
        }
        for(int i=0;i<4*n+5;i++){
            t[i]=0;
            t2[i]=0;
        }
        build(a,1,0,n-1);
        build2(a,1,0,n-1);
        // for(int i=0;i<4*n;i++){
        //     cout<<t[i]<<' ';
        // }
        // cout<<'\n';
        // for(int i=0;i<4*n;i++){
        //     cout<<t2[i]<<' ';
        // }
    }
    
    vector<int> gather(int k, int maxRow) {
        vector<int> anss;
        long long l=0,r=maxRow,ans=maxRow+1;
        while(l<=r){
            long long mid=(l+r)/2;
            long long mx=query(1,0,n-1,0,mid);
            if(mx>=k){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==maxRow+1)return anss;
        anss.push_back(ans);
        anss.push_back(m-a[ans]);
        a[ans]=a[ans]-k;
        update(1,0,n-1,ans,a[ans]);
        update2(1,0,n-1,ans,a[ans]);
        return anss;
    }
    
    bool scatter(int k, int maxRow) {
        long long l=0,r=maxRow,ans=maxRow+1,x=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            long long summ=sum(1,0,n-1,0,mid);
            if(summ>=k){
                r=mid-1;
                ans=mid;
                x=summ;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==maxRow+1)return false;
        int i;
        for(i=y;i<ans;i++){
            a[i]=0;
            update(1,0,n-1,i,a[i]);
            update2(1,0,n-1,i,a[i]);
        }
        y=max(y,ans);
        if(x==k){
            a[i]=0;
            update(1,0,n-1,i,a[i]);
            update2(1,0,n-1,i,a[i]);
            y=max(y,ans+1);
        }
        else{
            a[i]=x-k;
            update(1,0,n-1,i,a[i]);
            update2(1,0,n-1,i,a[i]);
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */