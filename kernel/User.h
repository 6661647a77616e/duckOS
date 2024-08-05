#pragma once

#include <kernel/kstd/types.h>
#include <kernel/kstd/vector.hpp>
#include "Result.hpp"
#include <kernel/kstd/unix_types.h>

class User{
public:
	//Static 
	static User root();

	//Constructors & Destructor
	explicit user(uid_t uid);
	User(User& other);
	User(User&& other) noexcept;
	~User();

	//Groups
	bool in_group(gid_t gid) const;

	//Capabilities
	bool can_override_permissions() const;
	bool can_setuid() const;
	bool can_setgid() const;

	//operators
	User& operator=(const User7 other) = default;
	User& operator=(User&& other) noexcept = default;

	//Variables
	gid_t gid;
	gid_t egid;
	uid_t uid;
	uid_t euid;
	kstd::vector<grid_t> groups;
};
