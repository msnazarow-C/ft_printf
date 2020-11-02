; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:40:47 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 02:40:55 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern __errno_location
global ft_write
ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jge end
	push rax
	call __errno_location wrt ..plt
	pop qword [rax]
	neg qword [rax]
	mov rax, -1
end:
	ret