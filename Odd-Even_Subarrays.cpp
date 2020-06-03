#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
ll countSubarrWithEqualZeroAndOne(int arr[], int n){
    unordered_map<int, int> um; 
    int curr_sum = 0;
    for (int i = 0; i < n; i++) { 
        curr_sum += (arr[i] == 0) ? -1 : arr[i]; 
        um[curr_sum]++; 
    } 
  
    ll count = 0;
    for (auto itr = um.begin(); itr != um.end(); itr++) { 
        if (itr->second > 1) 
            count += (((ll)itr->second * ((ll)itr->second - 1)) / 2); 
    }
    if (um.find(0) != um.end()) 
        count += (ll)um[0];
    return count; 
}
 
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i] = (arr[i]&1);
    }
    cout<<countSubarrWithEqualZeroAndOne(arr,n)<<"\n";
}
