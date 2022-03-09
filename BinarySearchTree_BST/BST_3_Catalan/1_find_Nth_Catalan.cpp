#include<iostream>
using namespace std;

int Catalan(int n)
{
    if(n<= 1)  // C0 = 1   C1 = 1
    {
        return 1;
    }

    int result =0;
    for(int i=0; i<=n-1; i++)
    {
        result += Catalan(i) * Catalan(n-i-1);
    }
    return result;
}



int main()
{
    // catalan sequence =  1,1,2,5,14,42,132,429....

    cout<<Catalan(6);

    cout<<endl;


    
    // first 10 catalan numbers     .....use loop
    for(int i=0; i<10; i++)
    {
        cout<<Catalan(i)<<" ";
    }
    cout<<endl;

    return 0;

}