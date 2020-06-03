#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    ans += (n*(n+1))/2;
    ll multiplesOfK = n/k;
    ans-=k*((multiplesOfK * (multiplesOfK+1))/2);
 
    ll kthpow = 1;
    vector<ll> vec;
    while(1){
        if(pow(k,kthpow) > n)
            break;
        vec.emplace_back(pow(k,kthpow));
        kthpow++;
    }
    for(auto u : vec){
        ll tempAgain = n/u;
        ans += (tempAgain*(tempAgain+1))/2;
        ll tempAgain2 = tempAgain/k;
        ans -= k*(tempAgain2*(tempAgain2+1))/2;
    }
    cout<<ans<<"\n";
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
