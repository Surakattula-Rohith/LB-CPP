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

string reverseStack(string s)
{

    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }

    string ans = "";

    while (!st.empty())
    {
        char ch = st.top();
        ans += ch;
        st.pop();
    }

    return ans;
}

void solve(stack<int> &st, int count, int size)
{
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();

    solve(st, count + 1, size);
    st.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int cnt = 0;
    solve(inputStack, cnt, N);
}

bool isValidParenthesis(string s)
{
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{' or s[i] == '(' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int n = s.top();
    s.pop();

    // pushAtBottom(s, x);
    s.push(n);
}

stack<int> pushAtBottom(stack<int> &s, int x)
{
    solve(s, x);
    return s;
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int n = s.top();
    s.pop();

    reverseStack(s);
    pushAtBottom(s, n);
}

void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() or (!s.empty() and s.top() < num))
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();

    sortedInsert(s, num);

    s.push(n);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
        return;

    int num = s.top();
    s.pop();
    sortStack(s);

    sortedInsert(s, num);
}

#include <stack>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == '(') or (s[i] == '+') or (s[i] == '-') or (s[i] == '*') or (s[i] == '/'))
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                bool ans = true;
                while (st.top() != '(')
                {
                    char ch = st.top();
                    if ((ch == '+') or (ch == '-') or (ch == '*') or (ch == '/'))
                    {
                        ans = false;
                    }
                    st.pop();
                }
                if (ans)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

void print(stack<char> s)
{
    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << ans << nl;
}

int findMinimumCost(string str)
{
    int n = str.size();
    if (n & 1)
        return -1;

    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '{')
            s.push(str[i]);
        else
        {
            if (!s.empty() and s.top() == '{')
                s.pop();
            else
                s.push(str[i]);
        }
    }

    // print(s) ;

    int l = 0, r = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
            l++;
        else
            r++;
        s.pop();
    }

    // cout << nl << l << " " << r << nl ;
    int ans = 0;
    while (true)
    {
        if (l == 0 or l == 1)
            break;
        l = l - 2;
        ans = ans + 1;
    }
    if (l & 1)
    {
        ans += 2 * l + (r - l) / 2;
    }
    else
    {
        ans += r / 2;
    } 

    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << findMinimumCost(s) << nl;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}