; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_size.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:39:06 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 02:39:09 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_list_size

ft_list_size:
	mov rax, 0
loop:
	cmp rdi, 0
	je end
	inc rax
	mov rdi, [rdi + 8]
	jmp loop
end:
	ret
