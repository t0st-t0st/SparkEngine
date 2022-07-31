#pragma once

#include <SparkEngine/Core/Export.hpp>

#include <functional>
#include <string>

#ifdef WIN32

#include <SparkEngine/Core/Platform/Win32/DllImplWin32.hpp>
using DllImpl = DllImplWin32;

#endif

class CORE_API Dll
{
public:
    Dll()  = delete;
    ~Dll() = delete;

    template <typename T>
    static std::function<T*()> import(const std::string& libName, const std::string& funcName)
    {
        return DllImpl::import<T>(libName, funcName);
    }
};
