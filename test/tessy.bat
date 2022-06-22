cd C:\tessy\TESSY_4.3\bin\
::需修改
tessyd --file C:\Users\zhaozhongyi\Projects\TESSY\zhz\tessy\tessy.pdbx
tessycmd connect
tessycmd restore-db -target project
tessycmd exec-test C:\Users\zhaozhongyi\Desktop\zzy\zhz.tbs
tessycmd disconnect