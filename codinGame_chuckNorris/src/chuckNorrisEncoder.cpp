#include "chuckNorrisEncoder.h"
#include "iostream"

string chuckNorrisEncoder::encode(string toEncode)
{
	string result = "";

	for(auto character : toEncode)
		result.append(toBinary(character));

	result = encodeString(result);

	return result;
}

string chuckNorrisEncoder::toBinary(char toConvert) {
	return std::bitset<7>(toConvert).to_string();
}

string chuckNorrisEncoder::encodeString(string toEncode)
{
	string result = "";

	for(string item : splitToSameCharacterStrings(toEncode))
		result.append(encodeHomogenousString(item) + " ");

	return result.substr(0, result.length()-1);
}

std::vector<string> chuckNorrisEncoder::splitToSameCharacterStrings(string toSplit)
{
	std::vector<string> result;
	string subString;
	string ref = toSplit.substr(0,1);

	for(int i = 0; i <= toSplit.length(); ++i)
	{
		if(ref.compare(toSplit.substr(i,1)) == 0)
			subString.append(toSplit.substr(i,1));
		else
		{
			result.push_back(subString);
			subString = ref = toSplit.substr(i,1);
		}
	}

	return result;
}

string chuckNorrisEncoder::encodeHomogenousString(string toEncode)
{
	string result = "";
	result.append(getValueIndicator(!toEncode.substr(0,1).compare("1")));

	for(int i = 0; i < toEncode.length(); ++i)
		result.append("0");

	return result;
}

string chuckNorrisEncoder::getValueIndicator(bool isOne)
{
	if(isOne)
		return "0 ";
	return "00 ";
}
