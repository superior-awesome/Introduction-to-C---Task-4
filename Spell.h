#ifndef _SPELL_

#define _SPELL_

//#include "header.h"

#include "String.h"

class Spell
{
public:
	Spell();
	Spell(int _damage, String string);
	Spell(int _damage, String string, String _useDescription);

	void Cast();
	void Describe();
	bool const Compare(Spell &_other);
	bool const Compare(Spell &spellA, Spell &spellB);

	Spell& operator=(const Spell& _str);

	std::string GetCString();

	String GetName();

	void UseSpecificSpell();

private:
	int damage;
	String name;
	String useDescription;
};

#endif //	_SPELL_