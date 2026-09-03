#include <iostream>
using namespace std;

void add(int &x, int &y, int &sum){
    sum=x+y;
}

int main(){
    int a,b,result;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    add(a,b,result);
    cout<<"Sum = "<<result<<endl;
    return 0;
}