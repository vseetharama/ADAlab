area p,code,readonly
start
	mov r5,#2
	ldr r0,memory
again	ldr r1,[r0]
	mov r4,#32
rotate rors r1,#1
	bcs ones
	add r3,r3,#1;zeros
	b next
ones add r2,r2,#1
next sub r4,r4,#1
	cmp r4,#0
	bne rotate
	subs r5,r5,#1
	cmp r5,#0
	beq STORE
	add r0,r0,#4
	b again
STORE strb r2,[r0,#8]
	   strb r3,[r0,#12]
stop b stop
memory dcd 0x40000000
	end
