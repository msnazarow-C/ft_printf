; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_sort.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:39:45 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 17:32:04 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_list_sort
ft_list_sort:
	push r12
	push r14
	push r15
	mov r14, rdi
	mov r15, rsi
	mov r8, 1
loop1:
	cmp r8, 1
	jne end2
	mov r8, 0
	mov r9, [r14]
	mov r10, [r9 + 8]
	mov r11 , [r10 + 8]
	cmp r11, 0
	je loop1
	mov r12, [r11 + 8]
	mov rdi, [r9]
	mov rsi, [r10]
	call r15
	cmp eax, 0
	jle next3
	mov [r14],r10
	mov [r10 + 8], r9
	mov [r9 + 8], r11
	mov r8, r9
	mov r9, r10
	mov r10, r8
	mov r8, 1
	next3:
	cmp r11, 0
	je loop1
loop2:
	mov rdi, [r10]
	mov rsi, [r11]
	call r15
	cmp eax, 0
	jle next1
	mov [r9 + 8],r11
	mov [r11 + 8], r10
	mov [r10 + 8], r12
	mov r8, 1
	next1:
	cmp r12, 0
	je loop1
	mov r9,[r9 + 8]
	mov r10,[r10 + 8]
	mov r11,[r11 + 8]
	mov r12,[r12 + 8]
	jmp loop2
end2:
	pop r15
	pop r14
	pop r12 
	ret