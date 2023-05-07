#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_SUCCESS 0
void save_text(char *text, char *filename)
{
  // check if filename has txt extension
  int filenameLen = strlen(filename);
  if(strcmp(filename + filenameLen - 4, ".txt") != 0 )
  {
    strcat(filename, ".txt");
  }
  FILE* file = fopen(filename, "w");
  if(file)
  {
    fprintf(file, "%s", text);
    printf("File saved");
    fclose(file);
  } 
  else
  {
    printf("Error: could not create a file\n");
  }
}


void input_text(char* text, char* filename)
{
  char c;
  int iterator = 0;
  printf("Write your text\n ");
  while((c = getchar()) != EOF){
    text[iterator++] = c;
    if(c == 'q')
    { 
      break;
    }
    if(c == ' ' || c == '\n')
      continue;
    printf("%d ('%c')", c, c);
  }
  char userChoice;
  printf("You quit the editor, do you want to save [y|n] ");
  scanf("%s", &userChoice);
  if(userChoice == 'Y' || userChoice == 'y')
  {
      printf("Enter filename: \n");
      scanf("%s", filename);
      save_text(text, filename);   
  }
  printf("\nBye\n");
}

void edit_file(void)
{

}

int main(void)
{
  char text[1000];
  char filename[50];

  int userChoice;
  printf("Do you want to write (1) or to edit (2)? ");
  scanf("%d", &userChoice);
  switch (userChoice) 
  {
     case 1:
       input_text(text, filename);
       break;
     case 2:
       printf("This function will be added");
       break;
     default:
       printf("Invalid number");
       break;
  }

  //printf("%s", filename);
  //printf("%s", text);
  return EXIT_SUCCESS;
}
