0x400f49 <phase_2>      push   %rbp
0x400f4a <phase_2+1>    push   %rbx
0x400f4b <phase_2+2>    sub    $0x28,%rsp
0x400f4f <phase_2+6>    mov    %fs:0x28,%rax
0x400f58 <phase_2+15>   mov    %rax,0x18(%rsp)
0x400f5d <phase_2+20>   xor    %eax,%eax
0x400f5f <phase_2+22>   mov    %rsp,%rsi
0x400f62 <phase_2+25>   callq  0x4017b2 <read_six_numbers>
0x400f67 <phase_2+30>   cmpl   $0x0,(%rsp)
0x400f6b <phase_2+34>   jns    0x400f72 <phase_2+41>
0x400f6d <phase_2+36>   callq  0x40177c <explode_bomb>
0x400f72 <phase_2+41>   mov    %rsp,%rbp
0x400f75 <phase_2+44>   mov    $0x1,%ebx
0x400f7a <phase_2+49>   mov    %ebx,%eax
0x400f7c <phase_2+51>   add    0x0(%rbp),%eax
0x400f7f <phase_2+54>   cmp    %eax,0x4(%rbp)
0x400f82 <phase_2+57>   je     0x400f89 <phase_2+64>
0x400f84 <phase_2+59>   callq  0x40177c <explode_bomb>
0x400f89 <phase_2+64>   add    $0x1,%ebx
0x400f8c <phase_2+67>   add    $0x4,%rbp
0x400f90 <phase_2+71>   cmp    $0x6,%ebx
0x400f93 <phase_2+74>   jne    0x400f7a <phase_2+49>
0x400f95 <phase_2+76>   mov    0x18(%rsp),%rax
0x400f9a <phase_2+81>   xor    %fs:0x28,%rax
0x400fa3 <phase_2+90>   je     0x400faa <phase_2+97>
0x400fa5 <phase_2+92>   callq  0x400b90 <__stack_chk_fail@plt>
0x400faa <phase_2+97>   add    $0x28,%rsp
0x400fae <phase_2+101>  pop    %rbx
0x400faf <phase_2+102>  pop    %rbp
0x400fb0 <phase_2+103>  ret