#include <gtest/gtest.h>
#include "../TimeParser.h"

// Test suite: TimeParserTest
TEST(TimeParserTest, TestCaseCorrectTime) {
    // Note that this test fails on purpose!! Muokkasin sen läpäisemään
    // Test with correct time string
    char time_test[] = "141205";
    ASSERT_EQ(time_parse(time_test),725);
}

TEST(TimeParserTest, ExampleFromAssignment){
    char time_test[] = "000120";
    ASSERT_EQ(time_parse(time_test), 80);
}

// 1 Pisteen testi boundary value

TEST(TimeParserTest, SecondsAtUpperBoundary_Valid){
    char time_test[] = "001059";
    ASSERT_EQ(time_parse(time_test), 10 * 60 + 59);
}

TEST(TimeParserTest, SecondsOverUpperBoundary_Invalid){
    char time_test[] = "001060";
    ASSERT_EQ(time_parse(time_test), TIME_VALUE_ERROR);
}

TEST(TimeParserTest, MinutesAtUpperBoundary_Valid){
    char time_test[] = "005930";
    ASSERT_EQ(time_parse(time_test), 59 * 60 + 30);
}

TEST(TimeParserTest, MinutesOverUpperBoundary_Invalid){
    char time_test[] = "006030";
    ASSERT_EQ(time_parse(time_test), TIME_VALUE_ERROR);
}

TEST(TimeParserTest, HoursAtUpperBoundary_Valid){
    char time_test[] = "235959";
    ASSERT_EQ(time_parse(time_test), 59 * 60 + 59);
}

TEST(TimeParserTest, HoursOverUpperBoundary_Invalid){
    char time_test[] = "240000";
    ASSERT_EQ(time_parse(time_test), TIME_VALUE_ERROR);
}

// 1 lisäpisteen lisätestit :)

// Tarkistus onko merkkijono aina tasan 6 merkkiä pitkä. Päätin lisätä
// myös itse TimeParser cpp jotta ei tuu ylimääräisiä vahiko arvoja :)
TEST(TimeParserTest, CorrectLength_Valid){
    char time_test[] = "010203";
    ASSERT_EQ(time_parse(time_test), 2 * 60 + 3);
}

// Onko liian lyhyt ja sama ajatus kuin tuossa ylemmässä testissä
TEST(TimeParserTest, WrongLenght_TooShort_Invalid){
    char time_test[] = "1234";
    ASSERT_EQ(time_parse(time_test), TIME_LEN_ERROR);
}

TEST(TimeParserTest, WrongLenght_TooLong_Invalid){
    char time_test[] = "1234567";
    ASSERT_EQ(time_parse(time_test), TIME_LEN_ERROR);
}

// Tarkistus ettei palautusarvo oo 0 sekunttia

TEST(TimeParserTest, NonZeroTime_Valid){
    char time_test[] = "000001";
    ASSERT_EQ(time_parse(time_test), 1);
}

TEST(TimeParserTest, ZeroTime_Valid){
    char time_test[] = "000000";
    ASSERT_EQ(time_parse(time_test), TIME_VALUE_ERROR);
}

TEST(TimeParserTest, AllDigits_Valid){
    char time_test[] = "121505";
    ASSERT_EQ(time_parse(time_test), 15 * 60 + 5);
}

TEST(TimeParserTest, NonDigitsCharacters_Invalid){
    char time_test[] = "0A0000";
    ASSERT_EQ(time_parse(time_test), TIME_ARRAY_ERROR);
}

// Ei ole tyhjä (NULL)

TEST(TimeParserTest, NullString_Invalid){
    ASSERT_EQ(time_parse(nullptr), TIME_ARRAY_ERROR);
}

// Tyhjä merkkijono ei sallittu
TEST(TimeParserTest, EmptyString_Invalid){
    char time_test[] = "";
    ASSERT_EQ(time_parse(time_test), TIME_LEN_ERROR);
}
// https://google.github.io/googletest/reference/testing.html
// https://google.github.io/googletest/reference/assertions.html
