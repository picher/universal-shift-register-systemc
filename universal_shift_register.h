//universal_shift_register.h
#include <systemc.h>
#include "user.h"
const int WIDTH=3;
enum select_type{HOLD,SHIFT_LEFT,SHIFT_RIGHT,LOAD};

SC_MODULE(universal_shift_register){
	
	sc_in<bool> clk,clr,lin,rin;

	sc_out<bool> found;//sequence detoector

	sc_in<select_type> select;

	sc_in<sc_uint<WIDTH>> par_in;
	sc_out<sc_uint<WIDTH>> q;
	
	void prc_usr();
	void prc_sequece_detector();

	SC_CTOR(universal_shift_register){
		SC_METHOD(prc_usr);
		sensitive<<clk.pos()<<clr.neg();

		SC_METHOD(prc_sequece_detector);
		sensitive<<q;
	}
};