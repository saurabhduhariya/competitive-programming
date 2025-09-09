#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

void solve() {
    string s;
    cin>> s;
    int a=0;
    bool flag=false;
    for(int i=0;i<s.size();i++){
       if(s[i]=='('){
        a++;
       }
       else{
        a--;
       }
       if(a==0&&i!=s.size()-1){
        flag = true;
       }
    }
    if(flag == true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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