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

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&h1)
{

    Node *head = h1;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << nl;
}

void insertAtTail(Node *&tail, int d)
{

    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void reveseRec(Node *&head, Node *&cur, Node *&prev)
{
    if (cur == NULL)
    {
        head = prev;
        return;
    }

    reveseRec(head, cur->next, cur);
    cur->next = prev;
}

void reverseIt(Node *&head)
{
    Node *prev = NULL;
    Node *cur = head;
    if (cur == NULL)
    {
        cout << "LinkedList is Empty. Please check again!!";
        return;
    }
    Node *ford = head;
    if (ford == NULL)
    {
        return;
    }
    while (ford != NULL)
    {
        ford = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ford;
    }
    head = prev;
}

void middleLL(Node* &head)
{
    Node *pro = head;
    Node *noob = head;

    if (pro->next == NULL)
    {
        cout << head->data << nl;
    }

    while (pro != NULL)
    {
        pro = pro->next->next;
        noob = noob->next;
    }
    cout << noob->data << nl;
}

Node *reveseRecHead(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallHead = reveseRecHead(head->next);
    head->next->next = head;
    head->next = NULL;

    return smallHead;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    Node *head = new Node(10);
    Node *tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);

    print(head);

    cout << nl;

    reverseIt(head);
    print(head);

    cout << nl;

    Node *cur = head;
    Node *prev = NULL;
    reveseRec(head, cur, prev);
    print(head);

    cout << nl;

    // Node *h = reveseRecHead(head);
    // print(h);

    middleLL(head);
    cout << nl;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}