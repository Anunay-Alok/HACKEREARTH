#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 1000001
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b,c) for(ll i=a;(c)?i<(ll)b:i>=(ll)b;(c)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(1e9+7)
#define all(a,b) memset(a,b,sizeof(a))
 
void multiply(ll a[2][2], ll b[2][2]) {
    ll mul[2][2]; 
    for (ll i = 0; i < 2; i++) { 
        for (ll j = 0; j < 2; j++){ 
            mul[i][j] = 0; 
            for (ll k = 0; k < 2; k++){ 
                mul[i][j] += (a[i][k]*b[k][j])%(mod);
                mul[i][j] %= (mod);
            }
        } 
    } 
    for (ll i=0; i<2; i++) 
        for (ll j=0; j<2; j++) 
            a[i][j] = mul[i][j];
} 
 
ll modpow(ll a,ll b){
    a%=mod;
    ll res = 1LL;
    while(b>0){
        if(b&1) res = (res * a) % mod;
        a = (a*a) % mod;
        b >>= 1LL;
    }
    return res;
}
 
ll invModulo(ll A)
{
    return modpow(A,mod-2);
}
 
void findPow(ll M[2][2],ll exp){
    ll res[2][2] = {{1LL,0LL},{0LL,1LL}};
    while(exp>0){
        if(exp&1) multiply(res,M);
        multiply(M,M);
        exp >>= 1LL;
    }
    for (ll i=0; i<2; i++) 
        for (ll j=0; j<2; j++) 
            M[i][j] = res[i][j];
}
 
int main(){
    // clock_t tStart = clock();
    // file;
    fast;
    int t;
    ll n;
    cin>>t;
    while(t--){
    ll M[2][2] = {{1LL,1LL},{1LL,0LL}};
        cin>>n;
        findPow(M,n-1);
        cout<<((M[0][0]*2LL + M[0][1]*1LL)%mod)<<"\n";
    }
 
    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
