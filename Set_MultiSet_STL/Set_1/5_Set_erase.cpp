#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);   // 1,3,5,7

    // erasing elements

    s.erase(3);  // 3 deleted  , value direclty given 

    s.erase(s.begin()); //  points to the 1st element  ie, 1 is deleted


    for(auto i: s)
    {
        cout<<i<<" ";   // 5,7 
    }
    return 0;
}