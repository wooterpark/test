@echo off&&setlocal enabledelayedexpansion
findstr	"excluding"	.cproject>>list_excluding.txt
for /f "delims=" %%i in (list_excluding.txt) do (
	set var=%%i
	set "var=!var:						<entry excluding=!"
	::去空格，一般不需要修改
	set var=!var:~2,-69!
	::掐头去尾，一般不需要修改
	set "var=!var:/=\!"
	echo	!var!>>list_excluding_c.txt
)