# CS 224 - Lab 4
## Problem 1
    * a:  0x42 = 0100 0010 b
    * b:  0x00 = 0000 0000 b  
<br>
    * c:  4b 28 44 72  (prints contents # of locations, however large the var is. int=4, long=8)
        * 72 44 28 4b  (have to put it in reverse)
        * 724428fb     (concatenate)
    * d:  D     (prints contents 2 memory locations later)
    * e:  (DrB  (prints starting from 1 memory location later, until it his 0x00
    * f:  r     (contents 3 memory locations later)



---  



## Problem 2  
* a: 0x54  =  0101 0100 b  
* b: 0x41  =  0100 0001 b  
<br>
    * c:  49 73 54 39
        * 39 54 73 49
        * 39547349
    * d:  T
    * e:  gA
    * f:  49 73 54 39 21 67 41  
        * 41 67 21 39 54 73 49
        * 41672139547349




---  



## Problem 3  
* a: 0x42  =  0100 0010 b  
* b: 0x63  =  0110 0011 b   
<br>
    * c:  42 59 55 20
        * 20 55 59 42
        * 20555942
    * d:  0x55 = U
    * e:  42 59 55 20 63 73 20 69 73 20 63 6f 6f 6c 21 -> BYU cs is cool!
    * f:  73 20 63 6f 6f 6c 21 00
        * 00 21 6c 6f 6f 63 20 73
        * 00216c6f6f632073


---



## Problem 4
* a: 0x26 = 0010 0110 b
* b: 0x74 = 0111 0100 b
<br>

    * c:  2e 53 74 72
        * 72 74 53 2e
        * 7274532e
    * d:  0x74 = t
    * e:  52 69 73 65 26 53 68 6f 75 74  ->  Rise&Shout
    * f:  75 74 00 52 6f 79 61 6c
        * 6c 61 79 6f 52 00 74 75
        * 6c61796f52007475



---



## Problem 5
* a: 0x68 = 0110 1000 b
* b: 0x3f = 0011 1111 b
<br>

    * c:  46 00 3f 6a
        * 6a 3f 00 46
        * 6a3f0046
    * d:  0x68 = h
    * e:  68 5f 39 46 -> h_9F
    * f:  39 68 5f 39 46 00 3f 6a
        * 6a3f0046395f6839



---



## Problem 6
* a: 0x41 = 0100 0001 b
* b: 0x70 = 0111 0000 b
<br>

    * c:  41 00 49 4f
        * 4f 49 00 41
        * 4f490041
    * d:  0x70 = p
    * e:  70 32 65 4c 6d 41 -> p2eLmA
    * f:  24 70 3b 70 32 65 4c 6d
        * 6d 4c 65 32 70 3b 70 24
        * 6d4c6532703b7024



---



## Problem 7
* a: 0x21 = 0010 0001 b
* b: 0x48 = 0100 1000 b
<br>

    * c:  78 48 69 21
        * 21 69 48 78
        * 21694878
    * d:  0x21 = !
    * e:  78 48 69 21 21 -> xHi!!
    * f:  0x48 = H



---



## Problem 8
* a: 0x31 = 0011 0001 b
* b: 0x79 = 0111 1001 b
<br>

    * c:  34 60 31 4f
        * 4f 31 60 34
        * 4f316034
    * d:  0x34 = V
    * e:  5a 77 78 78 -> Zwxx
    * f:  34 4b 79 42 34 68 3e 5a
        * 5a 3e 68 34 42 79 4b 34
        * 5a3e683442794b34



---



## Problem 9
73 34 4e 42 = s4NB -> BN4s
2c 4b 57 61 = ,KWa -> aWK,
3d 51 40 2a = =Q@* -> *@Q=

BN4saWK,*@Q=



---  



## Problem 10
first scan needs to input 'esiR', but in Hex.  
it needs to be backwards since it prints arrays backwards from how it scans.  
- 65 73 69 52
- 65736952

second scan gets the next 2 ints (8 bytes, or 8 chars), so it gets '+Sho' and 'ut+B' in the second scan. 
starts at s_prt, which is a + 1, so at index 5
- +Shout+B

third scan needs '00!UY' but in Hex
starts at a[3], which should be 3 * 4, so at index 12
- 00 21 55 59
- 00215559



---



## Problem 11

str = I <3 cs 224!! (*ˆ_ˆ*)

first a long hex (8 bytes)
second an int hex (4 bytes)
third an int hex (4 bytes)
4th a string of chars, ending in 0 NULL

first
* 49 20 3c 33 20 63 73 20 (have to reverse it due to how it reads in Hex)
* 20 73 63 20 33 3c 20 49
* 20736320333c2049

second
* 32 32 34 21 (have to reverse it again)
* 21 34 32 32
* 21343232

third 
* 21 20 28 2a
* 2a 28 20 21
* 2a282021

fourth
* ˆ_ˆ*)


20736320333c2049 21343232 2a282021 ˆ_ˆ*)

