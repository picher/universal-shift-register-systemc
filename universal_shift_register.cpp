//universal_shift_register.cpp
#include "universal_shift_register.h"

void universal_shift_register::prc_usr(){
	sc_uint<WIDTH> q_temp;
	select_type sel_temp;
		
	if(!clr)
		q=0;
	else{
		q_temp=	q.read();
		sel_temp=select.read();
		
		switch(sel_temp){
			case HOLD: break;
			case SHIFT_LEFT: q=(q_temp.range(WIDTH-2,0),rin.read()); break;
			case SHIFT_RIGHT: q=(lin.read(),q_temp.range(WIDTH-1,1)); break;
			case LOAD: q=par_in;break;
		}
	}
}
void universal_shift_register::prc_sequece_detector(){
	sc_uint<WIDTH> temp; 
	temp=q;
	found=0;
	if(temp[0]==1 && temp[1]==1 && temp[2]==0){
		found=1;
	}
}