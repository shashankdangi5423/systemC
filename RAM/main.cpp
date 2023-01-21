#include <systemc.h>
#include "ram.h"

SC_MODULE(DRIVER)
{
	sc_out<sc_uint<8>> ADDRESS;
	sc_in<sc_uint<32>> DATA_in;
	sc_out<sc_uint<32>> DATA_out;
	sc_out<bool> READ_WRITE;
	sc_out<bool> CHIP_ENABLE;

	sc_uint<8> address = 0x00;
	sc_uint<32> data = 0x4fa11;

	void process()
	{
		for(int i = 0;i< 200;i++,address++,data++){
			CHIP_ENABLE.write(1);
			READ_WRITE.write(0);
			DATA_out.write(data);
			ADDRESS.write(address);
			wait(1,SC_NS);
		}

		data=0;
		address = 0x00;

		for(int i = 0;i<100;i++){
		
			CHIP_ENABLE.write(1);
			READ_WRITE.write(1);
			data = DATA_in.read();
			ADDRESS.write(address);
			wait(1,SC_NS);
			if(i!=0){
			cout<<"Data stored in memory address :" << address<< " is : "<<data<<endl;
			}
			address++;

		}
	}

	SC_CTOR(DRIVER)
	{
		SC_THREAD(process);
	}
};

int sc_main(int ac, char *av[])
{
	sc_signal<sc_uint<32>> s_data_in, s_data_out;
	sc_signal<sc_uint<8>> s_address;
	sc_signal<bool> s_read_write, s_chip_enable;

	RAM ram("RAM");
	DRIVER D1("d1");

	ram.ADDRESS(s_address);
	ram.DATA_in(s_data_in);
	ram.DATA_out(s_data_out);
	ram.READ_WRITE(s_read_write);
	ram.CHIP_ENABLE(s_chip_enable);

	D1.ADDRESS(s_address);
	D1.DATA_in(s_data_out);
	D1.DATA_out(s_data_in);
	D1.READ_WRITE(s_read_write);
	D1.CHIP_ENABLE(s_chip_enable);

	sc_start();

	return 0;
}
