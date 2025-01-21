#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_points(init_hit_points), energy_points(init_energy_points), \
	attack_damage(init_attack_damage) {
	std::cout << "Default constructor ClapTrap called" << std::endl << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string player_name) : name(player_name), hit_points(init_hit_points), \
	energy_points(init_energy_points), attack_damage(init_attack_damage) {
	std::cout << "Parametric constructor ClapTrap called" << std::endl << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "Copy constructor ClapTrap called" << std::endl;
	*this = src;
	return;
}

std::string ClapTrap::getName() const {
	std::cout << "getName member function called" << std::endl;
	return (this->name);
}

int ClapTrap::getHitPoints(void) const {
	std::cout << "getHitPoints member function called" << std::endl;
	return (this->hit_points);
}

int ClapTrap::getEnergyPoints(void) const {
	std::cout << "getEnergyPoints member function called" << std::endl;
	return (this->energy_points);
}

int ClapTrap::getAttachDamage(void) const {
	std::cout << "getAttachDamage member function called" << std::endl;
	return (this->attack_damage);
}

void ClapTrap::attack(const std::string& target) {
	if (this->energy_points <= 0) {
		std::cout << "ClapTrap " << this->name << " can't attack, because he has no energy points left" << std::endl << std::endl;
		return ;
	}
	if (this->hit_points <= 0) {
		std::cout << "ClapTrap " << this->name << " can't attack, because he has no hit points left" << std::endl << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << \
		" causing " << this->attack_damage << " points of damage" << std::endl << std::endl;
	this->energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points - amount <= 0) {
		std::cout << "ClapTrap " << this->name << " can't take damage, because he has no hit points left" << std::endl << std::endl;
		this->hit_points = 0;
		return ;
	}
	if (this->energy_points <= 0) {
		std::cout << "ClapTrap " << this->name << " can't take damage, because he has no energy points left" << std::endl << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " takes " << amount << \
		" points of damage" << std::endl;
	if (this->hit_points < amount)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " has " << this->hit_points << \
		" hit points now" << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hit_points <= 0) {
		std::cout << "ClapTrap " << this->name << " can't be repaired, because he has no hit points left" << std::endl << std::endl;
		return ;
	}
	if (this->energy_points <= 0) {
		std::cout << "ClapTrap " << this->name << " can't be repaired, because he has no energy points left" << std::endl << std::endl;
		this->energy_points = 0;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " gets " << amount << \
		" hit points back" << std::endl;
	this->hit_points += amount;
	this->energy_points -= 1;
	std::cout << "ClapTrap " <<  this->name << " has " << this->hit_points << \
		" hit points now" << std::endl << std::endl;
}


ClapTrap::~ClapTrap() {
	std::cout << "Destructor ClapTrap called" << std::endl;
	return;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	std::cout << "Copy assignment operator ClapTrap called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.getName();
		this->hit_points = rhs.getHitPoints();
		this->energy_points = rhs.getEnergyPoints();
		this->attack_damage = rhs.getAttachDamage();
	}
	return *this;
}