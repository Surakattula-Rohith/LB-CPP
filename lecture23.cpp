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
vector<int> wavePrint(vector<vector<int>> arr, int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        if (i & 1)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                //                 cout << arr[j][i] <<" " ;
                ans.push_back(arr[j][i]);
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                //                 cout << arr[j][i] <<" " ;
                ans.push_back(arr[j][i]);
            }
        }
    }
    return ans;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int n = matrix.size();
    int m = matrix[0].size();

    int idx = 0;
    if (matrix[0][m - 1] == target)
        return true;

    for (int i = 1; i < n; i++)
    {
        if (matrix[i][m - 1] == target)
            return true;
        else
        {
            if (matrix[i - 1][m - 1] < target and target < matrix[i][m - 1])
            {
                idx = i;
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        if (matrix[idx][i] == target)
            return true;
    }

    return false;
}

bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // start from the [last row, first column] element
    int i = n - 1;
    int j = 0;
    while (j < m && i >= 0)
    {
        if (matrix[i][j] == target) // target found
            return true;
        else if (matrix[i][j] > target) // target is smaller go upwards
            --i;                        // decrease the row index
        else                            // target is larger go rightwards
            ++j;                        // increase the column index
    }
    return false; // target not found
}

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int cnt = 0;
        int total = row * col;

        int startRow = 0;
        int endRow = row - 1;
        int endCol = col - 1;
        int startCol = 0;

        while (cnt < total)
        {
            for (int i = startCol; cnt < total and i <= endCol; i++)
            {
                ans.push_back(matrix[startRow][i]);
                cnt++;
            }
            startRow++;
            for (int i = startRow; cnt < total and i <= endRow; i++)
            {
                ans.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;
            for (int i = endCol; cnt < total and i >= startCol; i--)
            {
                ans.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;

            for (int i = endRow; cnt < total and i >= startRow; i--)
            {
                ans.push_back(matrix[i][startCol]);
                cnt++;
            }
            startCol++;
        }
        return ans;
    }
};

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
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << nl;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}