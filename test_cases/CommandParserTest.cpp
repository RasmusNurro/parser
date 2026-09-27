#include <gtest/gtest.h>
#include "../CommandParser.h"

// Kelvolliset komennot
TEST(CommandParserTest, RedWithDuration_Valid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_TRUE(parse_command("R,1000", &color, &duration));
    EXPECT_EQ(color, 'R');
    EXPECT_EQ(duration, 1000u);
}

TEST(CommandParserTest, YellowWithDuration_Valid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_TRUE(parse_command("Y,500", &color, &duration));
    EXPECT_EQ(color, 'Y');
    EXPECT_EQ(duration, 500u);
}

TEST(CommandParserTest, GreenWithDuration_Valid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_TRUE(parse_command("G,1000", &color, &duration));
    EXPECT_EQ(color, 'G');
    EXPECT_EQ(duration, 1000u);
}
 
// Kelvolliset värit

TEST(CommandParserTest, RedWithoutDuration_UsesDefault)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_TRUE(parse_command("R", &color, &duration));
    EXPECT_EQ(color, 'R');
    EXPECT_EQ(duration, 1000u);
}

TEST(CommandParserTest, YellowWithoutDuration_UsesDefault)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_TRUE(parse_command("Y", &color, &duration));
    EXPECT_EQ(color, 'Y');
    EXPECT_EQ(duration, 1000u);
}

TEST(CommandParserTest, GreenWithoutDuration_UsesDefault)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_TRUE(parse_command("G", &color, &duration));
    EXPECT_EQ(color, 'G');
    EXPECT_EQ(duration, 1000u);
}

// Virheelliset värit

// Valkonen ei kuulu liikennevaloihin
   TEST(CommandParserTest, WhiteColor_Invalid)
{

    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("W,1000", &color, &duration));
}

// Liilla ei ole liikennevalo
TEST(CommandParserTest, PurpleColor_Invalid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("P,500", &color, &duration));
}

    // Sininen - yleinen mutta virheellinen arvaus 
TEST(CommandParserTest, BlueColor_Invalid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("B,1000", &color, &duration));
}

TEST(CommandParserTest, LowercaseColor_Invalid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("r,1000", &color, &duration));
}

// Virhe syötteet
TEST(CommandParserTest, EmptyString_Invalid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("", &color, &duration));
}

TEST(CommandParserTest, CommaWithoutDuration_Invalid)
{    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("R,", &color, &duration));
}

TEST(CommandParserTest, ExtraCharacterWithoutComma_Invalid)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("RR", &color, &duration));
}

TEST(CommandParserTest, RepeatCommand_T_HandledElsewhereReturnsFalse)
{
    char color = 0;
    uint32_t duration = 0;
    ASSERT_FALSE(parse_command("T", &color, &duration));
}

// Negativiinen kesto
TEST(CommandParserTest, NegativeDuration_DocumentedQuirk)
{
    char color = 0;
    uint32_t duration = 0;
    bool result = parse_command("R,-100", &color, &duration);
    ASSERT_TRUE(result);
    EXPECT_EQ(color, 'R');
    //7 -100 tulkitaan unsigned-lukuna: UINT32_MAX - 100 + 1 
    EXPECT_EQ(duration, 4294967196u);
}

// https://google.github.io/googletest/reference/testing.html
// https://google.github.io/googletest/reference/assertions.html