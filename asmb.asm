.data

.text
li $t8,268500992

 main:
li $t1 5
sw t1 0($t8)
li $t1 -2
sw t1 12($t8)
li $t1 3
sw t1 16($t8)
li $t1 1
sw t1 20($t8)
li $t1 5
sw t1 24($t8)
li $t1 -4
sw t1 28($t8)
li $t1 0
sw t1 4($t8)
li $t1 0
sw t1 8($t8)

Lbl0:
lw $t0, 4($t8)
lw $t1, 0($t8)
bge $t0, $t1, Lbl1
lw $t2, 4($t8)
muli $t2, $t2 ,4
add  $t2, $t2, 12
add  $t2, $t2, $t8
lw   $t2, 0($t2)
lw $t1, ($t8)
muli $t1, $t1 ,4
add  $t1, $t1, 8
add  $t1, $t1, $t8
lw   $t1, 0($t1)
add $t2, $t1, $t2
sw t2 8($t8)
li $t2 1
lw $t1, ($t8)
muli $t1, $t1 ,4
add  $t1, $t1, 4
add  $t1, $t1, $t8
lw   $t1, 0($t1)
add $t2, $t1, $t2
sw t2 4($t8)
j Lbl0

Lbl1:
li $t1 1
sw t1 32($t8)

li $v0,1
move $a0,$t0
syscall
