#include <iostream>
#include "shared.h"
#include <memory>

mystruct::mystruct()
{
    whoTouchy.push_back(0);
    std::cout << "main constructor" << std::endl; 
}
mystruct::mystruct(mystruct const& other)
  :whoTouchy(other.whoTouchy)
{
  whoTouchy.push_back(0);
    std::cout << "main copyconstructor" << std::endl;
} 

mystruct::mystruct(mystruct&& other)
  :whoTouchy(std::move(other.whoTouchy))
{
  whoTouchy.push_back(0);
  std::cout << "main moveconstructor" << std::endl;
}

mystruct& mystruct::operator=(mystruct const& other)
{
  whoTouchy = other.whoTouchy;
  whoTouchy.push_back(0);
  std::cout << "main assignment" << std::endl;
  return *this;
}
mystruct& mystruct::operator=(mystruct&& other)
{
  whoTouchy = std::move(other.whoTouchy);
  whoTouchy.push_back(0);
  std::cout << "main move assignment" << std::endl;
  return *this;
}

mystruct::~mystruct()
{
    std::cout << "main destructor" << std::endl;
    std::cout << "record of calls: ";
    for(auto entry: whoTouchy)
    {
      std::cout << entry << ", ";
    }
    std::cout << std::endl;
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

int main() 
{
    std::cout << "creating/passing struct by value..." << std::endl << std::endl;
    mystruct st;
    take_struct(st);

    std::cout << std::endl;
    std::cout << "passing struct with move()/rvalue" << std::endl << std::endl;
    take_struct_rval(std::move(st));
  
    std::cout<<std::endl;
    std::cout << "creating/passing struct as unique_ptr" << std::endl << std::endl;
    auto heap = std::make_unique<mystruct>();
    take_struct_uniqe_no_move(std::move(heap));

    std::cout << std::endl;
    std::cout << "creating/passing struct as unique_ptr, moving it in lib" << std::endl << std::endl;
    auto heap2 = std::make_unique<mystruct>();
    take_struct_uniqe(std::move(heap2));

    std::cout << std::endl;
    std::cout << "library local struct" << std::endl << std::endl;
    libLocal();

    std::cout << std::endl;
    std::cout << "scope ends here" << std::endl;
}
