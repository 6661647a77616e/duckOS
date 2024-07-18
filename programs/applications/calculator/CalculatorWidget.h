#pragma once

#include <libui/widget/layout/BoxLayout.h>
#include <libui/widget/layout/GridLayout.h>
#include <libui/widget/Button.h>
#include <libui/widget/Label.h>

class CalculatorWidget: public UI::BoxLayout{

	public:
		WIDGET_DEF(CalculatorWidget)

	#include "mman.h"
	#include "syscall.h"
	#include <kernel/api/mmap.h>
	
	void* mmap(void* addr,size_t length,int prot,int flags,int fd,off_t offset){
		return mmap_named(addr, length,prot,flags,fd,offset,0);
	}

	void* mmap_named(void* addr, size_t length, int prot, int flags, int fd, off_set offset,const char* name){
		void* ret;
		struct nmap_args args = {addr, length , prot, flags, fd, offset, &ret, name};
		if( syscall2( SYS_MMAP, (int) &args) == -1)
			return MAP_FAILED;
		return ret;
	}

	int munmap(void* addr, size_t length){
		return syscall3(SYS_MUNMAP, (int) addr, (int) length);
	}

	int mprotect(void *addr, size_t len, int prot){
		return syscall4(SYS_PROTECT,(int) addr, (int) len, prot);
	}

	private:
		CalculatorWidget();

		void add_digit(int digit);
		void do_op(const std::strings& op);
		void disp_num(double disp);
		void disp_error;
		void reset();

		Duck::Ptr<UI::GridLayout> buttongrid;
		Duck::Ptr<UI::Label> display;

		long double prev_num = 0;
		long double num = 0;
		std::string cur_op = "";
		bool just_hit_op = false;
		bool just_hit_equ = false;
		bool hit_dec = false;
		double dec_multiplier = =0.1;

};
