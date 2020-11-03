; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_atoi_base.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 23:54:44 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 23:54:50 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_atoi_base
extern ft_strlen

ft_skip_spaces:
pass:
	cmp byte [rdi],9
	jl end
	cmp byte [rdi],13
	jle l6
	cmp byte [rdi],32
	jne end
l6:
	inc rdi
	jmp pass
end:
	cmp byte [rdi],43
	jne l2
	inc rdi
	jmp end4
l2:
	cmp byte [rdi],45
	jne end4
	inc rdi
	mov r12, -1 ;znak
end4:
	mov rax, rdi
	ret

ft_check_rep:
	mov rdx, 0
	mov rcx, 255
	mov rax, check
loop5:
	cmp byte [rax + rcx], 0
	je next5
	mov byte [rax + rcx], 0
next5:
	loop loop5
loop3:
	cmp byte [rdi + rcx], 0
	je end3
	mov dl, byte [rdi + rcx]
	cmp dl ,9
	jl next1
	cmp dl ,13
	jle error3
	cmp dl ,32
	je error3
	cmp dl ,43
	je error3
	cmp dl ,45
	je error3
next1:
	inc byte [rax + rdx]
	cmp byte [rax + rdx], 1
	jg error3
	inc rcx
	jmp loop3
	mov rax, 1
	ret
error3:
	mov rax, -1
	ret
end3:
	mov rax, 1
	ret
ft_chr_to_number:
	mov rax, 0
loop1:
	cmp dil ,13
	jle error1
	cmp dil ,32
	je error1
	cmp dil ,43
	je error1
	cmp dil ,45
	je error1
	cmp byte [rsi + rax] , 0
		je error1
	cmp dil, byte [rsi + rax]
		je end1
	inc rax
		jmp loop1
error1:
	mov rax, -1
end1:
	ret

ft_atoi_base:
	push r12
	mov r12, 1
	mov r8, 0
	mov r9, 0
	mov r11, 0 ; answer

	call ft_skip_spaces
	mov rdi, rax
	call ft_strlen
	cmp rax, 0
	je error2
	mov rcx, rax
	push rdi
	mov rdi, rsi
	call ft_strlen
	pop rdi
	cmp rax, 1
	jle error2
	mov r10,rax ; base
	push rdi
	mov rdi, rsi
	push rcx
	call ft_check_rep
	pop rcx
	pop rdi
	cmp rax, 0
	jle error2

loop2:
	push rdi
	mov dil, byte [rdi + r8]
	call ft_chr_to_number
	pop rdi
	cmp rax, 0
	jl error2
	push rax
	mov rax, r11
	mul r10
	add rax, [rsp]
	mov r11, rax
	pop rax
	inc r8
	loop loop2
	jmp end2

error2:
	pop r12
	mov rax, 0
	ret
end2:
	mov rax, r11
	mul r12
	pop r12
	ret
section .data
	check times 256 db 0