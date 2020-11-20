#include "fns.h"

void search(CSCICLASS classes[NUM_CLASSES], char mode) {
	char str[STR_LEN]; 					// string variable
	char* token;
	char search_term[STR_LEN]; 				// string for what we're searching for
	switch(mode) {
	case 'N':
	case 'n':
		printf("| Enter class number: ");
		fgets(search_term, STR_LEN, stdin); 		// get the title of the class
		search_term[strlen(search_term)-1] = '\0'; 	// delete the \n from the string
		for(int i = 0; i < NUM_CLASSES; i++) { 		// for each classe in the array
			// check if the search term = the title of the class
			// if it does, print off the class
			if(strcmp(search_term, classes[i].title) == 0) display(classes[i]);
		}
		break;
	case 'D':
	case 'd':
		printf("| Enter class days to print (MWF or TR): ");
		scanf("%s%*c", search_term); 			// retrieve the string, throwing away the \n character
		for(int i = 0; i < NUM_CLASSES; i++) { 		// for each class in the array
			strcpy(str, classes[i].times); 		// get a copy of the times string
			token = strtok(str, " "); 		// parse it using strtok
						  		// this way token is just equal to MWF or TR
			if(token == NULL) break;  		// error handling
			// check if the token is the same thing as the search term
			// if it is, display the class
			if(strcmp(search_term, token) == 0) display(classes[i]);
		}
		break;
	case 'P':
	case 'p':
		printf("| Enter Professor's Last Name: ");
		scanf("%s%*c", search_term); 			// retrieve the professor's last name
		for(int i = 0; i < NUM_CLASSES; i++) {
			strcpy(str, classes[i].professor); 	// get a copy of the professor string
			token = strtok(str, " "); 		// parse it to get their last name
			if(token == NULL) break;  		// error handling
			// last verse same as the first
			if(strcmp(search_term, token) == 0) display(classes[i]);
		}
		break;
	case 'Q':
	case 'q': // deal with q
		break;
	default: // handle bad input
		printf("| Invalid choice. Valid choices: \'n\', \'d\', \'p\' and \'q\'.\n");
		break;
	}
}
