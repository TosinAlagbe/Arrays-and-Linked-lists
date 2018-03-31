int main()
{
	char str[] = "Helloworldiesbiscuitoflife";
	char btr[] = "lawoawtliaqjtkj ,.kdflkdnfkenfojenrirfjnrksjfnksrjnfrfjrnjaqtrniuujrnijrfrnsljniwnorwfnowrnurfiaqzt";
	char atr[] = "aqt";
	cout << findx(btr, atr) << endl << endl;

	Link* norse_gods = new Link{ "Thor" };
	norse_gods = norse_gods->insert(new Link{ "Odin" });
	norse_gods = norse_gods->insert(new Link{ "Zeus" });
	norse_gods = norse_gods->insert(new Link{ "Freia" });
	norse_gods = norse_gods->add(new Link{ "Shrek" });
	Link*p = norse_gods->find("Zeus");
	if (p)
	{
		p = p->add(new Link{ "Kpako" });;
	}
	Link* st = nullptr;
	if (st = norse_gods->find("Odin"))
	{
		st = st->add(new Link{ "Olopa" });
	}


	Link* greek_gods = new Link{ "Hera" };
	greek_gods = greek_gods->insert(new Link{ "Athena" });

	greek_gods = greek_gods->insert(new Link{ "Mars" });
	greek_gods = greek_gods->insert(new Link{ "Poseidon" });

	Link* alphabets = new Link{ "T" };
	alphabets = alphabets->insert(new Link{ "Z" });
	alphabets = alphabets->insert(new Link{ "G" });
	alphabets = alphabets->insert(new Link{ "O" });
	alphabets = alphabets->insert(new Link{ "W" });
	alphabets = alphabets->insert(new Link{ "P" });
	alphabets = alphabets->insert(new Link{ "I" });


	print_all(alphabets);
	cout << "\n";


	print_all(norse_gods);
	cout << "\n";
	print_all(greek_gods);
	cout << "\n";

	Link* gods_chars = new Link{ { "Zeus", "Greek", "","lightning" } };

	gods_chars = gods_chars->insert(new Link{ { "Odin", "Norse", "Eight-legged flying horse called"
		"Sleipner", "Spear called Gungir" } });

	gods_chars = gods_chars->insert(new Link{ { "Poseidon","Greek", "four wheel drive", "Bow and arrow" } });

	gods_chars = gods_chars->insert(new Link{ { "Boss", "Naija", "Danfo", "Cutlass" } });


	print_all_chars(gods_chars);

	delete gods_chars;
	delete norse_gods;
	delete greek_gods;

}
