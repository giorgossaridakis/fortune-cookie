#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXPATH 1000
#define PARTPATH 100

int retrievepathpart(char pathpart[PARTPATH]);
char path[MAXPATH];

int main()
{
  int c, i=0, r;
  char datafile[100];
  FILE *f;
   
   // locate fortune.dat
   strcpy(path, ".:"); // add pwd
   strcat(path, getenv("PATH")); // add system path
   while ((c=retrievepathpart(datafile))) {
    strcat(datafile, "/fortunes.dat");
    if ((f=fopen(datafile, "r")))
   break; }
   if (!f) {
    printf("missing fortune.dat file.\n");
   exit(1); }
   // read number of cookies
   while ((c=fgetc(f))!=EOF)
    i+=(c=='%') ? 1 : 0;
   rewind(f);
   // randomize
   srand(time(NULL)); 
   r=rand() % (i-1) + 1;
   // read to randomly selected cookie
   i=0;
   while (i<r)
    i+=((c=fgetc(f))=='%') ? 1 : 0;
   // display fortune cookie
   fgetc(f); // read newline
   while ((c=fgetc(f))!='%' && f)
    putchar(c);
   fclose(f);
   
  return 0;
}

// retrieve path part
int retrievepathpart(char pathpart[])
{
  int i1=0;
  static int i=0;
  
  if (i1==strlen(path))
   return 0;
   
   while (path[i]!=':' && i<strlen(path))
    pathpart[i1++]=path[i++];
   ++i; // for next operation
   pathpart[i1]='\0';
   
 return 1;
}
