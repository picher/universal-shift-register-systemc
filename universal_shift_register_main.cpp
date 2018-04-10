#include "systemc.h"
//universal_shift_register_main.cpp
//#include "universal_shift_register.h"
#include "universal_shift_register_driver.h"
#include "universal_shift_register_monitor.h"
  
//int sc_main_usr1()
int sc_main(int argc , char *argv[] )
{	
	sc_uint<2> uint1=3;
	cout<<"\nHELLO SIM USR"<<" uint1:"<<(sc_bv<4>)(~uint1)<<" ,: "<<(sc_bv<4>)(uint1)<<" \n";
	cout<<"\nHELLO SIM USR \n";
	sc_clock mclk("mclk",10,SC_NS,0.5,5,SC_NS,false);
	sc_signal<bool> t_clr,t_lin,t_rin,t_found;
	sc_signal<select_type> t_select;
	sc_signal<sc_uint<3>> t_par_in;//in
	sc_signal<sc_uint<3>> t_q;//out

	universal_shift_register usr("usr1");
	usr.clk(mclk);
	usr.clr(t_clr);
	usr.lin(t_lin);
	usr.rin(t_rin);

	usr.select(t_select);
	usr.par_in(t_par_in);

	usr.q(t_q);
	usr.found(t_found);

	universal_shift_register_driver usr_d("usr_d");
	usr_d.d_clr(t_clr);
	usr_d.d_lin(t_lin);
	usr_d.d_rin(t_rin);

	usr_d.d_select(t_select);
	usr_d.d_par_in(t_par_in);
	//usr_d.d_clk(mclk);

	universal_shift_register_monitor usr_m("usr_m1");
	usr_m.m_clk(mclk);
	usr_m.m_clr(t_clr);
	usr_m.m_lin(t_lin);
	usr_m.m_rin(t_rin);
	
	//usr_m.m_select(t_select);
	usr_m.m_par_in(t_par_in);

	usr_m.m_q(t_q);
	usr_m.m_found(t_found);
	
	//monitor<<t_tsq<<t_rsq;
	//
	sc_trace_file *tf=sc_create_vcd_trace_file("USR");
	sc_trace(tf, mclk, "mclk");
	sc_trace(tf, t_lin, "t_lin");
	sc_trace(tf, t_rin, "t_rin");
	sc_trace(tf, t_clr, "t_clr");
	sc_trace(tf, t_q, "t_q");
	sc_trace(tf, t_found, "found");


	sc_start(100,SC_NS);

	return(0);
}