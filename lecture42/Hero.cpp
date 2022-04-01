#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

class Hero
{

    int health;

public:
    char *name;
    char level;
    static int timeRequired;
    Hero()
    {
        name = new char[100];
        // cout << nl << "Constructor" << nl <<nl;
    }
    // Hero(int health){
    // cout << "this value is " << this << nl ;
    //     this->health = health;
    // }
    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);

        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    void setHealth(int n)
    {
        health = n;
    }
    int getHealth()
    {
        return health;
    }

    void setLevel(char n)
    {
        level = n;
    }
    char getLevel()
    {
        return level;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    void print()
    {
        cout << name << " " << health << " " << level << nl;
    }

    static int random(){
        return timeRequired ;
    }

    ~Hero()
    {
        cout << nl << "Destructor called !!" << nl;
    }
};