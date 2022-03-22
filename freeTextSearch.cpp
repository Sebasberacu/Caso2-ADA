#include "libs.h"

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
/* C program for Boyer Moore Algorithm with
Good Suffix heuristic to find pattern in
given text string */

// preprocessing for strong good suffix rule
void preprocess_strong_suffix(int *shift, int *bpos, string pat, int m)
{
	// m is the length of pattern
	int i=m, j=m+1;
	bpos[i]=j;

	while(i>0)
	{
		/*if character at position i-1 is not equivalent to
		character at j-1, then continue searching to right
		of the pattern for border */
		while(j<=m && pat[i-1] != pat[j-1])
		{
			/* the character preceding the occurrence of t in
			pattern P is different than the mismatching character in P,
			we stop skipping the occurrences and shift the pattern
			from i to j */
			if (shift[j]==0)
				shift[j] = j-i;

			//Update the position of next border
			j = bpos[j];
		}
		/* p[i-1] matched with p[j-1], border is found.
		store the beginning position of border */
		i--;j--;
		bpos[i] = j;
	}
}

//Preprocessing for case 2
void preprocess_case2(int *shift, int *bpos, string pat, int m)
{
	int i, j;
	j = bpos[0];
	for(i=0; i<=m; i++)
	{
		/* set the border position of the first character of the pattern
		to all indices in array shift having shift[i] = 0 */
		if(shift[i]==0)
			shift[i] = j;

		/* suffix becomes shorter than bpos[0], use the position of
		next widest border as value of j */
		if (i==j)
			j = bpos[j];
	}
}

/*Search for a pattern in given text using
Boyer Moore algorithm with Good suffix rule */
vector <int> search(string text, string pat)
{
	// s is shift of the pattern with respect to text
    vector <int> occurrences;
	int s=0, j;
	int m = pat.length();
	int n = text.length();

	int bpos[m+1], shift[m+1];

	//initialize all occurrence of shift to 0
	for(int i=0;i<m+1;i++) shift[i]=0;

	//do preprocessing
	preprocess_strong_suffix(shift, bpos, pat, m);
	preprocess_case2(shift, bpos, pat, m);

	while(s <= n-m)
	{

		j = m-1;

		/* Keep reducing index j of pattern while characters of
			pattern and text are matching at this shift s*/
		while(j >= 0 && pat[j] == text[s+j])
			j--;

		/* If the pattern is present at the current shift, then index j
			will become -1 after the above loop */
		if (j<0)
		{
			//printf("pattern occurs at shift = %d\n", s);
            occurrences.push_back(s);
			s += shift[0];
		}
		else
			/*pat[i] != pat[s+j] so shift the pattern
			shift[j+1] times */
			s += shift[j+1];
	}
    return occurrences;

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
// int main()
// {
// 	auto start = high_resolution_clock::now();
//     sendSearch("");
// 	auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<milliseconds>(stop - start);
//     cout << "Time taken by function: " << duration.count() << " miliseconds" << endl;
// 	return 0;
// }

