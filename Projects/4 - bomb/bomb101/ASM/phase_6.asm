0x401252 <phase_6>      push   %r14             
0x401254 <phase_6+2>    push   %r13
0x401256 <phase_6+4>    push   %r12
0x401258 <phase_6+6>    push   %rbp
0x401259 <phase_6+7>    push   %rbx
0x40125a <phase_6+8>    sub    $0x60,%rsp
0x40125e <phase_6+12>   mov    %fs:0x28,%rax
0x401267 <phase_6+21>   mov    %rax,0x58(%rsp)
0x40126c <phase_6+26>   xor    %eax,%eax
0x40126e <phase_6+28>   mov    %rsp,%rsi
0x401271 <phase_6+31>   callq  0x4017b2 <read_six_numbers>
0x401276 <phase_6+36>   mov    %rsp,%r12
0x401279 <phase_6+39>   mov    %rsp,%r13
0x40127c <phase_6+42>   mov    $0x0,%r14d
0x401282 <phase_6+48>   mov    %r13,%rbp
0x401285 <phase_6+51>   mov    0x0(%r13),%eax
0x401289 <phase_6+55>   sub    $0x1,%eax
0x40128c <phase_6+58>   cmp    $0x5,%eax
0x40128f <phase_6+61>   jbe    0x401296 <phase_6+68>
0x401291 <phase_6+63>   callq  0x40177c <explode_bomb>
0x401296 <phase_6+68>   add    $0x1,%r14d
0x40129a <phase_6+72>   cmp    $0x6,%r14d
0x40129e <phase_6+76>   je     0x4012c1 <phase_6+111>
0x4012a0 <phase_6+78>   mov    %r14d,%ebx
0x4012a3 <phase_6+81>   movslq %ebx,%rax
0x4012a6 <phase_6+84>   mov    (%rsp,%rax,4),%eax
0x4012a9 <phase_6+87>   cmp    %eax,0x0(%rbp)
0x4012ac <phase_6+90>   jne    0x4012b3 <phase_6+97>
0x4012ae <phase_6+92>   callq  0x40177c <explode_bomb>
0x4012b3 <phase_6+97>   add    $0x1,%ebx
0x4012b6 <phase_6+100>  cmp    $0x5,%ebx
0x4012b9 <phase_6+103>  jle    0x4012a3 <phase_6+81>
0x4012bb <phase_6+105>  add    $0x4,%r13
0x4012bf <phase_6+109>  jmp    0x401282 <phase_6+48>
0x4012c1 <phase_6+111>  lea    0x18(%rsp),%rcx
0x4012c6 <phase_6+116>  mov    $0x7,%edx
0x4012cb <phase_6+121>  mov    %edx,%eax
0x4012cd <phase_6+123>  sub    (%r12),%eax
0x4012d1 <phase_6+127>  mov    %eax,(%r12)
0x4012d5 <phase_6+131>  add    $0x4,%r12
0x4012d9 <phase_6+135>  cmp    %r12,%rcx
0x4012dc <phase_6+138>  jne    0x4012cb <phase_6+121>
0x4012de <phase_6+140>  mov    $0x0,%esi
0x4012e3 <phase_6+145>  jmp    0x4012ff <phase_6+173>
0x4012e5 <phase_6+147>  mov    0x8(%rdx),%rdx
0x4012e9 <phase_6+151>  add    $0x1,%eax
0x4012ec <phase_6+154>  cmp    %ecx,%eax
0x4012ee <phase_6+156>  jne    0x4012e5 <phase_6+147>
0x4012f0 <phase_6+158>  mov    %rdx,0x20(%rsp,%rsi,2)
0x4012f5 <phase_6+163>  add    $0x4,%rsi
0x4012f9 <phase_6+167>  cmp    $0x18,%rsi
0x4012fd <phase_6+171>  je     0x401313 <phase_6+193>
0x4012ff <phase_6+173>  mov    (%rsp,%rsi,1),%ecx
0x401302 <phase_6+176>  mov    $0x1,%eax
0x401307 <phase_6+181>  mov    $0x6042f0,%edx
0x40130c <phase_6+186>  cmp    $0x1,%ecx
0x40130f <phase_6+189>  jg     0x4012e5 <phase_6+147>
0x401311 <phase_6+191>  jmp    0x4012f0 <phase_6+158>
0x401313 <phase_6+193>  mov    0x20(%rsp),%rbx
0x401318 <phase_6+198>  lea    0x20(%rsp),%rax
0x40131d <phase_6+203>  lea    0x48(%rsp),%rsi
0x401322 <phase_6+208>  mov    %rbx,%rcx
0x401325 <phase_6+211>  mov    0x8(%rax),%rdx
0x401329 <phase_6+215>  mov    %rdx,0x8(%rcx)
0x40132d <phase_6+219>  add    $0x8,%rax
0x401331 <phase_6+223>  mov    %rdx,%rcx
0x401334 <phase_6+226>  cmp    %rax,%rsi
0x401337 <phase_6+229>  jne    0x401325 <phase_6+211>
0x401339 <phase_6+231>  movq   $0x0,0x8(%rdx)
0x401341 <phase_6+239>  mov    $0x5,%ebp
0x401346 <phase_6+244>  mov    0x8(%rbx),%rax
0x40134a <phase_6+248>  mov    (%rax),%eax
0x40134c <phase_6+250>  cmp    %eax,(%rbx)
0x40134e <phase_6+252>  jge    0x401355 <phase_6+259>
0x401350 <phase_6+254>  callq  0x40177c <explode_bomb>
0x401355 <phase_6+259>  mov    0x8(%rbx),%rbx
0x401359 <phase_6+263>  sub    $0x1,%ebp
0x40135c <phase_6+266>  jne    0x401346 <phase_6+244>
0x40135e <phase_6+268>  mov    0x58(%rsp),%rax
0x401363 <phase_6+273>  xor    %fs:0x28,%rax
0x40136c <phase_6+282>  je     0x401373 <phase_6+289>
0x40136e <phase_6+284>  callq  0x400b90 <__stack_chk_fail@plt>
0x401373 <phase_6+289>  add    $0x60,%rsp
0x401377 <phase_6+293>  pop    %rbx
0x401378 <phase_6+294>  pop    %rbp
0x401379 <phase_6+295>  pop    %r12
0x40137b <phase_6+297>  pop    %r13
0x40137d <phase_6+299>  pop    %r14
0x40137f <phase_6+301>  retq