#include <iostream>
#include "shared.h"
#include <memory>

mystruct::mystruct()
{
    std::cout << "main constructor" << std::endl; 
}
mystruct::mystruct(mystruct const&)
{
    std::cout << "main copyconstructor" << std::endl;
} 

mystruct::~mystruct()
{
    std::cout << "main destructor" << std::endl;
}

void* mystruct::operator new(size_t size) 
{ 
    std::cout<< "main new operator with size: " << size << std::endl; 
    void * p = ::new mystruct();
    return p; 
} 

void mystruct::operator delete(void* p) 
{ 
    std::cout<< "main delete operator " << std::endl; 
    free(p); 
}

template<typename T>
void take_struct_dummy_template(mystruct)
{
    std::cout << "main " << __func__ << std::endl;
}

int main() 
{
    mystruct st;
    take_struct(st);
    std::cout << std::endl;
    take_struct_dummy_template<void>(st);
    std::cout << std::endl;
    take_struct_dummy_template<int>(st);
    std::cout << std::endl;
    take_struct_rval(std::move(st));

    std::cout<<std::endl;
    
    auto heap = std::make_unique<mystruct>();
    take_struct(std::move(heap));
}
