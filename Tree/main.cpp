#include <iostream>
#include <string>
#include <cwctype>
#include <cctype>
#include <iomanip>
#include "ctype.h"
#include <fstream>
#include "binarysearchtree.h"
#include "timer.h"
#include <vector>

using namespace std;

// This function cleans the word that is passed and then returns it
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

int main(){
    // Variable Declatation
    Timer t;
    BinarySearchTree<string> dictionary;
    vector<string> misspelled;
    ifstream read; string bookWrd;
    int wordsFound(0);  int wordsNotFound(0); int wordsNotChecked(0); long long int wfCompares(0); long long int wnfCompares(0);

    // This loads the dicionary into the Trees
    read.open("dict.txt");
    string tmp;
    read >> tmp;
    while(!read.eof())
    {
        dictionary.insert(CleanWord(tmp));
        read >> tmp;
    }  
    read.close();

    // Spellchecker Start
    t.Start(); // Timer Start
    read.open("book.txt");
    read >> bookWrd;
    while(!read.eof())
    {
      string tmp = CleanWord(bookWrd);
        if (tmp.length() > 0) // If the Word is Not Nothing
        {
            if (isalpha(tmp[0])) // If the First Letter is a Letter
            {
                if(dictionary.find(tmp, wfCompares, wnfCompares)) // If it is Found in the Dicitonary
                {
                    wordsFound++; // Add to Words Found
                }
                else {wordsNotFound++; misspelled.push_back(tmp);} // Add to Words Not Found
            }
            else wordsNotChecked++; // Add to Words Not Checked
        }  
     read >> bookWrd;      
    }
    read.close();
    t.Stop(); // Timer Stop

    // Write Misspelled Words to File
    ofstream write;
    write.open("misspelled.txt");
    for(int i = 0; i < misspelled.size(); i++)
    {
        write << misspelled[i] << endl;
    }
    write.close();

    // Print Results
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