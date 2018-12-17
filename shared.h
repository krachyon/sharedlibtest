#pragma once
#include "sharedlib_export.h"
#include <iostream> 
#include <memory>
#include <vector>

struct mystruct
{
    mystruct();
    mystruct(mystruct const&);
    mystruct(mystruct&&);
    mystruct& operator=(mystruct const&);
    mystruct& operator=(mystruct&&);
    ~mystruct();

    std::vector<bool> whoTouchy;
    
    void* operator new(size_t size);
    void operator delete(void* p);
};



SHAREDLIB_EXPORT void take_struct(mystruct);

SHAREDLIB_EXPORT void take_struct_rval(mystruct&&);

SHAREDLIB_EXPORT void take_struct(std::unique_ptr<mystruct>);

SHAREDLIB_EXPORT void libLocal();
