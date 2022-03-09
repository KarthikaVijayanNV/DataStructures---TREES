#include<iostream>
#include<set>
using namespace std;
int main()
{

    set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(5);
    s.insert(7);   // 1,4,2,5,7

    //lower bound
    cout<<*s.lower_bound(1)<<" "; // 1  as it is
    cout<<*s.lower_bound(5)<<" "; // 5  as it is

    cout<<*s.lower_bound(3)<<" ";// 3 not present next greater element of 3 in the set is 
                                //  4

    cout<<endl;



    // upper bound
    cout<<*s.upper_bound(4)<<" ";// next greater after 4 = 5
    cout<<*s.upper_bound(2)<<" "; // next greater after 2 = 4

    cout<<*s.upper_bound(6); //6 not present then immediate greater after 6
    
    cout<<endl;




    cout<<(s.lower_bound(10) == s.end());   // 10 present allaa so where the iterator stands last will be the lower bound
                        // o/p is 1 (true)

    cout<<endl;

    cout<<(s.upper_bound(10) == s.end());    // 1 (true);            
    return 0;

}