set param=%1

set flags="-w"

gcc %flags% ^
    test.c ^
    vector.c ^
    -o a.exe

@echo off
if "%param%"=="run" (
    a.exe
)
