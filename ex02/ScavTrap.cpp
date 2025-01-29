#include "ScavTrap.hpp"

//--------------------------------Constructors--------------------------------//

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Default constructor ScavTrap called" << std::endl << std::endl;
	this->hit_points = init_hit_points;
	this->energy_points = init_energy_points;
	this->attack_damage = init_attack_damage;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src.name) {
	std::cout << "Copy constructor ScavTrap called" << std::endl << std::endl;
	*this = src;
	this->hit_points = init_hit_points;
	this->energy_points = init_energy_points;
	this->attack_damage = init_attack_damage;
	return;
}

ScavTrap::ScavTrap(std::string player_name) : ClapTrap(player_name) {
	std::cout << "Parametric constructor ScavTrap called" << std::endl << std::endl;
	this->hit_points = init_hit_points;
	this->energy_points = init_energy_points;
	this->attack_damage = init_attack_damage;
	return;
}

//---------------------------------Destructor---------------------------------//

ScavTrap::~ScavTrap() {
	std::cout << "Destructor ScavTrap called" << std::endl;
	return;
}

//-------------------------Copy assignment operator---------------------------//

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
	std::cout << "Copy assignment operator ScavTrap called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

//-------------------------------Member functions------------------------------//

void ScavTrap::guardGate() {
	if (this->energy_points <= 0) {
		std::cout << "ScavTrap " << this->name << " can't go into Gate keeper mode, because he has no energy points left" << std::endl << std::endl;
		return ;
	}
	if (this->hit_points <= 0) {
		std::cout << "ScavTrap " << this->name << " can't go into Gate keeper mode, because he has no hit points left" << std::endl << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl << std::endl;	
}

void ScavTrap::attack(const std::string& target) {
	if (this->energy_points <= 0) {
		std::cout << "ScavTrap " << this->name << " can't attack, because he has no energy points left" << std::endl << std::endl;
		return ;
	}
	if (this->hit_points <= 0) {
		std::cout << "ScavTrap " << this->name << " can't attack, because he has no hit points left" << std::endl << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << \
		" causing " << this->attack_damage << " points of damage" << std::endl << std::endl;
	this->energy_points -= 1;
}
