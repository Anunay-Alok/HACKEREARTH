#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 1000001
#define debug(x) cout<<#x<<" "<<x<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b,c) for(ll i=a;(c)?i<(ll)b:i>=(ll)b;(c)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(1e9+7)
#define all(a,b) memset(a,b,sizeof a)
 
vector<ll>v1,v2,v3,v4;
 
void classify(int * ar,int n){
	ll i=1;
    int flag=0;
    while(i<n){
        if(flag){
            if(!(ar[i]>ar[i-1])/*false condition*/){
                v2.eb(i-1);
                flag=0;
            }
        }
        else{
            if(ar[i]>ar[i-1]/*true condition i.e., start*/){
                flag=1;
                v1.eb(i-1);
            }
        }
        i++;
    }
    if(flag==1){
        if(ar[n-1]>ar[n-2] /*true condition*/) v2.eb(n-1);
    }
}
//clear vectors for testcases
 
int main(){
    // clock_t tStart = clock();
    // file;
    fast;
 
    int n;
    cin>>n;
    int ar[n+2];
    ar[0] = INT_MIN;
    FOR(i,1,n+1,1) cin>>ar[i];
    ar[n+1] = INT_MAX;
    // int ar[n];
    // FOR(i,0,n,1) cin>>ar[i];
    classify(ar,n+2);
    // FOR(i,0,v1.size(),1){
    // 	cout<<v1[i]<<" "<<v2[i]<<"\n";
    // }
    int flag = 0;
    ll maxm = INT_MIN;
    FOR(i,0,v1.size()-1,1){
    	if(v2[i] == v1[i+1]-1 && (ar[v1[i+1]+1] > ar[v2[i]] || ar[v2[i]-1]  < ar[v1[i+1]])){
    		ll newSize = v2[i+1] - v1[i] - (v1[i]==0) - (v2[i+1]==n+1);
    		maxm = max(maxm,newSize);
    		flag = 1;
    	}
    }
    if(!flag){
    	FOR(i,0,v1.size(),1)
    		maxm = max(maxm,(v2[i]-v1[i] + 1 -(v1[i]==0)-(v2[i]==n+1)));
    }
 
    cout<<maxm<<'\n';
 
    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
