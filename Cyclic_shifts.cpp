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
 
int main(){
    // clock_t tStart = clock();
    // file;
    f;
 
    int t;
    unsigned short int n,m;
    char c;
    cin>>t;
    unsigned short int x;
    while(t--){
    	cin>>n>>m>>c;
    	if(c=='L'){
    		x = (n<<m)|(n>>(16-m));
    	}
    	else{
    		x = ((n>>m)|(n<<(16-m)));
    	}
    	cout<<x<<"\n";
    }
 
    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
