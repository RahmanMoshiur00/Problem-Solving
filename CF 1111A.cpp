#include <bits/stdc++.h>
using namespace std;
typedef long long int intl; //
typedef unsigned long long intu; //
#define int             long long
#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfd(a)          scanf("%lf", &a)
#define sfd2(a,b)       scanf("%lf %lf", &a, &b)
#define sfd3(a, b, c)   scanf("%lf %lf %lf", &a, &b, &c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)
#define pfi(a)          printf("%lld", (intl)a)
#define pfin(a)         printf("%lld\n", (intl)a)
#define pfis(a)         printf("%lld ", (intl)a)
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '
#define INPUT           freopen("input.txt","r",stdin);
#define OUTPUT          freopen("output.txt","w",stdout);
#define FastRead        ios::sync_with_stdio(0); cin.tie(0);
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, a)  for(__typeof__((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define perit(it, a)  for(__typeof__((a).rbegin()) it = (a).rbegin(); it != (a).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin); i < (end); i++)
#define per(i, end, begin) for(int i = (end)-1; i >= (begin); i--)
#define all(a)          a.begin(), a.end()
#define PB              push_back
#define mem(a, v)       for(int i=0, sz=sizeof(a)/sizeof(*a); i<sz; i++){ a[i] = v; }
#define setval(a, v)    memset((a), v, sizeof(a))
#define min3(a, b, c)   min(a,min(b,c))
#define max3(a, b, c)   max(a,max(b,c))
#define ff              first
#define ss              second
#define CEIL(a, b)      ((a)%(b)==0 ? (a)/(b) : ((a)/(b))+1)
#define ABS(a)          ((a)<0?-(a):(a))
#define SQ(a)           ((a)*(a))
#define PI              acos(-1.00)
#define ERR             1e-9
#define INF             1000000007
#define mod             1000000007
#define debug           if( 1 )
#define mxn             100010

bool isVowel(char ch)
{
    return (ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u');
}

bool isCon(char ch){
    return !isVowel(ch);
}

void solve(int tc)
{
    string s, t;
    cin>>s>>t;
    if(s.size() == t.size()){
        rep(i, 0, s.size()){
            if(isVowel(s[i])){
                if(!isVowel(t[i])){
                    cout<<"No"<<endl;
                    return;
                }
            }
            if(isCon(s[i])){
                if(!isCon(t[i])){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}

int32_t main()
{
    //INPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

