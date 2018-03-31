void print_array(ostream& os, int* a, int n)
{
	os << "{ ";
	for (int i = 0; i < n - 1; ++i)
	{
		os << a[i] << " , ";
	}
	os << a[n - 1] << " }";
	cout << endl << endl;

}

void tolower(char* s)
{
	int i = 0;
	while (s[i] != 0)
	{
		if (static_cast<int>(s[i]) >= 65 && static_cast<int>(s[i]) <= 90)
		{
			s[i] = static_cast<int>(s[i]) + 32;
		}
		++i;
	}
}

int char_length(const char* y)
{
	int i = 0;
	while (y[i] != 0)
	{
		++i;
	}
	return i;
}


char* stordup(const char* wrd)
{
	int i = 0;
	int l = char_length(wrd);
	char* s_mem = new char[l];

	for (; i<l; ++i)
	{
		s_mem[i] = wrd[i];
	}
	s_mem[i] = '\0';

	return s_mem;
}

char* check_word(const char* cwrd, int start, int stop)
{
	int l = stop - start + 1;
	char *s_m = new char[l];
	int k = 0;
	for (int i = start; i <= stop; ++i)
	{
		s_m[k] = cwrd[i];
		++k;
	}
	s_m[k] = '\0';

	return s_m;
}


char* findx(const char* s, const char* x)
{

	int i = 0;
	int j = 0;

	char* ex = stordup(x);

	while (s[i] != 0)
	{
		if (s[i] == x[j])
		{
			if (check_word(s, i, i + char_length(x) - 1) == string(x))
			{
				cout << "found at " << i + 1 << "th character" << endl;
				return ex;
			}
			else ++i;
		}
		else
			++i;
	}
	char n_f[] = "not found";
	char *n_fc = stordup(n_f);
	return n_fc;
}
