#include "half_adder.h"

void half_adder::proc_half_adder()
{
    C.write (A.read() & B.read()); // Carry
    S.write (A.read() ^ B.read()); // Sum
}
