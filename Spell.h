#ifndef _SPELL_

#define _SPELL_

//#include "header.h"

#include "String.h"

class Spell
{
public:
	Spell();
	Spell(int _damage, String string);

	void Cast();
	bool const Compare(Spell &_other);
	bool const Compare(Spell &spellA, Spell &spellB);

	Spell& operator=(const Spell& _str);


private:
	int damage;
	String name;
};

#endif //	_SPELL_