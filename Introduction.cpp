#include <iostream>
using namespace std;

int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of long long int : " << sizeof(long long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

   cout << "Hello" << endl ;
   char ch = 'a' ;
   int al = ch ;
   cout  << al << endl ;

   long ll = 34  ;
   cout << ll << endl ;

   short st= 897 ;
   cout  << st  << endl ;
   
  cout <<  sizeof(signed long long int) << endl; 

   int hello = 5  ;
   

   if(hello & 1) {
      cout << "Odd" << endl ;
   }else {
       cout << "Even" << endl ;
   }
   cout << endl ;

   int a ,bk ;
   cin  >> a >> bk ; 

   
   cout << a*bk <<endl ; 
   cout << bk*a <<endl ; 

   return 0;
}