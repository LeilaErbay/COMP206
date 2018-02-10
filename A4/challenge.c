#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
*	Function returns 1 if player found the treasure, 0 if player doesn't find the treasure and -1 if the player entered an invalid guess
*/
int checkForTreasure(char *input){
	int CORRECT_GUESS = 1;
	int INCORRECT_GUESS = 0;
	int INVALID_GUESS = -1;
	int QUIT = 5;

	if (strcmp(input, "cmd=sofa") == 0){
		return CORRECT_GUESS;				
	}
	else if (strcmp(input, "cmd=rug") == 0){
		return INCORRECT_GUESS;
	}
	else if (strcmp(input, "cmd=lamp") == 0){
		return INCORRECT_GUESS;
	}
	else if (strcmp(input, "cmd=sink") == 0){
		return INCORRECT_GUESS;
	}
	else if (strcmp(input, "cmd=phone") == 0){
		return INCORRECT_GUESS;
	}
	else if (strcmp(input, "cmd=QUIT") == 0){
		return QUIT;
	}
	else
		return INVALID_GUESS;
}

int main() {
	char * correctGuessHTML = "<!DOCTYPE html><html><head> <link rel = 'stylesheet' href='css/style.css'></head><body><h1 class='center'> The COMP206 Triumvirate Welcomes You </h1><div id = 'room'> <img src = 'https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg' width = '800' height = '500'> <div class = 'transport_buttons_container'> <form class = 'button north_button' action = 'http://www.cs.mcgill.ca/~szheng14/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='NORTH'> </form> <form class = 'button east_button' action = 'http://cgi.cs.mcgill.ca/~rtao10/ass4/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='EAST'> </form> <form class = 'button west_button' action = 'http://cs.mcgill.ca/~rke/jungleroom/cgi-bin/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='WEST'> </form> <form class = 'button south_button' action = 'http://www.cs.mcgill.ca/~tspark1/cgi-bin/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='SOUTH'> </form> </div> <h3> You have found the treasure! :O :O :O </h3> <p> Choose up to 5 gold and manna from the treasure, lest the room god loose her temper. </p> <p> Room gold: 10 </p> <p> Room manna: 10 </p> <form class = 'submit' action = 'room.cgi' method = 'post'> Gold: <input type='text' name='command' size='35'> Manna: <input type='text' name='inventory' size='35'> <br> <br> <input type='submit' value='Take the treasure!' > </form></div></body></html>";
	char * tryAgainHTML = "<!DOCTYPE html><html> <head> <link rel = 'stylesheet' href='css/style.css'> <title> I see you </title> </head> <body> <h1 class='center'> The COMP206 Triumvirate Welcomes You </h1> <div id = 'challenge'> <div class='helper_text_container'> <div class = 'instructions_container'> <h2>Instructions:</h2> <p> There is a hidden prize behind a piece of furniture </p> <p> Choose the correct one </p> <div class='instructions'> <ul> <li> sofa </li> <li> rug </li> <li> lamp </li> <li> sink </li> <li> phone </li> </ul> </div> </div> <div class= 'result_container'> Oops, the treasure is not behind the selected furnitre. Please try again! </div> </div> <img src='https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg' width='800' height='500'> <p> Please enter your guess below </p> <form class = 'submit' action = 'challenge.cgi' method = 'post'> <input type='text' name='cmd' size='35'> <input type='submit' value = 'Guess!'> </form> </div> </body></html>";
	char * noInputHTML = "<!DOCTYPE html><html> <head> <link rel = 'stylesheet' href='css/style.css'> <title> I see you </title> </head> <body> <h1 class='center'> The COMP206 Triumvirate Welcomes You </h1> <div id = 'challenge'> <div class='helper_text_container'> <div class = 'instructions_container'> <h2>Instructions:</h2> <p> There is a hidden prize behind a piece of furniture </p> <p> Choose the correct one </p> <div class='instructions'> <ul> <li> sofa </li> <li> rug </li> <li> lamp </li> <li> sink </li> <li> phone </li> </ul> </div> </div> <div class= 'result_container'> Don't waste your tries! Choose the furniture from the list. </div> </div> <img src='https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg' width='800' height='500'> <p> Please enter your guess below </p> <form class = 'submit' action = 'challenge.cgi' method = 'post'> <input type='text' name='cmd' size='35'> <input type='submit' value = 'Guess!'> </form> </div> </body></html>";
	char * invalidInputHTML = "<!DOCTYPE html><html> <head> <link rel = 'stylesheet' href='css/style.css'> <title> I see you </title> </head> <body> <h1 class='center'> The COMP206 Triumvirate Welcomes You </h1> <div id = 'challenge'> <div class='helper_text_container'> <div class = 'instructions_container'> <h2>Instructions:</h2> <p> There is a hidden prize behind a piece of furniture </p> <p> Choose the correct one </p> <div class='instructions'> <ul> <li> sofa </li> <li> rug </li> <li> lamp </li> <li> sink </li> <li> phone </li> </ul> </div> </div> <div class= 'result_container'> Don't waste your tries! Please guess! </div> </div> <img src='https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg' width='800' height='500'> <p> Please enter your guess below </p> <form class = 'submit' action = 'challenge.cgi' method = 'post'> <input type='text' name='cmd' size='35'> <input type='submit' value = 'Guess!'> </form> </div> </body></html>";
	char * roomHTML = "<!DOCTYPE html><html> <head> <link rel = 'stylesheet' href='css/style.css'> </head> <body> <h1 class='center'> The COMP206 Triumvirate Welcomes You </h1> <div id = 'room'> <img src = 'https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg' width = '800' height = '500'> <div class = 'transport_buttons_container'> <form class = 'button north_button' action = 'www.cs.mcgill.ca/~szheng14/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='NORTH'> </form> <form class = 'button east_button' action = 'http://cgi.cs.mcgill.ca/~rtao10/ass4/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='EAST'> </form> <form class = 'button west_button' action = 'http://cs.mcgill.ca/~rke/jungleroom/cgi-bin/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='WEST'> </form> <form class = 'button south_button' action = 'http://www.cs.mcgill.ca/~tspark1/cgi-bin/transporter.py' method = 'post'> <input type = 'hidden' name = 'inventory' value = '10, 10'> <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/room.html'> <input type='submit' value ='SOUTH'> </form> </div> <p> Please enter ONE of the following commands below </p> <p> REFRESH | to refresh the page </p><p> PLAY | to begin playing our awesome game </p><p> EXIT | to exit the entire dungeon game </p><p> DROP n | to drop a certain amount of gold, n is a number value </p> <form class = 'submit' action = 'room.cgi' method = 'post'> <!-- change name of file --> <input type='text' name='command' size='35'> <input type='hidden' name='inventory' value='10,10'><input type='submit'> </form> </div> </body></html>";
	

	/*
	* read input from HTML post
	*
	*/	
	
	char* len_char = getenv("CONTENT_LENGTH");				// gets length of input
	if (len_char == NULL){
	//	printf("%s\n", noInputHTML);
		exit(EXIT_FAILURE);
	}

	long int len = strtol(len_char, NULL, 10);				// converts it from a char* to an int
	char* input = malloc(len + 1);							// allocate memory for the input
	if (!input){
	//	printf("%s\n", invalidInputHTML);
		exit(EXIT_FAILURE);
	}
	fgets(input, len + 1, stdin);							// copy the input into the memory created

	/*
	*	Check if player found treasure and write back to the HTML file
	*/

	int isTreasureFound = checkForTreasure(input);
	if (isTreasureFound == 1){
		printf("Content-type: text/html\n\n");
		printf("%s\n", correctGuessHTML);
	return 1;
	}
	else if (isTreasureFound == 0){
		printf("Content-type: text/html\n\n");
		printf("%s\n", tryAgainHTML);
	}
	else if (isTreasureFound == 5){
		printf("Content-type: text/html\n\n");
		printf("%s\n", roomHTML);
	}	
	else{
		printf("Content-type: text/html\n\n");
		printf("%s\n", invalidInputHTML);
	}
	return 0;
	//free(input);
}
