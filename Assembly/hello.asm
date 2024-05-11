.data
	msg: .asciiz "Por favor, informe seu nome: "
	prefix: .asciiz "Olá-, Sr(a). "
	name: .space 20

.text
	li $v0, 4 # print string
	la $a0, msg
	syscall
	
	li $v0, 8 # read string
	la $a0, name
	la $a1, 20 # set buffer size
	syscall
	
	li $v0, 4
	la $a0, prefix
	syscall
	
	li $v0, 4
	la $a0, name
	syscall
