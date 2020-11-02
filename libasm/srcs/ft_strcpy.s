; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:40:29 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 02:40:30 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_strcpy
ft_strcpy:
mov rax, rdi
loop:
	cmp byte [rsi] , 0
	movsb
	jne loop
	ret