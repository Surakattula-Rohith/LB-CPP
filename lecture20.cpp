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

void reverseArray(vector<int> &arr, int m)
{
	int n = arr.size();
	int i = m + 1, j = n - 1, cnt = (-m + n) / 2;
	while (cnt > 0 and i < n and j < n)
	{
		swap(arr[i], arr[j]);
		j--;
		cnt--;
		i++;
	}
}

void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
	vector<int> arr(n + m);
	int i = 0, j = 0, k = 0;
	while (i < n and j < m)
	{
		if (nums1[i] > nums2[j])
		{
			arr[k] = nums2[j];
			j++;
			k++;
		}
		else if (nums1[i] < nums2[j])
		{
			arr[k] = nums1[i];
			i++;
			k++;
		}
	}
	while (i < n)
	{
		arr[k] = nums1[i];
		i++;
		k++;
	}
	while (j < m)
	{
		arr[k] = nums2[j];
		j++;
		k++;
	}
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] > nums2[j])
		{
			nums1[k] = nums1[i];
			k--;
			i--;
		}
		else
		{
			nums1[k] = nums2[j];
			k--;
			j--;
		}
	}
	while (j >= 0)
	{
		nums1[k] = nums2[j];
		k--;
		j--;
	}
}

void moveZeroes(vector<int> &arr)
{
	int n = arr.size();
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			swap(arr[i], arr[j]);
			j++;
		}
	}
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


void reverseArray(vector<int> &arr, int m)
{
	int n = arr.size();
	int i = m + 1, j = n - 1, cnt = (-m + n) / 2;
	while (cnt > 0 and i < n and j < n)
	{
		swap(arr[i], arr[j]);
		j--;
		cnt--;
		i++;
	}
}

void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
	vector<int> arr(n + m);
	int i = 0, j = 0, k = 0;
	while (i < n and j < m)
	{
		if (nums1[i] > nums2[j])
		{
			arr[k] = nums2[j];
			j++;
			k++;
		}
		else if (nums1[i] < nums2[j])
		{
			arr[k] = nums1[i];
			i++;
			k++;
		}
	}
	while (i < n)
	{
		arr[k] = nums1[i];
		i++;
		k++;
	}
	while (j < m)
	{
		arr[k] = nums2[j];
		j++;
		k++;
	}
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] > nums2[j])
		{
			nums1[k] = nums1[i];
			k--;
			i--;
		}
		else
		{
			nums1[k] = nums2[j];
			k--;
			j--;
		}
	}
	while (j >= 0)
	{
		nums1[k] = nums2[j];
		k--;
		j--;
	}
}

void moveZeroes(vector<int> &arr)
{
	int n = arr.size();
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			swap(arr[i], arr[j]);
			j++;
		}
	}
}