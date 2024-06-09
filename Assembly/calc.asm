.data
$t0: 0x10
$t1: 0x4
$t2: 0x5

.text
add $s0, $t0, $t1
sub $t2, $s0, $t3
li $v0, 1
move $a0, $t2
syscall