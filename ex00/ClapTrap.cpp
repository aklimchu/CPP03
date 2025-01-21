#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string CT_name) : name(CT_name) {
	std::cout << "Parametric constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

std::string ClapTrap::getName() const {
	std::cout << "getName member function called" << std::endl;
	return (this->name);
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
	if (this->hit_points > 10)
		this->hit_points = 10;
	this->energy_points -= 1;
	std::cout << "ClapTrap " << this->name << " has " << this->hit_points << \
		" hit points now" << std::endl << std::endl;
}


ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
	return;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->name = rhs.getName();
	return *this;
}