#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,a,b) for(int i = a;i<b;i++)
#define setCount(x) __builtin_popcountll(x)
 
ll log2n(ll n) 
{ 
    return (n > 1) ? 1 + log2n(n / 2) : 0; 
} 
 
 
ll solve(ll l, ll r){
    if(l==r) return 1LL;
    if(l==0) return (solve(1LL,r) + 1LL);
    ll y = (1LL << (ll)(log2n(l^r)+1LL)) - 1LL;
    l &= y;
    r &= y;
    if(l==r) return 1LL;
    if(l==0) return (solve(1LL,r) + 1LL);
    if(l==1LL) return (1LL << ((ll)(log2n(r)) + 1LL)) - 1LL;
    if(setCount(r)==1)
        return (2LL * (r - l) + 1LL);
    ll x = (ll)log2n(r);
    ll temp1 = (1LL << x);//
    x = temp1 - 1LL;//255
    x = ((x - l + 1LL)<<1LL) + 1LL;//507
    ll temp2 = temp1 + l; //259
    if(r >= temp2){
        return x + (l - 1LL);
    }
    ll ans = solve(1LL,r - temp1);
    if(temp1 + ans >= temp2) return x + l - 1LL;
    return x + ans;
}
 
int main(){
    ll l,r;
    cin>>l>>r;
    cout<<solve(l,r)<<"\n";
}
