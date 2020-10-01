# Linux-x86-course
Flat memory was introduced in the Intel 80386 microprocessor.
Expansion of x86 32 bit came with Intel P5. It came up with a new technology (MMX)
Then came Intel P6 came up with SSE

Intel Netburst included SSE2, to cover double precision values

In 2006, intel launched Core extended to 64-Bit (16-Bit,32-Bit,64-Bit,SS4.1)

Intel Nehalem microarchitecture in 2008 (16-Bit,32-Bit,64-Bit,SS4.1) e.g.,(i3,i5,i7) 

In 2011, intel launched Intel Sandy Bridge (16-Bit,32-Bit,64-Bit,AVX) using 256 wide registers (2nd Gen core i3,i5,i7 CPUs)

In 2013, Intel Haswell was launched (16-Bit,32-Bit,64-Bit,AVX2) and FMA operations. (4th Gen core i3,i5,i7 CPUs)

            Name                    Year                Transistors                 MHz
            8086                    1978                    29K                     5-10
            386                     1985                    275K                    16-33
        Pentium 4E                  2004                    125K                    2800-3800
           Core 2                   2006                    291M                    1060-3333
           Core i7                  2008                    731M                    1060-4400

--------------------------------------------------------------------------------------------------------------           

Von Neumann Architecture in 1947                                    

  ----->ALU                                                             CPU                Memory 
  |      |                                                               |                   |
  |      |                                                               |-------------------|   
  | Control Unit--------|                                                          |
  |     |  |            |                                                         I/O              
  |     |  |            |                                                       
  |----Memory <------> I/O                                                      
Architecture proposed by John Von Neumann in 1947                          Von Neumann Architecture today

---------------------------------------------------------------------------------------------------------------

Harvard Architecture, separated memory for data and memory for instructions

        Instruction memory                          CPU                     Data Memory
            |                                       | |                         |
            ----------------------------------------- ---------------------------
                                                                   |
                                                                  I/O          
----------------------------------------------------------------------------------------------------------------

Simplifying both architectures

                Von Neumann                                                       Harvard  
                                            
        CPU<---------------------->Memory                                    |     Data Bus     |
            data & instruction bus                                           |<---------------->|  
                                                                          CPU|                  |Memory   
                                                                             |<---------------->|
                                                                             |  Instruction Bus |

    1.Single bus is simpler design                                      1. Multi-Bus is relatively complex
    2.Single bus is cheaper                                             2. Multi-Bus is relatively expensive
    3.Does not allow simultaneous                                       3. Allows 2 simultaneous memory fetches
        multiple memory fetches

------------------------------------------------------------------------------------------------------------------

1 hexadecimal digits is 4 binary digits

-------------------------------------------------------------------------------------------------------------------

byte -> 8bit
word -> 16bit
doubleword -> 32bit
quadword -> 64bit

--------------------------------------------------------------------------------------------------------------------

Basic x86 Microcomputer Design

                                          Data and I/O Bus
            ----------------------------------------------------------------------------------------------------------
            |                   |                |                  |          
            |                   |                |                  |
  ----------------------    ----------      ------------      -------------
  |         Registers  |    |        |      |          |      |           |
  |                    |    |Memory  |      |   I/O    |      |   I/O     |
  |       CPU          |    |Storage |      |  Device  |      |  Device   |
  |                    |    |Unit    |      |    #1    |      |    #2     |
  | alu  cu    clock   |    |        |      |          |      |           |
  |____________________|    |________|      |__________|      |___________|
      |         |             |    |           |    |            |      |
      |         |Control Bus  |    |           |    |            |      |
      |         |-------------|----------------|-----------------|-----------------------------------------------------
      |                       |                |                 |
      | Address Bus           |                |                 | 
      -----------------------------------------------------------------------------------------------------------------

  Clock: Sunchronizes internal operations
  CU(Control Unit): For coordination
  ALU(Arithmetic Logic Unit): For performing arithmetic operations
  Memory Storage Unit: Holds instructions and data
  Bus: Transfer data from one part of the computer to another

----------------------------------------------------------------------------------------------------------------------------------
x86 Operating Modes

1. Protected Mode
      |Virtual - 8086 Mode

2. Real - Address Mode

3. System Management Mode

Protected Mode
  It is the native state of processor
  All instruction features are available
  Includes virtual-8086 sub-mode
  Projects are given separate memory areas called segments
  Processor prevents program from referencing outside their segment
  It allows program to run in a safe multitasking environment, that is if one crashes it wont affect others.

Virtual - 8086 Mode
  Allows processor to directly execute real-address mode software while in Protected Mode.

Real-Address Mode
  Implements 8086 programming environment
  Capable of switching into other modes
  Programs that require direct access to system memory and hardware devices.
  Programs running in this mode can cause the OS to crash.

System Management Mode
  It provides the OS with some system functions like power management, system security. Usually implemented by computer manufacturers.

--------------------------------------------------------------------------------------------------------------------------------
x86 Registers

A register is a storage inside the processor core.
Can be accessed at much higher speeds than conventional memory.

8086(16-bit) registers

  1. General Purpose Registers (GPR)    AH | Al     BH | BL     CH | CL     DH | DL
      The AX is used as an accumulator, and preferred for most operations
      The BX is used as a base register, used to hold address of a procedure or variable.
      The CX is used as a count register, typically used for looping.
      The DX is used as a data register, typically used for multiplication and division.

      All GPR's can be represented as 2-8bit quantities.
      The high byte represented as H.
      The low byte as L.

  2. Index Registers      SI      DI      DP      SP
    contains offset from a segment register for information we are interested in.
    DP is the base pointer register and is the offset from the SS register, to locate variables on the stack.
    SP is the stack pointer register and is the offset from the SS register, to the location of the stack stop.
    SI is the source index register and is used in copying strings.
    DI is the destination index register and is also used in copying strings.

  3. Instruction Pointer      IP
    The IP register points to the next instruction to be executed

  4. Segment Registers    CS      DS      ES      SS
      The CS is the code segment register, and is the base location for program code.
      The DS is the data segment register, and is the base location for variables.
      The SS is the stack segment register, is the base location for the stack.
      The ES is the extra segment register, for variables in memory.

  5. Flags Register     Flags
    The flags contains flags of processor

-------------------------------------------------------------------------------------------------------------------------

80386(32-bit)

1. General Purpose Registers(32-bit):     8
2. Segment Registers(16-bit):     6
3. Processor Status Flags Register(EFLAGS):     1
4. Instruction Pointer(EIP):      1

GPR:  EAX   EBX   ECX   EDX   EBP   ESP  ESI  EDI

SR:   CS    SS    DS    ES    FS    GS

Index registers are also known as Specialized Registers
                
                 32-Bit                     16-Bit
                 ESI                          SI  
                 EDI                          DI  
                 EBP                          BP
                 ESP                          SP

---------------------------------------------------------------------------------------------------------------------------
Pentium 4 (x64)
It has 16 GPRs.
GPR:    RAX   RBX   RCX   RDX   RBP   RSP   RSI   RDI   R8    R9    R10   R11   R12   R13   R14   R15

RIP       RFLAGS

we can reference lowest 8-bit in register RAX as AL and highest as AH same goes for 32-Bit registers

-----------------------------------------------------------------------------------------------------------------------------

x86 FLAGS
        1         Set
        0         Reset/Clear

    There are two groups of flags in x86.
    These are:
    1.  Control flags
    2.  Status Flags

    Control Flags
      Control CPU operations, to break after completion, or cause the CPU to interrupt when an arithmetic overflow is detected.

    Status Flags
      Reflect outcome of arithmetic and logical operations performed by the CPU.
      They are:
      a. Overflow(OF):  Set when the result of an signed arithmetic operation is too large to fit into the destination.
      b. Sign(SF):  Set when the result of an arithmetic or logical operation is negative.
      c. Zero(ZF):  Set when the result of an arithmetic or logical operation is zero.
      d. Carry(CF): Set when the result of an unsigned arithmetic operation is too large to fit into the destination.
      e. Parity flag(PF): Set if the least-significant byte in the result contains an even number of 1 bits.(Error checking)
      f. Auxiliary Carry(AC): Set when an arithmetic operation causes a carry from bit 3 to bit 4 in an 8-bit operand

---------------------------------------------------------------------------------------------------------------------------------

x86 SIMD and Floating-Point Registers
MMX Registers
1.  Pentium processors were first to have them.
2.  8 64-bit registers.
3.  They support special instructions like SIMD(Single Instructions Multiple Data)

The x86 architecture also contains 8 128-bit XMM Registers.

The FPU(Floating Point Unit) has been integrated on the main processor chip from Intel 486, before that a separate chip was required.
There are 8 floating point registers in the FPU.
These are :   ST(0)   ST(1)   ST(2)   ST(3)   ST(4)   ST(5)   ST(6)   ST(7) (80 bit Data Registers)

There are also 2 Pointer Registers
These are :   FPU Instruction Pointer         FPU Data Pointer    (48-bit Pointer Registers)

There are also 3 Control Registers
These are:    Tag Register      Control Register      Status Register     (16 - bit Control Registers)

we also have an Opcode Register
The FPU is sometimes called a x87 architecture
The FPU's 8 registers are organized as a stack.

The FPU instruction set support 3 types of memory operands.
1. Signed Integer
2. Floating Point
3. Packed BCD

Use of Signed bit Integer operands include 16-bit Word, 32-bit Doubleword, 64-bit Quadword.
Supported Floating point operands include the 32-bit Single Precision, 64-bit Double Precision, 80-bit Double Extended Precision
Many C and C++ compilers use Single and Double Precision operand types to implement float and double values respectively.

The x87 FPU encodes floating point values using 3 distinct fields.
we have: The Significand, The exponent, and the Signed bit
The Significand field represents the numbers significant digit, or the fractional part.
The exponent field locates the binary or decimal point in the significand which determines the magnitude
The Signed bit indicates whether the number is positive or negative, if S = 0, then positive and if S = 1 then negative.

----------------------------------------------------------------------------------------------------------------------------------

x86 Memory Model

Real-Address Mode:- Only 1MB of memory can be addressed
From 00000 to FFFFF
Processor can run only one program at a time but it can interrupt that program for a moment to process the request from peripherals
Application programs can access any memory location

Protected Mode:- Processor can run only multiple programs at a time
Each running program is assigned 4GB of memory
Programs cannot access each other's code and data
MS Windows and Linux run in protected mode.

Virtual-8086 Mode:-Computer runs in protected mode. Processor creates a virtual 8086 machine with its own 1MB of address space that simulates an 8086 computer running in Real-Address Mode.

    8000 : 0000
      ^     ^
      |     |
     seg   ofs

Byte Addressable Memory: Each byte location(8-bit) has separate address

In Real Address mode,the linear address is 20-Bit ranging from 0 to FFFFF.
Programs cannot use linear addresses directly, so addresses are expressed using 2-16 Bit integers.
A segment offset address includes a 16-bit segment value, placed in one of the segment registers like CS, DS, ES or SS.
The CPU automatically converts the segment offset value to a 20-bit .

For Example
  Segment-offset address        08F1:0100
  The CPU multiplies the segment value by 16 
  0851 x 0100 = 08F10h
  Add the offset : 0851:0100
  08F10
  +0100

Program Segments:
1. CODE
2. DATA
3. STACK

CS contains the 16-bit code segment address
DS contains the 16-bit data segment address
SS contains the 16-bit stack segment address


In Protected Mode
There is 4GB Linear address space



Base address    limit     access
00000000        0040       ----

upto FFFFFFFF only upto 00040000 is used in this case.

--------------------------------------------------------------------------------------------------------------------------

64-bit register     |     Lower 32 bits     |     Lower 16 bits     |     Lower 8 bits
======================================================================================
      rax           |         eax           |         ax            |       al
      rbx           |         ebx           |         bx            |       bl
      rcx           |         ecx           |         cx            |       cl
      rdx           |         edx           |         dx            |       dl
      rsi           |         esi           |         si            |       sil
      rdi           |         edi           |         di            |       dil
      rbp           |         ebp           |         bp            |       bpl
      rsp           |         esp           |         sp            |       spl
      r8            |         r8d           |        r8w            |       r8b
      r9            |         r9d           |        r9w            |       r9b
      r10           |         r10d          |        r10w           |       r10b 
      r11           |         r11d          |        r11w           |       r11b
      r12           |         r12d          |        r12w           |       r12b
      r13           |         r13d          |        r13w           |       r13b
      r14           |         r14d          |        r14w           |       r14b
      r15           |         r15d          |        r15w           |       r15b
=====================================================================================

----------------------------------------------------------------------------------------------------------------------

x86 Integer Constants

  + or - digits radix

  Radix can be:
  H     Hexadecimal
  r     Encoded real
  q/o   Octal
  t     Decimal
  d     Decimal
  y     Binary
  b     Binary

--------------------------------------------------------------------------------------------------------------------
Integer Precedence
          Operator                Name                  Precedence
          ()                     Parentheses                 1
          + , -              Unary plus,Unary minus          2
          * , /                 Multiply,Divide              3
          MOD                       Modulus                  3
          + , -                 Add, Subtract                4

-------------------------------------------------------------------------------------------------------------------   

Directives and Instructions

Directives?
1. Assist and control assembly process.
2. They are not part of the instruction set, they aren't instructions.
3. Are also called pseudo-ops.
4. They change the way code is assembled.

Some Directives are:
  .CODE - Indicates the start of a code segment
  .DATA - Indicates the start of a data segment
  .STACK  - Indicates the start of a stack segment
  .END  - Marks the end of a module
  .DD - Allocate a double word (4 bytes) storage
  .DWORD  - Allocate a double word(4 bytes) storage

Instructions?
1.  A statement that becomes executable when a program is assembled
2.  Are translated by assembler into machine language bytes.
  An instruction has 4 parts, of which two are optional
      [label:] mnemonic [operands] [;comment]
      label and comment are optional, other 2 are required

      E.g.,
      start : mov eax,10000h ; EAX = 10000h

      Label:  Used as a place marker for instructions and data. it implies the instruction's address

      Data Labels
      E.g.,
        count DWORD 100
        we have declared a 32-bit variable called count and value assigned to it is 100.

      E.g.,
        amount DWORD 1024, 2048
               DWORD 4069, 8192
        amount defines the location of first number which is 1024, other numbers follow consecutively.

      Code Labels
        A label with code, must end with a colon(:)
      E.g.,
        start:
            mov ax, bx
            ...
            jmp start

      Mnemonic : Identifies an instruction
      E.g.,
      mov : Move (assign) one value to another
      add : Add two values
      sub : Subtract one value from another
      mul : Multiply two values
      jmp : Jump to a new location
      Call: Call a procedure

      Operand : quantity on which an operation can be done
            Operator          Name
              20              Constant
              35-7            Constant expression
              EAX             Register
              count           Memory

      Comment
      Block Comments:
        COMMENT !
        This is awesome
        Isn't it?
        !

        COMMENT &
        This is awesome
        Isn't it?
        &

      Single line Comments:
        just use semi-colon before the comment.

----------------------------------------------------------------------------------------------------------------------------

Endianness

It describes how data is stored and retrieved from memory.
x86 use the little endian order.
This means that the least significant byte is stored at the first memory address allocated for the data, the remaining byte are stored at the next consecutive positions.
        E.g.,
          12345678h                                   
            Offset      Value                         Offset        Value
            0000          78                          0000          12
            0001          56                          0001          34
            0002          34                          0002          56
            0003          12                          0003          78

            Little Endian                                 Big Endian
----------------------------------------------------------------------------------------------------------------------------------
Call Conventions

      x86 32                                      x86 64                                      x87 (FP)

  1st argument = ebx                        1st argument = rdi                            1st argument = xmm0
  2nd argument = ecx                        2nd argument = rsi                            2nd argument = xmm1
  3rd argument = edx                        3rd argument = rdx                            3rd argument = xmm2
  4th argument = esi                        4th argument = rcx                            4th argument = xmm3
  5th argument = edi                        5th argument = r8                             5th argument = xmm4
  6th argument = ebp                        6th argument = r9                             6th argument = xmm5
                                                                                          7th argument = xmm6

  eax : return register, syscall number      
  rax : return register, syscall number

----------------------------------------------------------------------------------------------------------------------------------

GAS Directives (MAC OSX)

.section data                                            .section __DATA,__data   
# your data here                                          # your data here 
                                  OR
.section text                                            .section __TEXT,__text  
# your code here                                          # your code here

    this way                is converted to                  this way   


.lcomm
  1. Defines a local uninitialized block of storage called a local common (LC) section
  2. Use the .lcomm pseudo-op with local uninitialized data, which is data that will probably not be accessed outside the local assembly 
  3. Allocates storage in the .css section

.bss (block start by symbol)
  1. Section for all uninitialized Variables.    

.globl : make label accessible by other files

  Snippet
          .section text
          .globl _main

          _main:
            movl $5, %eax
            movl $3, %ebx
            .
            .
            .   
----------------------------------------------------------------------------------------------------------------------------------

NASM Directives

    .section .data
    # your data here

    .section .text
    # your code here

    BITS: Specifying Target Processor Mode

    SECTION or SEGMENT: Changing and Defining Sections

    EXTERN: Importing Symbols from Other Modules

    COMMON: Defining Common Data Areas

    GLOBAL: Exporting Symbols to Other Modules

    STATIC: Local Symbols within Modules

    EQU: Define Symbol to a given constant

Pseudo-Instructions
  Initialized Data
    DB, DW, DD, DQ, DT, DO, DY and DZ

  Uninitialized Data
    RESB, RESW, RESD, RESQ, REST, RESQ, RESY and RESZ  

----------------------------------------------------------------------------------------------------------------------------------

Linux Syscalls
  We use system calls to request services from the OS kernel.

  section .data
    msg db    "hello, world!"

  section .text
    global _start

  _start:
    mov   rax, 1          <-------------------------------  Syscall number 1 = write
    mov   rdi, 1          <-------------------------------  1st argument to function
    mov   rsi, msg        <-------------------------------  2nd argument to function
    mov   rdx, 13         <-------------------------------  3rd argument to function  
    syscall
    mov   rax, 60                   rax - temporary resgister; when we call a  syscall, rax must contain syscall number
    mov   rdi, 0                    rdx - used to pass 3rd argument to functions
    syscall                         rdi - used to pass 1st argument to funtions
                                    rsi - pointer used to pass 2nd argument to functions


                            rdi               rsi             rdx
    size_t sys_write( unsigned int fd, const char * buf, size_t count );

    fd: file descriptor, 0 for standard input, 1 for standard output and 2 for standard error
    buf: points to a character array, which can be used to store content obtained from the file pointed by fd
    count: specifies the number of bytes to be written from the file into the character array.

    https://filippo.io/linux-syscall-table/

--------------------------------------------------------------------------------------------------------------------------------

Operand Types

  mnemonic
  mnemonic [destination]
  mnemonic [destination], [source]
  mnemonic [destination], [source 1], [source 2]

Types of Instruction Operands
  Immediate -> uses numeric literal expression
  Register -> uses named letter in the CPU
  Memory -> uses memory location

Direct Memory Operand
  Variable names are reference to offset within the data segment    
  E.g.,
    .data
    num1 BYTE 13h
    This declaration shows a byte containing the number 13h has been allocated in the data segment.

  Program code contains instructions that dereference memory operands using the addresses.
  E.g.,   num1 is located at 10400h
          to move it to Al, the instruction would look like this
          mov AL, num1
              |      
              |
        A0 00010400

Some notation adopted for operands in x86 manuals
  reg8  : 8-bit GPR:  AH, AH, BH, BL, CH, CL, DH, DL
  reg16 : 16-bit GPR:   AX, BX, CX, DX, SI, DI, SP, BP
  reg32 : 32-bit GPR:   EAX, EBX, ECX, EDX, ESI, EDI, ESP, EBP
  reg : Any GPR
  sreg  : 160bit segment register:    CS, DS, SS, ES, FS, GS
  imm : 8-, 16-, or 32-bit immediate value
  imm8  : 8-bit immediate byte value
  imm16 : 32-bit immediate word value
  imm32 : 32-bit immediate doubleword value
  reg/mem8  : 8-bit operand, which can be an 8-bit general register or memory byte   
  reg/mem16  : 16-bit operand, which can be an 16-bit general register or memory word
  reg/mem32  : 32-bit operand, which can be an 32-bit general register or memory doubleword
  mem : An 8-, 16-, or 32-bit memory operand

----------------------------------------------------------------------------------------------------------------------------------

The MOV Instruction

copies dta from source to destination operand.

    MOV destination, source

Copying Smaller Values to Larger Ones: MOV cannot directly copy data from smaller operand to larger one.
  E.g., Suppose we move count i.e., an unsigned 16-bit value to ECX(32-bit)
      count : unsigned 16-bit value

      .data
      count WORD 1

      .code
      mov ecx, 0
      mov cx, count
----------------------------------------------------------------      
 MOVZX (MOV with zero-extend)
            MOVZX       reg32, reg/mem8
            MOVZX       reg32, reg/mem16
            MOVZX       reg16, reg/mem8
    E.g.,
    zero-extend binary 10001111b into AX:
    .data
    byteVal   BYTE  10001111b

    .code
    movzx ax, byteVal   ; AX = 0000000010001111b

    # MOVZX to copy a byte into a 16-bit destination
----------------------------------------------------------------
MOVSX (MOV with sign-extend)
          MOVSX       reg32, reg/mem8
          MOVSX       reg32, reg/mem16
          MOVSX       reg16, reg/mem8
    An operand is sign extended by taking the smaller operand's highest bit and repeating the bit throughout the extended bit
    and the destination operand
    E.g.,
      sign-extend binary 10001111b into AX:
      .data
      byteVal BYTE 10001111b

      .code
      movsx ax, byteVal ; AX = 1111111110001111b
----------------------------------------------------------------
Direct-Offset Operands:
We can add a displacement to the name of variable creating direct offset operand
This lets us access memory location that may not have explicit labels.
e.g.,
  numArray BYTE 10h, 20h, 30h, 40h, 50h
  mov al, numArray  ; AL = 10h
  mov al, [numArray+1]  ; AL = 20h
  mov al, [numArray+2]  ; AL = 30h

----------------------------------------------------------------------------------
 Memory Address Modes:
 The x86 uses upto 4 components to specify memory operand
 1. Base Register
 2. Index Register
 3. Scale Factor
 4. Displacement Value

 The Effective Address = BaseReg + IndexReg * ScaleFactor + DispValue

 BaseReg can be any GPR
 IndexReg can be any GPR except the Stack Pointer(SP)
 DispValue are constants that are encoded within the instruction
 The ScaleFactor can be 1, 2, 4 or 8
 The size of Final Effective Address is always 32 bit.

 Addressing Form                                Example
  Disp                                      mov eax,  [MyVal]
  BaseReg                                   mov eax,  [ebx]
  BaseReg + Disp                            mov eax,  [ebx+12]
  Disp + IndexReg * SF                      mov eax,  [MyArray+esi*4]
  BaseReg + IndexReg                        mov eax,  [ebx+esi]
  BaseReg + IndexReg + Disp                 mov eax,  [ebx+esi+12]
  BaseReg + IndexReg * SF                   mov eax,  [ebx+esi*4]
  BaseReg + IndexReg * SF + Disp            mov eax,  [ebx+esi*4+20]

---------------------------------------------------------------------------------------------------
Some Arithmetic Instructions
  ADD - signed integer add
  SUB - subtract
  MUL - unsigned multiply
  IMUL  - signed multiply
  DIV - unsigned divide
  IDIV  - signed divide
  INC - increment
  DEC - decrement
  NEG - negate

-------------------------------------------------------------------------------------------------------

Arithmetic Instructions

Increment and Decrement

INC reg/mem
DEC reg/mem

  e.g.,
    .data
    myWord  WORD 1000h

    .code
    inc myWord    ;myWord = 1001h
    mov bx, myWord
    decbx ;BX = 1000h

-------------------------------------------------------------------------------------------------------------

Addition and Subtraction 

ADD dest, source
  e.g.,
  .data
  var1  DWORD 10000h
  var2  DWORD 20000h

  .code
  mov eax,  var1  ;EAX = 10000h
  add eax,  var2  ;EAX = 30000h

SUB dest,source
  e.g.,
  .data
  var1  DWORD 30000h
  var2  DWORD 10000h

  .code
  mov eax,  var1  ;EAX = 30000h
  sub eax,  var2  ;EAX = 20000h 

-----------------------------------------------------------------------------------------------------------------
int means interrupt, and the number 0x80 is the interrupt number. An interrupt transfers the program flow to whomever is handling that interrupt, which is interrupt 0x80 in this case. In Linux, 0x80 interrupt handler is the kernel, and is used to make system calls to the kernel by other programs.

The kernel is notified about which system call the program wants to make, by examining the value in the register %eax (AT&T syntax, and EAX in Intel syntax). Each system call have different requirements about the use of the other registers. For example, a value of 1 in %eax means a system call of exit(), and the value in %ebx holds the value of the status code for exit().
-------------------------------------------------------------------------------------------------------------------

Data Operatives and Directives:
Are not executable instructions, they are simply interpreted by the assembler.

OPERATIVES----
1. OFFSET:  Returns offset of a data label
2. PTR: Override operand's default size
3. TYPE:  Returns size of operand or array element size
    e.g.,
    TYPE of BYTE = 1
    TYPE of WORD = 2
    TYPE of DOUBLEWORD = 4
    TYPE of QUADWORD = 8
4. LENGTHOF:  Returns number of elements in an array
5. SIZEOF: Returns number of bytes used by array initializer (TYPE * LENGTHOF) 

DIRECTIVES----
1. LABEL: Redefines same variable with different size attributes
2. ALIGN: Aligns a variable on a boundary (boundary can be a byte, word or a dword)

-------------------------------------------------------------------------------------------------------------------------------

AT&T Syntax Addressing Modes
1. Indexed Addressed: 
  The memory location is determined by the following
  - A base address
  - An offset address to add to the base address
  - The size of the data element
  - An index to determine which data element to select

  base_address(offset_address, index, size)

  - The data value retreived is located at:
    base_address + offset_address + index * size

  - If any of the values are zero, they can be omitted 
    (but the commas are still required as placeholders)
    E.g.,
        movl $2, %edi
        movl values( , %edi, 4), %eax

2.  Indirect Memory addressing
  Move the memory address the value label references to the EDI register
  E.g.,
      movl  $values, %edi
      movl  %ebx, (%edi)

  - The dollar sign ($) before the label instructs the assembler to use the memory address, and not the data value located at the address
  - Without the parentheses around the EDI register, the instruction would just load the value in the EBX register to the EDI register. With the parentheses around the EDI register, the instruction instead moves the value in the EBX register to the memory location contained in the EDI register.

---------------------------------------------------------------------------------------------------------------------------------

Some Control Flow
There is a CMP instruction, after this the below ones occurs on the basis of comparison results:-

JE  - if equal
JZ  - if zero
JNE - if not equal
JNZ - if not zero
JG  - if first operand is greater than second
JGE - if first operand is greater or equal to second
JZ  - same as JG, but performs unsigned comparison
JAE  - same as JGE, but performs unsigned comparison

---------------------------------------------------------------------------------------------------------------------------------

Conditional Branching:-

1. The Jump Instruction
    The JMP causes an unconditional transfer to a destination, identified by a code label that is translated by the assembler into an offset. 
    
    JMP destination
    E.g.,
        start:
        .
        .
        jmp start   ;repeat the endless loop

2.  The Loop Instruction
    It repeats a block of statement a specific number of times.
    The ECX register is automatically used as a counter and is decremented each time a loop repeats.

    LOOP destination steps
    1. It subtracts 1 from ECX register,
    2. It compares it to zero
    3. If ECX is not equal to zero, then it jumps to the label identified by the destination.

3.  Logic Instructions
    AND Instruction performs a bitwise AND operation

    AND destination, source  

    Different operands in AND
    - AND reg,reg 
    - AND reg,mem
    - AND reg,imm
    - AND mem,reg
    - AND mem,imm

    OR Instruction performs a bitwise OR operation

    OR destination, source  

    Different operands in OR
    - OR reg,reg 
    - OR reg,mem
    - OR reg,imm
    - OR mem,reg
    - OR mem,imm  

    TEST Instruction
      It performs an implied AND operation between each pair of matching bits in two operands and sets the sign zero in parity flags based on the value assigned in destination operand
      TEST reg,reg

      test al, 00001001b ; test bits 0 and 3 in the al register      

    CMP Instruction
      CMP destination, source

      It performs subtraction of source from a destination operand.

    Condtional Jump Instruction
      
      SUB-----|
              |
      AND-----|-> Modify CPU status flags
              |
      CMP-----|

      Jcond destination

      E.g.,                                                       E.g.,
          cmp eax, 0                                                  cmp eax, 0 
          jz level2 ; jump if ZF = 1                                  jnz level2 ; jump if ZF = 0
          .                                                           .
          .                                                           .
          level2:                                                     level2:

      Table:

          JC              Jump if Carry flag is set               CF = 1 
          JNC             Jump if Carry flag is not set           CF = 0

          JZ              Jump if Zero flag is set                ZF = 1 
          JNC             Jump if Zero flag is not set            ZF = 0

          JO              Jump if Overflow flag is set            CF = 1 
          JNO             Jump if Overflow flag is not set        CF = 0 

          JS              Jump if signed flag is set              SF = 1 
          JNS             Jump if signed flag is not set          SF = 0 

          JP              Jump if parity flag is set              PF = 1 
          JNP             Jump if parity flag is not set          PF = 0  


      Equality Comparisons
        JE          Jump if equal
        JNE         Jump if not equal
        JCXZ        Jump if CX = 0 
        JECXZ        Jump if ECX = 0 

                     CMP leftOp, rightOp     

--------------------------------------------------------------------------------------------------------------------------------        
Instruction Operands
            Type                          Example                     In C/C++

          Immediate                     mov eax, 42                   eax = 42
                                        imul ebx, 11h                 ebx *= 0*11
                                        xor dl, 55h                   dl ^= 0x55
                                        add esi, 8                    esi += 8

          Register                      mov eax, ebx                  eax = ebx
                                        inc ecx                       ecx += 1
                                        add ebx, esi                  ebx += esi
                                        mul ebx                       edx:eax = eax * ebx

          Memory                        mov eax, [ebx]                eax = *ebx
                                        add eax, [val1]               eax += *val1
                                        or ecx, [ebx+esi]             ecx |= *(ebx + esi)
                                        sub word ptr [edi],12         *(short*)edi -= 12


--------------------------------------------------------------------------------------------------------------------------------


























































