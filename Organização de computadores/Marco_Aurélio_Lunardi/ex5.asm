	.data 
str: .space 100
saida: .space 100

	.text
main:	
	call leitura
	j end

leitura:
	la a0, str
	li a1, 256
	li a7, 8
	ecall
	la a1, saida
	li t0, 0
	li t1, 1
	
loop:
    lb t2, 0(a0)
    beqz t2, fim
    
    li t3, 'a'
    beq t2, t3, proximo
    li t3, 'e'
    beq t2, t3, proximo
    li t3, 'i'
    beq t2, t3, proximo
    li t3, 'o'
    beq t2, t3, proximo
    li t3, 'u'
    beq t2, t3, proximo
    li t3, 'A'
    beq t2, t3, proximo
    li t3, 'E'
    beq t2, t3, proximo
    li t3, 'I'
    beq t2, t3, proximo
    li t3, 'O'
    beq t2, t3, proximo
    li t3, 'U'
    beq t2, t3, proximo
    
    sb t2, 0(a1)
    addi a1, a1, 1  
    
proximo:
    addi a0, a0, 1  
    j loop 
    
fim:

    sb zero, 0(a1)
    la a0, saida  
    li a7, 4  
    ecall  
    ret

end:
	nop
	


	
