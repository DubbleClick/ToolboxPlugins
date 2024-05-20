#include "AllowAllDialogs.h"

#include <GWCA/Utilities/Scanner.h>
#include <GWCA/Utilities/Hooker.h>

namespace {
    using IsDialogAvailable_pt = bool(__cdecl *)(unsigned int dialog_id);
    IsDialogAvailable_pt IsDialogAvailable_Func = nullptr;
    IsDialogAvailable_pt IsDialogAvailable_Ret = nullptr;

    bool OnIsDialogAvailable(unsigned int)
    {
        // Any other logic here.
        return true;
    }
}

DLLAPI ToolboxPlugin* ToolboxPluginInstance()
{
    static AllowAllDialogs instance;
    return &instance;
}

void AllowAllDialogs::SignalTerminate()
{
    if (IsDialogAvailable_Func)
        GW::HookBase::DisableHooks(IsDialogAvailable_Func);
}

bool AllowAllDialogs::CanTerminate()
{
    return GW::HookBase::GetInHookCount() == 0;
}

void AllowAllDialogs::Terminate()
{
    ToolboxPlugin::Terminate();
    GW::HookBase::RemoveHook(IsDialogAvailable_Func);
    GW::HookBase::Deinitialize();
}

void AllowAllDialogs::Initialize(ImGuiContext* ctx, ImGuiAllocFns fns, HMODULE toolbox_dll)
{
    ToolboxPlugin::Initialize(ctx, fns, toolbox_dll);

    GW::HookBase::Initialize();
    GW::Scanner::Initialize(toolbox_dll);
    const uintptr_t address = GW::Scanner::Find("\x25\x00\x00\x00\xFF\x74\x02", "xxxxxxx", 0xd);
    IsDialogAvailable_Func = reinterpret_cast<IsDialogAvailable_pt>(GW::Scanner::FunctionFromNearCall(address));

    if (IsDialogAvailable_Func) {
        GW::HookBase::CreateHook(reinterpret_cast<void**>(&IsDialogAvailable_Func), OnIsDialogAvailable, reinterpret_cast<void**>(&IsDialogAvailable_Ret));
        GW::HookBase::EnableHooks(IsDialogAvailable_Func);
    }
    else {
        MessageBox(nullptr, Name(), "Failed to get signature for IsDialogAvailable_Func", 0);
    }
}
