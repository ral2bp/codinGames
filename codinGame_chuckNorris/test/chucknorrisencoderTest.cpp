#include "../gtest/gtest.h"
#include "../src/chuckNorrisEncoder.h"
#include <vector>

class ChuckieTests : public ::testing::Test {
public:
	chuckNorrisEncoder testEncoder;
	void SetUp()
	{

	}

	void TearDown()
	{

	}
};

TEST_F(ChuckieTests, givenCharacterReturnsBinary)
{
	ASSERT_EQ("1000011", this->testEncoder.toBinary('C'));
}

TEST_F(ChuckieTests, givenOneReturnsOneValueIndicator)
{
	ASSERT_EQ("0 ", this->testEncoder.getValueIndicator(1));
}

TEST_F(ChuckieTests, givenZeroReturnsZeroIndicator)
{
	ASSERT_EQ("00 ", this->testEncoder.getValueIndicator(0));
}

TEST_F(ChuckieTests, givenZeroStringReturnsEncodedZeroString)
{
	ASSERT_EQ("00 0", this->testEncoder.encodeHomogenousString("0"));
}

TEST_F(ChuckieTests, givenTwoZeroesReturnsEncodedString)
{
	ASSERT_EQ("00 00", this->testEncoder.encodeHomogenousString("00"));
}

TEST_F(ChuckieTests, givenThreeZeroesReturnsEncodedString)
{
	ASSERT_EQ("00 000", this->testEncoder.encodeHomogenousString("000"));
}

TEST_F(ChuckieTests, givenSevenZeroesReturnsEncodedString)
{
	ASSERT_EQ("00 0000000", this->testEncoder.encodeHomogenousString("0000000"));
}

TEST_F(ChuckieTests, encodesSingleOneCorrectly)
{
	ASSERT_EQ("0 0", this->testEncoder.encodeHomogenousString("1"));
}

TEST_F(ChuckieTests, encodesMultipleeOnesCorrectly)
{
	ASSERT_EQ("0 000000", this->testEncoder.encodeHomogenousString("111111"));
}

TEST_F(ChuckieTests, mixedStringEncodesCorrectly)
{
	ASSERT_EQ("00 0 0 0", this->testEncoder.encodeString("01"));
}

TEST_F(ChuckieTests, charToBinaryIsEncoded)
{
	ASSERT_EQ("0 0 00 0000 0 00", this->testEncoder.encode("C"));
}

TEST_F(ChuckieTests, multipleCharactersAreEncoded)
{
	ASSERT_EQ("0 0 00 0000 0 000 00 0000 0 00", this->testEncoder.encode("CC"));
}

TEST_F(ChuckieTests, stringSplitterSplitsAsIntended)
{
	vector<string> expected;
	expected.push_back("AA");
	expected.push_back("BBB");
	expected.push_back("C");
	expected.push_back("DDD");
	vector<string> result = this->testEncoder.splitToSameCharacterStrings("AABBBCDDD");

	ASSERT_EQ(expected[0], result[0]);
	ASSERT_EQ(expected[1], result[1]);
	ASSERT_EQ(expected[2], result[2]);
	ASSERT_EQ(expected[3], result[3]);
}

TEST_F(ChuckieTests, stringSplitterSplitsSingleCharacters)
{
	vector<string> expected;
	expected.push_back("0");
	expected.push_back("1");
	vector<string> result = this->testEncoder.splitToSameCharacterStrings("01");

	ASSERT_EQ(expected[0], result[0]);
	ASSERT_EQ(expected[1], result[1]);
}
