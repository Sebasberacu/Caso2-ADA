#include "libs.h"

//from: https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

string importText(){
    fstream file;
    string result = "";
    file.open("text.txt",ios::in);
    if (file.is_open()){
        string tp = "";
        while(getline(file,tp)){
            result+=tp;
        }
        file.close();
    }
    return result;
}

// prints all occurrences of pattern in text using Z algo
vector <int> search(string text, string pattern)
{
	vector <int> res;
	string concat = pattern + "$" + text;
	int l = concat.length();

	int Z[l];
	getZarr(concat, Z);

	for (int i = 0; i < l; ++i)
	{
		if (Z[i] == pattern.length())
			res.push_back(i - pattern.length() -1);
	}
	return res;
}

// Fills Z array for given string str[]
void getZarr(string str, int Z[])
{
	int n = str.length();
	int L, R, k;

	L = R = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R<n && str[R-L] == str[R])
				R++;
			Z[i] = R-L;
			R--;
		}
		else
		{
			k = i-L;
			if (Z[k] < R-i+1)
				Z[i] = Z[k];
			else
			{
				L = i;
				while (R<n && str[R-L] == str[R])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
}

void sendSearch(string pattern){
    string text = importText();
	vector <int> foundAt = search(text, pattern);
    int foundAtSize = foundAt.size();
    for (int i = 0 ; i < foundAtSize ; i++){
        string found="";
        int foundAtPosition = foundAt.at(i);
        int count = 0;
        while (text[foundAtPosition+count]!=32){
            found+=text[foundAtPosition+count];
            count++;
        }
        cout << found << endl;

    }
}


