#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset <int> s;
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(4);   // 1,3,3,3,3,4   duplicates allowed

    for(auto i: s)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    // s.erase(3);  // all 3's are deleted
    // for(auto i: s)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    s.erase(s.find(3)); // first occurace of 3 is deleted here
     for(auto i: s)
    {
        cout<<i<<" ";
    }
    cout<<endl;


    s.erase(3);  // all 3's are deleted
    for(auto i: s)
    {
        cout<<i<<" ";
    }
    cout<<endl;




    return 0;
}