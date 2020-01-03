#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "list.h"
int main() {
   int c;
   char command[50];
   create();
   FILE *fp;
   char x[1850];		// getting a line from txt, length to 1850
   fp=fopen("a.txt","r");	// opening the file read only
   while((c = fgetc(fp)) != EOF){	// reading the file to end
      fscanf(fp,"%[^\n]",x);		// getting a line to 'x' char array
      add(x);				// sending food list to insert node add 
   }
   strcpy(command,"./script.sh");
   system(command);
   printf("shows that menu of the day.");
   printList();		
   fclose(fp);
   

   
   return 0;
}    
