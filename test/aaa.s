
a.out：     文件格式 elf64-x86-64


Disassembly of section .init:

00000000004003c8 <_init>:
  4003c8:	48 83 ec 08          	sub    $0x8,%rsp
  4003cc:	48 8b 05 25 0c 20 00 	mov    0x200c25(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  4003d3:	48 85 c0             	test   %rax,%rax
  4003d6:	74 05                	je     4003dd <_init+0x15>
  4003d8:	e8 43 00 00 00       	callq  400420 <__libc_start_main@plt+0x10>
  4003dd:	48 83 c4 08          	add    $0x8,%rsp
  4003e1:	c3                   	retq   

Disassembly of section .plt:

00000000004003f0 <printf@plt-0x10>:
  4003f0:	ff 35 12 0c 20 00    	pushq  0x200c12(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003f6:	ff 25 14 0c 20 00    	jmpq   *0x200c14(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400400 <printf@plt>:
  400400:	ff 25 12 0c 20 00    	jmpq   *0x200c12(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400406:	68 00 00 00 00       	pushq  $0x0
  40040b:	e9 e0 ff ff ff       	jmpq   4003f0 <_init+0x28>

0000000000400410 <__libc_start_main@plt>:
  400410:	ff 25 0a 0c 20 00    	jmpq   *0x200c0a(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400416:	68 01 00 00 00       	pushq  $0x1
  40041b:	e9 d0 ff ff ff       	jmpq   4003f0 <_init+0x28>

Disassembly of section .plt.got:

0000000000400420 <.plt.got>:
  400420:	ff 25 d2 0b 20 00    	jmpq   *0x200bd2(%rip)        # 600ff8 <_DYNAMIC+0x1d0>
  400426:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000400430 <_start>:
  400430:	31 ed                	xor    %ebp,%ebp
  400432:	49 89 d1             	mov    %rdx,%r9
  400435:	5e                   	pop    %rsi
  400436:	48 89 e2             	mov    %rsp,%rdx
  400439:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40043d:	50                   	push   %rax
  40043e:	54                   	push   %rsp
  40043f:	49 c7 c0 e0 05 40 00 	mov    $0x4005e0,%r8
  400446:	48 c7 c1 70 05 40 00 	mov    $0x400570,%rcx
  40044d:	48 c7 c7 26 05 40 00 	mov    $0x400526,%rdi
  400454:	e8 b7 ff ff ff       	callq  400410 <__libc_start_main@plt>
  400459:	f4                   	hlt    
  40045a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400460 <deregister_tm_clones>:
  400460:	b8 3f 10 60 00       	mov    $0x60103f,%eax
  400465:	55                   	push   %rbp
  400466:	48 2d 38 10 60 00    	sub    $0x601038,%rax
  40046c:	48 83 f8 0e          	cmp    $0xe,%rax
  400470:	48 89 e5             	mov    %rsp,%rbp
  400473:	76 1b                	jbe    400490 <deregister_tm_clones+0x30>
  400475:	b8 00 00 00 00       	mov    $0x0,%eax
  40047a:	48 85 c0             	test   %rax,%rax
  40047d:	74 11                	je     400490 <deregister_tm_clones+0x30>
  40047f:	5d                   	pop    %rbp
  400480:	bf 38 10 60 00       	mov    $0x601038,%edi
  400485:	ff e0                	jmpq   *%rax
  400487:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40048e:	00 00 
  400490:	5d                   	pop    %rbp
  400491:	c3                   	retq   
  400492:	0f 1f 40 00          	nopl   0x0(%rax)
  400496:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40049d:	00 00 00 

00000000004004a0 <register_tm_clones>:
  4004a0:	be 38 10 60 00       	mov    $0x601038,%esi
  4004a5:	55                   	push   %rbp
  4004a6:	48 81 ee 38 10 60 00 	sub    $0x601038,%rsi
  4004ad:	48 c1 fe 03          	sar    $0x3,%rsi
  4004b1:	48 89 e5             	mov    %rsp,%rbp
  4004b4:	48 89 f0             	mov    %rsi,%rax
  4004b7:	48 c1 e8 3f          	shr    $0x3f,%rax
  4004bb:	48 01 c6             	add    %rax,%rsi
  4004be:	48 d1 fe             	sar    %rsi
  4004c1:	74 15                	je     4004d8 <register_tm_clones+0x38>
  4004c3:	b8 00 00 00 00       	mov    $0x0,%eax
  4004c8:	48 85 c0             	test   %rax,%rax
  4004cb:	74 0b                	je     4004d8 <register_tm_clones+0x38>
  4004cd:	5d                   	pop    %rbp
  4004ce:	bf 38 10 60 00       	mov    $0x601038,%edi
  4004d3:	ff e0                	jmpq   *%rax
  4004d5:	0f 1f 00             	nopl   (%rax)
  4004d8:	5d                   	pop    %rbp
  4004d9:	c3                   	retq   
  4004da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004004e0 <__do_global_dtors_aux>:
  4004e0:	80 3d 51 0b 20 00 00 	cmpb   $0x0,0x200b51(%rip)        # 601038 <__TMC_END__>
  4004e7:	75 11                	jne    4004fa <__do_global_dtors_aux+0x1a>
  4004e9:	55                   	push   %rbp
  4004ea:	48 89 e5             	mov    %rsp,%rbp
  4004ed:	e8 6e ff ff ff       	callq  400460 <deregister_tm_clones>
  4004f2:	5d                   	pop    %rbp
  4004f3:	c6 05 3e 0b 20 00 01 	movb   $0x1,0x200b3e(%rip)        # 601038 <__TMC_END__>
  4004fa:	f3 c3                	repz retq 
  4004fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400500 <frame_dummy>:
  400500:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  400505:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400509:	75 05                	jne    400510 <frame_dummy+0x10>
  40050b:	eb 93                	jmp    4004a0 <register_tm_clones>
  40050d:	0f 1f 00             	nopl   (%rax)
  400510:	b8 00 00 00 00       	mov    $0x0,%eax
  400515:	48 85 c0             	test   %rax,%rax
  400518:	74 f1                	je     40050b <frame_dummy+0xb>
  40051a:	55                   	push   %rbp
  40051b:	48 89 e5             	mov    %rsp,%rbp
  40051e:	ff d0                	callq  *%rax
  400520:	5d                   	pop    %rbp
  400521:	e9 7a ff ff ff       	jmpq   4004a0 <register_tm_clones>

0000000000400526 <main>:
  400526:	55                   	push   %rbp
  400527:	48 89 e5             	mov    %rsp,%rbp
  40052a:	48 83 ec 10          	sub    $0x10,%rsp
  40052e:	c7 45 f8 01 00 00 00 	movl   $0x1,-0x8(%rbp)
  400535:	c7 45 fc 20 00 00 00 	movl   $0x20,-0x4(%rbp)
  40053c:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40053f:	8b 55 f8             	mov    -0x8(%rbp),%edx
  400542:	89 c1                	mov    %eax,%ecx
  400544:	d3 e2                	shl    %cl,%edx
  400546:	89 d0                	mov    %edx,%eax
  400548:	ba 00 00 00 00       	mov    $0x0,%edx
  40054d:	89 c6                	mov    %eax,%esi
  40054f:	bf f4 05 40 00       	mov    $0x4005f4,%edi
  400554:	b8 00 00 00 00       	mov    $0x0,%eax
  400559:	e8 a2 fe ff ff       	callq  400400 <printf@plt>
  40055e:	b8 00 00 00 00       	mov    $0x0,%eax
  400563:	c9                   	leaveq 
  400564:	c3                   	retq   
  400565:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40056c:	00 00 00 
  40056f:	90                   	nop

0000000000400570 <__libc_csu_init>:
  400570:	41 57                	push   %r15
  400572:	41 56                	push   %r14
  400574:	41 89 ff             	mov    %edi,%r15d
  400577:	41 55                	push   %r13
  400579:	41 54                	push   %r12
  40057b:	4c 8d 25 8e 08 20 00 	lea    0x20088e(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  400582:	55                   	push   %rbp
  400583:	48 8d 2d 8e 08 20 00 	lea    0x20088e(%rip),%rbp        # 600e18 <__init_array_end>
  40058a:	53                   	push   %rbx
  40058b:	49 89 f6             	mov    %rsi,%r14
  40058e:	49 89 d5             	mov    %rdx,%r13
  400591:	4c 29 e5             	sub    %r12,%rbp
  400594:	48 83 ec 08          	sub    $0x8,%rsp
  400598:	48 c1 fd 03          	sar    $0x3,%rbp
  40059c:	e8 27 fe ff ff       	callq  4003c8 <_init>
  4005a1:	48 85 ed             	test   %rbp,%rbp
  4005a4:	74 20                	je     4005c6 <__libc_csu_init+0x56>
  4005a6:	31 db                	xor    %ebx,%ebx
  4005a8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4005af:	00 
  4005b0:	4c 89 ea             	mov    %r13,%rdx
  4005b3:	4c 89 f6             	mov    %r14,%rsi
  4005b6:	44 89 ff             	mov    %r15d,%edi
  4005b9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4005bd:	48 83 c3 01          	add    $0x1,%rbx
  4005c1:	48 39 eb             	cmp    %rbp,%rbx
  4005c4:	75 ea                	jne    4005b0 <__libc_csu_init+0x40>
  4005c6:	48 83 c4 08          	add    $0x8,%rsp
  4005ca:	5b                   	pop    %rbx
  4005cb:	5d                   	pop    %rbp
  4005cc:	41 5c                	pop    %r12
  4005ce:	41 5d                	pop    %r13
  4005d0:	41 5e                	pop    %r14
  4005d2:	41 5f                	pop    %r15
  4005d4:	c3                   	retq   
  4005d5:	90                   	nop
  4005d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4005dd:	00 00 00 

00000000004005e0 <__libc_csu_fini>:
  4005e0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000004005e4 <_fini>:
  4005e4:	48 83 ec 08          	sub    $0x8,%rsp
  4005e8:	48 83 c4 08          	add    $0x8,%rsp
  4005ec:	c3                   	retq   
