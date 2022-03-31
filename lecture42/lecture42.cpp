#include <bits/stdc++.h>

#include "Hero.cpp"

using namespace std;
#define nl "\n"
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

    int n;
    cin >> n;
    cout << n << nl;

    Hero h1;
    cout << sizeof(h1) << nl;

    h1.name = "Ramesh";
    h1.level = 'A';
    h1.setHealth(70);

    cout << nl << h1.name << " " << h1.level << " " << h1.getHealth() << nl << nl ;

    Hero a ; 
    Hero *b = new Hero ;
    cout << sizeof(b) << nl ;
    (*b).setHealth(100) ;
    cout << (*b).getHealth() << nl ;
    cout << b << nl <<nl ;

    b->name = "Rohith" ;
    b->level = 'S' ;
    cout << b->name << nl ;
    cout << b->level << nl ;

    cout << nl;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}