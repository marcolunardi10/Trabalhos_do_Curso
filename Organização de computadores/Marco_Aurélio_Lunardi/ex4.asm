.data 
vector: .word -2, 5, 10, 4, 8, -1, -5, 7, 9, -10, 6, 11, -7, 13, -3
size: .word 15
str: .string "  "


	.text
main:	
	call ord
	j end

ord:
    la a0, vector
    lw a1, size
    li a2, 0 
    
loop:
    blt a1, a2, end_loop
    lw t3, 0(a0)
    lw t4, 4(a0)
    blt t4, t3, swap
    addi a0, a0, 4
    addi a2, a2, 1
    j loop
 	

swap:
    sw t4, 0(a0)
    sw t3, 4(a0)
    j ord
    
end_loop:
    la a0, vector
    lw a1, size
    li a2, 0

print:
	beq a1, a2, fim_loop
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
	j print	
	
fim_loop:
	ret
	
	
end:
	nop