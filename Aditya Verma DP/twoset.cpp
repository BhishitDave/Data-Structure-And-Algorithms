#include <bits/stdc++.h>
using namespace std;

#define fp ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define chck(x) cout << "#case" << "=" << x << endl

#define ll long long
#define all(x) x.begin(), x.end()

const int mod = 1'000'000'007;


int main()
{
    fp;
    ll n;
    cin>>n;
    ll sum=n*(n+1)/2;
    if(sum%2!=0){
        cout<<"NO";
        return 0;
    }
    sum/=2;
    vector<int> a1, a2;
    for(ll i=n,ans=0;i>0;i--){
        if(ans+i<=sum){
            ans+=i;
            a1.push_back(i);
        }
        else{
            a2.push_back(i);
        }
    }
    sort(a1.begin(), a1.end()); 
    sort(a2.begin(), a2.end());
    cout << "YES\n";
    cout << a1.size() << "\n";
    for (int x : a1) cout << x << " ";
    cout << "\n"; 
    cout << a2.size() << "\n";
    for (int x : a2) cout << x << " ";
    cout << "\n";
    
    return 0;
}