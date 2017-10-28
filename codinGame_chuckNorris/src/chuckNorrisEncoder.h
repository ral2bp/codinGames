#include <string>
#include <bitset>
#include <vector>

using namespace std;
class chuckNorrisEncoder
{
public:
	string encode(string toEncode);

//private:
	string toBinary(char charToConvert);
	string encodeString(string toEncode);
	std::vector<string> splitToSameCharacterStrings(string toSplit);
	string encodeHomogenousString(string toEncode);
	string getValueIndicator(bool isOne);

};
