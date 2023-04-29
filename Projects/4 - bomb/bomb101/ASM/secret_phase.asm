0x4013be <secret_phase>         push   %rbx
0x4013bf <secret_phase+1>       callq  0x4017f1 <read_line>
0x4013c4 <secret_phase+6>       mov    $0xa,%edx
0x4013c9 <secret_phase+11>      mov    $0x0,%esi
0x4013ce <secret_phase+16>      mov    %rax,%rdi
0x4013d1 <secret_phase+19>      callq  0x400c20 <strtol@plt>
0x4013d6 <secret_phase+24>      mov    %rax,%rbx
0x4013d9 <secret_phase+27>      lea    -0x1(%rax),%eax
0x4013dc <secret_phase+30>      cmp    $0x3e8,%eax
0x4013e1 <secret_phase+35>      jbe    0x4013e8 <secret_phase+42>
0x4013e3 <secret_phase+37>      callq  0x40177c <explode_bomb>
0x4013e8 <secret_phase+42>      mov    %ebx,%esi
0x4013ea <secret_phase+44>      mov    $0x604110,%edi
0x4013ef <secret_phase+49>      callq  0x401380 <fun7>
0x4013f4 <secret_phase+54>      cmp    $0x3,%eax
0x4013f7 <secret_phase+57>      je     0x4013fe <secret_phase+64>
0x4013f9 <secret_phase+59>      callq  0x40177c <explode_bomb>
0x4013fe <secret_phase+64>      mov    $0x402768,%edi
0x401403 <secret_phase+69>      callq  0x400b70 <puts@plt>
0x401408 <secret_phase+74>      callq  0x401917 <phase_defused>
0x40140d <secret_phase+79>      pop    %rbx
0x40140e <secret_phase+80>      retq