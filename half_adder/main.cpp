#include "half_adder.h"

SC_MODULE (driver)
{
    sc_out <bool> d_A, d_B;
    
    void proc_driver()
    {
        // Test-bench
        
        sc_uint<2> pattern;
        pattern = 0; // Checking all different combinations of inputs for the half-adder (A,B = 00, 01, 10, 11)
        
        while (1)
        {
            d_A = pattern[1];
            d_B = pattern[0];
            
            wait(1, SC_NS);
            
            pattern++;
            
            if (pattern == 0)
                sc_stop();
        }
    }

    SC_CTOR(driver)
    {
        SC_THREAD (proc_driver);
    }
};

int sc_main (int argc, char * argv[])
{
    sc_signal <bool> t_A, t_B;
    sc_signal <bool> t_C, t_S;
    
    // DRIVER
    driver DRIVER ("DRIVER");
    DRIVER.d_A    (t_A);
    DRIVER.d_B    (t_B);
        
    // MAIN MODULE
    half_adder HA ("half-adder");
    HA.A (t_A);
    HA.B (t_B);
    HA.C (t_C);
    HA.S (t_S);

    // Dumping signals into .vcd file
    sc_trace_file *trace = sc_create_vcd_trace_file ("HALFADDER");
    
    sc_trace (trace, t_A                              , "A");
    sc_trace (trace, t_B                              , "B");
    sc_trace (trace, t_C                              , "Carry");
    sc_trace (trace, t_S                              , "Sum");

    sc_start(5, SC_NS);
    
    sc_close_vcd_trace_file(trace);

    return 0;
}

