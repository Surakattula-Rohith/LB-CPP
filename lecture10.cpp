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
void swap2ele(int arr[], int n)
{
    if (n & 1)
        n = n - 1;
    loop(i, 0, n - 1)
    {
        swap(arr[i], arr[i + 1]);
        i = i + 1;
    }
}

int findUnique(int *arr, int n)
{
    int a = arr[0];
    for (int i = 1; i < n; i++)
    {
        a = (a ^ arr[i]);
    }
    return a;
}

bool uniqueOccurrences(vector<int> &arr)
{

    unordered_map<int, int> mp;
    set<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ans.insert(i->second);
    }
    return ans.size() == mp.size() ? true : false;
}

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    {
        // Write your code here.
        int n = arr.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == K)
                    {

                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                        ans.push_back(temp);
                    }
                }
            }
        }

        //     sort(ans.begin(),ans.end()) ;
        if (ans.size() == 0)
        {
            vector<int> temp;
            temp.push_back(-1);

            ans.push_back(temp);
        }
        return ans;
    }
}
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.
    vector<int> ans;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++, j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
        {
            j++;
        }
    }

    if (ans.size() == 0)
        ans.push_back(-1);

    return ans;
}

int findDuplicate(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    long ss = ((n - 1) * (n)) / 2;

    return sum - ss;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    int n;
    cin >> n;
    // vi arr(n);
    int arr[n];

    loop(i, 0, n - 1)

    {
        cin >> arr[i];
    }

    // sort(arr.begin(), arr.end());

    loop(i, 0, n - 1) cout << arr[i] << " ";
    cout << nl;
    swap2ele(arr, n);

    loop(i, 0, n - 1) cout << arr[i] << " ";
    cout << nl;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}