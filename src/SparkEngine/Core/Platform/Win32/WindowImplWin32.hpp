#pragma once

#include <SparkEngine/Core/Export.hpp>

#include <SparkEngine/Core/WindowImpl.hpp>

#include <Windows.h>

#include <string>

class CORE_API WindowImplWin32 final : public WindowImpl
{
public:
    WindowImplWin32();

    WindowImplWin32(std::string title, Vector2u size);

    ~WindowImplWin32() override;

public:
    void create(std::string title, Vector2u size) override;
    void destroy() override;

    bool processMessages() override;

    bool isOpen() const override;

private:
    static LRESULT CALLBACK globalOnEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    HINSTANCE   m_hInstance;
    HWND        m_hWnd;
    LPCSTR      m_className;
    std::string m_title;
    Vector2u    m_size;
    bool        m_isOpen;
};