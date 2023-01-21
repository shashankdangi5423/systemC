#include<systemc.h>
#include "alu.h"


int sc_main(int ac,char *av[]){

    sc_signal<sc_bv<3>> aluctrl;
    sc_signal <sc_bv<DWORD>> a;
    sc_signal <sc_bv<DWORD>> b;
    sc_signal<sc_bv<DWORD>> result;
    sc_signal< sc_bv<5> > flag;


    ALU alu("ALU");

    //connecting alu inputs and outputs to signals
    alu.aluctrl(aluctrl);
    alu.a(a);
    alu.b(b);
    alu.result(result);
    alu.flag(flag);


    //TEST CASE FOR AND
    a=10;
    b=20;
    aluctrl =  ALU_AND ;

    sc_start(1,SC_NS);

    cout << result<<endl;
    cout<<flag<<endl; 

    //TEST CASE FOR ADD
    a=20;
    b=2;
    aluctrl =  ALU_ADD ;

    sc_start(1,SC_NS);
    
    cout << result<<endl;
    cout<<flag<<endl;    

    return 0;
}