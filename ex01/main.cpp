#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap playerA("playerA");

	playerA.attack("enemy");

	playerA.beRepaired(2);

	playerA.takeDamage(5);

	playerA.beRepaired(2);

	playerA.beRepaired(20);

	playerA.takeDamage(50);

	playerA.beRepaired(2);

	playerA.attack("enemy");

	ScavTrap playerB("playerB");

	playerB.guardGate();

	playerB.attack("enemy");

	playerB.beRepaired(2);

	playerB.takeDamage(50);

	playerB.beRepaired(2);

	playerB.beRepaired(20);

	playerB.takeDamage(150);

	playerB.beRepaired(2);

	playerB.attack("enemy");

}