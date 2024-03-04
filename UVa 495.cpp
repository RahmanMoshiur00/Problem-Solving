#include <bits/stdc++.h>
using namespace std;
typedef int intt;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    scanf("%lld %lld", &x, &y)
#define sfi3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)
#define pfi(x)        printf("%lld", (intl)x)
#define pfi2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfi3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for (__typeof(end) i = (end)-1; i >= (begin); i -= 1)
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           100010


vector<string> fib(5010);

int INT(char c)
{
    int v = (c - '0');
    return v;
}

void ADD(int n)
{
    int l1 = fib[n-1].length(), l2 = fib[n-2].length(), carry = 0, v;

    for(int i=l1-1, j=l2-1; i>=0 or j>=0; i--, j--){
        if(i>=0 and j>=0){
            v = INT(fib[n-1][i]) + INT(fib[n-2][j]) + carry;
            carry = v / 10;
            v = v % 10;
        }
        else if(i>=0){
            v = INT(fib[n-1][i]) + carry;
            carry = v / 10;
            v = v % 10;
        }
        else if(j>=0){
            v = INT(fib[n-2][j]) + carry;
            carry = v / 10;
            v = v % 10;
        }

        fib[n] += '0' + v;
    }

    if(carry) fib[n] += '1';

    reverse(all(fib[n]));
}

void precal()
{
    fib[0] = "0";
    fib[1] = "1";
    fib[2] = "1";

    rep(i, 3, 5001) ADD(i);
}

void solve(int tc)
{
    int n;
    while(cin>>n){
        cout<<"The Fibonacci number for "<<n<<" is "<<fib[n]<<endl;
    }
}

int32_t main()
{
    //INPUT
    //FastRead

    precal();

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

