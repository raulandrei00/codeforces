@echo off
if "%~1"=="" (
    echo Usage: run.bat filename.cpp
    exit /b 1
)
set FILE=%~n1
set OUTDIR=exec

rem Create the exec directory if it doesn't exist
if not exist "%OUTDIR%" mkdir "%OUTDIR%"

g++ -std=c++17 -Wall -O2 -DLOCAL "%~1" -o "%OUTDIR%\%FILE%.exe"
if %errorlevel% neq 0 exit /b %errorlevel%

"%OUTDIR%\%FILE%.exe"