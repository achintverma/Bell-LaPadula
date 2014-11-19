#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	char str[100];
	char strg[100];
	FILE *p;
	FILE *q;
		  
	int record_found = 0;
	int access_level_found = 0;
	int has_read_access = 0;
	int file_permit;
	int access_level;
	
	int i;
	char *access_levels[2];
	char *access_permissions[2];
		  
	if((p=fopen("BLP_user_levels.txt","r"))==NULL)
	{
		printf("\nUnable to access access levels file");
		exit(1);
	}
	
	// Find security level of current user 
	while(fgets(str,100,p)!=NULL)
	{
		
		  char *pch;
		  pch = strtok (str,"#");
		  
		  i=0; 
		  
		  
		  // read one line into array (access record)
		  while (pch != NULL)
		  {
			
			access_levels[i++] = pch;
			//printf ("%s\n",pch);
			pch = strtok (NULL, "#");
			
		  }
		  
		  // convert user ID into a string
			char user_id[10];
			sprintf(user_id,"%d",getuid());
			
			//printf("user ID: %s\n",user_id);
		  
		  if(strcmp(access_levels[0],user_id)==0)
		  {
			// user access level record found. Lets process it.
			
			access_level_found = 1;
			access_level = atoi(access_levels[1]);  
			
		  }
		  
	}
	fclose(p);
	
	if((q=fopen("BLP_permissions.txt","r"))==NULL)
	{
		printf("\nUnable to access permissions file");
		exit(1);
	}
	
	// Find security level of requested file
	while(fgets(strg,100,q)!=NULL)
	{
		
		  char * qch;
		  qch = strtok(strg,"#");
		  
		  i=0; 
		  
		  
		  // read one line into array (access record)
		  while (qch != NULL)
		  {
			
			access_permissions[i++] = qch;
			//printf ("%s\n",qch);
			qch = strtok (NULL, "#");
			
		  }
		  	  
		  // process access record to check if user has access to the file 
		  char *filename = argv[1];
		  
		  if(strcmp(access_permissions[0],filename)==0)
		  {
			
				record_found = 1;
				// check access flags for permissions 
				file_permit = atoi(access_permissions[1]);
			
				
		  }
		 
	}
				
	printf("File Permit: %d\n",file_permit);
	printf("User Access Level: %d\n", access_level);
				
	// User has access to the file only if its  level is equal or higher than file level
			
	if(file_permit <= access_level)
	has_read_access = 1;
		
	if(access_level_found)
	{
		
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
		
	
	}
	else
		printf("Error: Unauthorized User - Access level not defined.");
	
	
	
	
	
	fclose(p);
	return 0;
}
