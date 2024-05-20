# GWToolbox++ Plugins

## $${\color{red}For an official GWToolbox plugin, check the gwdevhub/gwtoolboxpp repository. This repository is merely allow people to set up their own plugins in a convenient fashion. Do not file any complaints or refer to this, use it at your own discretion.}$$

## A set of plugins for the popular Guild Wars 1 tool "GWToolbox"

If you don't know what GWToolbox is, see [https://gwtoolbox.com](https://gwtoolbox.com)

## How to download, build, and run
### Requirements
* Visual Studio 2022 version 17.7+. You can download [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) for free. You will also need the "Desktop development with C++" package.
* C++23 compatible v143 MSVC Platform Toolset
* Windows 11 SDK
* CMake 3.16 or higher. This is integrated in the [Visual Studio Developer PowerShell](https://learn.microsoft.com/en-us/visualstudio/ide/reference/command-prompt-powershell?view=vs-2022). Alternatively download the latest version from [https://cmake.org/download/](https://cmake.org/download/).
* [Git](https://git-scm.com/)

1. Open **Git Bash**. Use all the following commands in **Git Bash**. 

2. Clone the repository: 
`git clone https://github.com/DubbleClick/ToolboxPlugins.git`

3. Navigate to the ToolboxPlugins folder: 
`cd ToolboxPlugins`

4. Build: `cmake -B build`

5. Open: `cmake --open build`

6. Build the solution.

7. Copy the resulting dlls in `bin/Debug` or `bin/Release` to your GWToolbox plugin folder. Default is `%USERPROFILE%/GWToolboxpp/<ComputerName>/plugins`
