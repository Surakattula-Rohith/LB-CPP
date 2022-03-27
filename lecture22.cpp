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

void reverseString(vector<char> &as)
{
    int n = as.size();
    int s = 0, e = n - 1;
    while (s < e)
        swap(as[s++], as[e--]);
}
bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (!isalnum(s[l]))
            l++;
        else if (!isalnum(s[r]))
            r--;
        else if (tolower(s[l]) != tolower(s[r]))
            return false;
        else
        {
            l++;
            r--;
        }
    }
    return true;
}

char getMaxOccuringChar(string str)
{
    int n = str.length();
    char ans;
    int cnt = 0;

    for (char i = 'a'; i != 'z'; i++)
    {
        int m_cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == i)
                m_cnt++;
        }
        if (m_cnt > cnt)
        {
            ans = i;
            cnt = m_cnt;
        }
    }
    return ans;
}

int compress(vector<char> &c)
{
    int n = c.size();
    string ans = "";
    if (n == 1)
        return 1;

    for (int i = 0; i < n - 1;)
    {
        char ch = c[i];
        if ((i + 1 < n) and c[i + 1] != ch)
        {
            ans += ch;
            i++;
        }
        else if ((i + 1 < n) and c[i + 1] == ch)
        {
            int cnt = 1;
            while ((i + 1 < n) and c[i + 1] == ch)
            {
                cnt++;
                i++;
            }
            ans += ch;
            ans += to_string(cnt);
            i++;
        }
    }
    if (c[n - 1] != c[n - 2])
    {
        ans += c[n - 1];
    }

    vector<char> cc(ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cc[i] = ans[i];
    }
    c = cc;

    return c.size();
}

bool checkPermutations(string s1, string s2)
{
    vector<int> a(100, 0);
    for (int i = 0; i < s2.size(); i++)
    {
        a[-'a' + s2[i]]++;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        a[s1[i] - ('a')]--;
        if (a[s1[i] - ('a')] < 0)
            return false;
    }
    return true;
}

string removeOccurrences(string s, string part)
{
    string x = s;
    int n = s.size(), m = part.size(), i, j;
    for (i = 0, j = 0; i < n; i++)
    {
        x[j++] = s[i];
        if (j >= m && x.substr(j - m, m) == part)
            j -= m;
    }
    return x.substr(0, j);
}

string replaceSpaces(string &s)
{
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
            ans += s[i];
        else
            ans += "@40";
    }
    return ans;
}

bool check(string s1, string s2)
{
    vector<int> a(100, 0);
    for (int i = 0; i < s2.size(); i++)
    {
        a[-'a' + s2[i]]++;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        a[s1[i] - ('a')]--;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
            return false;
    }

    return true;
}

bool checkInclusion(string s1, string s2)
{

    if (s2.size() < s1.size())
        return false;

    for (int i = 0; i <= (s2.size() - s1.size()); i++)
    {
        if (check(s1, s2.substr(i, s1.size())))
            return true;
    }
    return false;
}

class Solution
{
    bool areVectorsEqual(vector<int> a, vector<int> b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    string removeDuplicates(string s)
    {
        stack<char> st;
        if (s.size() == 1)
            return s;
        else
        {
            for (int i = 0; i < s.size(); i++)
            {

                if (!st.empty() and (st.top()== s[i]))

                    st.pop();
                else
                    st.push(s[i]);
            }

            string ans = "" ;
            while(!st.empty()){
                ans += st.top();
                st.pop() ;
            }

            // reverse(ans.begin() , ans.end() );
            for(int i = 0 ; i < ans.size()/2 ; i++){
                swap(ans[i] , ans[ans.size()-i-1]);
            }
            return ans;
        }
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
            return false;
        vector<int> freqS1(26, 0);
        for (char c : s1)
            freqS1[c - 'a']++;

        vector<int> freqS2(26, 0);
        int i = 0, j = 0;

        while (j < s2.size())
        {
            freqS2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size())
            {
                if (areVectorsEqual(freqS1, freqS2))
                    return true;
            }

            if (j - i + 1 < s1.size())
                j++;
            else
            {
                freqS2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // int n;
    // cin >> n;
    // vector<char> v;
    // for (int i = 0; i < n; i++)

    // {
    //     cin >> v[i];
    // }

    string s = "dcda";
    cout << s.substr(1, 3) << nl;
    cout << check("adc", "cda") << nl;
    cout << checkInclusion("adc", "dcda") << nl;

    // cout << compress(v);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}