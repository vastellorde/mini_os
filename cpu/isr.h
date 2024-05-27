#ifndef ISR_H
#define ISR_H

#include <stdint.h>

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

#define IRQ0 32 // timer
#define IRQ1 33 // keyboard
#define IRQ2 34 // Programmable Interrupt Controller (PIC)
#define IRQ3 35 // COM2
#define IRQ4 36 // COM1
#define IRQ5 37 // Sound card; printer port (LPT2:)
#define IRQ6 38 // Floppy disk controller
#define IRQ7 39 // Printer port (LPT1:)
#define IRQ8 40 // System CMOS/real-time clock
#define IRQ9 41 // Redirected from IRQ 02; network interface
#define IRQ10 42 // Network interface; USB host controller
#define IRQ11 43 // Video adapter; SCSI host adapter
#define IRQ12 44 // PS/2 mouse port
#define IRQ13 45 // Numeric data processor (math coprocessor)
#define IRQ14 46 // Primary IDE interface
#define IRQ15 47 // Secondary IDE interface

typedef struct {
    uint32_t ds;
    uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, esp, ss;
} registers_t;

void isr_install();
void isr_handler(registers_t r);

typedef void (*isr_t)(registers_t*);
void register_interrupt_handler(uint8_t n, isr_t handler);
void irq_install();

#endif
