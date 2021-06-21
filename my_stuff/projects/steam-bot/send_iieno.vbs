Set oShell = CreateObject ("Wscript.Shell") 
Dim strArgs
strArgs = "cmd /c send.bat"
oShell.Run strArgs, 0, false
