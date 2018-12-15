#include <iostream>
#include "shared.h"


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

int main() 
{
    mystruct st;
    take_struct(st);
    
    templateStruct<void> voidStruct;
    templateStruct<int> intStruct;
    
    take_template_struct(voidStruct);
    
    take_template_struct_template<int>(intStruct);
}
