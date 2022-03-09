#include<iostream>
using namespace std;

struct employee
{
    int empid;
    string  empname;
    float empSalary;
};


int main()
{
    struct employee karthika;
    karthika.empid = 1001;
    karthika.empname = "Karthika NV";
    karthika.empSalary = 12000000;

    cout<<karthika.empid<<endl;
    cout<<karthika.empname<<endl;
    cout<<karthika.empSalary<<endl;

    
    return 0;
}

