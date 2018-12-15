#pragma once
#include "sharedlib_export.h"
#include <iostream> 

struct mystruct
{
    mystruct();
    mystruct(mystruct const&);
    ~mystruct();
};

template<typename T>
struct templateStruct
{
    templateStruct();
    templateStruct(templateStruct const&);
    ~templateStruct();
};

template<typename T>
templateStruct<T>::templateStruct()
{
    std::cout << "shared template constructor" << std::endl; 
}

template<typename T>
templateStruct<T>::templateStruct(templateStruct const&)
{
    std::cout << "shared template copy constructor" << std::endl; 
}

template<typename T>
templateStruct<T>::~templateStruct()
{
    std::cout << "shared template destructor" << std::endl; 
}


SHAREDLIB_EXPORT void take_struct(mystruct);

SHAREDLIB_EXPORT void take_template_struct(templateStruct<void>);

template<typename T>
SHAREDLIB_EXPORT void take_template_struct_template(templateStruct<T> arg)
{
    templateStruct<T> copy(arg);
    std::cout << __func__ << std::endl;
}
