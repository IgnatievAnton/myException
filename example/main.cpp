#include <iostream>
#include <myExcept/myException.hpp>

template <typename T>
T devision(T a ,T b){
    if(b == 0)
        throw MyException("devison by zero!", __FUNCTION__);
    else{
        T devision_ = a/b;
        return devision_;
    }
}


int main(){
// Some example using !
    try{
       throw devision(11,1);
    }
    catch(MyException a){
        if (a.getMyException() == "devison by zero!"){
            cout << "some error check you input data!" << endl;
        }
    }
    catch(int a){
        cout << a << endl;
    }
    return 0;
}
