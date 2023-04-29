0x4011c6 <phase_5>      sub    $0x18,%rsp
0x4011ca <phase_5+4>    mov    %fs:0x28,%rax
0x4011d3 <phase_5+13>   mov    %rax,0x8(%rsp)
0x4011d8 <phase_5+18>   xor    %eax,%eax
0x4011da <phase_5+20>   lea    0x4(%rsp),%rcx
0x4011df <phase_5+25>   mov    %rsp,%rdx
0x4011e2 <phase_5+28>   mov    $0x402a6d,%esi
0x4011e7 <phase_5+33>   callq  0x400c40 <__isoc99_sscanf@plt>
0x4011ec <phase_5+38>   cmp    $0x1,%eax
0x4011ef <phase_5+41>   jg     0x4011f6 <phase_5+48>
0x4011f1 <phase_5+43>   callq  0x40177c <explode_bomb>
0x4011f6 <phase_5+48>   mov    (%rsp),%eax
0x4011f9 <phase_5+51>   and    $0xf,%eax
0x4011fc <phase_5+54>   mov    %eax,(%rsp)
0x4011ff <phase_5+57>   cmp    $0xf,%eax
0x401202 <phase_5+60>   je     0x401233 <phase_5+109>
0x401204 <phase_5+62>   mov    $0x0,%ecx
0x401209 <phase_5+67>   mov    $0x0,%edx
0x40120e <phase_5+72>   add    $0x1,%edx
0x401211 <phase_5+75>   cltq
0x401213 <phase_5+77>   mov    0x4027e0(,%rax,4),%eax
0x40121a <phase_5+84>   add    %eax,%ecx
0x40121c <phase_5+86>   cmp    $0xf,%eax
0x40121f <phase_5+89>   jne    0x40120e <phase_5+72>
0x401221 <phase_5+91>   movl   $0xf,(%rsp)
0x401228 <phase_5+98>   cmp    $0xf,%edx
0x40122b <phase_5+101>  jne    0x401233 <phase_5+109>
0x40122d <phase_5+103>  cmp    0x4(%rsp),%ecx
0x401231 <phase_5+107>  je     0x401238 <phase_5+114>
0x401233 <phase_5+109>  callq  0x40177c <explode_bomb>
0x401238 <phase_5+114>  mov    0x8(%rsp),%rax
0x40123d <phase_5+119>  xor    %fs:0x28,%rax
0x401246 <phase_5+128>  je     0x40124d <phase_5+135>
0x401248 <phase_5+130>  callq  0x400b90 <__stack_chk_fail@plt>
0x40124d <phase_5+135>  add    $0x18,%rsp
0x401251 <phase_5+139>  retq