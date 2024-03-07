@echo off

REM Get the current date and time
setlocal EnableDelayedExpansion
for /f "tokens=1,2 delims=/ " %%a in ('date /t') do (set mm=%%a& set dd=%%b)
for /f "tokens=1,2 delims=:, " %%a in ('time /t') do (set hh=%%a& set min=%%b)
set datetime=!dd!-!mm! !hh!:!min!
endlocal

REM Perform git operations
git add .
git commit -m "auto commit %datetime%"
git push