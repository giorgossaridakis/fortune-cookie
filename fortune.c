#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *datafile[]={ "fortune.dat", "~/fortune.dat", "~/bin/fortune.dat", "/usr/bin/fortune.dat", "/usr/include/fortune.dat" }; // add fortune.dat locations per se

int main()
{
  int c, i=0, r;
  FILE *f;
   
   // locate fortune.dat
   while (!f && datafile[i])
    f=fopen(datafile[i++], "r");
   if (!f) {
    printf("missing fortune.dat file.\n");
   exit(-1); }
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

