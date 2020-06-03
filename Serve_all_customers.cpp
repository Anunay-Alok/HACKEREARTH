#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,a,b) for(int i = a;i<b;i++)
 
struct Restaurant{
    int index;
    int arrTime;
    int waitTime;
    int disSat;
};
 
 
inline bool comp1(const Restaurant &a, const Restaurant &b){
    if(((a.waitTime) * b.disSat)!=((b.waitTime) * a.disSat))return ((a.waitTime) * b.disSat) <((b.waitTime) * a.disSat);
    if((a.waitTime*a.disSat) != (b.waitTime*b.disSat)) return (a.waitTime*a.disSat) < (b.waitTime*b.disSat);
    if(a.arrTime != b.arrTime) return a.arrTime < b.arrTime;
 
}
 
inline bool comp2(const Restaurant &a, const Restaurant &b){
    if(((a.waitTime) * b.disSat)!=((b.waitTime) * a.disSat))return ((a.waitTime) * b.disSat) <((b.waitTime) * a.disSat);
    if(a.arrTime != b.arrTime) return a.arrTime < b.arrTime;
    if((a.waitTime*a.disSat) != (b.waitTime*b.disSat)) return (a.waitTime*a.disSat) < (b.waitTime*b.disSat);
}
 
inline bool comp3(const Restaurant &a, const Restaurant &b){
    if(((a.waitTime) * b.disSat)!=((b.waitTime) * a.disSat))return ((a.waitTime) * b.disSat) <((b.waitTime) * a.disSat);
    return a.arrTime < b.arrTime;
}
 
inline bool comp4(const Restaurant &a, const Restaurant &b){
    return ((a.arrTime + a.waitTime) * b.disSat) <((b.arrTime + b.waitTime) * a.disSat);
}
 
inline bool comp5(const Restaurant &a, const Restaurant &b){
    return ((a.waitTime) * a.disSat) <((b.waitTime) * b.disSat);
}
 
inline bool comp6(const Restaurant &a, const Restaurant &b){
    if(a.arrTime!=b.arrTime) return  a.arrTime < b.arrTime;
    if(a.waitTime!=b.waitTime) return a.waitTime < b.waitTime;
    if(a.disSat!=b.disSat) return a.disSat>b.disSat;
}
vector<Restaurant>nochange;
 
pair<ll,int> calc(int * arr1,int n,int index){
	ll add = 0;
	rep(i,0,n){
		add+=(arr1[i] - nochange[i].arrTime)*1LL*nochange[i].disSat;
	}
	// cout<<add<<"\n";
	return make_pair(add,index);
}
 
 
void solve(Restaurant* ar,int n,int k,int * answer){
    priority_queue<int,vector<int>,greater<int>>pq;
    rep(i,0,k) pq.push(0);
    int i = 0,j=k;
    while(i<n){
        answer[ar[i].index] = max(pq.top(),ar[i].arrTime);
        pq.pop();
        pq.push(answer[ar[i].index] + ar[i].waitTime);
        i++;
    }
}
 
int main(){
    int k,n;
    cin>>n>>k;
    nochange.resize(n);
    Restaurant ar[n],ar1[n],ar2[n],ar3[n],ar4[n],ar5[n];
    int ans[n],ans1[n],ans2[n],ans3[n],ans4[n],ans5[n];
    rep(i,0,n) cin>>ar[i].arrTime;
    rep(i,0,n) cin>>ar[i].waitTime;
    rep(i,0,n){
        cin>>ar[i].disSat;
        ar[i].index = i;
    }
    rep(i,0,n){
    	nochange[i] = ar1[i] = ar2[i] = ar3[i] = ar4[i] = ar5[i] = ar[i];
    }
    vector<pair<ll,int>>vec(6);
    sort(ar,ar+n,comp1);solve(ar,n,k,ans);vec[0] = calc(ans,n,0);
    sort(ar1,ar1+n,comp2);solve(ar1,n,k,ans1);vec[1] = calc(ans1,n,1);
    sort(ar2,ar2+n,comp3);solve(ar2,n,k,ans2);vec[2] = calc(ans2,n,2);
    sort(ar3,ar3+n,comp4);solve(ar3,n,k,ans3);vec[3] = calc(ans3,n,3);
    sort(ar4,ar4+n,comp5);solve(ar4,n,k,ans4);vec[4] = calc(ans4,n,4);
    sort(ar5,ar5+n,comp6);solve(ar5,n,k,ans5);vec[5] = calc(ans5,n,5);
    sort(vec.begin(),vec.end());
    if(vec[0].second == 0) 
    	rep(i,0,n) cout<<ans[i]<<" ";
    if(vec[0].second == 1) 
    	rep(i,0,n) cout<<ans1[i]<<" ";
    if(vec[0].second == 2) 
    	rep(i,0,n) cout<<ans2[i]<<" ";
    if(vec[0].second == 3) 
    	rep(i,0,n) cout<<ans3[i]<<" ";
    if(vec[0].second == 4) 
    	rep(i,0,n) cout<<ans4[i]<<" ";
    if(vec[0].second == 5) 
    	rep(i,0,n) cout<<ans5[i]<<" ";
}
