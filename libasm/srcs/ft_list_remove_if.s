; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_remove_if.s                                :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:37:09 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 17:20:19 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_list_remove_if
extern free
ft_list_remove_if:
	push r13
	push r14
	push r15
	mov r13, rsi
	mov r14, rdi
	mov r15, rdx
loop1:
	mov r9, [r14]
	cmp r9, 0
	je end2
	mov r10, [r9 + 8]
	mov rdi, [r9]
	mov rsi, r13
	call r15
	cmp eax, 0
	mov r11, [r10 + 8]
	jne loop2
	mov rdi, r9
	push r10
	call free wrt ..plt
	pop r10
	mov [r14], r10
	cmp qword [r14], 0
	je end2
	jmp loop1
loop2:
	cmp qword r10, 0
	je end2
	mov rdi, [r10]
	mov rsi, r13
	call r15
	cmp eax, 0
	jne next1
	mov [r9 + 8],r11
	mov rdi, r10
	push r9
	call free wrt ..plt
	pop r9
 	cmp r11, 0
	je end2
	mov r10, [r9 + 8]
	mov r11, [r10 + 8]
	jmp loop2
next1:
	mov r9,[r9 + 8]
	cmp r9, 0
	je loop1
	mov r10,[r9 + 8]
	cmp r10, 0
	je loop2
	mov r11,[r10 + 8]
	jmp loop2
end2:
	pop r15
	pop r14
	pop r13
	ret