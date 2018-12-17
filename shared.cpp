#include "shared.h"


mystruct::mystruct()
{
    std::cout << "shared constructor" << std::endl; 
    whoTouchy.push_back(1);
}
mystruct::mystruct(mystruct const& other)
  :whoTouchy(other.whoTouchy)
{
    std::cout << "shared copyconstructor" << std::endl;
    whoTouchy.push_back(1);
} 

mystruct::mystruct(mystruct&& other)
  :whoTouchy(std::move(other.whoTouchy))
{
  std::cout << "shared moveconstructor" << std::endl;
  whoTouchy.push_back(1);
}

mystruct& mystruct::operator=(mystruct const& other)
{
  whoTouchy = other.whoTouchy;
  std::cout << "shared assignment" << std::endl;  
  whoTouchy.push_back(1);
  return *this;
}
mystruct& mystruct::operator=(mystruct&& other)
{
  whoTouchy = std::move(other.whoTouchy);
  std::cout << "shared move assignment" << std::endl;
  whoTouchy.push_back(1);
  return *this;
}

mystruct::~mystruct()
{
    std::cout << "shared destructor" << std::endl;
    std::cout << "record of calls: ";
    for (auto entry : whoTouchy)
    {
      std::cout << entry << ", ";
    }
    std::cout << std::endl;
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
  mystruct moved(std::move(arg));
  std::cout << __func__ << std::endl;
}

void take_struct(std::unique_ptr<mystruct> arg)
{
    std::cout << __func__ << std::endl;
}

