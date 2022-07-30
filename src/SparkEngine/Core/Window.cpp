#include <SparkEngine/Core/Window.hpp>
#include <SparkEngine/Core/WindowImpl.hpp>

#ifdef WIN32

#include <SparkEngine/Core/Platform/Win32/WindowImplWin32.hpp>
using WindowImplType = WindowImplWin32;

#endif

Window::Window()
{
    m_impl = new WindowImplType();
}

Window::Window(std::string title, Vector2u size)
{
    m_impl = new WindowImplType(title, size);
}

Window::~Window()
{
    delete m_impl;
}

void Window::create(std::string title, Vector2u size)
{
    m_impl->create(std::move(title), size);
}

void Window::destroy()
{
    m_impl->destroy();
}

bool Window::processMessages()
{
    return m_impl->processMessages();
}

bool Window::isOpen() const
{
    return m_impl->isOpen();
}