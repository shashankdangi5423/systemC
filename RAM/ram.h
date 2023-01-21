#include<systemc.h>


SC_MODULE(RAM)
{
	//sc_clock clk;
	sc_in <sc_uint<8>> ADDRESS;
	sc_in <sc_uint<32>>DATA_in;
	sc_in<bool>READ_WRITE;
	sc_in<bool>CHIP_ENABLE;
	sc_out<sc_uint<32>> DATA_out;
	
	sc_uint<32> memory[256];	
	sc_uint<32> data;
	sc_uint<8> address;


	void read();
	void write();
	void process();

	SC_CTOR(RAM){
		SC_METHOD(process);
			sensitive << ADDRESS;

	}
};


