cd C:\Program Files\Razorcat\TESSY_4.3\bin
::需修改
tessyd --file C:\Users\yusenlin\Projects\TESSY\yu\tessy\tessy.pdbx
tessycmd connect
tessycmd restore-db -target project
tessycmd exec-test C:\Users\yusenlin\Projects\TESSY\yu\tessy\yu.tbs
tessycmd disconnect