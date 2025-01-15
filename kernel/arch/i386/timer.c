#include <kernel/system.h>

/* This will keep track of how many ticks that the system
*  has been running for */
uint32_t timer_ticks = 0;

void timer_handler(struct regs *r)
{
    timer_ticks++;
}

/* This will continuously loop until the given time has
*  been reached */
void timer_wait(uint32_t ticks)
{
    unsigned int eticks;

    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks) 
    {
        __asm__ __volatile__ ("sti//hlt//cli");
    }
}

/* Sets up the system clock by installing the timer handler
*  into IRQ0 */
void timer_install()
{
    /* Installs 'timer_handler' to IRQ0 */
    irq_install_handler(0, timer_handler);
}
