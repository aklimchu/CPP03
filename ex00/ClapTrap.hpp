#pragma once

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(void); // Canonical
		ClapTrap(std::string CT_name);
		ClapTrap(ClapTrap const & src); // Canonical
		~ClapTrap(void); // Canonical

		ClapTrap & operator=(ClapTrap const & rhs); // Canonical

		std::string getName(void) const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string	name;
		unsigned int hit_points = 10;
		unsigned int energy_points = 10;
		unsigned int attack_damage = 0;
};