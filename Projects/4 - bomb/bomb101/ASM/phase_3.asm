0x400fb1 <phase_3>      sub    $0x28,%rsp
0x400fb5 <phase_3+4>    mov    %fs:0x28,%rax
0x400fbe <phase_3+13>   mov    %rax,0x18(%rsp)
0x400fc3 <phase_3+18>   xor    %eax,%eax
0x400fc5 <phase_3+20>   lea    0x14(%rsp),%r8
0x400fca <phase_3+25>   lea    0xf(%rsp),%rcx
0x400fcf <phase_3+30>   lea    0x10(%rsp),%rdx
0x400fd4 <phase_3+35>   mov    $0x40278e,%esi
0x400fd9 <phase_3+40>   callq  0x400c40 <__isoc99_sscanf@plt>
0x400fde <phase_3+45>   cmp    $0x2,%eax
0x400fe1 <phase_3+48>   jg     0x400fe8 <phase_3+55>
0x400fe3 <phase_3+50>   callq  0x40177c <explode_bomb>
0x400fe8 <phase_3+55>   cmpl   $0x7,0x10(%rsp)
0x400fed <phase_3+60>   ja     0x4010ef <phase_3+318>
0x400ff3 <phase_3+66>   mov    0x10(%rsp),%eax
0x400ff7 <phase_3+70>   jmpq   *0x4027a0(,%rax,8)
0x400ffe <phase_3+77>   mov    $0x76,%eax
0x401003 <phase_3+82>   cmpl   $0x2c5,0x14(%rsp)
0x40100b <phase_3+90>   je     0x4010f9 <phase_3+328>
0x401011 <phase_3+96>   callq  0x40177c <explode_bomb>
0x401016 <phase_3+101>  mov    $0x76,%eax
0x40101b <phase_3+106>  jmpq   0x4010f9 <phase_3+328>
0x401020 <phase_3+111>  mov    $0x75,%eax
0x401025 <phase_3+116>  cmpl   $0xd8,0x14(%rsp)
0x40102d <phase_3+124>  je     0x4010f9 <phase_3+328>
0x401033 <phase_3+130>  callq  0x40177c <explode_bomb>
0x401038 <phase_3+135>  mov    $0x75,%eax
0x40103d <phase_3+140>  jmpq   0x4010f9 <phase_3+328>
0x401042 <phase_3+145>  mov    $0x72,%eax
0x401047 <phase_3+150>  cmpl   $0x32e,0x14(%rsp)
0x40104f <phase_3+158>  je     0x4010f9 <phase_3+328>
0x401055 <phase_3+164>  callq  0x40177c <explode_bomb>
0x40105a <phase_3+169>  mov    $0x72,%eax
0x40105f <phase_3+174>  jmpq   0x4010f9 <phase_3+328>
0x401064 <phase_3+179>  mov    $0x61,%eax
0x401069 <phase_3+184>  cmpl   $0x19f,0x14(%rsp)
0x401071 <phase_3+192>  je     0x4010f9 <phase_3+328>
0x401077 <phase_3+198>  callq  0x40177c <explode_bomb>
0x40107c <phase_3+203>  mov    $0x61,%eax
0x401081 <phase_3+208>  jmp    0x4010f9 <phase_3+328>
0x401083 <phase_3+210>  mov    $0x78,%eax
0x401088 <phase_3+215>  cmpl   $0x331,0x14(%rsp)
0x401090 <phase_3+223>  je     0x4010f9 <phase_3+328>
0x401092 <phase_3+225>  callq  0x40177c <explode_bomb>
0x401097 <phase_3+230>  mov    $0x78,%eax
0x40109c <phase_3+235>  jmp    0x4010f9 <phase_3+328>
0x40109e <phase_3+237>  mov    $0x6e,%eax
0x4010a3 <phase_3+242>  cmpl   $0x2c2,0x14(%rsp)
0x4010ab <phase_3+250>  je     0x4010f9 <phase_3+328>
0x4010ad <phase_3+252>  callq  0x40177c <explode_bomb>
0x4010b2 <phase_3+257>  mov    $0x6e,%eax
0x4010b7 <phase_3+262>  jmp    0x4010f9 <phase_3+328>
0x4010b9 <phase_3+264>  mov    $0x67,%eax
0x4010be <phase_3+269>  cmpl   $0x36b,0x14(%rsp)
0x4010c6 <phase_3+277>  je     0x4010f9 <phase_3+328>
0x4010c8 <phase_3+279>  callq  0x40177c <explode_bomb>
0x4010cd <phase_3+284>  mov    $0x67,%eax
0x4010d2 <phase_3+289>  jmp    0x4010f9 <phase_3+328>
0x4010d4 <phase_3+291>  mov    $0x64,%eax
0x4010d9 <phase_3+296>  cmpl   $0x3dc,0x14(%rsp)
0x4010e1 <phase_3+304>  je     0x4010f9 <phase_3+328>
0x4010e3 <phase_3+306>  callq  0x40177c <explode_bomb>
0x4010e8 <phase_3+311>  mov    $0x64,%eax
0x4010ed <phase_3+316>  jmp    0x4010f9 <phase_3+328>
0x4010ef <phase_3+318>  callq  0x40177c <explode_bomb>
0x4010f4 <phase_3+323>  mov    $0x69,%eax
0x4010f9 <phase_3+328>  cmp    0xf(%rsp),%al
0x4010fd <phase_3+332>  je     0x401104 <phase_3+339>
0x4010ff <phase_3+334>  callq  0x40177c <explode_bomb>
0x401104 <phase_3+339>  mov    0x18(%rsp),%rax
0x401109 <phase_3+344>  xor    %fs:0x28,%rax
0x401112 <phase_3+353>  je     0x401119 <phase_3+360>
0x401114 <phase_3+355>  callq  0x400b90 <__stack_chk_fail@plt>
0x401119 <phase_3+360>  add    $0x28,%rsp
0x40111d <phase_3+364>  retq