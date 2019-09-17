#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *datafile[]={ "fortune.dat", "~/fortune.dat", "~/bin/fortune.dat", "/usr/bin/fortune.dat", "/usr/include/fortune.dat" };

int main()
{
  int i=0;
  char c;
  FILE *f;
  
   while (!f && datafile[i])
    f=fopen(datafile[i++], "r");
   if (!f) {
    printf("missing fortune.dat file.\n");
   exit(-1); }
   srand(time(NULL)); 

   i=0;
   while (c!=EOF) {
    c=fgetc(f);
    if (c=='\0') 
   ++i; }
   rewind(f);
   
   int r=rand() % (i-1) + 1;
   i=0;
   while (i<r) {
    c=fgetc(f);
    if (c=='\0')
   ++i; }
   c='.';
   while (c!='\0' && c!=EOF) {
    c=fgetc(f);
   putchar(c); }

  return 0;
}

