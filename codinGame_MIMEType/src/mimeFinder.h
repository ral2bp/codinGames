#ifndef SRC_MIMEFINDER_H_
#define SRC_MIMEFINDER_H_

#include <string>
#include <map>

using namespace std;

class mimeFinder {
public:
    mimeFinder()
    {

    }

    mimeFinder(map<string,string> dictToUse) : dictionary(dictToUse)
    {

    }
    string findMimeType(string filename);

private:
    string getExtension(string fileName);
    map<string, string> dictionary;
};

#endif /* SRC_MIMEFINDER_H_ */
