#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Default constructor FragTrap called" << std::endl << std::endl;
	this->hit_points = init_hit_points;
	this->energy_points = init_energy_points;
	this->attack_damage = init_attack_damage;
	return;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src.name) {
	std::cout << "Copy constructor FragTrap called" << std::endl << std::endl;
	*this = src;
	this->hit_points = init_hit_points;
	this->energy_points = init_energy_points;
	this->attack_damage = init_attack_damage;
	return;
}

FragTrap::FragTrap(std::string player_name) : ClapTrap(player_name) {
	std::cout << "Parametric constructor FragTrap called" << std::endl << std::endl;
	this->hit_points = init_hit_points;
	this->energy_points = init_energy_points;
	this->attack_damage = init_attack_damage;
	return;
}

void FragTrap::highFivesGuys() {
	if (this->energy_points <= 0) {
		std::cout << "FragTrap " << this->name << " can't ask for highfives, because he has no energy points left" << std::endl << std::endl;
		return ;
	}
	if (this->hit_points <= 0) {
		std::cout << "FragTrap " << this->name << " can't ask for highfives, because he has no hit points left" << std::endl << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " is asking for highfives, guys!" << std::endl << std::endl;	
}

FragTrap::~FragTrap() {
	std::cout << "Destructor FragTrap called" << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
	std::cout << "Copy assignment operator FragTrap called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.getName();
		this->hit_points = rhs.getHitPoints();
		this->energy_points = rhs.getEnergyPoints();
		this->attack_damage = rhs.getAttachDamage();
	}
	return *this;
}