/** @file   system.c
    @author M. P. Hayes, UCECE
    @date   15 May 2007
    @brief  UCFK system initialisation
*/
#include "system.h"
#include <avr/wdt.h>


static void system_clock_init (void)
{
    /* Switch 1 MHz CPU clock to 8 MHz.  */
	//CLKSEL0 |= (1<<2) | (1<<0); //?
    CLKPR = BIT (CLKPCE);
    CLKPR = 0;
}


static void system_watchdog_timer_init (void)
{
    wdt_reset ();

    /* Clear WDRF in MCUSR.  */
    MCUSR &= ~BIT (WDRF);
    /* Write logical one to WDCE and WDE and keep old prescaler
       setting to prevent unintentional time-out.  */
    WDTCSR |= BIT (WDCE) | BIT (WDE);

    /* Turn off watchdog timer.  */
    WDTCSR = 0x00;
}


void system_init (void)
{
    system_clock_init ();
    system_watchdog_timer_init ();
}



