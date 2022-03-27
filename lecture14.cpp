#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define nl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int mySqrt(int n)
{
    if(n < 2) return n ;
    int ans = -1 ;
    int s = 1 , e = n ;
    int m = mid(s,e) ;
    while(s <= e){
        if(m*m == n) return m;
        else if(m*m > n) e = m-1 ;
        else {
            ans =  m ;
            s = m+1 ;}
        m = mid(s,e) ;
    }return ans ;
}

float morePresicion(int n , int pres , int tempSol){
    float factor = 1 , ans = tempSol ;
    for(int i = 0 ; i < pres ; i++){
        factor /= 10 ;
        for(float j = 0 ; j*j<n ; j+= factor){
            ans = j ;
        }
    }
    return ans ;    
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    int n , k;
    cin >> n >> k;

    cout << morePresicion(n , k , mySqrt(n)) << nl ;    

    // cout << n << nl ;
    // vi arr(n);

    // loop(i, 0, n - 1)
    // {
    //     cin >> arr[i];
    // }

    // int s = 0, e = n - 1;
    // int m = mid(s, e);
    // while (s <e)
    // {
    //     if (arr[m] >= arr[0])
    //     {
    //         s = m + 1;
    //     }
    //     else
    //     {
    //         e = m;
    //     }
    //     m = mid(s, e);
    // }
    // cout << s << nl;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}