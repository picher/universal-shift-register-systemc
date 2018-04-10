//universal_shift_register_driver.cpp
#include "universal_shift_register_driver.h"

void universal_shift_register_driver::prc_universal_shift_register_driver(){
	int i=0;
	sc_bv<8> bv="11111111";
	d_select=SHIFT_LEFT;
	d_clr=1;
	while(1){
		d_lin=bv[0];
		d_rin=bv[0];
		d_par_in=3;
		bv=bv>>1;
		wait(10,SC_NS);
	}
}