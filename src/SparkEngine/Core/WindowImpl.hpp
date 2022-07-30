#pragma once

#include <SparkEngine/Core/Export.hpp>

#include <SparkEngine/Core/Vector2.hpp>

#include <string>

class CORE_API WindowImpl
{
public:
    WindowImpl() = default;

    WindowImpl(std::string title, Vector2u size);

    virtual ~WindowImpl() = default;

public:
    virtual void create(std::string title, Vector2u size) = 0;
    virtual void destroy()                                = 0;

    virtual bool processMessages() = 0;

    virtual bool isOpen() const = 0;
};