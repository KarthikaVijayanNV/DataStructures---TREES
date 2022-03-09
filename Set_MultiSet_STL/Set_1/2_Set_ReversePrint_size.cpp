#include<iostream>
#include<set>
using namespace std;

int main()
{
   set<int> s;
   s.insert(1);
   s.insert(1);
   s.insert(2);
   s.insert(3);   // 1,2,3 ( duplications not allowed)

   // printing reversly

   for(auto i = s.rbegin() ; i != s.rend(); i++)
   {
       cout<<*i<<" ";     // 3,2,1  reversed
   }

   cout<<endl;

   cout<< s.size();  // 3


    return 0;
}