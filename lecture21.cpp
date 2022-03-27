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

void rotate2(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void rotate(vector<int> &arr, int k)
{

    int n = arr.size();

    if (k % n == 0)
        return;

    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
    arr = temp;
}

bool check(vector<int> &nums)
{
    int n = nums.size();
    int idx = -1;
    bool h = true;

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            idx = i;
            h = false;

            break;
        }
    }
    if (h)
        return true;

    for (int i = idx + 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            return false;
    }

    if (nums[n - 1] <= nums[0])
        return true;
    else
        return false;
}

bool check2(vector<int> &nums)
{

    int size = nums.size();
    int count = 0;

    for (int x = 0; x < size; x++)
    {
        if (nums[x] > nums[(x + 1) % size])
            count++;
    }
    return (count <= 1);
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int k = max(n, m);
    vector<int> ans(k + 1, 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i = 0, j = 0, f = 0;
    while (i < n and j < m)
    {
        if ((a[i] + b[j] + ans[f]) / 10 > 0)
            ans[f + 1] = 1;
        ans[f] = ((a[i] + b[j] + ans[f]) % 10);
        i++, j++, f++;
    }
    while (i < n)
    {
        ans[f] += a[i];
        i++, f++;
    }
    while (j < m)
    {
        ans[f] += b[j];
        j++, f++;
    }

    if (ans[k] == 0)
        ans.resize(k);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    int n;
    cin >> n;
    vi arr(n);

    loop(i, 0, n - 1)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    loop(i, 0, n - 1) cout << arr[i] << " ";
    cout << nl;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}