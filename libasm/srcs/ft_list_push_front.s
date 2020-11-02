; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_push_front.s                               :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/03 02:39:01 by sgertrud          #+#    #+#              ;
;    Updated: 2020/11/03 02:39:02 by sgertrud         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern malloc
global ft_list_push_front

ft_list_new:
	push rdi
	mov rdi, 16
	call malloc wrt ..plt
	pop qword [rax]
	mov qword [rax + 8], 0
	ret

ft_list_push_front:
	push rdi
	mov rdi, rsi
	call ft_list_new
	pop rdi
    cmp qword [rdi], 0
    je end
    mov r10, [rdi]
    mov [rax + 8], r10
end:
    mov [rdi], rax
    ret
