#include <iostream>
#include <string>
#include <cwctype>
#include <cctype>
#include <iomanip>
#include "ctype.h"
#include <fstream>
#include "mylist.h"
#include "timer.h"

using namespace std;


string CleanWord(string word)
{
    int wordCount(0);
    string holder = "";
    
    while(wordCount < word.length())
    {
    if (iswalnum(word[wordCount]) || word[wordCount] == ('\''))     
        holder += (char)tolower(word[wordCount]); 

    wordCount++; 
    }

    return holder;
}

void dictListLoad(myList<string>& d)
{ 
    ifstream read; string tmp;
    read.open("dict.txt");
    read >> tmp;
    while(!read.eof())
    {
        d.insert(CleanWord(tmp));
        read >> tmp;
    }
    
    read.close();
}


int main(){

    Timer t;
    myList<string> dictionary;
    int wordsFound(0);  int wordsNotFound(0); int wordsNotChecked(0); long int wfCompares(0); long int wnfCompares(0);

    dictListLoad(dictionary);
    
    t.Start();
    ifstream read; string bookWrd;
    read.open("book.txt");
    read >> bookWrd;
    while(!read.eof())
    {
      string tmp = CleanWord(bookWrd);
        if (tmp.length() > 0)
        {
            if (isalpha(tmp[0]))
            {
                if(dictionary.find(tmp, wfCompares, wnfCompares))
                {
                    wordsFound++;
                }
                else wordsNotFound++;
            }
            else wordsNotChecked++;
        }  
     read >> bookWrd;      
    }
    read.close();
    t.Stop();

    cout << "Dictionary size: " << dictionary.getSize() << endl;
    cout << "Done checking and these are the results:\n";
    cout << "Finished in time: " << t.Time() << endl;
    cout << "There are " << wordsFound << " words found in the dictionary\n";
    cout << "\t" << wfCompares << " compares. Average: " << wfCompares/wordsFound << endl;
    cout << "There are " << wordsNotFound << " words NOT found in the dictionary\n";
    cout << "\t" << wnfCompares << " compares. Average: " << wnfCompares/wordsNotFound << endl;
    cout << "There are " << wordsNotChecked << " words not checked.\n";

    return 0;

}
