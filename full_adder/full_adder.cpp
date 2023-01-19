#include "full_adder.h"

void full_adder::proc_full_adder()
{
	C_out.write(sig_carry1 | sig_carry2); 
}
