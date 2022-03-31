#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

class Hero
{

    int health;

public:
    string name;
    char level;

    void setHealth(int n)
    {
        health = n;
    }
    int getHealth()
    {
        return health;
    }
};