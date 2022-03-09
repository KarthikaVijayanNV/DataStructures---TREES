#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int, greater<int> > s;  // descending order
    s.insert(1);
    s.insert(2);
    s.insert(3);

    for(auto i: s)
    {
        cout<<i<<" ";   // 3,2 1
    }


    return 0;
}
