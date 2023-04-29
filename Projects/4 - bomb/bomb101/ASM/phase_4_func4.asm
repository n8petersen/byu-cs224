0x40111e <func4>        test   %edi,%edi
0x401120 <func4+2>      jle    0x40114d <func4+47>
0x401122 <func4+4>      mov    %esi,%eax
0x401124 <func4+6>      cmp    $0x1,%edi
0x401127 <func4+9>      je     0x401157 <func4+57>
0x401129 <func4+11>     push   %r12
0x40112b <func4+13>     push   %rbp
0x40112c <func4+14>     push   %rbx
0x40112d <func4+15>     mov    %esi,%ebp
0x40112f <func4+17>     mov    %edi,%ebx
0x401131 <func4+19>     lea    -0x1(%rdi),%edi
0x401134 <func4+22>     callq  0x40111e <func4>
0x401139 <func4+27>     lea    0x0(%rbp,%rax,1),%r12d
0x40113e <func4+32>     lea    -0x2(%rbx),%edi
0x401141 <func4+35>     mov    %ebp,%esi
0x401143 <func4+37>     callq  0x40111e <func4>
0x401148 <func4+42>     add    %r12d,%eax
0x40114b <func4+45>     jmp    0x401153 <func4+53>
0x40114d <func4+47>     mov    $0x0,%eax
0x401152 <func4+52>     retq
0x401153 <func4+53>     pop    %rbx
0x401154 <func4+54>     pop    %rbp
0x401155 <func4+55>     pop    %r12
0x401157 <func4+57>     repz retq