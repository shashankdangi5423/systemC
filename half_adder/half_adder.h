#include <stdio.h>
#include "systemc.h"

SC_MODULE (half_adder)
{
    sc_in <bool> A, B; // Inputs: A and B (ont-bit)
    sc_out <bool> C, S; // Outputs: C (Carry) and S (Sum)
    
    void proc_half_adder(); // half-adder process
    
    SC_CTOR (half_adder)
    {
        SC_METHOD (proc_half_adder);
        sensitive << A << B;
    }
};
