#include "mimeFinder.h"

mimeFinder::mimeFinder(map<string, string> dictToUse)
{
    for(auto item : dictToUse)
    {
        if(item.first.length() <= 10 && item.second.length() <= 50)
        {
            string key = item.first;
            std::transform(key.begin(), key.end(), key.begin(), ::tolower);
            dictionary[key] = item.second;
        }
    }
}

string mimeFinder::findMimeType(string fileName)
{
    string result = "UNKNOWN";

    std::transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);

    if(fileName.find(" ") != string::npos || fileName.length() > 256)
        return result;

    string extension = getExtension(fileName);

    if(extension.length() > 10 || extension.compare("") == 0)
        return result;

    result = dictionary[extension];
    if(result.compare("") != 0)
        return result;
    return "UNKNOWN";
}

string mimeFinder::getExtension(string fileName)
{
    std::size_t extensionStart = fileName.find_last_of(".");

    if(extensionStart == string::npos)
        return "";
    else
        return fileName.substr(extensionStart + 1);
}
