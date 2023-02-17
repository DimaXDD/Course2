.586P																;система команд(процессор Pentium)
.MODEL FLAT, STDCALL												;модель памяти, соглашение о вызовах
;includelib ucrt.lib													; библиотека времени исполнения C
includelib libucrt.lib
includelib kernel32.lib												;компоновщику: компоновать с kernel32
includelib "..\Debug\LP_asm01d.lib"

ExitProcess			PROTO	: DWORD											;прототип функции для заверения процесса Windows
system				PROTO C : DWORD											;вызов cmd-команды
GetStdHandle		PROTO	: DWORD											;получить handle вывода на консоль
printConsole		PROTO : DWORD, : DWORD									;вызов процедуры вывода в консоль
																			;(-10 ввод,-11 вывод , -12 ошибка устройства вывода)
WriteConsoleA		PROTO	: DWORD, : DWORD, : DWORD, : DWORD, : DWORD		;вывод на консоль(стандартная фукция)
SetConsoleTitleA	PROTO	: DWORD										;устанавливает заголовок окна консоли (ANSI)

EXTRN getmin : proc
EXTRN getmax : proc
EXTRN get_pause : proc

SetConsoleOutputCP	PROTO : DWORD									;устанавливает номер входной кодовой строки
																	;страницы для терминала
SetConsoleCP PROTO : DWORD											;устанавливает номер выходной кодовой страницы для терминала


.STACK 4096															;выделение стека

.CONST																;сегмент констант
endl		equ 0ah													;символ перевода строки (ANCI)
str_endl	byte endl, 0											; строка "конец строки"
str_pause	db 'pause', 0
zero		byte 40 dup(0)


.DATA																;сегмент данных
Array			SDWORD	 -5, 5, 23, -1, 25, 9, -4, 22, 9, 0	
consoleTitle	BYTE	'My Console | ТрубачДмитрий 2-5 Win-1251',0				;82h, 0e1h, 0a5h, 0a2h, 0aeh, 0abh, 0aeh, 0a4h
text			BYTE	 "Трубач : getmax - getmin = "
string			BYTE	 40 dup(0)
min_string		BYTE	"Минимальное значение = "
min_str			BYTE	 40 dup(0)
max_string		BYTE	"Максимальное значение = "
max_str			BYTE	 40 dup(0)
array_string	BYTE	"Массив:",0


messageSize		DWORD	?
min				SDWORD	?
max				SDWORD	?
result			SDWORD	?


HW				=($ - text)											;вычисление длины строки text
consolehandle	DWORD 0h											;состояние консоли

.CODE																;сенмент кода

int_to_char PROC uses eax ebx ecx edi esi,
					pstr		: dword, ;адрес строки результата
					intfield	: sdword ;число для преобразования

	mov edi, pstr
	mov esi, 0
	mov eax, intfield												;число -> в eax
	cdq
	test eax, 80000000h													;тестируем знаковый бит
	mov ebx, 10;
	idiv ebx														;eax = eax/ebx, остаток в edx(деление целых со знаком)
	jns plus														;если положительный то переходим на plus jz plus
	neg eax
	neg edx
	mov cl, '-'														;первый символ результата '-'
	mov [edi], cl													;первый символ результата '-'
	inc edi															;++edi

plus:
	push dx															;отстаток ->стек
	inc esi															;++esi
	test eax, eax													;eax == 0?
	jz fin															;если да то переход на fin
	cdq																;знак расростаняется с eax на edx
	idiv ebx  
	jmp plus														;безусловный переход на plus

fin:																;если в ecx кол-во не 0-ых остатков = кол-ву символов результата
	mov ecx, esi

write:																 ;цикл записи результата
	pop bx															 ;отстаок из стека ->bx
	add bl,'0'														 ;сформировали символ в bl
	mov [edi], bl													 ;bl -> в результат
	inc edi
	loop write														 ;если (--ecx)>0 переход на write
	ret
	
int_to_char ENDP

main PROC															;точка входа main
START :																;метка
		INVOKE SetConsoleOutputCP, 1251d
		INVOKE SetConsoleCP, 1251d
		;------------------------------------------------
		push LENGTHOF Array											;блок вывода минимального значение
		push OFFSET Array
		call getmin
		mov min, eax
		INVOKE int_to_char, OFFSET min_str, min
		INVOKE printConsole, OFFSET min_string, OFFSET  consoleTitle		;вывод в консоль
		INVOKE printConsole, OFFSET str_endl, OFFSET  consoleTitle
		;------------------------------------------------
		push LENGTHOF Array											;блок вывода максимального значение
		push OFFSET Array
		call getmax						
		mov max, eax
		INVOKE int_to_char, OFFSET max_str, max
		INVOKE printConsole, OFFSET max_string, OFFSET  consoleTitle		;вывод в консоль
		INVOKE printConsole, OFFSET str_endl, OFFSET  consoleTitle
		;------------------------------------------------
		sub eax, min														;блок разницы между минимальным и максимальным
		mov result, eax
		INVOKE int_to_char, OFFSET string, result
		INVOKE printConsole, OFFSET text, OFFSET  consoleTitle		;вывод в консоль
		INVOKE printConsole, OFFSET str_endl, OFFSET  consoleTitle
		;------------------------------------------------
																	
		call get_pause												;system("pause")	
		push - 1													;код возврата процесса Windows(параметр ExitProcess)
		call ExitProcess											;так завершается любой процесс Windows


main ENDP															;конец процедуры
;-----------------printConsole-------------------------------------------------------------
printConsole	 PROC uses eax ebx ecx edi esi,
						pstr	: dword,
						ptitle	: dword

	INVOKE SetConsoleTitleA, ptitle
	INVOKE GetStdHandle, -11
	mov esi, pstr													;подсчет количества симвлов 
	mov edi, -1														;до 0 символа
count:																;выводимой
	inc edi															;на консоль строки
	cmp byte ptr [esi+edi], 0
	jne count														;если не 0-символ, на метку  count

	INVOKE WriteConsoleA, eax, pstr, edi, 0, 0						;вывод в консоль

	ret
printConsole ENDP



end main															;конец модуля main

		