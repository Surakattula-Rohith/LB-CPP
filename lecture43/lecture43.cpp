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

class Student
{
private:
    string name;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
};

class Human
{
public:
    int height;
    int weight;
    int age;

    int getAge()
    {
        return this->age;
    }

    void setWeyght(int w)
    {
        this->weight = w;
    }
};

class Male : public Human
{
public:
    string color;
    void sleep()
    {
        cout << "Male is sleeping !!" << nl;
    }
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    Male m ;
    m.setWeyght(34);
    cout << m.weight << nl ;
    m.sleep() ;
    cout << nl ;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms" << nl;
#endif
    return 0;
}