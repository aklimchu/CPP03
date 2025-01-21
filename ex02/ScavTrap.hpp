#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void); // Canonical
		ScavTrap(std::string player_name);
		ScavTrap(ScavTrap const & src); // Canonical
		~ScavTrap(void); // Canonical

		ScavTrap & operator=(ScavTrap const & rhs); // Canonical

		void guardGate();
		void attack(const std::string& target);

	private:
		static const unsigned int init_hit_points = 100;
		static const unsigned int init_energy_points = 50;
		static const unsigned int init_attack_damage = 20;
};