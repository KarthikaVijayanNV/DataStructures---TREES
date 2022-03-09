#include<iostream>
#include<set>

using namespace std;
int main()
{

    set<int> S;

    S.insert(1);
    S.insert(2);
    S.insert(2);   // duplicates are not allowed
    S.insert(3);


    // priting Method - 1

    for(auto i : S)
    {
        cout<<i<<" ";    // 1,2,3  
    }


    

    cout<<endl;




    //printing Method - 2

    for(auto i = S.begin() ; i != S.end(); i++)
    {
        cout<<*i<<" ";   // 1,2,3
    }

    return 0;
}

