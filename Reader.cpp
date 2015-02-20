#ifndef READER_CPP
#define READER_CPP
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
//                                  This Is A Controller class of MVC.
#include "Letter.cpp"
#include "Display.cpp"
using namespace std;
class Reader
{
               int num_of_wrong_guesses; 
        char letter; 
        Storage *st;
public:
        Reader();
        char entered[100];
        int index;
		int iv;       
        int whilemethod();
        string show1;
        string show2;
        string show5;
        string show6;
};
Reader::Reader() {
    show1="Whoops! That letter isn't in there!";
    show2="You found a letter! Isn't that exciting!";
    show5="yeah! you got it!!!";
    show6="\nSorry, you lose...you've been hanged.";
	index = 0;
    memset(entered, 0, 100);
}

int Reader::whilemethod()
{
    iv =0;
    num_of_wrong_guesses =0;
     st = Storage::getInstance();

    Letter l2;
    Display *d1 = Display::getInstance();
                                                       //Abstract Factory Use of Display class which is VIew.  
    DisplayTypes *dtype = new DisplayTypes();
    DisplayGotWordOrder *dwo = new DisplayGotWordOrder (dtype);
    DisplayMaskOrder *dmo = new DisplayMaskOrder (dtype);
    Agent *agent = new Agent();
    

    int temp =st->Getmaxtries();    //get max tries from storage class.
        while (num_of_wrong_guesses < temp)//loop untill guesses are used up.
			{
                                    
                agent->placeOrder(dmo);		
                 letter=d1->inputletter();
                 entered[index++]=letter;
// Fill secret word with letter if the guess is correct,
// otherwise increment the number of wrong guesses.
				if (l2.letterFill(letter)==0)
					{
						d1->display_op(show1);
                      	num_of_wrong_guesses++;
						DispGallow* dg = GallowFactory::getGallow(num_of_wrong_guesses);
						dg->display_gallows();
		
					}
				else
					{   
                        d1->display_op(show2);
						
					}
					     d1->printEnteredLetters(entered);
// Tell user how many guesses has left.
				         cout << "You have " << temp - num_of_wrong_guesses;
				         cout << " guesses left." << endl;
// Check if user guessed the word.
				if (l2.matchWord())
					{
                        agent->placeOrder(dwo);
                        d1->display_op(show5);
												break;
					}
			}
				if(num_of_wrong_guesses == temp)
					{
                                        d1->display_op(show6);
					
					agent->placeOrder(dwo);
    //                cout << "The word was : " << gotword << endl;
					}
	cin.ignore();
	cin.get();
	return 0;
}	   

#endif
