#include "universal_shift_register_monitor.h"

void universal_shift_register_monitor:: prc_universal_shift_register_monitor(){

	cout << "time " << sc_time_stamp() << "::";
		cout   <<" ,m_clk:"<<m_clk
			<< " ,m_clr: "<<m_clr 
			<< " ,m_lin: "<<(sc_bv<WIDTHDM>)m_lin 
			<< " ,m_rin: "<<(sc_bv<WIDTHDM>)m_rin 
			//<< " ,m_select: "<<m_select 
			<< " ,m_par_in: "<<(sc_bv<WIDTHDM>)m_par_in 
			<< " ,m_q: "<<(sc_bv<WIDTHDM>)m_q 
			<< " ,m_found: "<<m_found 
			
			<<"\n" ;
}
