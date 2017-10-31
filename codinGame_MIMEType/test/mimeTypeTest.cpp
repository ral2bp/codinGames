#include "../gtest/gtest.h"

#define private public
#include "../src/mimeFinder.h"
#undef private

class mimeTypeTests: public ::testing::Test
{
public:
    mimeFinder testFinder;
};

TEST_F(mimeTypeTests, givenStringWithSpaceReturnsUnknown)
{
    ASSERT_EQ("UNKNOWN", testFinder.findMimeType("String with spaces"));
}

TEST_F(mimeTypeTests, givenStringWithOutSpaceReturnsUnknownOnEmptyDictionary)
{
    map<string, string> testDictionary = map<string, string>();
    testFinder = mimeFinder(testDictionary);
    ASSERT_EQ("UNKNOWN", testFinder.findMimeType("StringWithoutSpaces"));
}
TEST_F(mimeTypeTests, givenProperFileNameReturnsExtension)
{
    ASSERT_EQ("png", testFinder.getExtension("image.png"));
}

TEST_F(mimeTypeTests, givenOnlyExtensionReturnsEmpty)
{
    ASSERT_EQ("png", testFinder.getExtension(".png"));
}

TEST_F(mimeTypeTests, givenOnlyExtensionWithoutDotReturnsEmpty)
{
    ASSERT_EQ("", testFinder.getExtension("png"));
}

TEST_F(mimeTypeTests, givenDictionaryHasCorrectDictionary)
{
    map<string, string> testDictionary = map<string, string>();
    testDictionary["png"] = "image/png";
    mimeFinder uniqueTestFinder = mimeFinder(testDictionary);
    ASSERT_EQ(1u, uniqueTestFinder.dictionary.size());
    ASSERT_EQ("image/png", uniqueTestFinder.dictionary["png"]);
}

TEST_F(mimeTypeTests, givenNonEmptyMapReturnsMimeTypeInMap)
{
    map<string, string> testDictionary = map<string, string>();
    testDictionary["png"] = "image/png";
    mimeFinder uniqueTestFinder = mimeFinder(testDictionary);
    ASSERT_EQ("image/png", uniqueTestFinder.findMimeType("image.png"));
}
TEST_F(mimeTypeTests, codinGameTest2)
{
    map<string, string> testDictionary = map<string, string>();
    testDictionary["flv"] = "video/x-flv";
    testDictionary["txt"] = "text/plain";
    testDictionary["xml"] = "text/xml";
    mimeFinder uniqueTestFinder = mimeFinder(testDictionary);
    for(auto item : testDictionary)
    {
        ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType(item.second));
    }
}

TEST_F(mimeTypeTests, codinGameTest3)
{
    map<string, string> testDictionary = map<string, string>();
    testDictionary["wav"] = "audio/x-wav";
    testDictionary["mp3"] = "audio/mpeg";
    testDictionary["pdf"] = "application/pdf";

    mimeFinder uniqueTestFinder = mimeFinder(testDictionary);

    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType("a"));
    ASSERT_EQ("audio/x-wav", uniqueTestFinder.findMimeType("a.wav"));
    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType("b.wav.tmp"));
    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType("test.vmp3"));
    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType("pdf"));
    ASSERT_EQ("application/pdf", uniqueTestFinder.findMimeType(".pdf"));
    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType("mp3"));
    ASSERT_EQ("application/pdf", uniqueTestFinder.findMimeType("report..pdf"));
    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType("defaultwav"));
    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType(".mp3."));
    ASSERT_EQ("UNKNOWN", uniqueTestFinder.findMimeType("final."));
}
