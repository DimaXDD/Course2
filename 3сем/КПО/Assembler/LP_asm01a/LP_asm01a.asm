.586P																;система команд(процессор Pentium)
.MODEL FLAT, STDCALL												;модель памяти, соглашение о вызовах


getmin		PROTO : DWORD, : DWORD
getmax		PROTO : DWORD, : DWORD

.STACK 4096															;выделение стека

.CONST																;сегмент констант

.DATA																;сегмент данных
num  sdword ?

.CODE																;сенмент кода

getmin PROC parm1 : DWORD, parm2 : DWORD 
START:
	mov ecx, parm2
	mov esi, parm1
	mov eax, [esi]
	dec ecx
	add esi, 4
CYCLE:
	mov edx, [esi]
	cmp eax, edx
	jl minimum
	mov eax, edx
minimum:	
	add esi, 4
loop CYCLE
ret
getmin ENDP

getmax PROC parm1 : DWORD, parm2 : DWORD 
START:
	mov ecx, parm2
	mov esi, parm1
	mov eax, [esi]
	dec ecx
	add esi, 4
CYCLE:
	mov edx, [esi]
	cmp eax, edx
	jg maximum
	mov eax, edx

maximum:	
	add esi, 4
loop CYCLE

ret
getmax ENDP


END
