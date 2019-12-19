#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXPATH 1000
#define PARTPATH 100

int retrievepathpart(char pathpart[100]);
char path[MAXPATH];

int main()
{
  int c, i=0, r;
  char datafile[PARTPATH];
  FILE *f;
   
   // locate fortune.dat
   strcpy(path, ".:"); // add pwd
   strcat(path, getenv("PATH")); // add system path
   while ((c=retrievepathpart(datafile))) {
    strcat(datafile, "/fortune.dat");
    if ((f=fopen(datafile, "r")))
   break; }
   if (!f) {
    printf("missing fortune.dat file.\n");
   exit(1); }
   // read number of cookies
   while ((c=fgetc(f))!=EOF)
    i+=(c=='\0') ? 1 : 0;
   rewind(f);
   // randomize
   srand(time(NULL)); 
   r=rand() % (i-1) + 1;
   // read to randomly selected cookie
   i=0;
   while (i<r)
    i+=((c=fgetc(f))=='\0') ? 1 : 0;
   // display fortune cookie
   while ((c=fgetc(f))!='\0')
    putchar(c);
   fclose(f);
   
  return 0;
}

// retrieve path part
int retrievepathpart(char pathpart[])
{
  int i1=0;
  static int i;
  
  if (i==strlen(path))
   return 0;
   
   while (path[i]!=':' && i<strlen(path))
    pathpart[i1++]=path[i++];
   ++i; // for next operation
   pathpart[i1]='\0';
  
 return 1;
}
