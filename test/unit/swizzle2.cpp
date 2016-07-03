#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define VMATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS
#include <vmath/core/vector.hpp>
#include <vmath/core/swizzle/swizzle2.hpp>

BOOST_AUTO_TEST_SUITE(swizzle2)

BOOST_AUTO_TEST_CASE(negate) {
	vmath::core::Vector<float, 2> V;
	V.x = 20.12f;
	V.y = 100.89f;
	vmath::core::Vector<float, 2> V_neg;
	V_neg = -V.xx;
	BOOST_CHECK_CLOSE(V_neg.x, -20.12f, 1e-4f);
	BOOST_CHECK_CLOSE(V_neg.y, -20.12f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(add) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	vmath::core::Vector<float, 2> V_add;
	V_add = V1.yx + V2.xx;
	BOOST_CHECK_CLOSE(V_add.x, 111.23f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, 30.46f, 1e-4f);
	V_add = V2.xx + V1.yx;
	BOOST_CHECK_CLOSE(V_add.x, 111.23f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, 30.46f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(add_eq) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	vmath::core::Vector<float, 2> V_add = V1;
	V_add.yx += V2.xx;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, 111.23f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(sub) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	vmath::core::Vector<float, 2> V_sub;
	V_sub = V1.yx - V2.xx;
	BOOST_CHECK_CLOSE(V_sub.x, 90.55f, 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, 9.78f, 1e-4f);
	V_sub = V2.xx - V1.yx;
	BOOST_CHECK_CLOSE(V_sub.x, -90.55f, 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, -9.78f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(sub_eq) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	vmath::core::Vector<float, 2> V_sub = V1;
	V_sub.yx -= V2.xx;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, 90.55f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(mult) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	vmath::core::Vector<float, 2> V_mult;
	V_mult = V1.yx * V2.xx;
	BOOST_CHECK_CLOSE(V_mult.x, 1043.2026f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, 208.0408f, 1e-4f);
	V_mult = V2.xx * V1.yx;
	BOOST_CHECK_CLOSE(V_mult.x, 1043.2026f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, 208.0408f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(mult_eq) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	vmath::core::Vector<float, 2> V_mult = V1;
	V_mult.yx *= V2.xy;
	BOOST_CHECK_CLOSE(V_mult.x, -311.86f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, 1043.2026f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(div) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.0f;
	V1.y = 40.0f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 2.0f;
	V2.y = 4.0f;
	vmath::core::Vector<float, 2> V_div;
	V_div = V1.yx / V2.xx;
	BOOST_CHECK_CLOSE(V_div.x, 20.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, 10.0f, 1e-4f);
	V_div = V1.xx / V2.yx;
	BOOST_CHECK_CLOSE(V_div.x, 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, 10.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(div_eq) {
	vmath::core::Vector<float, 2> V1;
	V1.x = 20.0f;
	V1.y = 40.0f;
	vmath::core::Vector<float, 2> V2;
	V2.x = 2.0f;
	V2.y = 4.0f;
	vmath::core::Vector<float, 2> V_div = V1;
	V_div.yx /= V2.xy;
	BOOST_CHECK_CLOSE(V_div.x, 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, 20.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	vmath::core::Vector<float, 2> V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	vmath::core::Vector<float, 2> V_mult;
	V_mult = V.xx * s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, -693.134f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
	vmath::core::Vector<float, 2> V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	vmath::core::Vector<float, 2> V_mult = V;
	V_mult.yx *= s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	vmath::core::Vector<float, 2> V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	vmath::core::Vector<float, 2> V_div;
	V_div = V.xx / s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, -0.5840348330914369f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
	vmath::core::Vector<float, 2> V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	vmath::core::Vector<float, 2> V_div = V;
	V_div.yx /= s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(access) {
	vmath::core::Vector<float, 2> V;
	V.x = 20.12f;
	V.y = 100.89f;
	vmath::core::Vector<float, 2> V2;
	// 2d swizzles <x,y>
	auto xx = V.xx;
	BOOST_CHECK_CLOSE(xx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xx.getE2(), V.x, 1e-4f);
	auto xy = V.xy;
	BOOST_CHECK_CLOSE(xy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xy.getE2(), V.y, 1e-4f);
	auto yx = V.yx;
	BOOST_CHECK_CLOSE(yx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yx.getE2(), V.x, 1e-4f);
	auto yy = V.yy;
	BOOST_CHECK_CLOSE(yy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yy.getE2(), V.y, 1e-4f);
	// 3d swizzles <x, y>
	auto xxx = V.xxx;
	BOOST_CHECK_CLOSE(xxx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxx.getE3(), V.x, 1e-4f);
	auto xxy = V.xxy;
	BOOST_CHECK_CLOSE(xxy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxy.getE3(), V.y, 1e-4f);
	auto xyx = V.xyx;
	BOOST_CHECK_CLOSE(xyx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyx.getE3(), V.x, 1e-4f);
	auto yxx = V.yxx;
	BOOST_CHECK_CLOSE(yxx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxx.getE3(), V.x, 1e-4f);
	auto yxy = V.yxy;
	BOOST_CHECK_CLOSE(yxy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxy.getE3(), V.y, 1e-4f);
	auto yyx = V.yyx;
	BOOST_CHECK_CLOSE(yyx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyx.getE3(), V.r, 1e-4f);
	auto yyy = V.yyy;
	BOOST_CHECK_CLOSE(yyy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyy.getE3(), V.y, 1e-4f);
	// 4d swizzles <x, y>
	auto xxxx = V.xxxx;
	BOOST_CHECK_CLOSE(xxxx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxx.getE4(), V.x, 1e-4f);
	auto xxxy = V.xxxy;
	BOOST_CHECK_CLOSE(xxxy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxy.getE4(), V.y, 1e-4f);
	auto xxyx = V.xxyx;
	BOOST_CHECK_CLOSE(xxyx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xxyx.getE4(), V.x, 1e-4f);
	auto xxyy = V.xxyy;
	BOOST_CHECK_CLOSE(xxyy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xxyy.getE4(), V.y, 1e-4f);
	auto xyxx = V.xyxx;
	BOOST_CHECK_CLOSE(xyxx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxx.getE4(), V.x, 1e-4f);
	auto xyxy = V.xyxy;
	BOOST_CHECK_CLOSE(xyxy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxy.getE4(), V.y, 1e-4f);
	auto xyyx = V.xyyx;
	BOOST_CHECK_CLOSE(xyyx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyx.getE4(), V.x, 1e-4f);
	auto xyyy = V.xyyy;
	BOOST_CHECK_CLOSE(xyyy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyy.getE4(), V.y, 1e-4f);
	auto yxxx = V.yxxx;
	BOOST_CHECK_CLOSE(yxxx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxx.getE4(), V.x, 1e-4f);
	auto yxxy = V.yxxy;
	BOOST_CHECK_CLOSE(yxxy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxy.getE4(), V.y, 1e-4f);
	auto yxyx = V.yxyx;
	BOOST_CHECK_CLOSE(yxyx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyx.getE4(), V.x, 1e-4f);
	auto yxyy = V.yxyy;
	BOOST_CHECK_CLOSE(yxyy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyy.getE4(), V.y, 1e-4f);
	auto yyxx = V.yyxx;
	BOOST_CHECK_CLOSE(yyxx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yyxx.getE4(), V.x, 1e-4f);
	auto yyxy = V.yyxy;
	BOOST_CHECK_CLOSE(yyxy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yyxy.getE4(), V.y, 1e-4f);
	auto yyyx = V.yyyx;
	BOOST_CHECK_CLOSE(yyyx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyx.getE4(), V.x, 1e-4f);
	auto yyyy = V.yyyy;
	BOOST_CHECK_CLOSE(yyyy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyy.getE4(), V.y, 1e-4f);
}

BOOST_AUTO_TEST_CASE(assign) {
	vmath::core::Vector<float, 2> V2;
	V2.x = 20.12f;
	V2.y = 100.89f;
	vmath::core::Vector<float, 2> V;
	V.x = 0.0f;
	V.y = 0.0f;
	// 2d swizzle assign <x, y> from vector
	V.xy = V2;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-4f);
	V.yx = V2;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	// 2d swizzle assign <x, y> from swizzle
	V.xy = V2.xx;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	V.yx = V2.yy;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-4f);
}

BOOST_AUTO_TEST_SUITE_END()
