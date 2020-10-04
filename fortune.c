#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORTUNEFILEPATH "~/fortune.dat" // local bin folder
#define SEPARATIONCHAR '\0'

int main()
{
  int c, cookie=0, cookies;
  FILE *f;
   
   // open data file
   if ((f=fopen(FORTUNEFILEPATH, "r"))==0) {
    printf("missing fortune.dat file.\n");
   exit(EXIT_FAILURE); }
   
   // read number of cookies
   while ((c=fgetc(f))!=EOF)
    cookie+=(c==SEPARATIONCHAR) ? 1 : 0;
   rewind(f);
   
   // randomize
   srand(time(NULL)); 
   cookies=rand() % (cookie-1) + 1;
   
   // read to randomly selected cookie
   cookie=0;
   while (cookie<cookies)
    cookie+=((c=fgetc(f))==SEPARATIONCHAR) ? 1 : 0;
   
   // display fortune cookie
   while ((c=fgetc(f))!=SEPARATIONCHAR && c!=EOF)
    putchar(c);
   fclose(f);
   
  return 0;
}
