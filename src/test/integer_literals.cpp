#include "utilities/integer_literals.hpp"

#include <algorithm>

#include <boost/test/unit_test.hpp>

using namespace util::integer_literals;

BOOST_AUTO_TEST_CASE(zero) {
	BOOST_CHECK_EQUAL(0, 0_i8);
	BOOST_CHECK_EQUAL(0, 0_u8);
	BOOST_CHECK_EQUAL(0, 0_i16);
	BOOST_CHECK_EQUAL(0, 0_u16);
	BOOST_CHECK_EQUAL(0, 0_i32);
	BOOST_CHECK_EQUAL(0, 0_u32);
	BOOST_CHECK_EQUAL(0, 0_i64);
	BOOST_CHECK_EQUAL(0, 0_u64);
	BOOST_CHECK_EQUAL(0, 0_sz);
	BOOST_CHECK_EQUAL(0, 0_pd);
}

BOOST_AUTO_TEST_CASE(one) {
	BOOST_CHECK_EQUAL(1, 1_i8);
	BOOST_CHECK_EQUAL(1, 1_u8);
	BOOST_CHECK_EQUAL(1, 1_i16);
	BOOST_CHECK_EQUAL(1, 1_u16);
	BOOST_CHECK_EQUAL(1, 1_i32);
	BOOST_CHECK_EQUAL(1, 1_u32);
	BOOST_CHECK_EQUAL(1, 1_i64);
	BOOST_CHECK_EQUAL(1, 1_u64);
	BOOST_CHECK_EQUAL(1, 1_sz);
	BOOST_CHECK_EQUAL(1, 1_pd);
}

BOOST_AUTO_TEST_CASE(max) {
	BOOST_CHECK_EQUAL(127, 127_i8);
	BOOST_CHECK_EQUAL(255, 255_u8);
	BOOST_CHECK_EQUAL(32767, 32767_i16);
	BOOST_CHECK_EQUAL(65535, 65535_u16);
	BOOST_CHECK_EQUAL(2147483647, 2147483647_i32);
	BOOST_CHECK_EQUAL(4294967295, 4294967295_u32);
	BOOST_CHECK_EQUAL(9223372036854775807, 9223372036854775807_i64);
	BOOST_CHECK_EQUAL(18446744073709551615ULL, 18446744073709551615_u64);
}

BOOST_AUTO_TEST_CASE(binary) {
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_i8);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_u8);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_i16);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_u16);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_i32);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_u32);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_i64);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_u64);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_sz);
	BOOST_CHECK_EQUAL(0b001'10010, 0b001'10010_pd);
}

BOOST_AUTO_TEST_CASE(octal) {
	BOOST_CHECK_EQUAL(01'11, 01'11_i8);
	BOOST_CHECK_EQUAL(01'11, 01'11_u8);
	BOOST_CHECK_EQUAL(01'11, 01'11_i16);
	BOOST_CHECK_EQUAL(01'11, 01'11_u16);
	BOOST_CHECK_EQUAL(01'11, 01'11_i32);
	BOOST_CHECK_EQUAL(01'11, 01'11_u32);
	BOOST_CHECK_EQUAL(01'11, 01'11_i64);
	BOOST_CHECK_EQUAL(01'11, 01'11_u64);
	BOOST_CHECK_EQUAL(01'11, 01'11_sz);
	BOOST_CHECK_EQUAL(01'11, 01'11_pd);
}

BOOST_AUTO_TEST_CASE(hex) {
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_i8);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_u8);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_i16);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_u16);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_i32);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_u32);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_i64);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_u64);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_sz);
	BOOST_CHECK_EQUAL(0x4'4, 0x4'4_pd);
}

