#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
   unordered_set <int> s;
   s.insert(4);
   s.insert(8);
   s.insert(8);    // dup not allowed
   s.insert(9);
   s.insert(1);   

   for(auto i: s)
   {
       cout<<i<<" ";  // 1,8,9,4  randomly not soreted
   }
   cout<<endl;

   //erase

   s.erase(8);   // 8 deletd

    for(auto i: s)
    {  
        cout<<i<<" ";   // 1,9,4
    }
   cout<<endl;



   s.erase(s.find(9));   // 9 deleted
   for(auto i: s)
    {
        cout<<i<<" "; //  1,4
    }
   cout<<endl;



    return 0;
}