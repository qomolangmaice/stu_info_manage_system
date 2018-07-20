@echo off

set DestPath=C:\Users\it-share50\Desktop\src-code\app

rem 你的后缀
set DestExtH=*.h.h1
set DestExtC=*.c.c1
set DestExtS=*.s.s1
set DestExtSCT=*.sct.sct1
set DestExtMAP=*.map.map1

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtH%') do (echo %%i)

FOR /R %DestPath% %I IN (*.h.h1) DO REN "%I" *.h
FOR /R %DestPath% %I IN (*.c.c1) DO REN "%I" *.c
FOR /R %DestPath% %I IN (*.s.s1) DO REN "%I" *.s
FOR /R %DestPath% %I IN (*.map.map1) DO REN "%I" *.map
FOR /R %DestPath% %I IN (*.sct.sct1) DO REN "%I" *.sct

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtH%') do (call :RevertH %%i)

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtH%') do (call :RevertH %%i)

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtC%') do (call :RevertC %%i)

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtS%') do (call :RevertS %%i)

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtSCT%') do (call :RevertSCT %%i)

::for /f "delims=" %%i in ('dir /b/a-d/s %DestPath%\%DestExtMAP%') do (call :RevertMAP %%i)

::延迟时间
for /l %%i in (1,1,10000) do echo %%i>nul

:RevertH
echo [#] Revert '%1'
ren %1 *.h
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:RevertC
echo [#] Revert '%1'
ren %1 *.c
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:RevertS
echo [#] Revert '%1'
ren %1 *.s
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:RevertSCT
echo [#] Revert '%1'
ren %1 *.sct
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

:RevertMAP
echo [#] Revert '%1'
ren %1 *.map
echo=
echo [#] Delete '%1'
del %1
echo=
goto :eof

