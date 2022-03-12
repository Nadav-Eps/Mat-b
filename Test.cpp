#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input where row<col") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	CHECK(nospaces(mat(11, 9, '@', '-')) == nospaces("@@@@@@@@@@@\n"
													 "@---------@\n"
													 "@-@@@@@@@-@\n"
													 "@-@-----@-@\n"
                                                     "@-@-@@@-@-@\n"
                                                     "@-@-----@-@\n"
													 "@-@@@@@@@-@\n"
													 "@---------@\n"
													 "@@@@@@@@@@@"));

	CHECK(nospaces(mat(11, 5, '@', '-')) == nospaces("@@@@@@@@@@@\n"
													 "@---------@\n"
													 "@-@@@@@@@-@\n"
													 "@---------@\n"
                                                     "@@@@@@@@@@@"));

    CHECK(nospaces(mat(11, 3, '@', '-')) == nospaces("@@@@@@@@@@@\n"
													 "@---------@\n"
													 "@@@@@@@@@@@"));
    
    CHECK(nospaces(mat(13, 11, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													  "@-----------@\n"
													  "@-@@@@@@@@@-@\n"
													  "@-@-------@-@\n"
                                                      "@-@-@@@@@-@-@\n"
                                                      "@-@-@---@-@-@\n"
                                                      "@-@-@@@@@-@-@\n"
                                                      "@-@-------@-@\n"
													  "@-@@@@@@@@@-@\n"
													  "@-----------@\n"
													  "@@@@@@@@@@@@@"));
    
    CHECK(nospaces(mat(13, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													  "@-----------@\n"
													  "@-@@@@@@@@@-@\n"
													  "@-@-------@-@\n"
                                                      "@-@-@@@@@-@-@\n"
                                                      "@-@-------@-@\n"
													  "@-@@@@@@@@@-@\n"
													  "@-----------@\n"
													  "@@@@@@@@@@@@@"));
    
    CHECK(nospaces(mat(13, 7, '@', '-')) == nospaces( "@@@@@@@@@@@@@\n"
													  "@-----------@\n"
													  "@-@@@@@@@@@-@\n"
													  "@-@-------@-@\n"
                                                      "@-@@@@@@@@@-@\n"
                                                      "@-----------@\n"
													  "@@@@@@@@@@@@@"));
    
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces( "@@@@@@@@@@@@@\n"
													  "@-----------@\n"
													  "@-@@@@@@@@@-@\n"
													  "@-----------@\n"
                                                      "@@@@@@@@@@@@@"));

    CHECK(nospaces(mat(13, 3, '@', '-')) == nospaces( "@@@@@@@@@@@@@\n"
													  "@-----------@\n"
													  "@@@@@@@@@@@@@"));                                                                                                                                                                                                        
}

TEST_CASE("Good input where row>col") {
    CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces( "@@@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
                                                     "@@@"));

    CHECK(nospaces(mat(3, 7, '@', '-')) == nospaces( "@@@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
                                                     "@-@\n"
                                                     "@-@\n"
                                                     "@@@"));                                                 

    CHECK(nospaces(mat(3, 9, '@', '-')) == nospaces( "@@@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
                                                     "@-@\n"
                                                     "@-@\n"
                                                     "@-@\n"
                                                     "@-@\n"
                                                     "@@@"));

    CHECK(nospaces(mat(5, 9, '@', '-')) == nospaces( "@@@@@\n"
													 "@---@\n"
													 "@-@-@\n"
													 "@-@-@\n"
                                                     "@-@-@\n"
                                                     "@-@-@\n"
                                                     "@-@-@\n"
                                                     "@---@\n"
                                                     "@@@@@"));

    CHECK(nospaces(mat(7, 9, '@', '-')) == nospaces( "@@@@@@@\n"
													 "@-----@\n"
													 "@-@@@-@\n"
													 "@-@-@-@\n"
                                                     "@-@-@-@\n"
                                                     "@-@-@-@\n"
                                                     "@-@@@-@\n"
                                                     "@-----@\n"
                                                     "@@@@@@@"));

}
TEST_CASE("Good input where row=col") {
    CHECK(nospaces(mat(5, 5, '@', '-')) == nospaces( "@@@@@\n"
													 "@---@\n"
													 "@-@-@\n"
													 "@---@\n"
                                                     "@@@@@"));

    CHECK(nospaces(mat(7, 7, '@', '-')) == nospaces( "@@@@@@@\n"
													 "@-----@\n"
													 "@-@@@-@\n"
													 "@-@-@-@\n"
                                                     "@-@@@-@\n"
                                                     "@-----@\n"
                                                     "@@@@@@@")); 

    CHECK(nospaces(mat(9, 9, '@', '-')) == nospaces( "@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
                                                     "@-@-@-@-@\n"
                                                     "@-@---@-@\n"
                                                     "@-@@@@@-@\n"
                                                     "@-------@\n"
                                                     "@@@@@@@@@"));                                                                                                  
}
TEST_CASE("row/col/both are even") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(10, 4, '$', '%'));
    CHECK_THROWS(mat(2, 5, '$', '%'));
    CHECK_THROWS(mat(21, 6, '$', '%'));
    CHECK_THROWS(mat(16, 3, '$', '%'));
}
TEST_CASE("row/col/both are negative") {
	CHECK_THROWS(mat(-10, 5, '$', '%'));
    CHECK_THROWS(mat(10, -4, '$', '%'));
    CHECK_THROWS(mat(-2, -5, '$', '%'));
    CHECK_THROWS(mat(-21, 6, '$', '%'));
    CHECK_THROWS(mat(-16, -3, '$', '%'));
}


/* Add more test cases here */
