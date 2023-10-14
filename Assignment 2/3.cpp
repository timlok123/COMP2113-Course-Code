#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //I include this to check whether the character is uppercase
#include <sstream> //split the space in a line

using namespace std;

// Search for a word w in a file named fn
// word: word to search for
// fn: name of file to search
// nLines: (output) number of lines w appear in fn
// total: (output) total number of occurrences of w in fn
// return 0 if file operation is successful
// return 1 otherwise
int SearchWord(string word, string fn, int &nLines, int &total)
{

 ifstream fin;
 fin.open(fn.c_str());

 //Return 1 if we cannot open the file
 if (fin.fail()) return 1;

 else{
   //convert the input string to lowercase
   for(int i=0; i<word.length();i++){
     if (isupper(word[i])){
       word[i] = word[i] + ('a'-'A');
     }
   }

  string line;
  while(getline(fin,line)){
    int temp_total = total;

    //Convert all the letter in a line to lowercase first
    for(int i=0; i<line.length();i++){
      if (isupper(line[i])){
        line[i] = line[i] + ('a'-'A');
      }
    }

    //Split the line by white space
    istringstream line_in(line);
    string s;

    //Add 1 if there are words matching the search word
    while(line_in>>s){
      if(word == s) total +=1;
    }

    //Add 1 if the total change in the process(word match)
    if(temp_total != total) nLines+=1;
  }

}

 fin.close();
 return 0;

}



// argc is the number of arguments from the command line
// argv[0] == program name
// argv[1..argc-1] are the arguments
// e.g., if this program's name is "prog" and the following command is run
// at the command prompt:
// > ./prog word file1 file2
// then in the main function, argc is 4, and argv[0] is "./prog",
// argv[1] is "word", argv[2] = "file1", argv[3] = "file2"
//
// usage: ./wordsearch word_to_search file1 file2 files3 ...
//
int main(int argc, char* argv[])
{
  if (argc < 3) {
    cout << "usage: " << argv[0] << " [word_to_search] [file1] [file2] [file3]...\n";
    exit(1);
  }

  string word = argv[1];  // word to search for

  // loop through all the filenames in the command line argumentp
  for (int i = 2; i < argc; ++i) {
    string filename = argv[i];
    int lineCount=0, totalCount=0;
    // search word in file
    if (SearchWord(word, filename, lineCount, totalCount))
      cout << filename << ": error opening file" << endl;
    else
      cout << filename << ": " << lineCount << " " << totalCount << endl;
  }


  return 0;

}
