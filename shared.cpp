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


void take_struct(mystruct arg)
{
    mystruct copy(arg);
    std::cout << "take_struct" << std::endl;
}


void take_template_struct(templateStruct<void> arg)
{
    templateStruct<void> copy(arg);
    std::cout << __func__ << std::endl;
}
