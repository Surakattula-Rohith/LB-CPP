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
    Node *next, *rad;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->rad = NULL;
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

class dNode
{
public:
    int data;
    dNode *prev;
    dNode *next;
    dNode(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printD(dNode *head)
{
    dNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << nl;
}

int getLengthD(dNode *head)
{
    dNode *temp = head;
    int n = 0;

    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    return n;
}

void insertAtHeadD(dNode *&head, int d)
{
    dNode *temp = new dNode(d);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
        return;
    }
}

void inserAtTailD(dNode *&head, int d)
{

    int n = getLengthD(head);
    if (n == 0)
    {
        insertAtHeadD(head, d);
        return;
    }
    n--;
    dNode *temp = head;
    while (n--)
    {
        temp = temp->next;
    }
    dNode *h = new dNode(d);
    h->prev = temp;
    temp->next = h;
    return;
}

void insertAtMiddleD(dNode *&head, int d, int val)
{
    if (val == 1)
    {
        insertAtHeadD(head, d);
        return;
    }
    else
    {
        int n = getLengthD(head);
        if (val > n)
        {
            inserAtTailD(head, d);
            return;
        }
        val = val - 2;
        dNode *temp = head;
        while (val--)
        {
            temp = temp->next;
        }
        dNode *h = new dNode(d);
        dNode *p = temp->next;
        temp->next = h;
        h->next = p;
        p->prev = h;
        h->prev = temp;
        return;
    }
}

void deleteAtHeadD(dNode *&head)
{
    if (head->next == NULL)
    {
        delete head;
        return;
    }
    else
    {
        dNode *temp = head->next;
        dNode *h = head;
        head = temp;
        delete h;
        return;
    }
}

void deleteAttailD(dNode *&head)
{
    int n = getLengthD(head);
    if (n == 1)
    {
        deleteAtHeadD(head);
        return;
    }
    else
    {
        dNode *temp = head;
        n = n - 2;
        while (n--)
        {
            temp = temp->next;
        }
        dNode *h = temp->next;
        temp->next = NULL;
        h->prev = NULL;
        delete h;
        return;
    }
}

void deleteAtMiddleD(dNode *&head, int pos)
{
    int n = getLengthD(head);
    if (pos == 1)
    {
        deleteAtHeadD(head);
        return;
    }
    else if (pos >= n)
    {
        deleteAttailD(head);
        return;
    }
    else
    {
        pos = pos - 2;
        dNode *temp = head;
        while (pos--)
        {
            temp = temp->next;
        }
        dNode *h = temp->next;
        temp->next = h->next;
        h->next->prev = temp;
        h->next = NULL;
        h->prev = NULL;
        delete h;
        return;
    }
}

Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseIt(Node *&head)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *ford = NULL;

    while (cur != NULL)
    {
        ford = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ford;
    }

    return prev;
}
void inserAtTailR(Node *&head, Node *&tail, int d)
{

    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

Node *getCloned(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        inserAtTailR(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    unordered_map<Node *, Node *> oldToNew;
    temp = head;
    Node *temp2 = cloneHead;

    while (temp != NULL and temp2 != NULL)
    {
        oldToNew[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    temp = head;
    temp2 = cloneHead;

    while (temp != NULL)
    {
        temp2->rad = oldToNew[temp->rad];
        temp = temp->next;
        temp2 = temp2->next;
    }
}

Node *getCloned(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        inserAtTailR(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL and cloneNode != NULL)
    {
        Node *nxt = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = nxt;

        nxt = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = nxt;
    }
 
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
            if (cloneNode->next)
                temp->next->rad = temp->rad->next;
            else
                temp->next = NULL;
        temp = temp->next->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL and cloneNode != NULL)
    {

        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
            cloneNode->next = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    Node *n1 = new Node(100);
    Node *tail = n1;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}