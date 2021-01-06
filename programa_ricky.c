#include<18F4550.h>
#fuses NOMCLR INTRC_IO NOMCLR
#use delay(clock=4000000)
void main(){
    int8 decenas,unidades;
    set_tris_C(0x0F);
    set_tris_D(0x00);
    set_tris_B(0x00);
    setup_oscillator(OSC_4MHZ); // oscilador interno
    decenas = 0;
    unidades =0;
    output_d(0);
    output_b(0);
    while(TRUE){
        if(input(PIN_C0)==1){
            output_b(unidades);
            output_d(decenas);
            unidades=unidades+1;
            if(unidades==10){
            unidades=0;
            decenas=decenas+1;
            if(decenas==10){
            decenas=0;
            }//decenas
            }//unidades
        }//PIN
        delay_ms(200);
    }//while
}//main