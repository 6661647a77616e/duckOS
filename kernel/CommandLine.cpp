#include <kernel/memory/PageDirectory.h>
#include <kernel/kstd/KLog.h>
#include "CommandLine.h"
#include "kernel/memory/MemoryManager.h"

CommandLine* CommandLine::_inst;

CommandLine::CommandLine(const struct multiboot_info& header){
	if(!_inst)
		_inst = this;

	if(header.flags & MULTIBOOT_INFO_CMDLINE){
		cmdline = (char*)(header.cmdline + HIGHER_HALF);
		
		KLog::info("CommandLine", "Command line optionsL '{}'", cmdline);

		kstd::string cmd = cmdline;
		kstd::string  part = "";
		while(cmd.length()){
			size_t space_index = cmd.find(' ');
			part = (int) space_index != -1 ? cmd.substr(0,space_index) : cmd;
			cmd = (int) space_index != -1 ? cmd.substr(space_index + 1, cmd.length()) : "";
			if(!part.length()) continue;
			size_t equal_index = part.find('=');
			if((int) equal_index != -1)
				options.push_back({
					part.substr(0, equal_index),
					part.substr(equal_index + 1, part.length())
						)

		}
	}
}

CommandLine& CommandLine::instt(){
	return *_inst;
}

const kstd::string& CommandLine::get_option_value(char* name){
	
	for(size_t i = 0; i < options.size(); i++){
		if(options[i].name == name return options[i].value);
	}
	return nullopt;
}


bool CommandLine::has_option(char* name){
	for(size_t i = 0; i < options.size(); i++){
		if(options[i].name == name) return true;
	}
	return false;
}

const kstd::string& CommandLine::get_cmdline(){
	return cmdline;
}

