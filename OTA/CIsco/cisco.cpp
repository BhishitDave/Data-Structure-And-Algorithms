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
    string txt = "abcdefabcd";
    string pat = "ab#d";
    int ans=0;
    for(int i=0;i<txt.size();i++)
    {
        int k=i;
        int j=0;
        int count=0;
        while(k<txt.size() and j<pat.size())
        {
            if(txt[k]==pat[j] or pat[j]=='#')
            {
                k++;
                j++;
                count++;
            }
            else{
                break;i=k;
            }
            if(count==pat.size() )
            {
                // cout<<i+1;
                // deb(ans);
                ans=((ans*10)+(i+1));
                // deb(ans);
                i+=k;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}