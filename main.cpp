#include <iostream>
#include <libunwind.h>
#include "copy_and_assign_construct/String.h"

struct STACK_VALUE
{
    uint64_t    _type:8;
    uint64_t    _stack_cnt:56;
    uint64_t    _ident[2];
    void*       _stacks[16];
};

class Foo {
public:
    /*void* operator new(std::size_t s) {
        cout << "operator new function called" <<endl;
        return malloc(s);
    }*/
    void show(){
        STACK_VALUE stack_val;
        unw_backtrace(stack_val._stacks,16);
        cout<< "show() function called!"<<stack_val._stacks;
    }
};

int main() {
    auto f = new Foo();
    f->show();

    String s1("hello");
    String s3(s1); //调用拷贝构造函数
    cout<<s3.get()<<endl;

    String s2;
    s2 = s1;        //调用拷贝赋值构造函数
    cout << s2.get() <<endl;

    const volatile int MAX_LEN = 1024;//需要加volatile才能看到效果

    int* p = (int*)&MAX_LEN;
    *p = 2048;
    cout<< MAX_LEN <<endl;
}
