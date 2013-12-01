#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define MATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS
#include <math/types.hpp>

BOOST_AUTO_TEST_SUITE(Swizzle2)

BOOST_AUTO_TEST_CASE(add) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(add_eq) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(sub) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(sub_eq) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(mult) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(mult_eq) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(div) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(div_eq) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(access) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	// 2d swizzles <x,y>
	auto xx = V.xx;
	BOOST_CHECK_CLOSE(xx.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xx.getE2(), V.x, 1e-5f);
	auto xy = V.xy;
	BOOST_CHECK_CLOSE(xy.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xy.getE2(), V.y, 1e-5f);
	auto yx = V.yx;
	BOOST_CHECK_CLOSE(yx.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yx.getE2(), V.x, 1e-5f);
	auto yy = V.yy;
	BOOST_CHECK_CLOSE(yy.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yy.getE2(), V.y, 1e-5f);
	// 3d swizzles <x, y>
	auto xxx = V.xxx;
	BOOST_CHECK_CLOSE(xxx.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxx.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxx.getE3(), V.x, 1e-5f);
	auto xxy = V.xxy;
	BOOST_CHECK_CLOSE(xxy.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxy.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxy.getE3(), V.y, 1e-5f);
	auto xyx = V.xyx;
	BOOST_CHECK_CLOSE(xyx.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xyx.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xyx.getE3(), V.x, 1e-5f);
	auto yxx = V.yxx;
	BOOST_CHECK_CLOSE(yxx.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxx.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxx.getE3(), V.x, 1e-5f);
	auto yxy = V.yxy;
	BOOST_CHECK_CLOSE(yxy.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxy.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxy.getE3(), V.y, 1e-5f);
	auto yyx = V.yyx;
	BOOST_CHECK_CLOSE(yyx.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyx.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyx.getE3(), V.r, 1e-5f);
	auto yyy = V.yyy;
	BOOST_CHECK_CLOSE(yyy.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyy.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyy.getE3(), V.y, 1e-5f);
	// 4d swizzles <x, y>
	auto xxxx = V.xxxx;
	BOOST_CHECK_CLOSE(xxxx.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxxx.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxxx.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxxx.getE4(), V.x, 1e-5f);
	auto xxxy = V.xxxy;
	BOOST_CHECK_CLOSE(xxxy.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxxy.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxxy.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxxy.getE4(), V.y, 1e-5f);
	auto xxyx = V.xxyx;
	BOOST_CHECK_CLOSE(xxyx.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxyx.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxyx.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xxyx.getE4(), V.x, 1e-5f);
	auto xxyy = V.xxyy;
	BOOST_CHECK_CLOSE(xxyy.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxyy.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xxyy.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xxyy.getE4(), V.y, 1e-5f);
	auto xyxx = V.xyxx;
	BOOST_CHECK_CLOSE(xyxx.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xyxx.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xyxx.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xyxx.getE4(), V.x, 1e-5f);
	auto xyxy = V.xyxy;
	BOOST_CHECK_CLOSE(xyxy.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xyxy.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xyxy.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xyxy.getE4(), V.y, 1e-5f);
	auto xyyx = V.xyyx;
	BOOST_CHECK_CLOSE(xyyx.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xyyx.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xyyx.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xyyx.getE4(), V.x, 1e-5f);
	auto xyyy = V.xyyy;
	BOOST_CHECK_CLOSE(xyyy.getE1(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(xyyy.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xyyy.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(xyyy.getE4(), V.y, 1e-5f);
	auto yxxx = V.yxxx;
	BOOST_CHECK_CLOSE(yxxx.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxxx.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxxx.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxxx.getE4(), V.x, 1e-5f);
	auto yxxy = V.yxxy;
	BOOST_CHECK_CLOSE(yxxy.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxxy.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxxy.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxxy.getE4(), V.y, 1e-5f);
	auto yxyx = V.yxyx;
	BOOST_CHECK_CLOSE(yxyx.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxyx.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxyx.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxyx.getE4(), V.x, 1e-5f);
	auto yxyy = V.yxyy;
	BOOST_CHECK_CLOSE(yxyy.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxyy.getE2(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yxyy.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yxyy.getE4(), V.y, 1e-5f);
	auto yyxx = V.yyxx;
	BOOST_CHECK_CLOSE(yyxx.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyxx.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyxx.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yyxx.getE4(), V.x, 1e-5f);
	auto yyxy = V.yyxy;
	BOOST_CHECK_CLOSE(yyxy.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyxy.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyxy.getE3(), V.x, 1e-5f);
	BOOST_CHECK_CLOSE(yyxy.getE4(), V.y, 1e-5f);
	auto yyyx = V.yyyx;
	BOOST_CHECK_CLOSE(yyyx.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyyx.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyyx.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyyx.getE4(), V.x, 1e-5f);
	auto yyyy = V.yyyy;
	BOOST_CHECK_CLOSE(yyyy.getE1(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyyy.getE2(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyyy.getE3(), V.y, 1e-5f);
	BOOST_CHECK_CLOSE(yyyy.getE4(), V.y, 1e-5f);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Vector2 V2;
	V2.x = 20.12f;
	V2.y = 100.89f;
	math::Vector2 V;
	V.x = 0.0f;
	V.y = 0.0f;
	// 2d swizzle assign <x, y> from vector
	V.xy = V2;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-5f);
	V.yx = V2;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-5f);
	// 2d swizzle assign <x, y> from swizzle
	V.xy = V2.xx;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-5f);
	V.yx = V2.yy;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-5f);
}

BOOST_AUTO_TEST_SUITE_END()
