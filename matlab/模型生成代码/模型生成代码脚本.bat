@echo off&&setlocal enabledelayedexpansion
matlab -nojvm -nodesktop -nodisplay -r "run('G:\zzy\project\model\TRSP_V2\compile.m')"
::注意修改compile.m地址，compile.m存放于你想要的模型路径下

::taskkill /f  /im matlab.exe
