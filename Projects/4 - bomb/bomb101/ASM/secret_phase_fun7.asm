0x401380 <fun7>                 sub    $0x8,%rsp
0x401384 <fun7+4>               test   %rdi,%rdi
0x401387 <fun7+7>               je     0x4013b4 <fun7+52>
0x401389 <fun7+9>               mov    (%rdi),%edx
0x40138b <fun7+11>              cmp    %esi,%edx
0x40138d <fun7+13>              jle    0x40139c <fun7+28>
0x40138f <fun7+15>              mov    0x8(%rdi),%rdi
0x401393 <fun7+19>              callq  0x401380 <fun7>
0x401398 <fun7+24>              add    %eax,%eax
0x40139a <fun7+26>              jmp    0x4013b9 <fun7+57>
0x40139c <fun7+28>              mov    $0x0,%eax
0x4013a1 <fun7+33>              cmp    %esi,%edx
0x4013a3 <fun7+35>              je     0x4013b9 <fun7+57>
0x4013a5 <fun7+37>              mov    0x10(%rdi),%rdi
0x4013a9 <fun7+41>              callq  0x401380 <fun7>
0x4013ae <fun7+46>              lea    0x1(%rax,%rax,1),%eax
0x4013b2 <fun7+50>              jmp    0x4013b9 <fun7+57>
0x4013b4 <fun7+52>              mov    $0xffffffff,%eax
0x4013b9 <fun7+57>              add    $0x8,%rsp
0x4013bd <fun7+61>              retq