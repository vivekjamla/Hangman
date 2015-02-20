#ifndef LETTER_CPP
#define LETTER_CPP
//                             Class Letter::: This is another Model class which compares a letter in original word.
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Display.cpp"
#include "Storage.cpp"
using namespace std;
class Letter 
{
	public:
        Display *d2;
        Storage *st;
        Letter();
        static string vivek;
        static string gotword;   
        int letterFill(char guess);       //to check if letter is in the original word.    
        bool matchWord();
        void displaymask();
        void displaygotword();
};

string Letter::vivek = "";
string Letter::gotword = "";

Letter::Letter() {                       //getting the original word from storage class and initialing mask word with *.
    d2=Display::getInstance();
    st = Storage::getInstance();
    gotword = st->getWord();
    string temp(gotword.length(), '*');
    vivek = temp;    
}

void Letter::displaymask()   //get and display masked word.
{
  d2->display_op(vivek);   
}
void Letter::displaygotword()   // get and display original word.
{
     d2->display_op(gotword);
}
bool Letter::matchWord() {
    return vivek==gotword;    
}


int Letter::letterFill (char guess)
{
	int i;
	int matches=0;
	int len=vivek.length();
		for (i = 0; i< len; i++)
		{	
// Did we already match this letter in a previous guess?
			if (guess == vivek[i])
			return 0;
// Is the guess in the secret word?
			if (guess == gotword[i])
				{
					vivek[i] = guess;
					//cout<<i<<"th word is"<<vivek[i]<<endl;
					matches++;
				}
		}
return matches;
}

//**********************************************************************************

//Commmand Pattern Implemented.


class DispOrder
{                                                                      
  public:
    virtual void execute() = 0;               //Abstract method.
};

// Receiver class.
class DisplayTypes {
    Display *d2;
    public:
    DisplayTypes() {
        d2=Display::getInstance();
    }
    public:
    void displaymask() {
        d2->display_op(Letter::vivek);
    }
    void displaygotword() {
        d2->display_op(Letter::gotword);
    }
};

// Invoker.
class Agent {
    public:    
    void placeOrder(DispOrder *order) {
        order->execute();
    }    
};

class DisplayGotWordOrder:public DispOrder {
    DisplayTypes *dt;  
    public:
    DisplayGotWordOrder ( DisplayTypes *st) {
        dt = st;
    }
    void execute( ) {
        dt->displaygotword();
    }
};

class DisplayMaskOrder:public DispOrder {
    DisplayTypes *dt;  
    public:
    DisplayMaskOrder ( DisplayTypes *st) {
        dt = st;
    }
    void execute() {
        dt->displaymask();
    }
};




#endif
