#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    if(c<=d && (b-a)>=0){
        cout<<(b-a)*c<<endl;
    } 
    else if(c>d && (b-a)>=0){
       while(a!=b){
          if(a%2==0){
            ans+=d;
          }
          else{
            ans+=c;
          }
          a++;
       }
        cout<<ans<<endl;
    }
    else if((a-b)==1 && a%2!=0){
        cout<<d<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    // vi primes;
    // sieveOfEratosthenes(1000000, primes);
    while(t--){
        solve();
    }
 
    return 0;
}