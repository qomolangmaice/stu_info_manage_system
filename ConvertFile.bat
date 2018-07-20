@echo off

set DestPath=C:\Users\it-share50\Desktop\src-code\app

rem 你的后缀
set DestExtH=*.h
set DestExtC=*.c
set DestExtS=*.s
set DestExtSCT=*.sct
set DestExtMAP=*.map

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtH%') do (echo %%i)
for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtH%') do (call :ConvertH %%i)

for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtC%') do (call :ConvertC %%i)

for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtS%') do (call :ConvertS %%i)

for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtSCT%') do (call :ConvertSCT %%i)

for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtMAP%') do (call :ConvertMAP %%i)

::延迟时间
for /l %%i in (1,1,10000) do echo %%i>nul

:ConvertH
echo [#] Convert '%1'
type %1 > %1.h1
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:ConvertC
echo [#] Convert '%1'
type %1 > %1.c1
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:ConvertS
echo [#] Convert '%1'
type %1 > %1.s1
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:ConvertSCT
echo [#] Convert '%1'
type %1 > %1.sct1
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:ConvertMAP
echo [#] Convert '%1'
type %1 > %1.map1
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof