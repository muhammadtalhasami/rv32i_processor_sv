#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vcore.h"

vluint64_t sim_time = 0;

void values(Vcore* dut){
    if(sim_time == 0 ){
        dut-> rst = 0;
    }
    else if(sim_time >=1){
        dut-> rst  =   1;
    }
}

int main(int argc,char** argv,char** env)
{
    Vcore *dut =new Vcore;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    dut -> clk = 1;
    dut-> rst =  0;
    
    while(sim_time<60)
    {
        dut->clk = ! dut->clk;
        dut->eval();
        m_trace->dump(sim_time);
        values(dut);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS);
}