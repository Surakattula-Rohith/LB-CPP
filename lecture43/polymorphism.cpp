#include <bits/stdc++.h>
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


class A{
    public:
    void sayHello(){
        cout << " HI Hello " << nl ;
    }
    void sayHello(string name){
        cout << " HI Hello "<< name << nl ;
    }
    
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    A obj ;
    obj.sayHello();
    obj.sayHello("ROHITH") ;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms" << nl;
#endif
    return 0;
}

// Encapsulation
// Inheritance (5)
// Polymorphism (2)
// Abstraaction
