//universal_shift_register_driver.h
#include <systemc.h>
#include "universal_shift_register.h"
const int WIDTHDD=3;


SC_MODULE(universal_shift_register_driver){
	sc_out<bool> d_clr,d_lin,d_rin;
	sc_out<select_type> d_select;
	sc_out<sc_uint<WIDTHDD>> d_par_in;
	//sc_in<bool> d_clk;

	void prc_universal_shift_register_driver();
	
	SC_CTOR(universal_shift_register_driver){
		SC_THREAD(prc_universal_shift_register_driver);
		//sensitive <<d_clk.pos() ;
	}
};