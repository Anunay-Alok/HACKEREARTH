#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 100001
#define debug(x) cout<<#x<<" "<<x<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b,c) for(ll i=a;(c)?i<(ll)b:i>=(ll)b;(c)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(999983)
#define all(a,b) memset(a,b,sizeof a)
int ar[MAX_SIZE];
int visited[MAX_SIZE];
int rotation[MAX_SIZE];
int component[MAX_SIZE];
int flag[MAX_SIZE];
set<int>s1,s2;
int trip;
void dfs(int s,int e,vector<int> *adj,int lvl = 0){
	// if(lvl & 1) s1.insert(s);
	// else s2.insert(s);
    if(!visited[s]){
		rotation[s] = lvl;
		component[s] = trip;
        visited[s]=true;
        for(auto u : adj[s]){
            dfs(u,s,adj,lvl ^ 1);
        }
    }
    else{
    	if(rotation[s] != rotation[e] ^ 1){
    		flag[component[s]] = 1;
    		return;
    	}
    }
}
 
int main(){
    // clock_t tStart = clock();
    // file;
    fast;
 
    all(visited,0);
	int l,r,gp,gf;
    int n,m,q;
    cin>>n>>m>>q;
    FOR(i,0,n,1) cin>>ar[i];
 
    vector<int>adj[n];
    FOR(i,0,m,1){
		cin>>l>>r;
		l--,r--;
		adj[l].eb(r);
		adj[r].eb(l);    	
    }
    trip = -1;
    FOR(i,0,n,1){
		if(!visited[i]){
			trip++;
	    	dfs(i,-1,adj,trip);
		} 
    }
    while(q--){
    	cin>>gp>>gf>>l>>r;
    	gp--,gf--;
    	if(flag[component[gp]] || flag[component[gf]]){
    		cout<<"NO";
    	}
    	else{
    		if(component[gp]!=component[gf]){
    			cout<<"YES";
    		}
    		else{
    			if(ar[gp]==ar[gf]){
	    			if((l!=r && rotation[gp]!=rotation[gf]) ||(l==r && rotation[gp]==rotation[gf])){
	    				cout<<"YES";
	    			}
	    			else cout<<"NO";    				
    			}
    			else{
    				if((l!=r && rotation[gp]==rotation[gf]) ||(l==r && rotation[gp]!=rotation[gf]))
	    				cout<<"YES";
	    			else cout<<"NO";    				
    			}
    		}
    	}
    	cout<<"\n";
    	// if(flag){
    	// 	cout<<"NO\n";
    	// }
    	// else{
    	// 	if((l!=r && rotation[gp]!=rotation[gf]) ||(l==r && rotation[gp]==rotation[gf])){
    	// 		cout<<"YES\n";
    	// 	}
    	// 	else{
    	// 		cout<<"NO\n";
    	// 	}
    	// }
    }
 
    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
