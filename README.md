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


































































