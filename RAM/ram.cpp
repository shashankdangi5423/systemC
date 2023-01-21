#include "ram.h"

void RAM::process()
{
	if(CHIP_ENABLE.read()){
		//cout << address << endl;
		address = ADDRESS.read();

		if(READ_WRITE.read()){
			//cout << address << endl;
			data = memory[address];
			//cout << data << endl;
			DATA_out.write(data);
		}else{
			//cout << address << endl;
			memory[address] = DATA_in.read();
			//cout<<memory[address]<<endl;

		}
	}
}



