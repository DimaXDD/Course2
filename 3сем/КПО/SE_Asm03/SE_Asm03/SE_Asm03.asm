.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO :DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
	myBytes BYTE 10h, 20h, 30h, 40h					; 1 байт
	myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h			; 2 байта
	myDoubles DWORD 1, 2, 3, 4, 5, 6				; 4 байта
	myPointer DWORD myDoubles						; 4 байта

	massive DWORD 1, 2, 3, 4, 5, 6, 7				; массив из 7 чисел, для задания с)
	sumOfElements DWORD 0							; сумма элементов массива, для задания с)
	
	STR1 DB "Трубач Дмитрий Сергеевич", 0			
	STR2 DB "Есть нулевой элемент", 0 
	STR3 DB "Нулевого элемента не найдено", 0 

.CODE

main PROC
start: 
	mov ESI, 0
	mov EAX, myDoubles[ESI + 1] ; EAX = 33554432
	mov EDX, [myDoubles + ESI] ; EDX = 1

	;Вычислить сумму элементов массива. Результат запомнить в регистре EAX.
	mov ESI, OFFSET massive
	mov ECX, lengthof massive						; сугубо счётчик
	mov EBX, 1
CYCLE:
	mov EAX, [ESI]									; EAX = massive[ESI], ESI = massive[0]
	add sumOfElements, EAX							; sumOfElements = sumOfElements + EAX, добавляем то, что в EAX
	add ESI, type massive							; +4 байта
	cmp EAX, 0										; само сравнение
	jz ZERO
	loop CYCLE										; --ECX, if (ECX != 0) goto CYCLE
	jmp ALLOK

ZERO:
	mov EBX, 0	
	jz ZD1

ALLOK:
	mov eax, sumOfElements	
	jnz ZD2


ZD1:
	INVOKE MessageBoxA, 0, OFFSET Str2, OFFSET Str1, 1
	INVOKE ExitProcess, 2

ZD2:
	INVOKE MessageBoxA, 0, OFFSET Str3, OFFSET Str1, 1
	INVOKE ExitProcess, 2
	
push -1
call ExitProcess

main ENDP

end main
