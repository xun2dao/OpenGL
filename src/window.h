#pragma once
#include <string>

struct WindowProps {
        std::string Title;
        int Width;
        int Height;
        bool VSync;
        WindowProps(const WindowProps &props)
            : Title(props.Title), Height(props.Height), Width(props.Width),
              VSync(props.VSync) {
        }

        WindowProps(std::string title, int width, int height, bool vsync)
            : Title(title), Height(height), Width(width),
              VSync(vsync) {
        }
};

class Window {
    public:
        Window(WindowProps& props): m_Props(props){} 
        virtual int GetHeight() const = 0;
        virtual int GetWidth() const = 0;
        virtual void Update() const = 0;
        virtual bool IsSync() const = 0;
        virtual void SetSync(bool flag) = 0;
        virtual void *GetNativeWindow() const = 0;
        virtual std::string GetTitle() const = 0;
        virtual void SetTitle(std::string) = 0;
        virtual bool IsStop() const = 0;
        virtual ~Window(){};

    protected:
        WindowProps m_Props;
};

extern Window *InitWindow(WindowProps &);
