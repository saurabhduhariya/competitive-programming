#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

void solve() {
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    vector<int> even;
    vector<int> odd;

    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even.push_back(arr[i]);
        }
        else{
            odd.push_back(arr[i]);
        }
    }
    if(even.empty()||odd.empty()){
        cout<<"0"<<endl;
    }
    else{
      sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    int evenst=0,oddst=0,evenend=0,oddend=0;
    for(int i=0;i<odd.size() ;i++){
        if(odd[i]<even[0]){
            evenst++;
        }
        if(odd[i]>even[even.size()-1]){
            evenend++;
        }
    }
     for(int i=0;i<even.size() ;i++){
        if(even[i]<odd[0]){
            oddst++;
        }
        if(even[i]>odd[odd.size()-1]){
            oddend++;
        }
    }
     int a = evenst+evenend;
     int b = oddst+oddend;

     int c = min(a,b);
     cout<<c<<endl;
    }
    
}

int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}