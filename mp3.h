#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node  {
  char* artist;
   char* album;
  char* song;
  char* date;
  int runTime;
  struct Node* next;
  struct Node* prev;
};


void PlaceInFront(char* artist, char* album, char* song, char* date, int runTime);
void PlaceInBack(char* artist, char* album, char* song, char* date, int runTime);
void PrintForward(); 
void PrintBackwards() ;
void delete(char* artist);


