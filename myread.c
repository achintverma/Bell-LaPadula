#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	char str[100];
	FILE *p;
	char *access_flag="1";
		  
	int record_found = 0;
	int has_read_access = 0;
		  
	if((p=fopen("permissions.txt","r"))==NULL)
	{
		printf("\nUnable to access permissions file");
		exit(1);
	}
	
	// reading 1 line at a time 
	while(fgets(str,100,p)!=NULL)
	{
		
		  char * pch;
		  pch = strtok (str,"#");
		  char *access_list[4];
		  int i=0; 
		  
		  
		  // read one record into a access record 
		  while (pch != NULL)
		  {
			
			access_list[i++] = pch;
			//printf ("%s\n",pch);
			pch = strtok (NULL, "#");
			
		  }
		  
		  
		  
		  // process access record to check if user has access to the file 
		  char *filename = argv[1];
		  
		  if(strcmp(access_list[0],filename)==0)
		  {
			//printf("\nFile Access Record Found\n");
			
			// convert user ID into a string
			char user_id[10];
			sprintf(user_id,"%d",getuid());
			
			// compare if the user access rule for this file is present 
			if(strcmp(access_list[1],user_id)==0)
			{
				
				record_found = 1;
				// check access flags for permissions 
				char *read_access = access_list[2];
				
				
				if(strcmp(access_flag,read_access)==0)
				{
					//printf("User has read access\n");
					has_read_access = 1;
					
					
				}
				
				
			}
		  }
		  
		  
		  
	}
	
	if(record_found)
	{
		if(has_read_access)
		{
				FILE *file = fopen( argv[1], "r" );
					
					int x;
					/* read one character at a time from file, stopping at EOF, which
					   indicates the end of the file.  Note that the idiom of "assign
					   to a variable, check the value" used below works because
					   the assignment statement evaluates to the value assigned. */
					while  ( ( x = fgetc( file ) ) != EOF )
					{
						printf( "%c", x );
					}
					
					printf("\n");
					
					fclose( file );
		}
		else
			printf("Error: You do not have read access to the file\n\n");
			
		
	
	}
	else
		printf("Error: File permission record not found hence you can not be granted permission to access the file.\n\n");
	
	
	
	fclose(p);
	return 0;
}
