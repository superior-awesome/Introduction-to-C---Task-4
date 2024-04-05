#include "Spell.h"

Spell::Spell()
{
	damage = 0;
	name = String("NoSpell");
	useDescription = String("NoSpell-Description");
};


Spell::Spell(int _damage, String string)
{
	damage = _damage;
	name = string;
	useDescription = String("NoSpell-Description");
}

Spell::Spell(int _damage, String string,String _useDescription)
{
	damage = _damage;
	name = string;
	useDescription = _useDescription;
}

void Spell::Cast()
{
	std::cout << "You cast ";
	name.WriteToConsole();
	std::cout << std::endl;
	useDescription.WriteToConsole();
	if (damage > 0)
	{
		std::cout << "\nYou do" << damage << " points of damage.\n";
	}
	else if (damage < 0)
	{
		int healholder = damage * -1;
		std::cout << "You heals " << healholder << " points of Health.\n";

	}
};

void Spell::Describe()
{
	std::cout << "You know ";
	name.WriteToConsole();

	if (damage > 0)
	{
		std::cout << ". It does "<<damage<< " points of Damage.";
	}
	else if (damage < 0)
	{
		int healholder = damage * -1;
		std::cout << ". It heals "<<healholder<< " points of Health.";

	}

	std::cout << "\n";

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

std::string Spell::GetCString()
{

	return name.CStr();

}

String Spell::GetName()
{

	return name;

}

void Spell::UseSpecificSpell()
{
	useDescription.WriteToConsole();
}