.weak  _init
.weak  _fini
.global _start
.align  2
_start:
	add     r19, r0, r0             # Zero the frame pointer.
	ori     r5, r0, main            # Get main() ...
	lw      r6, r0, r1              # Get argc...
	addi    r7, r1, 4               # ... and argv ...
	ori     r8, r0, _init           # and _init() ...
	ori     r9, r0, _fini           # and _fini() ...
	add     r10, r0, r0             # ldso_fini == NULL
	andi    r1, r1, -8              # align stack
	addik   r1, r1, -4*6            # Leave space for the args.
	bri     __libc_start_main       # Let's go!
	nop                             # Never gets here.

	.type	__dso_handle,@object
	.section	.sbss,"aw",@nobits
	.globl	__dso_handle
	.align	2
__dso_handle:
	.long	0
	.size	__dso_handle, 4
