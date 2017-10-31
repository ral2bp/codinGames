#ifndef SRC_MIMEFINDER_H_
#define SRC_MIMEFINDER_H_

#include <string>
#include <map>

using namespace std;

class mimeFinder {
public:
	mimeFinder(map<string,string> dictToUse) : dictionary(dictToUse){}
	string findMimeType(string filename);

private:
	map<string, string> dictionary;
};

#endif /* SRC_MIMEFINDER_H_ */
