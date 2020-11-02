; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:40:45 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 02:40:46 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_strlen
ft_strlen:
	mov rax, -1
loop:
	inc rax
	cmp byte [rdi + rax], 0
	jne loop
	ret