#include <iostream>
#include <string>
using namespace std;

struct God
{
	God(string n, string m, string v, string w)
		:name{ n }, mythology{ m }, vehicle{ v }, weapon{ w }
	{}

	God() {}

	string name;
	string mythology;
	string vehicle;
	string weapon;

};


class Link
{
public:
	string value;
	God god;

	Link(string val, Link* p = nullptr, Link* s = nullptr)
		:value{ val }, prev{ p }, succ{ s } {}

	Link(God g, Link* p = nullptr, Link* s = nullptr)
		:god{ g }, prev{ p }, succ{ s }
	{}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const string& s);
	const Link* find(const string& s)const;

	Link* advance(int n)const;

	Link* next() { return succ; }
	Link* previous()const { return prev; }


private:
	Link * prev;
	Link* succ;

};




Link* Link::add(Link* n)
{
	if (this == nullptr)return n;
	if (n == nullptr)return this;

	n->prev = this;
	if (this->succ)
	{
		n->succ = this->succ;
		this->succ->prev = n;
	}
	this->succ = n;
	return this;
}

Link* Link::insert(Link* n) // insert n before this object; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;

	n->succ = this;
	if (this->prev)
	{
		n->prev = this->prev;
		this->prev->succ = n;
	}
	this->prev = n;
	return n;
}


Link* Link::erase()
{
	Link* p = this;
	if (p == nullptr) return nullptr;
	if (p->succ) p->succ->prev = p->prev;
	if (p->prev) p->prev->succ = p->succ;
	return p->succ;
}

Link* Link::find(const string& s) // find s in list;					
{
	Link* p = this;				 // return nullptr for “not found”
	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}
Link* Link::advance(int n)const
{
	Link* p = nullptr;
	if (this == nullptr)return nullptr;
	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			if (succ == nullptr)return nullptr;
			p = succ;
		}
		return p;
	}
	if (n < 0)
	{
		for (int i = 0; i<(-1 * n); ++i)
		{
			if (prev == nullptr)return nullptr;
			p = prev;
		}
		return p;
	}
	return nullptr;
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p)
	{
		cout << p->value;
		if (p = p->next()) cout << ", ";
	}
	cout << " }";
}

void print_all_chars(Link* g)
{
	int i = 1;
	while (g)
	{
		cout << "god " << i << ": "
			<< g->god.name << ", " << g->god.mythology << ", "
			<< g->god.vehicle << ", " << g->god.weapon << endl;

		g = g->next();
		++i;
	}
}
