#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap(void); // Canonical
		FragTrap(std::string player_name);
		FragTrap(FragTrap const & src); // Canonical
		~FragTrap(void); // Canonical

		FragTrap & operator=(FragTrap const & rhs); // Canonical

		void highFivesGuys(void);

	private:
		static const unsigned int init_hit_points = 100;
		static const unsigned int init_energy_points = 100;
		static const unsigned int init_attack_damage = 30;
};