#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    // Char: Freq
    // Add 1 if in A, subtract 1 if in B
    // Sum of fre is number of deletions
    std::map<char, int> mapCommon;
    
    for (int i = 0; i < a.size(); ++i)
    {
        std::map<char, int>::iterator it = mapCommon.find(a[i]); 
        if (it != mapCommon.end())
        {
            it->second++;
        }
        else 
        {
            mapCommon.insert(std::make_pair(a[i], 1));
        }
    }
    
    for (int j = 0; j < b.size(); ++j)
    {
        std::map<char, int>::iterator it = mapCommon.find(b[j]); 
        if (it != mapCommon.end())
        {
            it->second--;
        }
        else 
        {
            mapCommon.insert(std::make_pair(b[j], -1));
        }
    }
    
    // Debugging
    /*
    for(auto x: mapCommon){
    cout<<x.first<<" "<<x.second<<endl;
}*/
int result = 0;
for(auto x: mapCommon)
{
    result += abs(x.second);
}
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
