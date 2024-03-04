#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long // change here

#define sfi(x)        scanf("%lld", &x) // change here
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 0 )

const int mxn = 50010;

vector<int> adj[mxn];
bool vis[mxn];
int n, Start, End, parent[mxn];

void clear()
{
    rep(i, 0, mxn) adj[i].clear();
    ZERO(vis);
    ZERO(parent);
}

void BFS(int s, int e)
{
    queue<int> qu;
    vis[s] = true;
    qu.push(s);

    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        if(u == e) return;
        repit(it, adj[u]){
            int v = *it;
            if(!vis[v]){
                parent[v] = u;
                vis[v] = true;
                qu.push(v);
            }
        }
    }
}

void print(int v)
{
    if(v == 0) return;
    print(parent[v]);

    if(v == Start) pfi(v);
    else spc, pfi(v);
}

void solve(int tc)
{
    clear();

    sfi(n);

    int u, v;
    rep(i, 0, n){
        sfi(v);
        if(i==0){
            Start = v;
            u = v;
            continue;
        }
        if(i == n-1){
            End = v;
        }
        adj[v].push_back(u);
        adj[u].push_back(v);
        u = v;
    }

    rep(i, 0, mxn) if(!adj[i].empty()) sort(all(adj[i]));

    BFS(Start, End);

    pfs("Case "), pfi(tc), pfs(":\n");
    print(End); nwl;
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
