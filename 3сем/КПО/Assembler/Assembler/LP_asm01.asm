		.586P																;система команд(процессор Pentium)
	.MODEL FLAT, STDCALL												;модель памяти, соглашение о вызовах
	includelib kernel32.lib												;компоновщику: компоновать с kernel32

	ExitProcess PROTO : DWORD											;прототип функции для заверения процесса Windows
	MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD				;прототип API-функции MessageBoxA
	getmin		PROTO : DWORD, : DWORD
	getmax		PROTO : DWORD, : DWORD

	.STACK 4096															;выделение стека

	.CONST																;сегмент констант

	.DATA																;сегмент данных
	Array	SDWORD 1, 5, 6, -1, 8, 9, -4, 22, 9, 0													;												
	min		SDWORD ?
	max		SDWORD ?
	num		DB	5

	MB_OK	EQU 0														;EQU определяет константу
	STR1	DB "Task1a:",	0								;строка, первый элемент данные + нулевой бит
	STR2	DB "Наименьшее значение в массиве: 0 ", 0										;строка, первый элемент данные + нулевой бит
	mas		dword	0h, 1h, 2h, 3h
	mas1	dword	4 dup(7h)
	HW		DWORD ?														;двойное слово длиной 4 байта, неинициализированно

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
	mov min, eax
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
mov max, eax
ret


getmax ENDP

	main PROC															;точка входа main
	START :																;метка
			INVOKE getmin, OFFSET Array, LENGTHOF Array
			INVOKE getmax, OFFSET Array, LENGTHOF Array
	
			;mov al, num
			;add STR2[31], al
			INVOKE MessageBoxA, 0, OFFSET STR2, OFFSET STR1, 0
			
		push - 1														;код возврата процесса Windows(параметр ExitProcess)
		call ExitProcess												;так завершается любой процесс Windows


	main ENDP															;конец процедуры


	end main															;конец модуля main


		