#pragma once

#include <IconsFontAwesome5.h>
#include <ToolboxUIPlugin.h>

class Follower : public ToolboxUIPlugin {
public:
    const char* Name() const override { return "Follower"; }
    const char* Icon() const override { return ICON_FA_DOLLY; }

    void Initialize(ImGuiContext*, ImGuiAllocFns, HMODULE) override;
    void Update(float) override;
    void Draw(IDirect3DDevice9*) override;
    void SignalTerminate() override;
    bool CanTerminate() override;
    void Terminate() override;

    void LoadSettings(const wchar_t*) override;
    void SaveSettings(const wchar_t*) override;
    void DrawSettings() override;
};
