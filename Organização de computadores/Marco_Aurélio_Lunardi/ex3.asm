.data 
vector: .word -2, 5, 10, 4, 8, -1, -5, 7, 9, 1
size: .word 10
str: .string "  "


	.text
main:	
	call print
	j end

print:
	la a0, vector
	lw a1, size
	li a2, 1
	
loop:
	blt a1, a2, fim_loop
	mv t2, a0
	lw a0, 0(a0)
	li a7, 1
	ecall
	la a0, str
	li a7, 4
	ecall
	mv a0, t2
	addi a0, a0, 4
	addi a2, a2, 1
	j loop
	
fim_loop:
	ret
	
	
end:
	nop