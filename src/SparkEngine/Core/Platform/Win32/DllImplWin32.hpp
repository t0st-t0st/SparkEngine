#pragma once

#include <SparkEngine/Core/Export.hpp>

#include <Windows.h>

#include <functional>
#include <string>
#include <unordered_map>

class CORE_API DllImplWin32
{
public:
    DllImplWin32()  = delete;
    ~DllImplWin32() = delete;

    template <typename T>
    static std::function<T*()> import(const std::string& libName, const std::string& funcName)
    {
        return (T * (*)()) GetProcAddress(LoadLibrary((libName + ".dll").c_str()), funcName.c_str());
    }
};
