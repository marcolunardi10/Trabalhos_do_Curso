	.data 
str: .string "bbababb"
size: .word 7
simP: .string "É UM PALINDROME"
naoP: .string "NÃO É UM PALINDROME"

	.text
main:	
	call palindrome
	li, a7, 4
	ecall
	j end

palindrome:
	la a0, str
	la a1, size
	lw a1, 0(a1)
	add a1, a0, a1
	addi a1, a1, -1
	
checar:
	bge a0, a1, sim
	lb t1, 0(a0)
	lb t2, 0(a1)
	bne t1, t2, nao
	addi a0, a0, 1
    	addi a1, a1, -1
	j checar
	
nao: 
	la a0, naoP
	ret

sim: 
	la, a0, simP
	ret
	
end:
	nop
	


	
