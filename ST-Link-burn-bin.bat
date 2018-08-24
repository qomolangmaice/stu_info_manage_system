@echo off
setlocal

:: Be sure to install the ST-LINK drivers and Utility application for Windows
:: Location of ST-LINK_CLI.exe, which is part of the Utility application
:: set STLINKUTIL="C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe"
set STLINKUTIL="C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\Insight3.exe"

set BIN_PATH="C:\Users\W001602\Desktop\M4-burn-file\m4-release\V100.000.000"

set BOOTLOADER=bootloader.bin
set APP=app.bin

set BOOTLOADER_START_ADDR=0x08000000
set APP_START_ADDR=0x08020000

echo [#] Checking JTAG ...
::call :CheckSTLink
%STLINKUTIL% -List

echo [#] Connect to device ...
%STLINKUTIL% -c SWD

echo [#] Erase full flash ...
%STLINKUTIL% -ME

echo [#] Flash '%BIN_PATH%\%BOOTLOADER%' at %BOOTLOADER_START_ADDR% ...
%STLINKUTIL% -V -P %BIN_PATH%\%BOOTLOADER% %BOOTLOADER_START_ADDR%

echo [#] Flash '%BIN_PATH%\%APP%' at %APP_START_ADDR% ...
%STLINKUTIL% -V -P %BIN_PATH%\%APP% %APP_START_ADDR%

echo [#] System Reset ...
%STLINKUTIL% -Rst

:end
::延迟时间
for /l %%i in (1,1,10000) do echo %%i>nul
goto :eof

:: function CheckSTLink: check ST-LINK adpater exists
:: Input:
:: Output: ERRORLEVEL
:CheckSTLink
%STLINKUTIL% -List

:: function Connect: connect to the device
:: Input:
:: Output: ERRORLEVEL
:Connect
%STLINKUTIL% -c SWD

:: function EraseFlash: full chip erase
:: Input:
:: Output: ERRORLEVEL
:EraseFlash
%STLINKUTIL% -ME

:: function Flash: Load firmware of FILE into ADDRESS and verify
:: Input: FILE - filepath, ADDRESS - location in flash
:: Output: ERRORLEVEL
:Flash
%STLINKUTIL% -V -P %FILE% %ADDRESS%