#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "gtest/gtest.h"
#include "src/mimeFinder.h"

using namespace std;

int main(int argc, char **argv)
{
/*
    int assiciationTableSize;
    cin >> assiciationTableSize;
    cin.ignore();
    int fileNamesToBeAnalyzed;
    cin >> fileNamesToBeAnalyzed;
    cin.ignore();

    map<string, string> extensionMimePairs;

    for (int i = 0; i < assiciationTableSize; i++)
    {
        string fileExtension;
        string mimeType;
        cin >> fileExtension >> mimeType;
        cin.ignore();
        extensionMimePairs[fileExtension] = mimeType;
    }

    mimeFinder finder = mimeFinder(extensionMimePairs);

    vector<string> result;
    for (int i = 0; i < fileNamesToBeAnalyzed; i++)
    {
        string fileName;
        getline(cin, fileName);
        result.push_back(finder.findMimeType(fileName));
    }

    for (auto item : result)
        cout << item << endl;
*/
    ::testing::InitGoogleTest(&argc, argv);
    int testResult = RUN_ALL_TESTS();

    system("pause");
    return testResult;
}
