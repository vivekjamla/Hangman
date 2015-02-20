#ifndef STORAGE_CPP
#define STORAGE_CPP

                    //This is a Model class which implements SINGLETON.
                    //Constructor is private so we have to call getInstance method to get object of class.
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdlib>
#include<fstream>
#include <ctime>
#include <string>
using namespace std;
class Storage
 {
    string word; 
    int MAX_TRIES;
	Storage();         
    static Storage* instance;
	public:
	static Storage* getInstance();
	string getWord();                        //Accessor Pattern
    int Getmaxtries();
   
};

Storage* Storage::instance = NULL;

Storage::Storage() //constructor..gets the random word from file.
					//i have to make this class as singleton because if we make object twice it will get us another word . and game will messed up.
{
    long length;
    std::ifstream is ("gsl.txt");   //word File.....
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    length = is.tellg();
    is.seekg (0, is.beg);
    srand(time(0));
   long num = rand()%length + 1;
    int i = 0;
      while( i!=num)
      {
       is >> word;
        ++i;
       }
       //cout<<word<<endl;
     // did we fine the right word?
    if( i != num )
    {
         // not that many words in the file.  so just bail out
         cout << "only "  << " words in the file." << endl;
    }
    
}
is.close();
} 

// this is a public mathod which can get you private variable named word.
//Accessor pattern.

string Storage::getWord() //return original word.
{  
	//cout<<endl<<"got word is:"<<word;   
	return word;
}
int Storage::Getmaxtries()
{
    MAX_TRIES=6;
return MAX_TRIES;
}

Storage* Storage::getInstance() {
    if(instance==NULL) {                           //if Object is generarated before then return that same or generate one.
        instance = new Storage();
    } 
    //else{
      //   cout<<"returning existing";
        // }                  
    return instance;                   
}
 
#endif
