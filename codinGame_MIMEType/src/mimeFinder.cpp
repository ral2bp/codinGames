#include "mimeFinder.h"

string mimeFinder::findMimeType(string fileName)
{
    string result = "UNKNOWN";

    if (fileName.find(" ") != string::npos || fileName.length() > 256)
        return result;

    string extension = getExtension(fileName);

    if (extension.length() > 10 || extension.compare("") == 0)
        return result;

    result = dictionary[extension];
    if (result.compare("") != 0)
        return result;
    return "UNKNOWN";
}

string mimeFinder::getExtension(string fileName)
{
    unsigned int extensionStart = fileName.find_last_of(".");

    if (extensionStart == string::npos || extensionStart == 0)
        return "";
    else
        return fileName.substr(extensionStart + 1);
}
