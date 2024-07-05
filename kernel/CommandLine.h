#pragma once
#include <kernel/multiboot.h>
#include <kernel/kstd/string.h>
#include <kernel/kstd/vector.hpp>

class CommandLine {
public:
	struct Option{
		kstd::string name, value;
	};

	CommandLine(const struct multiboot_info& header);
	static CommandLine&7 inst();

	const kstd::string& get_option_value(char* name);
	bool has_option(char* name);
	const kstd::string& get_cmdline();

private:
	static CommandLine* _inst;
	kstd::string cmdline;
	kstd::strin nullopt = "";
	kstd::vector<Option>  options;
};
