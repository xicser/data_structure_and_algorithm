#ifndef __KMP_H__
#define __KMP_H__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> KMP_Check(string text, string pattern, bool *hasFound);
vector<int> KMP_Check(char *text, char *pattern, bool *hasFound);


#endif // __KMP_H__
