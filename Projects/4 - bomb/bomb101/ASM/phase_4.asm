0x401159 <phase_4>      sub    $0x18,%rsp
0x40115d <phase_4+4>    mov    %fs:0x28,%rax
0x401166 <phase_4+13>   mov    %rax,0x8(%rsp)                       # rax into rsp+0x8
0x40116b <phase_4+18>   xor    %eax,%eax                            # sets rax to 0
0x40116d <phase_4+20>   mov    %rsp,%rcx                            # moves rsp (56) into rcx
0x401170 <phase_4+23>   lea    0x4(%rsp),%rdx                       # rsp+4(-1) -> %rdx
0x401175 <phase_4+28>   mov    $0x402a6d,%esi
0x40117a <phase_4+33>   callq  0x400c40 <__isoc99_sscanf@plt>
0x40117f <phase_4+38>   cmp    $0x2,%eax
0x401182 <phase_4+41>   jne    0x40118f <phase_4+54>
0x401184 <phase_4+43>   mov    (%rsp),%eax
0x401187 <phase_4+46>   sub    $0x2,%eax
0x40118a <phase_4+49>   cmp    $0x2,%eax
0x40118d <phase_4+52>   jbe    0x401194 <phase_4+59>
0x40118f <phase_4+54>   callq  0x40177c <explode_bomb>
0x401194 <phase_4+59>   mov    (%rsp),%esi
0x401197 <phase_4+62>   mov    $0x7,%edi
0x40119c <phase_4+67>   callq  0x40111e <func4>
0x4011a1 <phase_4+72>   cmp    0x4(%rsp),%eax
0x4011a5 <phase_4+76>   je     0x4011ac <phase_4+83>
0x4011a7 <phase_4+78>   callq  0x40177c <explode_bomb>
0x4011ac <phase_4+83>   mov    0x8(%rsp),%rax
0x4011b1 <phase_4+88>   xor    %fs:0x28,%rax
0x4011ba <phase_4+97>   je     0x4011c1 <phase_4+104>
0x4011bc <phase_4+99>   callq  0x400b90 <__stack_chk_fail@plt>
0x4011c1 <phase_4+104>  add    $0x18,%rsp
0x4011c5 <phase_4+108>  retq