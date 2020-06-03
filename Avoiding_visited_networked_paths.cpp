#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,a,b) for(ll i = (ll)a;i < (ll)b;i++)
#define mod (ll)(1e9 + 7)
const ll N = 1001;
ll ar[N][N];
 
struct dpStruct{
   ll dpArr[3][3][2];
};
 
dpStruct dp[N][N];
 
void init(){
    rep(i,1,N){
        rep(j,1,N){
            rep(itr1,0,3){
                rep(itr2,0,3){
                    rep(itr3,0,2){
                        dp[i][j].dpArr[itr1][itr2][itr3] = 0;
                    }
                }
            }
        }
    }
}
 
struct ans{
    bool flag;
    ll temp1;
    ll temp2;
    ll temp3;
};
 
ans checkFor(ll val){
    bool flag = true;
    ll temp1 = 0,temp2 = 0,temp3 = 0;
    if(val % 107==0){
        flag = false;
        while(val%107==0){
            temp1++;
            val /= 107;
        }
    }
    if(val % 1361 == 0){
        flag = false;
        while(val%1361==0){
            temp2++;
            val /= 1361;
        }
    }
    if(val % 10000019 == 0){
        flag = false;
        while(val%10000019==0){
            temp3++;
            val /= 10000019;
        }
    }
    if(temp1>2) temp1 = 2;
    if(temp2>2) temp2 = 2;
    if(temp3>1) temp3 = 1;
    return (ans){flag,temp1,temp2,temp3};
}
 
void solve(ll p,ll q){
    ll arrr[3][3][2];
    memset(arrr,0,sizeof arrr);
    dp[1][1].dpArr[0][0][0] = 1;
 
    ans tempAns = checkFor(ar[1][1]);
    if(!(tempAns.flag)){
        dp[1][1].dpArr[tempAns.temp1][tempAns.temp2][tempAns.temp3] = 1;
        dp[1][1].dpArr[0][0][0] = 0;
    }
 
 
    rep(i,2,q+1){
        rep(itr1,0,3){
            rep(itr2,0,3){
                rep(itr3,0,2){
                    dp[1][i].dpArr[itr1][itr2][itr3] = dp[1][i-1].dpArr[itr1][itr2][itr3];
                }
            }
        }
        tempAns = checkFor(ar[1][i]);
        if(!tempAns.flag){
            rep(itr1,0,3){
                rep(itr2,0,3){
                    rep(itr3,0,2){
                        ll itrn1 = itr1+tempAns.temp1,itrn2 = itr2+tempAns.temp2,itrn3 = itr3+tempAns.temp3;
                        if(itrn1 > 2) itrn1 = 2;
                        if(itrn2 > 2) itrn2 = 2;
                        if(itrn3 > 1) itrn3 = 1;
                            arrr[itrn1][itrn2][itrn3] =(arrr[itrn1][itrn2][itrn3] + dp[1][i].dpArr[itr1][itr2][itr3])%mod;
                    }
                }
            }
            rep(itr1,0,3){
                rep(itr2,0,3){
                    rep(itr3,0,2){
                        dp[1][i].dpArr[itr1][itr2][itr3] = arrr[itr1][itr2][itr3];
                        arrr[itr1][itr2][itr3] = 0;
                    }
                }
            }
        }
    }    
    rep(i,2,p+1){
        rep(itr1,0,3){
            rep(itr2,0,3){
                rep(itr3,0,2){
                    dp[i][1].dpArr[itr1][itr2][itr3] = dp[i-1][1].dpArr[itr1][itr2][itr3];
                }
            }
        }
        tempAns = checkFor(ar[i][1]);
        if(!tempAns.flag){
            rep(itr1,0,3){
                rep(itr2,0,3){
                    rep(itr3,0,2){
                        ll itrn1 = itr1+tempAns.temp1,itrn2 = itr2+tempAns.temp2,itrn3 = itr3+tempAns.temp3;
                        if(itrn1 > 2) itrn1 = 2;
                        if(itrn2 > 2) itrn2 = 2;
                        if(itrn3 > 1) itrn3 = 1;
                            arrr[itrn1][itrn2][itrn3] = (arrr[itrn1][itrn2][itrn3] + dp[i][1].dpArr[itr1][itr2][itr3])%mod;
                    }
                }
            }
            rep(itr1,0,3){
                rep(itr2,0,3){
                    rep(itr3,0,2){
                        dp[i][1].dpArr[itr1][itr2][itr3] = arrr[itr1][itr2][itr3];
                        arrr[itr1][itr2][itr3] = 0;
                    }
                }
            }  
        }
    }
 
    rep(i,2,p+1){
        rep(j,2,q+1){
            rep(itr1,0,3){
                rep(itr2,0,3){
                    rep(itr3,0,2){
                        dp[i][j].dpArr[itr1][itr2][itr3] = (dp[i][j-1].dpArr[itr1][itr2][itr3]%mod + dp[i-1][j].dpArr[itr1][itr2][itr3]%mod)%mod;
                    }
                }
            }
            tempAns = checkFor(ar[i][j]);
            if(!tempAns.flag){
                rep(itr1,0,3){
                    rep(itr2,0,3){
                        rep(itr3,0,2){
                            ll itrn1 = itr1+tempAns.temp1,itrn2 = itr2+tempAns.temp2,itrn3 = itr3+tempAns.temp3;
                            if(itrn1 > 2) itrn1 = 2;
                            if(itrn2 > 2) itrn2 = 2;
                            if(itrn3 > 1) itrn3 = 1;
                                arrr[itrn1][itrn2][itrn3] = (arrr[itrn1][itrn2][itrn3] + dp[i][j].dpArr[itr1][itr2][itr3])%mod;
                        }
                    }
                }   
                rep(itr1,0,3){
                    rep(itr2,0,3){
                        rep(itr3,0,2){
                            dp[i][j].dpArr[itr1][itr2][itr3] = arrr[itr1][itr2][itr3];
                            arrr[itr1][itr2][itr3] = 0;
                        }
                    }
                }  
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    init();
    rep(i,1,n+1) rep(j,1,m+1) cin>>ar[i][j];
    solve(n,m);
    ll sum = 0;
    rep(p,0,3){
        rep(q,0,3){
            rep(r,0,2){
                if(p==2 && q==2 && r==1)
                    continue;
                sum=(sum%mod + dp[n][m].dpArr[p][q][r]%mod)%mod;
            }
        }
    }
    cout<<sum<<"\n";
    return 0;
}
