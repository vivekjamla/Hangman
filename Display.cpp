#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include<cstring>           //Display:::this is a View class of MVC. also Implemented the SIngleton pattern in display class.
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class DispGallow
{
  public:
    virtual void display_gallows() = 0;
};

class Gallow_stage1: public DispGallow
{
  public:
    void display_gallows() {
       cout<<endl<<endl 
       <<"   +----+  "<<endl 
       <<"   |    |  "<<endl 
       <<"   |       "<<endl 
       <<"   |       "<<endl 
       <<"   |       "<<endl 
       <<"   |       "<<endl 
       <<"  ============="<<endl<<endl;          
    }         
};

class Gallow_stage2: public DispGallow
{
  public:
    void display_gallows() {
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"  ============="<<endl<<endl; 
    }         
};

class Gallow_stage3: public DispGallow
{
  public:
    void display_gallows() {
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |   /|  "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"  ============="<<endl<<endl; 
   
    }         
};

class Gallow_stage4: public DispGallow
{
  public:
    void display_gallows() {
  cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |   /|\\ "<<endl 
   <<"   |       "<<endl 
   <<"   |       "<<endl 
   <<"  ============="<<endl<<endl; 
   
    }         
};

class Gallow_stage5: public DispGallow
{
  public:
    void display_gallows() {
cout<<endl<<endl 
   <<"   +----+  "<<endl 
   <<"   |    |  "<<endl 
   <<"   |    O  "<<endl 
   <<"   |   /|\\ "<<endl 
   <<"   |     \\ "<<endl 
   <<"   |       "<<endl 
   <<"  ============"<<endl<<endl; 
    }         
};

class Gallow_stage6: public DispGallow
{
  public:
    void display_gallows() {
  // The \\ will translate as '\' because it is a special char 
  cout<<endl<<endl 
   <<"   +----+     "<<endl 
   <<"   |    |     "<<endl 
   <<"   |    O     "<<endl 
   <<"   |   /|\\   "<<endl 
   <<"   |   / \\   "<<endl 
   <<"   |Your Dead "<<endl 
   <<"  ============"<<endl<<endl;
    }         
};

// Abstract Factory Pattern .open to extend, close to change
//IF we have to add new stage in it we dont have to modify whole class we just add one more class of stage.
//
class GallowFactory {
      public:
          static DispGallow* getGallow(int stage) {
                 if(stage==1) {
                     return new Gallow_stage1();
                 }
                 if(stage==2) {
                     return new Gallow_stage2();
                 }
                 if(stage==3) {
                     return new Gallow_stage3();
                 }
                 if(stage==4) {
                     return new Gallow_stage4();
                 }
                 if(stage==5) {
                     return new Gallow_stage5();
                 }
                 if(stage==6) {
                     return new Gallow_stage6();
                 }
          }
};      

class Display                                    //view class.
{
      Display();
      static Display* instance;                 
	public :
	static Display* getInstance();              //get instance of display class.
	char letter;
	char entered[];
	void display_op(string todisplay);          //todisplay any string.
   char inputletter();                          //get input from user.
   void printEnteredLetters(char a[]);            
};
Display* Display::instance = NULL;

void Display::printEnteredLetters(char a[]) {
     cout<<"\n you have entered "<<a<<" ,"<<"\n";
}

Display::Display()      //consructor.
 {
	cout << "\n\nWelcome to hangman...Guess a word";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << "MAX_TRIES of 6" << " to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";                                      
}

char Display::inputletter()
{
     cout<<endl<<"enter a letter";
     cin>>letter;
     return letter;
}
void Display::display_op(string todisplay) //Display string 
{
  
    cout << endl << todisplay <<endl;     
}     
Display* Display::getInstance() {					//singleton .user has to call this method to make an object.
													//if there is an existing object ,it will just return that existing object.
    if(instance==NULL) {
        instance = new Display();
    } 
    //else{
      //   cout<<"returning existing";
        // }                  
    return instance;                   
}
 

#endif
