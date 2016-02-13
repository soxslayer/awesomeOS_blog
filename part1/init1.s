.global init2

@ Place the stack 2MB past the end of the kernel code, this should be enough
STACK_END = 0x80200000

.section .init
init1:
  @ initialize supervisor mode
  ldr sp, =STACK_END

  @ branch into C land
  ldr r4, =init2
  mov lr, sp
  bx r4

@ if we get here, something really bad happened
infinity:
  b infinity
