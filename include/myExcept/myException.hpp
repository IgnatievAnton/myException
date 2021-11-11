#include <iostream>
#include <string>
using namespace std;

class MyException{
public:
    MyException(const string& except, const string& funcName);
    ~MyException(){}
    string getMyException();
private:
    string dataException;
    string nameFunction;
};
