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

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    //     class Solution {
    // public:
    //     int reverse(int n) {
    //         int ans = 0 ;

    //         while(n!=0){
    //             int t = n%10;
    //             if((ans > (INT_MAX/10)) or (ans < (INT_MIN/10)) ){
    //                 ans = 0 ;
    //                 break;
    //             }
    //             ans = (ans*10) + t ;
    //             n /= 10 ;
    //         }

    //         return ans ;
    //     }
    // };

    // class Solution
    // {
    // public:
    //     int bitwiseComplement(int n)
    //     {

    //         int k = (~n);
    //         int mask = 0;

    //         if (n == 0)
    //             return 1;

    //         while (n != 0)
    //         {
    //             n = (n >> 1);
    //             mask = (mask << 1) | 1;
    //         }

    //         return (k & mask);
    //     }
    // };

    // class Solution
    // {
    // public:
    //     bool isPowerOfTwo(int n)
    //     {

    //         if (n == 1)
    //             return true;

    //         if (n & 1)
    //             return false;

    //         while (n != 0)
    //         {
    //             n = (n >> 1);
    //             if (n == 1)
    //                 return true;
    //             if ((n & 1) and (n != 1))
    //                 return false;
    //         }

    //         return false;
    //     }
    // };

    // class Solution
    // {
    // public:
    //     bool isPowerOfTwo(int n)
    //     {

    //         for (int i = 0; i < 31; i++)
    //         {
    //             if (n == pow(2, i))
    //                 return true;
    //         }

    //         return false;
    //     }
    // };




#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}