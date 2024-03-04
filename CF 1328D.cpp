#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long intu;
typedef long long int intl;
//-----------------directions-----------------//
// int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction
// int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
// int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
// int dx[]={2,1,-1,-2,-1,1}; int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//-------------------debug--------------------//
#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define FastRead        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define OUTPUT          freopen("output.txt","w",stdout);
#define INPUT           freopen("input.txt","r",stdin);
//------------------policy DS--------------------//
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//------------------print--------------------//
#define int             long long
#define pfi(a)          printf("%lld", (intl)a)
#define pfin(a)         printf("%lld", (intl)a), printf("\n")
#define pfis(a)         printf("%lld", (intl)a), printf(" ")
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define pfsn(a)         printf("%s", a), printf("\n")
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '
//------------------input--------------------//
#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)
//-------------------loop-------------------//
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
//--------------initialization--------------//
#define ZERO(a)         memset(a, 0, sizeof(a))
#define MINUS(a)        memset(a, 0xff, sizeof(a))
#define setval(a, v)    for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
//-------------------misc.------------------//
#define all(a)          a.begin(), a.end()
#define max3(a, b, c)   max(a,max(b,c))
#define min3(a, b, c)   min(a,min(b,c))
#define INF             1000000007
#define debug           if( 0 )

const int mxn = 200010;

int arr[mxn], ans[mxn];

int what(int n)
{
    for(int i=1; i<=3; i++){
        if(arr[n] != arr[n+1]){
            if(arr[n] != arr[n-1]){
                if(ans[n-1]!=i && i!=ans[n+1]) return i;
            }
            else{
                if(ans[n+1]!=i) return i;
            }
        }
        else{
            if(arr[n] != arr[n-1]){
                if(ans[n-1] != i) return i;
            }
            else{
                return i;
            }
        }
    }
}

void solve(int tc)
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    ZERO(ans);
    if(arr[0] != arr[n-1]){
        ans[0] =  1;
        ans[n-1] =  2;
    }
    else{
        ans[0] =  1;
        ans[n-1] = 1;
    }


    for(int i=1; i+1<n; i++) ans[i] = what(i);

//    for(int i=1; i+1<n; i++){
//        if(arr[i-1]!=arr[i]){
//            if(ans[i-1] == 0) ans[i] = 1;
//            else{
//                if(ans[i-1] == 1) ans[i] = 2;
//                else ans[i] = 1;
//            }
//        }
//    }
//    for(int i=n-2; i>0; i--){
//        if(arr[i] == arr[n-1]){
//            ans[i] = 0;
//        }
//        else break;
//    }
//
//    ans[n-2] = what(n-2);
//
//    for(int i=1; i<=n-3; i++){
//        ans[i] = what(i);
//    }

    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(ans[i]);
    }

    cout << st.size() << endl;
    for(int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int32_t main()
{
    //INPUT //OUTPUT
    FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

