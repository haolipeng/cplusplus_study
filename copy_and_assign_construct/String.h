//
// Created by AT on 2021/9/14.
//

#ifndef CPLUSPLUS_STUDY_STRING_H
#define CPLUSPLUS_STUDY_STRING_H

#include <iostream>
#include <string.h>
using namespace std;

//class with pointer members 必须有copy ctor和copy op=
class String{
public:
    String(const char* sz = 0);
    String(const String& s);//拷贝构造
    String& operator=(const String& s);//赋值构造
    char* get() const;
    ~String();
private:
    char* m_data;
};

String::String(const char *sz) {
    //1.已传参sz
    if(sz != nullptr){
        int length = strlen(sz) + 1;
        m_data = new char [length];
        memset(m_data,0, strlen(m_data));
        strcpy(m_data,sz);
    }else{
        //2.未传参sz
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::String(const String& str) {
    cout<<"call copy constructor function"<<endl;
    int length = strlen(str.m_data) + 1;
    m_data = new char[length];
    strcpy(m_data,str.m_data);
}

String& String::operator=(const String &str) {
    cout<<"call copy assign operator constructor function"<<endl;
    //0.检验下是否是自我赋值
    if(this == &str){
        return *this;
    }

    //1.释放以前的m_data内存
    delete []m_data;

    //2.申请新的存储空间
    int length = strlen(str.m_data) + 1;
    m_data = new char [length];

    //3.拷贝字符串
    strcpy(m_data,str.m_data);

    return *this;
}

char *String::get() const{
    return m_data;
}

String::~String() {
    //析构函数
    if(m_data != nullptr)
    {
        delete []m_data;
    }
}

#endif //CPLUSPLUS_STUDY_STRING_H
