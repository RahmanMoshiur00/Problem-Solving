#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           100010



int main()
{
    FasterIO

    int m, n; cin>>m>>n;
    string str;
    cin>>str;

    int sz = str.length();
    bool ok = false;
    for(int i=0; i<sz-n; i++){
        if((str[i]!=str[i+n]) || (str[i]=='.' && str[i+n])=='.'){
            if(str[i]=='0') str[i+n] = '1';
            else if(str[i]=='1') str[i+n] = '0';
            else if(str[i]=='.'){
                if(str[i+n]=='0') str[i] = '1';
                else if(str[i+n]=='1') str[i] = '0';
                else str[i] = '0', str[i+n] = '1';
            }
            ok = true;
            break;
        }
    }

    if(ok){
        for(int i=0; i<sz; i++) if(str[i]=='.') str[i] = '0';
        cout<<str<<endl;
    }

    else cout<<"No"<<endl;

    return 0;
}

