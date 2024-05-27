#include "ports.h"

uint8_t port_byte_in(unsigned short port) {
    unsigned char result;
    asm("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}
void port_byte_out(unsigned short port, unsigned char data) {
    asm volatile("out %%al, %%dx" : : "a" (data), "d" (port));
}
uint8_t port_word_int(unsigned short port) {
    unsigned short result;
    asm("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}
void port_word_out(unsigned short port, unsigned short data) {
    asm volatile("out %%ax, %%dx" : : "a" (data), "d" (port));
}
