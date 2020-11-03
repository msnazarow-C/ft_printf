; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_atoi_base_bonus.s                               :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:38:59 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 23:58:59 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_atoi_base_bonus
ft_atoi_base:
	mov rax, 0
	mov r9, 0
	mov r10, 1
pass:
	cmp byte [rdi],9
	jl end
	cmp byte [rdi],13
	jle l6
	cmp byte [rdi],32
	jne l1
l6:
	inc rdi
	jmp pass
l1:
	cmp byte [rdi],43
	jne l2
	inc rdi
	jmp l3
l2:
	cmp byte [rdi],45
	jne l3
	inc rdi
	mov r10,-1
l3:
	cmp rsi, 10
	jle l4
	mov r11, 'A'
	add r11, rsi
	sub r11, 10
l7:
	cmp byte [rdi], 'A'
	jl l4
	cmp byte [rdi], r11b
	jge end
	mul rsi
	mov r9b, byte [rdi]
	add rax, r9
	sub rax, 'A'
	add rax, 10
	inc rdi
	jmp l7
l4:
	cmp byte [rdi], '0'
	jl end
	cmp byte [rdi], '9'
	jg end
	mul rsi
	mov r9b, byte [rdi]
	add rax, r9
	sub rax, '0'
	inc rdi
	jmp l7
end:
	imul r10
	ret
