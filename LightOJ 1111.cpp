#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          "\n"
#define sp            " "
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(i, x)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1073741820
#define mod           1000000007
#define mxn           1010

vector<int> adj[mxn];
bool vis[mxn];
int cnt[mxn], k, n, m, u, v;

void bfs(int s){
    mem(vis, 0);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        u = q.front(); q.pop();
        cnt[u]++;
        rep(i, 0, adj[u].size()){
            v = adj[u][i];
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void solve(int t){

    cin>>k>>n>>m;

    vector<int> person(k);

    rep(i, 0, k) cin>>person[i];

    rep(i, 0, m) cin>>u>>v , adj[u].pb(v);


    rep(i, 0, k) bfs(person[i]);

    int ans = 0;
    rep(i, 1, n+1) if(cnt[i]>=k) ans++;

    cout<<"Case "<<t<<": "<<ans<<endl;

    mem(cnt, 0);
    rep(i, 0, mxn) adj[i].clear();
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


