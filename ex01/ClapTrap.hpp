#pragma once

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(void); // Canonical
		ClapTrap(std::string player_name);
		ClapTrap(ClapTrap const & src); // Canonical
		~ClapTrap(void); // Canonical

		ClapTrap & operator=(ClapTrap const & rhs); // Canonical

		std::string getName(void) const;
		int getHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getAttachDamage(void) const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string	name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	private:
		static const unsigned int init_hit_points = 10;
		static const unsigned int init_energy_points = 10;
		static const unsigned int init_attack_damage = 0;
};