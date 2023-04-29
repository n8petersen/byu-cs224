0x4017b2 <read_six_numbers>     sub    $0x8,%rsp
0x4017b6 <read_six_numbers+4>   mov    %rsi,%rdx
0x4017b9 <read_six_numbers+7>   lea    0x4(%rsi),%rcx
0x4017bd <read_six_numbers+11>  lea    0x14(%rsi),%rax
0x4017c1 <read_six_numbers+15>  push   %rax
0x4017c2 <read_six_numbers+16>  lea    0x10(%rsi),%rax
0x4017c6 <read_six_numbers+20>  push   %rax
0x4017c7 <read_six_numbers+21>  lea    0xc(%rsi),%r9
0x4017cb <read_six_numbers+25>  lea    0x8(%rsi),%r8
0x4017cf <read_six_numbers+29>  mov    $0x402a61,%esi
0x4017d4 <read_six_numbers+34>  mov    $0x0,%eax
0x4017d9 <read_six_numbers+39>  callq  0x400c40 <__isoc99_sscanf@plt>
0x4017de <read_six_numbers+44>  add    $0x10,%rsp
0x4017e2 <read_six_numbers+48>  cmp    $0x5,%eax
0x4017e5 <read_six_numbers+51>  jg     0x4017ec <read_six_numbers+58>
0x4017e7 <read_six_numbers+53>  callq  0x40177c <explode_bomb>
0x4017ec <read_six_numbers+58>  add    $0x8,%rsp
0x4017f0 <read_six_numbers+62>  retq