#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'checkMagazine' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY magazine
 *  2. STRING_ARRAY note
 */

                      
void checkMagazine(vector<string> magazine, vector<string> note) 
{
    std::map<string, int> mapMagazine, mapNote;
    
    for (int i = 0; i < magazine.size(); ++i)
    {
        std::map<string, int>::iterator it = mapMagazine.find(magazine[i]); 
        if (it != mapMagazine.end())
        {
            it->second++;
        }
        else 
        {
            mapMagazine.insert(std::make_pair(magazine[i], 1));
        }
    }
    
    for (int j = 0; j < note.size(); ++j)
    {
        std::map<string, int>::iterator it = mapNote.find(note[j]); 
        if (it != mapNote.end())
        {
            it->second++;
        }
        else 
        {
            mapNote.insert(std::make_pair(note[j], 1));
        }
    }
    
    /*
    for(auto x: mapMagazine){
    cout<<x.first<<" "<<x.second<<endl;}
    
    for(auto x: mapNote){
    cout<<x.first<<" "<<x.second<<endl;}*/
    
    bool result = true;
    std::map<string,int>::iterator iter = mapNote.begin();
    while(iter != mapNote.end() && result)
    {
        //cout << iter->first << iter->second<<endl;
        if (mapMagazine.find(iter->first) != mapMagazine.end())
        {
            // Check if values are equal
            std::map<string,int>::iterator iterMag = mapMagazine.find(iter->first);
            //cout << iterMag->first << iterMag->second<<endl;
            if(iter->second <= iterMag->second)
            {
                result = true;
            }
            else
            {
            result = false;
            }
        }
        else 
        {
            result = false;
            break;
        }    
     iter++;   
    }
    if(result)
    {
        cout << "Yes";
    }
    else {
    cout << "No";
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split(rtrim(magazine_temp_temp));

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split(rtrim(note_temp_temp));

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
