#include "ClapTrap.hpp"

int main() {
	ClapTrap playerA("playerA");

	playerA.attack("playerB");

	playerA.beRepaired(2);

	playerA.takeDamage(5);

	playerA.beRepaired(2);

	playerA.beRepaired(20);

	playerA.takeDamage(50);

	playerA.beRepaired(2);

	playerA.attack("playerB");


}