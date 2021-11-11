#include<myExcept/myException.hpp>

MyException::MyException(const string &except, const string &funcName): dataException(move(except)), nameFunction(move(funcName)){
    cout << "You have an exception on function: " << funcName << "(*)"<< endl;
    cout << "Please try cath Exception MyException! " << endl;
}

string MyException::getMyException()
{
    cout << "Exception data: " << dataException << endl;
    return dataException;
}
