@echo off
:loop
make_data
F
F0
fc F.out F0.out
if errorlevel == 1 pause
goto loop
