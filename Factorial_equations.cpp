#include<bits/stdc++.h>
#define ll long long int
#define mod (ll)(10)
using namespace std;
 
ll getpow(ll x,ll n){
    ll temp = 1;
    for(int i=0;i<n;i++){
        temp = (temp%mod * x%mod)%mod;
    }
    return temp;
}
 
int main(){
    ll x,n;
    ll fact[5] = {1,1,2,6,24};
    cin>>x>>n;
    if(n>=5){
        cout<<1<<"\n";
    }
    else{
        ll ans = getpow(x,fact[n])%mod;
        cout<<ans<<"\n";
    }
}
