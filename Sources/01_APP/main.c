/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "LED.h"
#include "BUTTON.h"

#define TIME_1S           (1800000u)

int main(void)
{
/*Init RED led*/
if( eTRUE_LED == efInit_LED( eRED_LED ) && eTRUE_LED == efInit_LED( eGREEN_LED ) &&
    eTRUE_LED == efInit_LED( eBLUE_LED ))
{
	printf("Succes Initializing LED driver");
}else{}

if( eTRUE_LED == efCreate_BUTTON() )
{
	printf("Succes Initializing BUTTON driver");
	sBUTTON_t ButtonA;
	sBUTTON_t ButtonB;

}else {}

	for(;;) {
		if( eTRUE_BUTTON == efRead_BUTTON(&ButtonA))
		{
			vfTurnOn_LED(eRED_LED);
			vfdelay_BUTTON(TIME_1S);
			vfTurnOff_LED(eRED_LED);
			vfTurnOn_LED(eGREEN_LED);
			vfdelay_BUTTON(TIME_1S);
			vfTurnOff_LED(eGREEN_LED);
			vfTurnOn_LED(eBLUE_LED);
			vfdelay_BUTTON(TIME_1S);
			vfTurnOff_LED(eBLUE_LED);
		}else if ( eTRUE_BUTTON == efRead_BUTTON(&ButtonB))
		{
			vfTurnOn_LED(eGREEN_LED);
			vfdelay_BUTTON(TIME_1S);
			vfTurnOff_LED(eGREEN_LED);
			vfTurnOn_LED(eRED_LED);
			vfdelay_BUTTON(TIME_1S);
			vfTurnOff_LED(eRED_LED);
			vfTurnOn_LED(eBLUE_LED);
			vfdelay_BUTTON(TIME_1S);
			vfTurnOff_LED(eBLUE_LED);
		}else{}

	}

	return 0;
}
