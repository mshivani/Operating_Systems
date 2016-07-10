#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>


main(int argc, char* argv[]) {

  int size = 5000;
  int oflags = 0644;
  int source; 
  int destination;  
  char buffer[size];
  ssize_t input;
  ssize_t output;
  source = open (argv [1], O_RDONLY);
  destination = open(argv[2], O_WRONLY | O_CREAT, oflags);

   if(argc != 3){
        printf ("Please input only two file names: Original Destination");
    }

    if (source == -1) {
        perror ("open");
    }

    if(destination == -1){
        perror("open");
    }    

    while((input = read (source, &buffer, size)) > 0){
            output = write (destination, &buffer, (ssize_t) input);
            if(output != input){
                perror("write");
            }
    }

 
    close (source);
    close (destination);

   return (EXIT_SUCCESS);
}
