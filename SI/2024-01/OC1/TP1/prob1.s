.data

##### R1 START MODIFIQUE AQUI START #####
#
# Este espaço é para você definir as suas constantes e vetores auxiliares.
#

vetor: .word 1 2 3 4 5 6 7 8 9 10


##### R1 END MODIFIQUE AQUI END #####

.text
        add s0, zero, zero #Quantidade de testes em que seu programa passou
        la a0, vetor
        addi a1, zero, 10
        addi a2, zero, 2
        jal ra, multiplos
        addi t0, zero, 5
        bne a0,t0,teste2
        addi s0,s0,1
teste2: la a0, vetor
        addi a1, zero, 10
        addi a2, zero, 3
        jal ra, multiplos
        addi t0, zero, 3
        bne a0,t0, FIM
        addi s0,s0,1
        beq zero,zero,FIM

##### R2 START MODIFIQUE AQUI START #####
multiplos:
        addi t0, zero, 0          # Inicializa t0 (contador de múltiplos) com 0
        addi t1, zero, 0          # Inicializa t1 (índice do vetor) com 0
        
inicio_for:
        beq t1, a1, fim_for       # Se t1 (índice) for igual a a1 (tamanho do vetor), fim do loop
        lw t2, 0(a0)              # Carrega o valor do vetor na posição a0 em t2
        rem t3, t2, a2            # Calcula o resto da divisão de t2 (valor atual) por a2 (número a ser verificado)
        beq t3, zero, eh_multiplo # Se o resto for 0, conta +1 multiplo
        j prox					          # Proximo elemento do vetor
        
eh_multiplo:
        addi t0, t0, 1            # Contador de multiplos + 1
        j prox			              # Proximo elemento do vetor
  
prox:
        addi a0, a0, 4            # Calcula o endereço da próxima posição do vetor
        addi t1, t1, 1            # Incrementa a posição a ser verificada
        j inicio_for              # Repete o loop
        
fim_for:
        add a0, t0, zero          # Coloca o contador de múltiplos em a0
        jalr zero, 0(ra)          # Retorna para a chamada anterior

##### R2 END MODIFIQUE AQUI END #####

FIM: addi t0, s0, 0