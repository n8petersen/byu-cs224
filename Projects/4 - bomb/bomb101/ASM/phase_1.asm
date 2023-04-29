0x400f2d <phase_1>      sub    $0x8,%rsp
0x400f31 <phase_1+4>    mov    $0x402730,%esi
0x400f36 <phase_1+9>    callq  0x4014a8 <strings_not_equal>
0x400f3b <phase_1+14>   test   %eax,%eax
0x400f3d <phase_1+16>   je     0x400f44 <phase_1+23>
0x400f3f <phase_1+18>   callq  0x40177c <explode_bomb>
0x400f44 <phase_1+23>   add    $0x8,%rsp
0x400f48 <phase_1+27>   retq