; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:40:21 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 02:40:22 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_strcmp
extern ft_strlen
section .text
ft_strcmp:
	call	ft_strlen
	mov rcx, rax
	inc rcx
	repe cmpsb
	dec rdi
	dec rsi
	mov rax, 0
	movzx rax, byte [rdi]
	movzx rsi, byte [rsi]
	sub rax, rsi
	ret
