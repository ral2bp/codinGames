#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "gtest/gtest.h"
#include "src/mimeFinder.h"

using namespace std;

int main(int argc, char **argv)
{
	int assiciationTableSize; // Number of elements which make up the association table.
	cin >> assiciationTableSize; cin.ignore();
	int fileNamesToBeAnalyzed; // Number Q of file names to be analyzed.
	cin >> fileNamesToBeAnalyzed; cin.ignore();

	map<string,string> extensionMimePairs;

	for (int i = 0; i < assiciationTableSize; i++) {
		string fileExtension; // file extension
		string mimeType; // MIME type.
		cin >> fileExtension >> mimeType; cin.ignore();
		extensionMimePairs[fileExtension] = mimeType;
	}

	mimeFinder finder = mimeFinder(extensionMimePairs);

	vector<string> result;
	for (int i = 0; i < fileNamesToBeAnalyzed; i++) {
		string fileName; // One file name per line.
		getline(cin, fileName);
		result.push_back(finder.findMimeType(fileName));
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;


	for(auto item : result)
		cout << item << endl;

    ::testing::InitGoogleTest(&argc, argv);
    int testResult = RUN_ALL_TESTS();

    system("pause");
    return testResult;
}
