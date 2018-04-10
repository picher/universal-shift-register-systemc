//universal_shift_register_monitor.h
#include <systemc.h>
const int WIDTHDM=3;

SC_MODULE(universal_shift_register_monitor) {
	sc_in<bool> m_clk,m_clr,m_lin,m_rin;
	//sc_in<sc_uint<2>> m_select;
	sc_in<sc_uint<WIDTHDM>> m_par_in;
	sc_in<sc_uint<WIDTHDM>> m_q;
	
	sc_in<bool> m_found;//sequence

        void prc_universal_shift_register_monitor();

        SC_CTOR(universal_shift_register_monitor)
        {
                SC_METHOD(prc_universal_shift_register_monitor);
				sensitive<< m_clk.pos()<<m_q;
        }
}; //Don't forget the semicolon!
