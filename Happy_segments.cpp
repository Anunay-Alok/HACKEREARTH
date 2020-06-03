#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 500001
#define f ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b,c) for(ll i=a;(c)?i<(ll)b:i>=(ll)b;(c)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(1e9+7)
#define all(a,b) memset(a,b,sizeof(a))
 
const int BLK_SIZE = 1400;
const int QUERY_SIZE = 500001;
// struct Query{
//     int l;
//     int r;
//     int idx;
// };
 
// inline bool comp(Query a, Query b){
//     if(a.l/ BLK_SIZE != b.l/ BLK_SIZE)
//         return a.l < b.l;
//     return a.l / BLK_SIZE % 2 ? a.r < b.r : a.r > b.r;
// }
 
inline ll gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0){
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow)?((y < hpow)?0:3):((y < hpow)?1:2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    ll subSquareSize = 1LL << (2*pow - 2);
    ll ans = seg * subSquareSize;
    ll add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
struct Query{
    int l;
    int r;
    int idx;
    ll ord;
 
    inline void calcOrder(){
        ord = gilbertOrder(l, r, 21, 0);
    }
};
 
inline bool operator<(const Query &a, const Query &b) 
{
    return a.ord < b.ord;
}
 
int feq,p,j;
int h[MAX_SIZE];
bool arr[MAX_SIZE];
int res_zero=0;
int mp[MAX_SIZE];
 
inline void check(int node){
    if(mp[node]==0){
        if(arr[node]==false){
            arr[node]=true;
            res_zero--;
        }
    }
    else{
        if(mp[node]==h[node]){
            if(arr[node] == false){
                arr[node] = true;
                res_zero--;
            }
        }
        else{
            if(arr[node] == true){
                arr[node] = false;
                res_zero++;
            }
        }   
    }   
}
 
inline void remove(int node){
    mp[node]--;
    check(node);
}
inline void add(int node){
    mp[node]++;
    check(node);
}
 
int main(){
    // file;
    // f;
    int n,m,q,l,r;
    scanf("%d%d", &n,&m);
    int a[n+1];
    FOR(i,1,m+1,1) arr[i] = true;
    for(int i=1;i<=n;i++) scanf("%d", a+i);
    for(int i=1;i<=m;i++) scanf("%d", h+i);
    scanf("%d", &q);
    Query Q[q];int ans[q];
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d%d", &l,&r);
        Q[i] = (Query){l,r,i};
        Q[i].calcOrder();
    }
    sort(Q,Q+q);   
    int currentL = Q[0].l,currentR = Q[0].l-1;
    
    for(int i=0;i<q;i++){
        int flag = 0;
        p = Q[i].l;
        j = Q[i].r; ll index = Q[i].idx;
 
        while(currentL < p){
            remove(a[currentL]);
            currentL++;
        }
        while(currentR > j){
            remove(a[currentR]);
            currentR--;
        }
        while(currentL > p){
            currentL--;
            add(a[currentL]);
            if(mp[a[currentL]] > h[a[currentL]]){
                ans[index] = 0;
                flag = 1;
                break;
            }
        }
        if(flag!=1){
            while(currentR < j){
                currentR++;
                add(a[currentR]);
                if(mp[a[currentL]] > h[a[currentL]]){
                    ans[index] = 0;
                    flag = 1;
                    break;
                }
            }   
        }
        if(flag!=1) ans[index] = (res_zero==0);
    }
    for(int i=0;i<q;i++) printf("%d\n", ans[i]);/*cout<<ans[i]<<"\n";*/
    return 0;
}
