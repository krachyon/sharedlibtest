#include "shared.h"


mystruct::mystruct()
{
    std::cout << "shared constructor" << std::endl; 
}
mystruct::mystruct(mystruct const&)
{
    std::cout << "shared copyconstructor" << std::endl;
} 

mystruct::~mystruct()
{
    std::cout << "shared destructor" << std::endl;
}

void* mystruct::operator new(size_t size) 
{ 
    std::cout<< "shared lib new operator with size: " << size << std::endl; 
    void* p = ::new mystruct();
    return p; 
} 

void mystruct::operator delete(void* p) 
{ 
    std::cout<< "shared lib delete operator " << std::endl; 
    free(p); 
} 


void take_struct(mystruct arg)
{
    mystruct copy(arg);
    std::cout << "take_struct" << std::endl;
}

void take_struct_rval(mystruct&& arg)
{
    std::cout << __func__ << std::endl;
}

void take_struct(std::unique_ptr<mystruct> arg)
{
    std::cout << __func__ << std::endl;
}

