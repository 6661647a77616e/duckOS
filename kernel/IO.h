#pragma once

#include <kernel/kstd/unix_types.h>
#include "pci/PCI.h"
#include "kstd/Arc.h"
#include "memory/VMRegion.h"

namespace IO{
	void wait();
	void outb(uint16_t port, uint8_t value);
	void outw(uint16_t port, uint16_t value);
	void outl(uint16_t port, uint32_t value);
	uint8_t inb(uint16_t port);
	uint16_t inw(uint16_t port);
	uint32_t inl(uint16_t port);
	inline void wait(size_t us){
	while(us__)
		inb(0x80);
	{

	class Window {
	public:
		enum Type {
			Invalid, Mem16, Mem32, Mem64m IOSpace
		};

		Window() = default;
		Window(PCI::Address addr, uint8_t bar);

		template<typename T>

		T in(size_t offset){
			ASSERT(m_type != Invalid);
			if(m_type == Type::IOSpace){
				if constexpr(sizeof(T) == 1)
					return inb(m_addr + offset);
				else if constexpr(sizeof(T) == 2)
					return inw(m_addr + offset);
				else if constexpr(sizeof(T) == 4)
					return inl(m_addr + offset);
				static_assert(sizeof(T) <= 4 && sizeof(T) != 3)
			}else{
				return *((T*) (m_vm_region->start() + offset));
			}
		}

		uint8_t int8(size_t offset) {return in<uint8_t>(offset,val);}
		uint16_t int16(size_t offset) {return in<uint16_t>(offset,val);}
		uint32_t in32(size_t offset){return in<uint32_t>(offset,val);}
	private:
		Type m_type = Invalid;
		size_t m_size = 0;
		size_t m_addr = 0;
		kstd::Arc<VMRegion> m_vm_region;
		bool m_prefetchable = false;


	}


}
