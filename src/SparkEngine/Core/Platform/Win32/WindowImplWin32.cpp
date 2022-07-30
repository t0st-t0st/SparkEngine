#include <SparkEngine/Core/Platform/Win32/WindowImplWin32.hpp>

WindowImplWin32::WindowImplWin32()
{
    m_isOpen = false;
}

WindowImplWin32::WindowImplWin32(std::string title, Vector2u size)
{
    create(std::move(title), size);
}

WindowImplWin32::~WindowImplWin32()
{
    destroy();
}

void WindowImplWin32::create(std::string title, Vector2u size)
{
    m_title = std::move(title);
    m_size  = size;

    m_hInstance = GetModuleHandle(nullptr);
    m_className = m_title.c_str();

    WNDCLASS wndClass      = {};
    wndClass.lpszClassName = m_className;
    wndClass.hInstance     = m_hInstance;
    wndClass.hIcon         = LoadIcon(nullptr, IDI_WINLOGO);
    wndClass.hCursor       = LoadCursorA(nullptr, IDC_ARROW);
    wndClass.lpfnWndProc   = WindowImplWin32::globalOnEvent;

    RegisterClass(&wndClass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    m_hWnd = CreateWindowEx(0, m_className, m_title.c_str(), style, 0, 0, m_size.x, m_size.y, nullptr, nullptr, m_hInstance, nullptr);

    ShowWindow(m_hWnd, SW_SHOW);

    m_isOpen = true;
}

void WindowImplWin32::destroy()
{
    UnregisterClass(m_className, m_hInstance);
}

bool WindowImplWin32::processMessages()
{
    MSG msg = {};

    bool result = PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE);

    if (msg.message == WM_QUIT)
        m_isOpen = false;

    TranslateMessage(&msg);
    DispatchMessage(&msg);

    return result;
}

bool WindowImplWin32::isOpen() const
{
    return m_isOpen;
}

LRESULT WindowImplWin32::globalOnEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
        {
            DestroyWindow(hWnd);
            break;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
