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

void insertAtMiddle(Node *&head, int d, int idx)
{
    if (idx == 1)
        insertAtHead(head, d);
    else
    {
        Node *temp = head;
        idx = idx - 2;
        while (idx-- and temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            insertAtTail(temp, d);
        }
        else
        {
            Node *h = new Node(d);
            h->next = temp->next;
            temp->next = h;
        }
    }
}
void deleteAtHead(Node *&head)
{
    if (head->next == NULL)
        head = NULL;
    Node *temp = head->next;
    delete head;
    head = temp;
}

void deleteAtMiddle(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
    }
    else
    {
        Node *temp = head;
        pos = pos - 2;
        while (pos-- and temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *h = temp->next;
        if (h->next != NULL)
            temp->next = h->next;
        else
            temp->next = NULL;
        delete h;
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    Node *n1 = new Node(100);
    Node *tail = n1;

    cout << n1->data << nl;
    cout << n1->next << nl;
    cout << nl;

    print(n1);

    insertAtHead(n1, 20);
    print(n1);

    insertAtHead(n1, 30);
    print(n1);

    cout << nl;

    insertAtTail(tail, 60);
    print(n1);

    insertAtTail(tail, 70);
    print(n1);

    cout << nl;

    insertAtMiddle(n1, 200, 2);
    print(n1);
    insertAtMiddle(n1, 18, 1);
    print(n1);
    insertAtMiddle(n1, 200, 7);
    print(n1);
    insertAtMiddle(n1, 22, 9);
    print(n1);
    insertAtMiddle(n1, 3333, 12);
    print(n1);

    cout << nl;

    deleteAtHead(n1);
    print(n1);

    cout << nl;

    deleteAtMiddle(n1, 5);
    print(n1);
    deleteAtMiddle(n1, 7);
    print(n1);
    deleteAtMiddle(n1,7) ;
    print(n1) ;
    deleteAtMiddle(n1,14) ;
    print(n1) ;

    cout << nl ;


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}