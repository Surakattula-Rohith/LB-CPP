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

void print(int *p){
    cout << *p << nl ;
}

int getSum(int *arr, int n){

    cout << "Size in function: " << sizeof(arr) << nl ;
    int sum = 0 ;
    loop(i,0,n-1){
        sum += i[arr];
    }
    return sum;
}

void update(int *p){
    p = p+1 ;
    cout << p << nl ;
    *p += 1 ;
    cout << *p << nl ;
}


int main(int argc, char const *argv[])
{
	clock_t begin = clock();
	file_i_o();
    
    int arr[10] = {109,3,4,5,6,2,4} ;
    cout << arr << nl ;
    cout << arr[0] << nl ;
    cout << &arr[0] << nl ;
    cout << *arr << nl ;
    cout << *arr + 1 << nl ;
    cout << *(arr + 1) << nl ;

    cout << nl ;
    cout << sizeof(arr) << nl ;
    int *p = arr;
    cout << sizeof(p) << nl ;


    cout << nl ;
    int a[9] = {2,4,5,3,2,3} ;

    cout << &a[0] << nl ;
    cout << &a << nl ;
    cout << a << nl ;

    int *pq = &a[10] ;

    cout << pq << nl ;
    cout << *pq << nl ;
    cout << &pq << nl ;

    cout << nl ;

    //Error arr = arr+1 ;

    cout << pq << nl ;
    cout << pq+1 << nl ;


    cout<<nl ;

    char ch[8] = "asdkjf" ;
    cout << ch << nl ;
    char *c = &ch[0] ;
    cout << c << nl ;
    cout << *ch << nl ;
    cout << &ch[0] << nl ;

    cout << nl ;

    char io = 'z' ;
    char *tr = &io ;
    cout << tr << nl ;


    cout << nl ;

    int b[3] = {3,58,6} ; 
    cout << getSum(b,3) <<nl;

    cout << nl ;

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}