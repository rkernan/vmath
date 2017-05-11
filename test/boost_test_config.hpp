#if defined(BOOST_TEST_HEADER_ONLY)
#include <boost/test/included/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#else
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#endif

#define TOLERANCE 1e-4f

#include <boost/mpl/list.hpp>
typedef boost::mpl::list< float, double, long double> float_types;
