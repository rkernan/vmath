#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <cmath>
#include <utility>

#define MATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS
#include <math/types.hpp>

BOOST_AUTO_TEST_SUITE(Vector2)

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Vector2 V_default;
	BOOST_CHECK_SMALL(V_default.x, 1e-10f);
	BOOST_CHECK_SMALL(V_default.y, 1e-10f);
	// parameterized constructor
	math::Vector2 V_param(1.0f, 2.0f);
	BOOST_CHECK_CLOSE(V_param.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param.y, 2.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_copy(V);
	BOOST_CHECK_CLOSE(V_copy.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_copy.y, V.y, 1e-5f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_move(std::move(V));
	BOOST_CHECK_CLOSE(V_move.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_move.y, V.y, 1e-5f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	V.r = 100.89f;
	V.g = 20.12f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	V.s = 20.12f;
	V.t = 100.89f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_assign;
	V_assign = V;
	BOOST_CHECK_CLOSE(V_assign.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_assign.y, V.y, 1e-5f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_neg;
	V_neg = -V;
	BOOST_CHECK_CLOSE(V_neg.x, -20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V_neg.y, -100.89f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_add;
	V_add = V1 + V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_add = V1;
	V_add += V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_sub;
	V_sub = V1 - V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.780000000000001f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_sub = V1;
	V_sub -= V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.780000000000001f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_mult;
	V_mult = V1 * V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.04080000000001f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_mult = V1;
	V_mult *= V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.04080000000001f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_div;
	V_div = V1 / V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_div = V1;
	V_div /= V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	math::Vector2 V_mult;
	V_mult = s * V;
	BOOST_CHECK_CLOSE(V_mult.x, -693.13400000000001f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605000000001f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	math::Vector2 V_div;
	V_div = V / s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mag) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 102.87665673028066f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	mag = V.mag();
	BOOST_CHECK_SMALL(mag, 1e-10f);
}

BOOST_AUTO_TEST_CASE(mag2) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 10583.6065f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_SMALL(mag2, 1e-10f);
}

BOOST_AUTO_TEST_CASE(normal) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_norm(V.normal());
	BOOST_CHECK_CLOSE(V_norm.x, 0.19557400716034246f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.9806889454476615f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V_norm = V.normal();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(normalize) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.normalize();
	BOOST_CHECK_CLOSE(V.x, 0.19557400716034246f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 0.9806889454476615f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	math::Vector2 V_norm;
	V_norm = V.normalize();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	BOOST_CHECK(V1 != V2);
	BOOST_CHECK(V2 != V3);
	BOOST_CHECK(V1 == V1);
	BOOST_CHECK(V1 == V3);
}

BOOST_AUTO_TEST_CASE(dot) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	float dot = math::Vector2::dot(V1, V2);
	BOOST_CHECK_CLOSE(dot, -1355.7542f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(cross) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	float cross = math::Vector2::cross(V1, V2);
	BOOST_CHECK_CLOSE(cross, -1355.0626000000002f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(reflect) {
	math::Vector2 I;
	I.x = -1.0f;
	I.y = -1.0f;
	math::Vector2 N;
	N.x = 1.0f;
	N.y = 0.0f;
	math::Vector2 R = math::Vector2::reflect(I, N);
	BOOST_CHECK_CLOSE(R.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -1.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(refract) {
	math::Vector2 I;
	I.x = -1.0f;
	I.y = -1.0f;
	math::Vector2 N;
	N.x = 1.0f;
	N.y = 0.0f;
	float eta = 0.2f;
	math::Vector2 R = math::Vector2::refract(I, N, eta);
	BOOST_CHECK_CLOSE(R.x, -1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -0.2f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(lerp) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_lerp;
	V_lerp = math::Vector2::lerp(V1, V2, 0.5f);
	BOOST_CHECK_CLOSE(V_lerp.x, 15.23f, 1e-5f);
	BOOST_CHECK_CLOSE(V_lerp.y, 42.695f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(swizzle_access) {
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
	// 2d swizzles <r, g>
	auto rr = V.rr;
	BOOST_CHECK_CLOSE(rr.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rr.getE2(), V.r, 1e-5f);
	auto rg = V.rg;
	BOOST_CHECK_CLOSE(rg.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rg.getE2(), V.g, 1e-5f);
	auto gr = V.gr;
	BOOST_CHECK_CLOSE(gr.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gr.getE2(), V.r, 1e-5f);
	auto gg = V.gg;
	BOOST_CHECK_CLOSE(gg.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gg.getE2(), V.g, 1e-5f);
	// 2d swizzle <s, t>
	auto ss = V.ss;
	BOOST_CHECK_CLOSE(ss.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ss.getE2(), V.s, 1e-5f);
	auto st = V.st;
	BOOST_CHECK_CLOSE(st.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(st.getE2(), V.t, 1e-5f);
	auto ts = V.ts;
	BOOST_CHECK_CLOSE(ts.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ts.getE2(), V.s, 1e-5f);
	auto tt = V.tt;
	BOOST_CHECK_CLOSE(tt.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tt.getE2(), V.t, 1e-5f);
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
	// 3d swizzles <r, g>
	auto rrr = V.rrr;
	BOOST_CHECK_CLOSE(rrr.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrr.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrr.getE3(), V.r, 1e-5f);
	auto rrg = V.rrg;
	BOOST_CHECK_CLOSE(rrg.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrg.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrg.getE3(), V.g, 1e-5f);
	auto rgr = V.rgr;
	BOOST_CHECK_CLOSE(rgr.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rgr.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rgr.getE3(), V.r, 1e-5f);
	auto grr = V.grr;
	BOOST_CHECK_CLOSE(grr.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grr.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grr.getE3(), V.r, 1e-5f);
	auto grg = V.grg;
	BOOST_CHECK_CLOSE(grg.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grg.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grg.getE3(), V.g, 1e-5f);
	auto ggr = V.ggr;
	BOOST_CHECK_CLOSE(ggr.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggr.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggr.getE3(), V.r, 1e-5f);
	auto ggg = V.ggg;
	BOOST_CHECK_CLOSE(ggg.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggg.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggg.getE3(), V.g, 1e-5f);
	// 3d swizzles <s, t>
	auto sss = V.sss;
	BOOST_CHECK_CLOSE(sss.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sss.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sss.getE3(), V.s, 1e-5f);
	auto sst = V.sst;
	BOOST_CHECK_CLOSE(sst.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sst.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sst.getE3(), V.t, 1e-5f);
	auto sts = V.sts;
	BOOST_CHECK_CLOSE(sts.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sts.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(sts.getE3(), V.s, 1e-5f);
	auto tss = V.tss;
	BOOST_CHECK_CLOSE(tss.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tss.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tss.getE3(), V.s, 1e-5f);
	auto tst = V.tst;
	BOOST_CHECK_CLOSE(tst.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tst.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tst.getE3(), V.t, 1e-5f);
	auto tts = V.tts;
	BOOST_CHECK_CLOSE(tts.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tts.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tts.getE3(), V.s, 1e-5f);
	auto ttt = V.ttt;
	BOOST_CHECK_CLOSE(ttt.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttt.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttt.getE3(), V.t, 1e-5f);
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
	// 4d swizzles <r, g>
	auto rrrr = V.rrrr;
	BOOST_CHECK_CLOSE(rrrr.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrrr.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrrr.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrrr.getE4(), V.r, 1e-5f);
	auto rrrg = V.rrrg;
	BOOST_CHECK_CLOSE(rrrg.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrrg.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrrg.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrrg.getE4(), V.g, 1e-5f);
	auto rrgr = V.rrgr;
	BOOST_CHECK_CLOSE(rrgr.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrgr.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrgr.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rrgr.getE4(), V.r, 1e-5f);
	auto rrgg = V.rrgg;
	BOOST_CHECK_CLOSE(rrgg.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrgg.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rrgg.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rrgg.getE4(), V.g, 1e-5f);
	auto rgrr = V.rgrr;
	BOOST_CHECK_CLOSE(rgrr.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rgrr.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rgrr.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rgrr.getE4(), V.r, 1e-5f);
	auto rgrg = V.rgrg;
	BOOST_CHECK_CLOSE(rgrg.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rgrg.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rgrg.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rgrg.getE4(), V.g, 1e-5f);
	auto rggr = V.rggr;
	BOOST_CHECK_CLOSE(rggr.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rggr.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rggr.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rggr.getE4(), V.r, 1e-5f);
	auto rggg = V.rggg;
	BOOST_CHECK_CLOSE(rggg.getE1(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(rggg.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rggg.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(rggg.getE4(), V.g, 1e-5f);
	auto grrr = V.grrr;
	BOOST_CHECK_CLOSE(grrr.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grrr.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grrr.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grrr.getE4(), V.r, 1e-5f);
	auto grrg = V.grrg;
	BOOST_CHECK_CLOSE(grrg.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grrg.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grrg.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grrg.getE4(), V.g, 1e-5f);
	auto grgr = V.grgr;
	BOOST_CHECK_CLOSE(grgr.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grgr.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grgr.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grgr.getE4(), V.r, 1e-5f);
	auto grgg = V.grgg;
	BOOST_CHECK_CLOSE(grgg.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grgg.getE2(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(grgg.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(grgg.getE4(), V.g, 1e-5f);
	auto ggrr = V.ggrr;
	BOOST_CHECK_CLOSE(ggrr.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggrr.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggrr.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(ggrr.getE4(), V.r, 1e-5f);
	auto ggrg = V.ggrg;
	BOOST_CHECK_CLOSE(ggrg.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggrg.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(ggrg.getE3(), V.r, 1e-5f);
	BOOST_CHECK_CLOSE(ggrg.getE4(), V.g, 1e-5f);
	auto gggr = V.gggr;
	BOOST_CHECK_CLOSE(gggr.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gggr.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gggr.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gggr.getE4(), V.r, 1e-5f);
	auto gggg = V.gggg;
	BOOST_CHECK_CLOSE(gggg.getE1(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gggg.getE2(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gggg.getE3(), V.g, 1e-5f);
	BOOST_CHECK_CLOSE(gggg.getE4(), V.g, 1e-5f);
	// 4d swizzles <s, t>
	auto ssss = V.ssss;
	BOOST_CHECK_CLOSE(ssss.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssss.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssss.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssss.getE4(), V.s, 1e-5f);
	auto ssst = V.ssst;
	BOOST_CHECK_CLOSE(ssst.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssst.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssst.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssst.getE4(), V.t, 1e-5f);
	auto ssts = V.ssts;
	BOOST_CHECK_CLOSE(ssts.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssts.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ssts.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ssts.getE4(), V.s, 1e-5f);
	auto sstt = V.sstt;
	BOOST_CHECK_CLOSE(sstt.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sstt.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sstt.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(sstt.getE4(), V.t, 1e-5f);
	auto stss = V.stss;
	BOOST_CHECK_CLOSE(stss.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(stss.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(stss.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(stss.getE4(), V.s, 1e-5f);
	auto stst = V.stst;
	BOOST_CHECK_CLOSE(stst.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(stst.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(stst.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(stst.getE4(), V.t, 1e-5f);
	auto stts = V.stts;
	BOOST_CHECK_CLOSE(stts.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(stts.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(stts.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(stts.getE4(), V.s, 1e-5f);
	auto sttt = V.sttt;
	BOOST_CHECK_CLOSE(sttt.getE1(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(sttt.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(sttt.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(sttt.getE4(), V.t, 1e-5f);
	auto tsss = V.tsss;
	BOOST_CHECK_CLOSE(tsss.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tsss.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tsss.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tsss.getE4(), V.s, 1e-5f);
	auto tsst = V.tsst;
	BOOST_CHECK_CLOSE(tsst.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tsst.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tsst.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tsst.getE4(), V.t, 1e-5f);
	auto tsts = V.tsts;
	BOOST_CHECK_CLOSE(tsts.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tsts.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tsts.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tsts.getE4(), V.s, 1e-5f);
	auto tstt = V.tstt;
	BOOST_CHECK_CLOSE(tstt.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tstt.getE2(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(tstt.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tstt.getE4(), V.t, 1e-5f);
	auto ttss = V.ttss;
	BOOST_CHECK_CLOSE(ttss.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttss.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttss.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ttss.getE4(), V.s, 1e-5f);
	auto ttst = V.ttst;
	BOOST_CHECK_CLOSE(ttst.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttst.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttst.getE3(), V.s, 1e-5f);
	BOOST_CHECK_CLOSE(ttst.getE4(), V.t, 1e-5f);
	auto ttts = V.ttts;
	BOOST_CHECK_CLOSE(ttts.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttts.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttts.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(ttts.getE4(), V.s, 1e-5f);
	auto tttt = V.tttt;
	BOOST_CHECK_CLOSE(tttt.getE1(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tttt.getE2(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tttt.getE3(), V.t, 1e-5f);
	BOOST_CHECK_CLOSE(tttt.getE4(), V.t, 1e-5f);
}

BOOST_AUTO_TEST_CASE(swizzle_assign) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_fromSwizzle;
	V_fromSwizzle.x = 9999.0f;
	V_fromSwizzle.y = 9999.0f;
	// assign in-order from vector
	V_fromSwizzle.xy = V;
	BOOST_CHECK_CLOSE(V.x, V_fromSwizzle.x, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V_fromSwizzle.y, 1e-5f);
	// assign out-of-order from vector
	V_fromSwizzle.yx = V;
	BOOST_CHECK_CLOSE(V.x, V_fromSwizzle.y, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V_fromSwizzle.x, 1e-5f);
	// assign in-order from swizzle
	V_fromSwizzle.xy = V.yy;
	BOOST_CHECK_CLOSE(V.y, V_fromSwizzle.x, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V_fromSwizzle.y, 1e-5f);
	// assign out-of-order from swizzle
	V_fromSwizzle.yx = V.xx;
	BOOST_CHECK_CLOSE(V.x, V_fromSwizzle.x, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V_fromSwizzle.y, 1e-5f);
}

BOOST_AUTO_TEST_SUITE_END()
