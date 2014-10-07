#include <iostream>
#include <string>

using namespace std;

class IdentifyingWood {
    public:
        string static check(const std::string& s, const std::string& t);
};

string IdentifyingWood::check(const string& s, const string& t)
{
    int s_len = s.length();
    int t_len = t.length();

    int i=0, j=0;
    while (i<s_len && j<t_len) {
        if(s[i] == t[j]) { 
            i++;
            j++;
        } else {
            i++;
        }
    }
    if(j==t_len) return "Yep, it's wood.";
    return "Nope.";
}

int main(int argc, char** argv)
{
    cout << IdentifyingWood::check("absdefgh", "asdf") << endl;
    cout << IdentifyingWood::check("oxoxoxox", "ooxxoo") << endl;
    cout << IdentifyingWood::check("oxoxoxox", "xxx") << endl;
    cout << IdentifyingWood::check("qwerty", "qwerty") << endl;
    cout << IdentifyingWood::check("string", "longstring") << endl;

    return 0;
}
