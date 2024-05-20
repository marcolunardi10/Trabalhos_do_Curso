	.data 
simT: .string "É TRIÂNGULO"
naoT: .string "NÃO É TRIÂNGULO"

	.text
main:	
	li a7, 5
	ecall
	mv a1, a0
	li a7, 5
	ecall
	mv a2, a0
	li a7, 5
	ecall
	call calculo
	li, a7, 4
	ecall
	j end
	
teste_ac:
	bgt a0, a2, maior_A
	mv  a4, a2  
	add a5, a0, a1 
	j triangulo
	
maior_A:
	mv a4, a0
	add a5, a1, a2
	j triangulo

maior_B:	
	mv a4, a1
	add a5, a0, a2 
	j triangulo
	
triangulo:
	bgt a5, a4, sim
	la a0, naoT
	ret

sim:
	la a0, simT
	ret
	
calculo:
	bgt a0, a1, teste_ac
	bgt a1, a2, maior_B
	mv  a4, a2
	add a5, a0, a1 
	j   triangulo


end:
	nop
	


	
