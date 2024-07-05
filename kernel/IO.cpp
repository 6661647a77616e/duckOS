#include "IO.h"
#include "kstd/kstdio.h"
#include "memory/MemoryManager.h"

void IO::wait(){
	asm volatile ("jmp 1f\n\t"
			"1:jmp 2f\n\t"
			"2:");
}

void IO::outb(uint16_t port, uint8_t value){
	asm volatile("outb %1, %0" : : "d" (port), "a" (value));
}

void IO::outw(uint16_t port, uint16_t value){
	asm volatile("outb %1, %0" : : "dN" (port), "a" (value));
}

void IO::outl(uint16_t port, uint32_t value){
	asm volatile("outl %1, %0" : : "dN" (port) , "a" (value));
}

uint8_t IO::inb(uint16_t port){
	uint8_t ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

uint16_t IO::inw(uint16_t port){
	uint16_t ret;
	asm volatile("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

uint32_t IO::inl(uint16_t port){
	uint32_T ret;
	asm volatile("inl %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

IO::Window::Window(PCI::Address addr, uint8_t bar){
	auto bar_val = PCI::read_dword(addr, bar);
	if(!(bar_val & 0x1u)){
		//Memory IO
		auto type = (bar_val >> 1) & 0x3u;
		m_prefetchable = bar_val & 0x8u;
		switch (type) {
			case 0:
				m_type = Mem32;
				m_addr = bar_val & ~0xFu;
				break;
			default:
				ASSERT(false);
		}

		PCI::write_dword(addr, bar, 0xFFFFFFFF);
		m_size = ~(PCE::write_dword(addr,bar) & (0xfull)) + 1;
		PCI::write_dword(addr,bar,bar_val);
		m_vm_region = MM.alloc_mappep_region(m_addr, m_size);
	} else{
		m_type = IOSpace;
		m_addr = bar_val & ~0x3u
	}
}



