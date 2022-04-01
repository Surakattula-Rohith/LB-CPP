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

int Hero::timeRequired = 10 ;

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    int n;
    cin >> n;
    cout << n << nl;

    // Hero h1;
    // cout << sizeof(h1) << nl;

    // h1.name = "Ramesh";
    // h1.level = 'A';
    // h1.setHealth(70);

    // cout << nl << h1.name << " " << h1.level << " " << h1.getHealth() << nl << nl;

    // Hero a;
    // Hero *b = new Hero;
    // cout << sizeof(b) << nl;
    // (*b).setHealth(100);
    // cout << (*b).getHealth() << nl;
    // cout << b << nl << nl;

    // b->name = "Rohith";
    // b->level = 'S';
    // cout << b->name << nl;
    // cout << b->level << nl;

    cout << nl;

    // Hero k(10);
    // cout << k.getHealth() << nl;

    Hero h3;
    h3.setHealth(300) ;
    h3.setLevel('F');
    char name[7] = "Babbar" ;
    h3.setName(name) ;

    Hero h4 = h3;

    h3.print();
    h4.print();

    cout << nl ;
    h3.name[0] = 'G';

    h3.print();
    h4.print();
    cout << nl ;
    
    // SHALLOW COPY

    // Babbar 300 F
    // Babbar 300 F

    // Gabbar 300 F
    // Gabbar 300 F

    //DEEP COPY

    // Babbar 300 F
    // Babbar 300 F

    // Gabbar 300 F
    // Babbar 300 F

    Hero *ab = new Hero() ;

    cout << nl << ab->timeRequired << nl ;
    delete ab ;

    cout << Hero::timeRequired  << nl ;
    cout << Hero::random() << nl  ;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms" << nl ;
#endif
    return 0;
}