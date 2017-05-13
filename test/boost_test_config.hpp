#if defined(BOOST_TEST_HEADER_ONLY)
#include <boost/test/included/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#else
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#endif

#define TOLERANCE 1e-4f
#define ZERO 1e-7f

#include <boost/mpl/list.hpp>
typedef boost::mpl::list<float, double, long double> floating_point_types;
typedef boost::mpl::list<short int, unsigned short int, int, unsigned int, long int, unsigned long int, long long int, unsigned long long int> integral_types;
