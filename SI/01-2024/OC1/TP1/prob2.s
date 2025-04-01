.data

##### R1 START MODIFIQUE AQUI START #####

#
# Este espaço é para você definir as suas constantes e vetores auxiliares.
#

vetor1: .word 1 2 3 4 #Primeiro vetor
vetor2: .word 1 1 1 1 #Segundo vetor

##### R1 END MODIFIQUE AQUI END #####
      
.text
    add s0, zero, zero
    la a0, vetor1
    addi a1, zero, 4
    jal ra, media
    addi t0, zero, 2
    bne a0,t0,teste2
    addi s0,s0,1
teste2: 
    la a0, vetor2
    addi a1, zero, 4
    jal ra, media
    addi t0, zero, 1
    bne a0,t0, FIM
    addi s0,s0,1
testeCov:
    la a0, vetor1 #Ponteiro Vetor 1
    la a1, vetor2 #Ponteiro Vetor 2
    addi a2, zero, 4        #Quantidade de elementos dos vetores
    jal ra, covariancia
    addi t0, zero, 0
    bne a0,t0, FIM
    addi s0,s0,2
    beq zero,zero, FIM

##### R2 START MODIFIQUE AQUI START #####

# Esse espaço é para você escrever o código dos procedimentos. 
# Por enquanto eles estão vazios

covariancia:
		# Calcular média de vetor1
        la a0, vetor1
        addi a1, zero, 8
        add t6, zero, ra
        jal ra, media
        add ra, zero, t6
        add s1, a0, zero  	# Média de vetor1 em s1

        # Calcular média de vetor2
        la a0, vetor2
        addi a1, zero, 8
        add t6, zero, ra
        jal ra, media
        add ra, zero, t6
        add s2, a0, zero  # Média de vetor2 em s2

        # Calcular covariância entre vetor1 e vetor2
        la a0, vetor1
        la a1, vetor2
        addi a2, zero, 8
        add a3, s1, zero  # Média de vetor1
        add a4, s2, zero  # Média de vetor2
        
calcula_covariancia:
        addi sp, sp, -28       # Reserva espaço na pilha
        sw ra, 24(sp)          # Salva o endereço de retorno
        sw t0, 20(sp)          # Salva t0
        sw t1, 16(sp)          # Salva t1
        sw t2, 12(sp)          # Salva t2
        sw t3, 8(sp)           # Salva t3
        sw t4, 4(sp)           # Salva t4
        sw t5, 0(sp)           # Salva t5

        add t0, zero, zero          # t0 = soma
        add t1, zero, zero          # t1 = índice

loop_covariancia:
        beq t1, a2, end_covariancia  # Se índice == tamanho, fim do loop
        lw t3, 0(a0)                 # Carrega o valor atual de vetor1 em t3
        lw t4, 0(a1)                 # Carrega o valor atual de vetor2 em t4
        sub t3, t3, s1               # t3 = xi - media(x)
        sub t4, t4, s2               # t4 = yi - media(y)
        mul t5, t3, t4               # t5 = (xi - media(x)) * (yi - media(y)) 
        add t0, t0, t5               # Soma o valor à soma total
        addi a0, a0, 4               # Incrementa o ponteiro de vetor1
        addi a1, a1, 4               # Incrementa o ponteiro de vetor2
        addi t1, t1, 1               # Incrementa o índice
        beq zero, zero, loop_covariancia           # Recomeça o loop

end_covariancia:
        addi a2, a2, -1         # a2 = N - 1
        div t0, t0, a2          # Calcula a covariância
        add a0, zero, t0        # Move o quociente para a0

        lw ra, 24(sp)           # Restaura o endereço de retorno
        lw t0, 20(sp)           # Restaura t0
        lw t1, 16(sp)           # Restaura t1
        lw t2, 12(sp)           # Restaura t2
        lw t3, 8(sp)            # Restaura t3
        lw t4, 4(sp)            # Restaura t4
        lw t5, 0(sp)            # Restaura t5
        addi sp, sp, 28         # Libera o espaço da pilha
        jalr ra                   # Retorna

media:
        addi sp, sp, -12       # Reserva espaço na pilha
        sw ra, 8(sp)           # Salva o endereço de retorno
        sw t0, 4(sp)           # Salva t0
        sw t1, 0(sp)           # Salva t1

        add t0, zero, zero    # t0 = soma
        add t1, zero, zero    # t1 = índice

loop_media:
        beq t1, a1, end_media  # Se índice == tamanho, fim do loop
        lw t2, 0(a0)           # Carrega o valor do endereço atual do vetor em t2
        add t0, t0, t2         # Soma o valor à soma total
        addi a0, a0, 4         # Calcula o endereço da próxima posição do vetor
        addi t1, t1, 1         # Adiciona 1 ao índice do vetor
        beq zero, zero, loop_media           # Recomeça o loop

end_media:
        div t0, t0, a1         # Calcula a média
        add a0, t0, zero       # Move o quociente para v0

        lw ra, 8(sp)           # Restaura o endereço de retorno
        lw t0, 4(sp)           # Restaura t0
        lw t1, 0(sp)           # Restaura t1
        addi sp, sp, 12        # Libera o espaço da pilha
        jalr ra                  # Retorna


##### R2 END MODIFIQUE AQUI END #####

FIM: add t0, zero, s0
