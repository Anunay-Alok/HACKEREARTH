#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 1000001
#define f ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b,c) for(ll i=a;(c)?i<(ll)b:i>=(ll)b;(c)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(1e9+7)
#define all(a,b) memset(a,b,sizeof(a))
 
ll tree[4*MAX_SIZE],lazy[4*MAX_SIZE];
void build(ll pre[], ll v, ll tl, ll tr)
{
    if(tl==tr){
        tree[v] = pre[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    build(pre, 2*v, tl, tm);
    build(pre, 2*v+1, tm+1, tr);
    tree[v] = max(tree[2*v], tree[2*v+1]);
}
// void push(ll v)
// {
//     tree[2*v] += lazy[v];
//     lazy[2*v] += lazy[v];
//     tree[2*v+1] += lazy[v];
//     lazy[2*v+1] += lazy[v];
//     lazy[v]=0;
// }
void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
    if(l<=r){
        if(l==tl && tr==r){
            tree[v] += add;
            // lazy[v] += add;
        }
        else {
            // push(v);
            ll tm = (tl+tr)/2;
            update(2*v, tl, tm, l, min(r, tm), add);
            update(2*v+1, tm+1, tr, max(l, tm+1), r, add);
            tree[v] = max(tree[2*v], tree[2*v+1]);
        }
    }
}
 
ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l>r) return INT64_MIN;
    if(l==tl && r==tr) return tree[v];
    // push(v);
    ll tm = (tl+tr)/2;
    return max(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
 
}
 
int main(){
    // clock_t tStart = clock();
    // file;
    f;
    ll t,n,k;
    cin>>t;
    while(t--){
        // memset(lazy,0,sizeof(lazy));
        cin>>n>>k;
        ll ar[n];
        FOR(i,0,n,1) cin>>ar[i];
        ll pre[n]={0};
        build(pre,1,0,n-1);
        FOR(i,n-1,0,0){
            if(i+k+1>=n)
                pre[i]=max(0LL,ar[i]);
            else{
                ll l=((i+k+1)>=n)?(n-1):(i+k+1);
                ll r=((i+2*k+1)>=n)?(n-1):(i+2*k+1);
                ll x = query(1,0,n-1,l,r);
                pre[i]=max(0LL,max(x,ar[i]+x));
            }
            update(1,0,n-1,i,i,pre[i]);
        }
        ll maxm = INT64_MIN;
        FOR(i,0,n,1)  maxm=max(maxm,pre[i]);
        cout<<maxm<<"\n";
    }
 
 
    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
