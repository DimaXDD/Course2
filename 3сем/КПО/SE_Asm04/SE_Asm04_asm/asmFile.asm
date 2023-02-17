.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

OK			EQU	0
TEXT_MESSAGE		DB "SE_Asm04", 0
HW			DD ?

FILESHORT DD 1, 2, 3, 4
SHORTSTR DB "short:    ", 0

FILEUSHORT16 DD 3, 5, 6
USHORT16STR DB "ushort16:     ", 0

.CODE

main PROC



mov eax, FILESHORT 
add eax, 30h
mov SHORTSTR +8, al


mov eax, FILESHORT  + type FILESHORT
add eax, 30h
mov SHORTSTR +9, al


mov eax, FILESHORT  + type FILESHORT + type FILESHORT
add eax, 30h
mov SHORTSTR +10, al


mov eax, FILESHORT  + type FILESHORT + type FILESHORT + type FILESHORT
add eax, 30h
mov SHORTSTR +11, al
invoke MessageBoxA, 0, offset SHORTSTR, ADDR TEXT_MESSAGE, OK


mov eax, FILEUSHORT16 
add eax, 30h
mov USHORT16STR + 10, al


mov eax, FILEUSHORT16  + type FILEUSHORT16
add eax, 30h
mov USHORT16STR + 11, al


mov eax, FILEUSHORT16  + type FILEUSHORT16 + type FILEUSHORT16
add eax, 30h
mov USHORT16STR + 12, al
invoke MessageBoxA, 0, offset USHORT16STR, ADDR TEXT_MESSAGE, OK
push - 1
call ExitProcess
main ENDP
end main
