#include <iostream>
#include <string>
using namespace std;
//LEVEL defaults to 1. Only message is mandatory.
void logMsg(const string &msg, int level = 1){
    const string tag[] = {"", "INFO", "WARN", "ERROR"};
cout<<"["<<tag[level]<<"]"<<msg<<endl;
}
//Simple Interest with a default rate of 7.5%
double interest(double principal, double years, double rate = 7.5){
    return principal*years*rate/10.0;
}
int main(){
    logMsg("System Started");
    logMsg("Low memory", 2);
    cout<<"Interest = "<<interest(10000,2)<<endl;
    cout<<"Interest = "<<interest(10000,2,9.0)<<endl;
    return 0;
}