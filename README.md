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
            











