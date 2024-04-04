#include "Spell.h"

Spell::Spell()
{
	damage = 0;
	name = String("NoSpell");
};


Spell::Spell(int _damage, String string)
{
	damage = _damage;
	name = string;
}

void Spell::Cast()
{

	std::cout << "You cast ";
	name.WriteToConsole();
	std::cout << ". you do " << damage << " points of damage.\n";

};

bool const Spell::Compare(Spell &_other)
{
	if(damage == _other.damage && name.EqualTo(_other.name))
	{ 
		return true;
	}
	else
	{
		return false;
	}
};

bool const Spell::Compare(Spell & spellA, Spell& spellB)
{
	if (spellA.damage == spellB.damage && spellA.name.EqualTo(spellB.name))// && name.EqualTo(_other.name))
	{
		return true;
	}
	else
	{
		return false;
	}
};

Spell& Spell::operator=(const Spell& _spl)
//	Overloads the = operator to copy the rhs object to the lhs object.
{

	name = _spl.name;
	damage = _spl.damage;

	return *this;

}
