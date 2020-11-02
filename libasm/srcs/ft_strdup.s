; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:40:36 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 02:40:42 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc
ft_strdup:
	push rdi
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc wrt ..plt
	pop rsi
	mov rdi, rax
	call ft_strcpy
	ret
