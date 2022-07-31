#pragma once

#include <SparkEngine/Core/Export.hpp>

#include <functional>
#include <string>

#ifdef WIN32
#include <Windows.h>
#endif

namespace dll
{
template <typename T>
std::function<T*()> import(const std::string& libName, const std::string& funcName)
{
#ifdef WIN32
    return (T * (*)()) GetProcAddress(LoadLibrary((libName + ".dll").c_str()), funcName.c_str());
#endif
}
} // namespace dll