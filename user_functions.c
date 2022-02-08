#include <stdio.h>
#include <stdlib.h>

/* function declaration */
void adduser(int *userid);

int main()
{
   int *userid;
   char[] newAttribute;

    /**Just put a main togther, not sure where we want to execute these functions from*/

    if(option == adduser)
    {
        printf("Enter New User ID: ");
        scanf("%d",&userid);
        adduser(&userid);
    }
    
    if(option == modifyuser)
    {
        printf("Enter Userid to Modify: ");
        scanf("%d", &userid);
        modifyuser(&userid);
    }
    
    if(option == deleteuser)
    {
        printf("Enter Userid to Delete: ");
        scanf("%d", &userid);
        deleteUser(&userid);
    }
    

   return 0;
}

void adduser(int *userid) {

   //Set up and open file
   FILE *fptr;
   
   // make sure file exists
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   fptr = fopen("test.txt", "w");
   
   if(userExists(&userid) == false)
   {

    if(&userid )
   //write to file
   fprintf(fptr,"%d",userid);
   
   //close file
   fclose(fptr);

   printf("User ID was successfully added.\n");

   return 0;
   }
   else
   {
         printf("User Already Exists!");   
   }
}


//MODIFYUSER https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-9.php
// Great example for rewriting lines in a text file... 


#include <stdio.h>
#include <string.h>

#define MAX 256

  int main() 
  {
        FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[MAX],fname[MAX];        
        char newln[MAX], temp[] = "temp.txt";
        
        printf("\n\n Replace a specific line in a text file with a new text :\n");
        printf("-------------------------------------------------------------\n"); 
        printf(" Input the file name to be opened : ");
        fgets(fname, MAX, stdin);
        fname[strlen(fname) - 1] = '\0';
        fptr1 = fopen(fname, "r");
        if (!fptr1) 
        {
                printf("Unable to open the input file!!\n");
                return 0;
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2) 
        {
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
        }
        /* get the new line from the user */
        printf(" Input the content of the new line : ");
        fgets(newln, MAX, stdin);
        /* get the line number to delete the specific line */
        printf(" Input the line no you want to replace : ");
        scanf("%d", &lno);
        lno++;
         // copy all contents to the temporary file other except specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                linectr++;
                if (linectr != lno) 
                    {
                        fprintf(fptr2, "%s", str);
                    } 
                    else 
                    {
                        fprintf(fptr2, "%s", newln);
                    }
                }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);
        printf(" Replacement did successfully..!! \n");
        return 0;
  }
  
  
 //DELETEUSER https://www.sanfoundry.com/c-program-delete-line-text-file/
  /*
 * C Program Delete a specific Line from a Text File
 */
#include <stdio.h>
 
int main()
{
    FILE *fileptr1, *fileptr2;
    char filename[40];
    char ch;
    int delete_line, temp = 1;
 
    printf("Enter file name: ");
    scanf("%s", filename);
    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
 `  while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen("replica.c", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
            temp++;
            //except the line to be deleted
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
    printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}

