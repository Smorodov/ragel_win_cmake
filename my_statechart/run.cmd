.\..\build\Release\ragel -Vp statechart.rl > statechart.dot
dot -Tpng statechart.dot >statechart.png
.\..\build\Release\ragel statechart.rl
.\..\tinycc\win32\tcc.exe statechart.c
statechart.exe < test.txt
pause