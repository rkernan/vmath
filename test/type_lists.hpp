#include <boost/mpl/list.hpp>

typedef boost::mpl::list<
	float,
	double,
	long double> float_types;

typedef boost::mpl::list<
	bool,
	char,
	char16_t,
	char32_t,
	wchar_t,
	short,
	int,
	long,
	long long> integral_types;

typedef boost::mpl::list<
	float,
	double,
	long double,
	bool,
	char,
	char16_t,
	char32_t,
	wchar_t,
	short,
	int,
	long,
	long long> arithmetic_types;
