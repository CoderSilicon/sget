@echo off
setlocal enabledelayedexpansion

echo ====================================================
echo  Sget intallation script
echo ====================================================

:: 1. Force Administrator privileges
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo [!] Error: This installation script must be run as Administrator.
    echo     Please right-click install.bat and select 'Run as administrator'.
    pause
    exit /b 1
)

:: 2. Define target path
set "INSTALL_DIR=C:\Program Files\sget"
echo [*] Staging target area: !INSTALL_DIR!

if not exist "!INSTALL_DIR!" (
    mkdir "!INSTALL_DIR!"
)

:: 3. Copy binary artifacts
if exist "sget.exe" (
    copy /Y "sget.exe" "!INSTALL_DIR!\sget.exe" >nul
    echo [+] Successfully deployed sget.exe engine.
) else (
    echo [!] Error: sget.exe not found in the current installation package directory.
    pause
    exit /b 1
)

:: 4. Safely inject into System PATH if not already present
echo %PATH% | findstr /I /C:"!INSTALL_DIR!" >nul
if %errorLevel% neq 0 (
    echo [*] Registering global environment path...
    setx /M PATH "%PATH%;!INSTALL_DIR!" >nul
    echo [+] Path registration verified.
) else (
    echo [*] System environment PATH registration already active.
)

echo ====================================================
echo [+] Installation Complete! Restart your terminal.
echo     Invoke globally using: sget --info [URL]
echo ====================================================
pause