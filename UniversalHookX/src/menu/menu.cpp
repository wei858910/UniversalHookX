#include "menu.hpp"

#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_impl_win32.h"

namespace ig = ImGui;

namespace Menu {
    void InitializeContext(HWND hwnd) {
        if (ig::GetCurrentContext( ))
            return;

        ImGui::CreateContext( );
        ImGui_ImplWin32_Init(hwnd);

        ImGuiIO& io = ImGui::GetIO( );
        io.IniFilename = io.LogFilename = nullptr;
        // 添加中文字体 (以微软雅黑为例)
        // 参数1: 字体文件路径
        // 参数2: 字体大小 (18.0f 只是一个示例，可以按需修改)
        // 参数4: 设置字符集范围，io.Fonts->GetGlyphRangesChineseFull() 会加载全部中文字符
        ImFont* font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 18.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull( ));
    }

    void Render( ) {
        if (!bShowMenu)
            return;

        ig::ShowDemoWindow( );
    }
} // namespace Menu
