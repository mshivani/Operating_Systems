
#include "mp3.h"

struct Node *head, *tail;
int MAX_LENGTH = 256;


struct Node* GetNewNode(char* artist, char* album, char* song, char*  date, int runTime) {

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->artist = malloc(sizeof(artist)+1);
  newNode->album = malloc(sizeof(album)+1);
  newNode->song = malloc(sizeof(song)+1);
  newNode->date = malloc(sizeof(date)+1);
  strcpy(newNode->artist, artist);
  strcpy(newNode->album, album);
  strcpy(newNode->song, song);
  strcpy(newNode->date, date);

  newNode->runTime = runTime;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}



void PlaceInBack(char* artist, char* album, char* song, char* date, int runTime){

struct Node* temp = head;
struct Node* newNode = GetNewNode(artist, album, song, date, runTime);

if(head == NULL) {
head = newNode;
return;
}

while(temp->next != NULL)
 { 
   temp = temp->next;
 }

temp->next = newNode;
newNode->prev = temp;

}


void PrintForward() {

struct Node* temp = head;
printf("Forward: ");
while(temp != NULL) {
 printf("%s %s %s %s %d  \n",temp->artist, temp->album, temp->song, temp->date, temp->runTime);
 temp = temp->next;
}
}

 

void PrintBackwards() {

struct Node* temp = head;

if(temp == NULL){
 return; 
}

while(temp->next != NULL) {
temp = temp->next;
}

printf("Backwards: ");

while(temp != NULL) {
 printf("%s %s %s %s %d  \n",temp->artist, temp->album, temp->song, temp->date, temp->runTime);
temp = temp->prev;
}

//	printf("\n");
}


void delete(char* artist)
{
  printf("inside delete");
  struct Node *temp = head;
  struct Node *temp2;
  
  /*int i =0;*/
  while(temp->next!=NULL) {
     printf("inside while");
    if(temp == head  && (strcmp(temp->artist, artist))==0){
      printf("inside if temp == head");
      temp->next->prev = head->prev;
      head = temp->next;
      temp2 = temp;
      temp=temp->next;
      free(temp2->artist);
      free(temp2->album);
      free(temp2->song);
      free(temp2->date);
      free(temp2);
      
    }
    else if((strcmp(temp->artist, artist))==0) {
      printf("inside else if temp prev not null");
      temp->next->prev = temp->prev;
      temp->prev->next=temp->next;
      temp2 = temp;
      temp = temp->next;
      free(temp2->artist);
      free(temp2->album);
      free(temp2->song);
      free(temp2->date);
      free(temp2);
    }
     else{
        printf("inside else no equal");
      temp = temp->next;
      }	 	 
  }
  
  if( (strcmp(temp->artist, artist))== 0){
    printf("last node");
    temp->prev->next = temp->next;
    //tail = temp->prev;
    //temp2 = temp;
    free(temp->artist);
      free(temp->album);
      free(temp->song);
      free(temp->date);
    free(temp);
  }
  //  free(temp);
}




int main() {
  

  head = NULL; 
  char buf[MAX_LENGTH];
  int i;
  //char * scanAloc = (char *) malloc(sizeof(char)*256);
  char * artist = (char *) malloc(sizeof(char)*256);
  char * album = (char *) malloc(sizeof(char)*256);
  char * song = (char *) malloc(sizeof(char)*256);
  char * date = (char *) malloc(sizeof(char)*256);
  char * time = (char *) malloc(sizeof(char)*256);
  // char * artist2 = (char *) malloc(sizeof(char)*256);
  char * name = (char *) malloc(sizeof(char)*256);
  int timeInput;
  
  do{
    printf("Enter a number:\n 1) add MP3 data to the list \n 2) delete MP3 data to the list? \n 3) Print the list form begenning to end \n 4) print the list from end to begenning \n");
    fgets(buf, sizeof(buf), stdin);
    i = atoi(buf);
    if(i<=0){
      printf("Choose a valid Option");
    }
   
    
    else {
      switch(i)
{
 
case 1:
 printf("\noption 1 selected\n");
 printf("Enter name of artist: ");
 fgets(artist,10,stdin);
 printf("Enter name of album: ");
 fgets(album,10,stdin);
 printf("Enter name of song: ");
 fgets(song,10,stdin);
 printf("Enter release date of song: ");
 fgets(date,10,stdin);
 printf("Enter run time of song in seconds: ");
 fgets(time,10,stdin);
 timeInput = atoi(time + 0);
 PlaceInBack(artist, album, song, date, timeInput);
 //PrintForward();
 //PrintBackwards();
 break;
 
case 2: 
 
 printf("\noption 2 selected\n");
 printf("Enter name of artist: ");
 fgets(name,256,stdin);
 printf("information");
 delete(name);
 //PrintForward();
 break;
 
 case 3: PrintForward(); break;
 case 4: PrintBackwards(); break;
 default:printf("Invalid option\n"); break;
 }
      
    }
    char buf2[MAX_LENGTH];

    printf("\n");
    printf("Enter 1 to continue and any other key to exit the program: "); 
    fgets(buf2, sizeof(buf2), stdin);
    i = atoi(buf2);
    switch(i){
    default: 
       free(artist);
       free(album);
       free(song);
       free(date);
       free(time);
       free(name);

      break;
    }
    
  }while(i==1);
  
}
