/**
 *  @file
 *  @copyright defined in ETA/LICENSE.txt
 */
#include <ETAiolib/ETAio.hpp>

#include "test_api.hpp"

void test_types::types_size() {

   ETAio_assert( sizeof(int64_t) == 8, "int64_t size != 8");
   ETAio_assert( sizeof(uint64_t) ==  8, "uint64_t size != 8");
   ETAio_assert( sizeof(uint32_t) ==  4, "uint32_t size != 4");
   ETAio_assert( sizeof(int32_t) ==  4, "int32_t size != 4");
   ETAio_assert( sizeof(uint128_t) == 16, "uint128_t size != 16");
   ETAio_assert( sizeof(int128_t) == 16, "int128_t size != 16");
   ETAio_assert( sizeof(uint8_t) ==  1, "uint8_t size != 1");

   ETAio_assert( sizeof(account_name) ==  8, "account_name size !=  8");
   ETAio_assert( sizeof(table_name) ==  8, "table_name size !=  8");
   ETAio_assert( sizeof(time) ==  4, "time size !=  4");
   ETAio_assert( sizeof(ETAio::key256) == 32, "key256 size != 32" );
}

void test_types::char_to_symbol() {

   ETAio_assert( ETAio::char_to_symbol('1') ==  1, "ETAio::char_to_symbol('1') !=  1");
   ETAio_assert( ETAio::char_to_symbol('2') ==  2, "ETAio::char_to_symbol('2') !=  2");
   ETAio_assert( ETAio::char_to_symbol('3') ==  3, "ETAio::char_to_symbol('3') !=  3");
   ETAio_assert( ETAio::char_to_symbol('4') ==  4, "ETAio::char_to_symbol('4') !=  4");
   ETAio_assert( ETAio::char_to_symbol('5') ==  5, "ETAio::char_to_symbol('5') !=  5");
   ETAio_assert( ETAio::char_to_symbol('a') ==  6, "ETAio::char_to_symbol('a') !=  6");
   ETAio_assert( ETAio::char_to_symbol('b') ==  7, "ETAio::char_to_symbol('b') !=  7");
   ETAio_assert( ETAio::char_to_symbol('c') ==  8, "ETAio::char_to_symbol('c') !=  8");
   ETAio_assert( ETAio::char_to_symbol('d') ==  9, "ETAio::char_to_symbol('d') !=  9");
   ETAio_assert( ETAio::char_to_symbol('e') == 10, "ETAio::char_to_symbol('e') != 10");
   ETAio_assert( ETAio::char_to_symbol('f') == 11, "ETAio::char_to_symbol('f') != 11");
   ETAio_assert( ETAio::char_to_symbol('g') == 12, "ETAio::char_to_symbol('g') != 12");
   ETAio_assert( ETAio::char_to_symbol('h') == 13, "ETAio::char_to_symbol('h') != 13");
   ETAio_assert( ETAio::char_to_symbol('i') == 14, "ETAio::char_to_symbol('i') != 14");
   ETAio_assert( ETAio::char_to_symbol('j') == 15, "ETAio::char_to_symbol('j') != 15");
   ETAio_assert( ETAio::char_to_symbol('k') == 16, "ETAio::char_to_symbol('k') != 16");
   ETAio_assert( ETAio::char_to_symbol('l') == 17, "ETAio::char_to_symbol('l') != 17");
   ETAio_assert( ETAio::char_to_symbol('m') == 18, "ETAio::char_to_symbol('m') != 18");
   ETAio_assert( ETAio::char_to_symbol('n') == 19, "ETAio::char_to_symbol('n') != 19");
   ETAio_assert( ETAio::char_to_symbol('o') == 20, "ETAio::char_to_symbol('o') != 20");
   ETAio_assert( ETAio::char_to_symbol('p') == 21, "ETAio::char_to_symbol('p') != 21");
   ETAio_assert( ETAio::char_to_symbol('q') == 22, "ETAio::char_to_symbol('q') != 22");
   ETAio_assert( ETAio::char_to_symbol('r') == 23, "ETAio::char_to_symbol('r') != 23");
   ETAio_assert( ETAio::char_to_symbol('s') == 24, "ETAio::char_to_symbol('s') != 24");
   ETAio_assert( ETAio::char_to_symbol('t') == 25, "ETAio::char_to_symbol('t') != 25");
   ETAio_assert( ETAio::char_to_symbol('u') == 26, "ETAio::char_to_symbol('u') != 26");
   ETAio_assert( ETAio::char_to_symbol('v') == 27, "ETAio::char_to_symbol('v') != 27");
   ETAio_assert( ETAio::char_to_symbol('w') == 28, "ETAio::char_to_symbol('w') != 28");
   ETAio_assert( ETAio::char_to_symbol('x') == 29, "ETAio::char_to_symbol('x') != 29");
   ETAio_assert( ETAio::char_to_symbol('y') == 30, "ETAio::char_to_symbol('y') != 30");
   ETAio_assert( ETAio::char_to_symbol('z') == 31, "ETAio::char_to_symbol('z') != 31");

   for(unsigned char i = 0; i<255; i++) {
      if((i >= 'a' && i <= 'z') || (i >= '1' || i <= '5')) continue;
      ETAio_assert( ETAio::char_to_symbol((char)i) == 0, "ETAio::char_to_symbol() != 0");
   }
}

void test_types::string_to_name() {

   ETAio_assert( ETAio::string_to_name("a") == N(a) , "ETAio::string_to_name(a)" );
   ETAio_assert( ETAio::string_to_name("ba") == N(ba) , "ETAio::string_to_name(ba)" );
   ETAio_assert( ETAio::string_to_name("cba") == N(cba) , "ETAio::string_to_name(cba)" );
   ETAio_assert( ETAio::string_to_name("dcba") == N(dcba) , "ETAio::string_to_name(dcba)" );
   ETAio_assert( ETAio::string_to_name("edcba") == N(edcba) , "ETAio::string_to_name(edcba)" );
   ETAio_assert( ETAio::string_to_name("fedcba") == N(fedcba) , "ETAio::string_to_name(fedcba)" );
   ETAio_assert( ETAio::string_to_name("gfedcba") == N(gfedcba) , "ETAio::string_to_name(gfedcba)" );
   ETAio_assert( ETAio::string_to_name("hgfedcba") == N(hgfedcba) , "ETAio::string_to_name(hgfedcba)" );
   ETAio_assert( ETAio::string_to_name("ihgfedcba") == N(ihgfedcba) , "ETAio::string_to_name(ihgfedcba)" );
   ETAio_assert( ETAio::string_to_name("jihgfedcba") == N(jihgfedcba) , "ETAio::string_to_name(jihgfedcba)" );
   ETAio_assert( ETAio::string_to_name("kjihgfedcba") == N(kjihgfedcba) , "ETAio::string_to_name(kjihgfedcba)" );
   ETAio_assert( ETAio::string_to_name("lkjihgfedcba") == N(lkjihgfedcba) , "ETAio::string_to_name(lkjihgfedcba)" );
   ETAio_assert( ETAio::string_to_name("mlkjihgfedcba") == N(mlkjihgfedcba) , "ETAio::string_to_name(mlkjihgfedcba)" );
   ETAio_assert( ETAio::string_to_name("mlkjihgfedcba1") == N(mlkjihgfedcba2) , "ETAio::string_to_name(mlkjihgfedcba2)" );
   ETAio_assert( ETAio::string_to_name("mlkjihgfedcba55") == N(mlkjihgfedcba14) , "ETAio::string_to_name(mlkjihgfedcba14)" );

   ETAio_assert( ETAio::string_to_name("azAA34") == N(azBB34) , "ETAio::string_to_name N(azBB34)" );
   ETAio_assert( ETAio::string_to_name("AZaz12Bc34") == N(AZaz12Bc34) , "ETAio::string_to_name AZaz12Bc34" );
   ETAio_assert( ETAio::string_to_name("AAAAAAAAAAAAAAA") == ETAio::string_to_name("BBBBBBBBBBBBBDDDDDFFFGG") , "ETAio::string_to_name BBBBBBBBBBBBBDDDDDFFFGG" );
}

void test_types::name_class() {

   ETAio_assert( ETAio::name{ETAio::string_to_name("azAA34")}.value == N(azAA34), "ETAio::name != N(azAA34)" );
   ETAio_assert( ETAio::name{ETAio::string_to_name("AABBCC")}.value == 0, "ETAio::name != N(0)" );
   ETAio_assert( ETAio::name{ETAio::string_to_name("AA11")}.value == N(AA11), "ETAio::name != N(AA11)" );
   ETAio_assert( ETAio::name{ETAio::string_to_name("11AA")}.value == N(11), "ETAio::name != N(11)" );
   ETAio_assert( ETAio::name{ETAio::string_to_name("22BBCCXXAA")}.value == N(22), "ETAio::name != N(22)" );
   ETAio_assert( ETAio::name{ETAio::string_to_name("AAAbbcccdd")} == ETAio::name{ETAio::string_to_name("AAAbbcccdd")}, "ETAio::name == ETAio::name" );

   uint64_t tmp = ETAio::name{ETAio::string_to_name("11bbcccdd")};
   ETAio_assert(N(11bbcccdd) == tmp, "N(11bbcccdd) == tmp");
}
