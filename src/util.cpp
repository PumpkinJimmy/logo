#include <string>
#include <vector>
using namespace std;
void split(const string& s, char c, vector<string>& items)
{
	items.clear();
	int lpos = 0, pos = 0;
	while (lpos < s.size() && (pos = s.find(c, lpos)) != string::npos)
	{
		if (pos - lpos > 0) items.push_back(s.substr(lpos, pos - lpos));
		lpos = pos + 1;
	}
	if (lpos < s.size()) items.push_back(s.substr(lpos));
}
