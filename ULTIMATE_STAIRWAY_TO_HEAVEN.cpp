#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 1000001
#define f ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b) for(ll i=a;i<(ll)b;i++)
#define eb emplace_back
#define mod (ll)(1e9+7)
 
int findSum(vector<ll>&c,int k,int l,int n){
    if(l>=n)
        l=n-1;
    return (c[k+1]%mod-c[l+1]%mod)%mod;
}
 
 
int main(){
    // clock_t tStart = clock();
    // file;
    // f;
    ll n;
    cin>>n;
    vi(a,n);
    vio(b,n,0);vio(c,n+1,0);
    FOR(i,0,n)
        cin>>a[i];
    a[n-1]=b[n-1]=c[n-1]=1;
    for(ll i=n-2;i>=0;i--){
        b[i] = findSum(c,i,i+a[i],n)%mod;
        c[i] = (c[i+1]%mod+b[i]%mod)%mod;
    }
    cout<<(b[0]%mod + mod)%mod<<"\n";
    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
