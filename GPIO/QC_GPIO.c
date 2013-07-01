#include "GPIO/QC_GPIO.h"

void QC_GPIO_Init(void){
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Enable port F
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); // Enable port B
ROM_GPIOPinConfigure(GPIO_PF2_T1CCP0); // Configure pin PF2 as output of Timer 1_A
ROM_GPIOPinConfigure(GPIO_PF3_T1CCP1); // Configure pin PF3 as output of Timer 1_B
ROM_GPIOPinConfigure(GPIO_PB6_T0CCP0); // Configure pin PB6 as output of Timer 0_A
ROM_GPIOPinConfigure(GPIO_PB7_T0CCP1); // Configure pin PB7 as output of Timer 0_B
ROM_GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_2 ); // Enable pin PF2 as output of timer addressed to it
ROM_GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_3 ); // Enable pin PF3 as output of timer addressed to it
ROM_GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_6 ); // Enable pin PB6 as output of timer addressed to it
ROM_GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_7 ); // Enable pin PB7 as output of timer addressed to it

Duty.Period = (SysCtlClockGet() / 500)/2;
Duty.Cycle1 = (unsigned long)(Duty.Period-1)*0.8;
Duty.Cycle2 = (unsigned long)(Duty.Period-1)*0.6;
Duty.Cycle3 = (unsigned long)(Duty.Period-1)*0.4;
Duty.Cycle4 = (unsigned long)(Duty.Period-1)*0.2;


ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1); // Enable Timer 1
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); // Enable Timer 0
ROM_TimerConfigure(TIMER1_BASE, (TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM|TIMER_CFG_B_PWM)); // Configure Timer 1 as two 16 but timers with both functioning as PWM
ROM_TimerConfigure(TIMER0_BASE, (TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM|TIMER_CFG_B_PWM)); // Configure Timer 0 as two 16 but timers with both functioning as PWM
ROM_TimerControlLevel(TIMER1_BASE, TIMER_BOTH, 0); //  Timer 1 is trigger low
ROM_TimerControlLevel(TIMER0_BASE, TIMER_BOTH, 0); // Timer 0 is trigger low
ROM_TimerLoadSet(TIMER1_BASE, TIMER_A, Duty.Period -1); // Timer 1 Load set
ROM_TimerLoadSet(TIMER1_BASE, TIMER_B, Duty.Period -1);
ROM_TimerLoadSet(TIMER0_BASE, TIMER_A, Duty.Period -1); // Timer 0 Load set
ROM_TimerLoadSet(TIMER0_BASE, TIMER_B, Duty.Period -1);
ROM_TimerMatchSet(TIMER1_BASE, TIMER_A, Duty.Cycle1); // Timer 1 Match set
ROM_TimerMatchSet(TIMER1_BASE, TIMER_B, Duty.Cycle2);
ROM_TimerMatchSet(TIMER0_BASE, TIMER_A, Duty.Cycle3); // Timer 0 Match set
ROM_TimerMatchSet(TIMER0_BASE, TIMER_B, Duty.Cycle4);
ROM_TimerEnable(TIMER1_BASE, TIMER_BOTH);
ROM_TimerEnable(TIMER0_BASE, TIMER_BOTH);
}


