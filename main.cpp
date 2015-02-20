#ifndef MAIN_CPP
#define MAIN_CPP
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Reader.cpp"
using namespace std;
int main()
{

	Reader r1;
	r1.whilemethod();          //start the game with reader class's method.
     //system("pause");       //uncommnent this command if you are testing project with DEV C++.
	 return 0;
}

#endif
