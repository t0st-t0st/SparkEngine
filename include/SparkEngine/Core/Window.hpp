#pragma once

#include <SparkEngine/Core/Export.hpp>

#include <SparkEngine/Core/Vector2.hpp>

#include <string>

class WindowImpl;

class CORE_API Window
{
public:
    Window();

    Window(std::string title, Vector2u size);

    ~Window();

public:
    void create(std::string title, Vector2u size);
    void destroy();

    bool processMessages();

    bool isOpen() const;

private:
    WindowImpl* m_impl;
};