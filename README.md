# 🌟 fn-instant-performance-mode 🌟

![Screenshot 2024-06-15 012812](https://github.com/kopithe/fn-instant-performance-mode/assets/166122699/b764d806-f82f-4e6f-af35-95abb30c94dd)
![ezgif-1-43b53ae285](https://github.com/kopithe/fn-instant-performance-mode/assets/166122699/597e33d3-b04d-4f17-b00b-d40c551c2727)

A powerful Fortnite C++ tool that allows users to launch Fortnite using Performance Mode/DirectX 11 instead of DirectX12 for the first time, while also skipping those pesky trailers. Created to enhance user experience by eliminating annoying game restarts and trailers after reinstalling Windows.

## 🛠️ Explanation

- 🚀 **Dynamic Console Title**: Uses a randomly generated console title that changes every 0.25 seconds.
- 🔄 **Automatic Updater**: Checks the software version against a server-hosted version (e.g., using [netlify.app](https://www.netlify.com/)). Notifies the user if an update is available.
- 🎮 **Graphics Mode Selection**: Allows users to choose between Performance Mode and DirectX 11. Downloads necessary files and configures settings to optimize gameplay.
- 🧹 **Cleanup**: Automatically deletes all temporary files and folders after configuration.

## 🔄 Auto Updater

- 🌐 **Version Check**: Compares the current software version with the latest version on the server using an HTTP GET request.
- 📥 **Seamless Updates**: If an update is available and the user consents, the new file is downloaded, executed, and the outdated file is deleted.

![Screenshot 2024-06-15 013516](https://github.com/kopithe/fn-instant-performance-mode/assets/166122699/68ee292e-a705-4d8c-9cca-da7a9dc0857f)

## 📜 Changelogs

### 🛡️ Hash Checker

- 🆕 **New Feature**: Added a server-side hash checker that verifies the integrity of the user's files.

![Screenshot 2024-06-15 090308](https://github.com/kopithe/fn-instant-performance-mode/assets/166122699/7e45a37f-38d8-41f3-9f89-cc6711f8ceb2)
![Screenshot 2024-06-15 090253](https://github.com/kopithe/fn-instant-performance-mode/assets/166122699/021298a5-52aa-4c2a-bd0a-e3fa2b90c926)

### How to Use

Open a PowerShell terminal and type `Get-FileHash` followed by the path of the executable. To get the path, you can drag and drop the executable into the PowerShell terminal.
Example: `Get-FileHash C:\Source\example.exe`.

## 📈 Updates

Fortnite updates often change the trailers. I'll keep this tool updated to match the latest game patches!

## 📋 To-Do List

- 🆕 Add multiple choices for different performance modes (e.g., 160FPS and 240FPS options).
- 🆕 Add DirectX 11 and DirectX 12 support.
- 🛡️ Add an anti-debugger to detect HTTP debuggers.
- ✔️ ~~Make the PowerShell extraction command invisible to the user or run in the background~~ (Almost finished).

## 🚀 Usage

To use or adapt this tool, update the version and download URLs to match your needs.

## 📄 License

This project is licensed under the MIT License. For more information, please read the LICENSE file.
