#include<stdio.h>
#include "systemc.h"
#include "half_adder.h"

SC_MODULE (full_adder)
{
	sc_in <bool> A,B,C_in;
	sc_out <bool> C_out,Sum;
	sc_signal<bool> sig_sum,sig_carry1,sig_carry2;

	void proc_full_adder();

	half_adder *h1;
	half_adder *h2;

	SC_CTOR(full_adder)
	{
		h1 = new half_adder("ha1");
		h1 -> A(A);
		h1 -> B(B);
		h1 -> S(sig_sum);
		h1-> C(sig_carry1);

		h2 = new half_adder("ha2");
		h2 -> A(sig_sum);
		h2 -> B(C_in);
		h2 -> S(Sum);
		h2-> C(sig_carry2);



		SC_METHOD (proc_full_adder);
		sensitive << sig_carry2 << sig_carry1 ;
	}
};
	
