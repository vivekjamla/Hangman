U00737546
Vivekkumar Patel
Project 1 Object Oriented Programming & design.
Fall 2014.

Environment ::C++

compile command g++ main.cpp
Run command: ./a.out

There are five Source code files in project.

Storage.cpp
Display.cpp
Letter.cpp
Reader.cpp
main.cpp

Model:
Storage.cpp
Letter.cpp

View:
Display.cpp

Controller:
Reader.cpp

Singleton and Accessor Pattern used in two classes.
Display and Storage.


Command Pattern:
In Letter.cpp file

     class named DispOrder with abstract method of void execute();
     DisplayTypes is a reciever class.
     Agent class is a invoker class.
     DisplyaGotWordOrder and DisplayMaskOrder are derived from base class DispOrder.
 
Factory Pattern:
In Display.cpp file.
   
     virtual method of display_gallows() in DispGallow class.
     Gallow_stage1 to 6 class are derived from DispGallow class.
     GallowFactory class's method getGallow(int state) will instantiate the class according to state.
 

to run program Compile and run "main.cpp" file.