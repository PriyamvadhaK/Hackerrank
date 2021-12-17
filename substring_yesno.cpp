#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

string twoStrings(string s1, string s2)
{
    std::map<char, int> mapS1, mapS2;
    for (int i = 0; i < s1.size(); ++i)
    {
        std::map<char, int>::iterator it = mapS1.find(s1[i]); 
        if (it != mapS1.end())
        {
            it->second++;
        }
        else 
        {
            mapS1.insert(std::make_pair(s1[i], 1));
        }
    }
    
    for (int i = 0; i < s2.size(); ++i)
    {
        std::map<char, int>::iterator it = mapS2.find(s2[i]); 
        if (it != mapS2.end())
        {
            it->second++;
        }
        else 
        {
            mapS2.insert(std::make_pair(s2[i], 1));
        }
    }
    bool result = false;
    std::string resultString;
    for(std::map<char,int>::iterator iter = mapS1.begin(); iter != mapS1.end(); ++iter)
    {
        char k =  iter->first;
        std::map<char,int>::iterator iterS2 = mapS2.find(k);
        //cout << iter->first << iter->second << endl << iterS2->first << iterS2->second << endl;
        if (iterS2 != mapS2.end())
        {
           if(iter->second > 0 && iterS2->second > 0 && (iter->second > (iterS2->second || iterS2->second > iter->second)))
           {
               result = result || true;
           }
           else 
           {
               result = result || false;
           }
        }
    }
    if(result)
    {
        resultString = "YES";
    }
    else {
    resultString = "NO";
    }
    return resultString;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

