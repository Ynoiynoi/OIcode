:loop
data.exe>1.txt
q.exe<1.txt>2.txt
QAQ.exe<1.txt>3.txt
fc 2.txt 3.txt
if errorlevel 1 goto die
goto loop
:die
pause