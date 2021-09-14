#include <iostream>
#include "copy_and_assign_construct/String.h"

int main() {
    String s1("hello");
    String s3(s1); //调用拷贝构造函数
    cout<<s3.get()<<endl;

    String s2;
    s2 = s1;        //调用拷贝赋值构造函数
    cout << s2.get() <<endl;
}
