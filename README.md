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





