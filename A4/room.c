#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * C program called room.c and a.out.
▪ The C program receives as input the player's inventory and the
command the player entered.
▪ It executes the command and redraws the room with the player's
inventory.
◦ Supported commands:
▪ DROP n
• Drops n gold pieces. For every 2 gold pieces the user gets 1
manna from the universe. The gold pieces are added to the
hidden resources of the room and removed from the player's
inventory.
▪ PLAY
• Activates the room's game
• Game can be terminated early by typing QUIT
▪ EXIT
• Marks the room as not occupied and all the players manna and
gold are added to the room's hidden resources. Sorry to leave
scene is displayed.
▪ REFRESH
• Just redraws the screen with the player's inventory preserved
* */

//---------------------------------------- TOP OF HTML ------------------------------//
void header_html(){
	printf("<head> <link rel = 'stylesheet' href='css/style.css'> </head> <body> <h1 class='center'> The COMP206 Triumvirate Welcomes You </h1> <div id = 'room'> <img src = 'https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg' width = '800' height = '500'>");
}


//---------------------------------------- UPDATE THE MID PART OF THE ROOM.HTML  ------------------------------//
void mid_html(int manna, int gold){
	printf("<div class = transport_buttons_container'>");
	printf("	<form class = 'button north_button' action = 'http://www.cs.mcgill.ca/~tspark1/cgi-bin/transporter.py' method = 'post'>");
        printf("		<input type = 'hidden' name = 'inventory' value ='%d, %d'>", manna, gold);
        printf("		<input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/cgi-bin/room.html'>");
        printf("            	<input type='submit' value ='NORTH'>");
        printf("        </form>");
        printf("        <form class = 'button east_button' action = 'http://cgi.cs.mcgill.ca/~rtao10/ass4/transporter.py' method = 'post'>");
        printf("                <input type = 'hidden' name = 'inventory' value ='%d, %d'>", manna, gold);
        printf("                <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/cgi-bin/room.html'>");
        printf("                <input type='submit' value ='EAST'>");
        printf("        </form>");
	printf("        <form class = 'button west_button' action = 'http://cs.mcgill.ca/~rke/jungleroom/cgi-bin/transporter.py' method = 'post'>");
        printf("                <input type = 'hidden' name = 'inventory' value ='%d, %d'>", manna, gold);
        printf("                <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/cgi-bin/room.html'>");
        printf("                <input type='submit' value ='WEST'>");
        printf("        </form>");
	printf("        <form class = 'button south_button' action = 'http://cs.mcgill.ca/~rgao11/cgi-bin/transporter.py' method = 'post'>");
        printf("                <input type = 'hidden' name = 'inventory' value ='%d, %d'>", manna, gold);
        printf("                <input type = 'hidden' name = 'URL' value = 'www.cs.mcgill.ca/~lerbay/cgi-bin/room.html'>");
        printf("                <input type='submit' value ='SOUTH'>");
        printf("        </form>");
	printf("</div>");
}

	//---------------------------------------- PRINT COMMANDS  ------------------------------//

void commands_html(int manna, int gold){
	printf("	<p> Please enter ONE of the following commands below </p>" );
	printf(" 	<p> REFRESH | to refresh the page</p>");
	printf("	<p> PLAY | to begin playing our awesome game</p>");
	printf("	<p> EXIT | to exit the entire dungeon</p>");
	 printf("	<p> DROP n | to drop a certain amount of gold, n is a number value</p>");
	
	printf("	<form class = 'submit' action='room.cgi' method='post'>");
	printf("		<input type='text' name='command' size='35'>");
	printf("		<input type='hidden' name='inventory' value='%d, %d'>",manna, gold);  
	printf("		<input type='submit'>");
	printf("	</form>");	
	printf("</div>");
}
//--------------------------------------- PLAYER WINS GAME!!! --------------------------------------//
void challengeWin(){
	printf("<h3> You have found the treasure! :O :O :O </h3>");
	printf("    <p> Choose up to 5 gold and manna from the treasure, lest the room god loose her temper. </p>");
	printf("    <p> Room gold: </p> <p> Room manna: </p>");

	printf("    <form class = 'submit' action = 'room.cgi' method = 'post'>");
	printf("        Gold: <input type='text' name='gold' size='35'>");
	printf("        Manna: <input type='text' name='manna' size='35'> <br> <br>");
	printf("        <input type='submit' value='Take the treasure!' >");
	printf("    </form>");
	printf("</div>");
}
	 //---------------------------------------- GET FIELD  ------------------------------//
const char* getfield(char* line, int num){

	const char* tok;
	for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}

 //---------------------------------------- GET RESOURCE  ------------------------------//

int getResource(char *resource){
	FILE *fp;
	fp = fopen("resources.csv", "r+");
	char resources[10];
	int i = 0;
	char c = fgetc(fp);

	while (c != EOF)
	{
		resources[i] = c;
		i++;
		c = fgetc(fp);
	}

	if (strcmp(resource, "manna") == 0)
		return atoi(getfield(resources, 1));
	else if (strcmp(resource, "gold") == 0)
		return atoi(getfield(resources, 2));
	else if (strcmp(resource, "occupied") == 0)
		return atoi(getfield(resources, 3));
	else
		return -1;
	fclose(fp);
}

 //---------------------------------------- UPDATE CSV   ------------------------------//

/*
	resource -> "manna", "gold", or "occupied"
	amount -> amount to be added (negative value for subtraction)

	for occupied, amount is either 0 or 1. No addition or subtraction takes place

	updates CSV with resource
*/
void updateResource(char *resource, int amount){
	FILE *fp;
	fp = fopen("resources.csv", "r+");

	int previousManna = getResource("manna");
	int previousGold = getResource("gold");
	int previousOccupied = getResource("occupied");

	if (strcmp(resource, "manna") == 0){
		int newManna = (((previousManna + amount) < 0) ? 0 : previousManna + amount);
		fprintf(fp, "%d%s%d%s%d", newManna, ",", previousGold, ",", previousOccupied);
	}
	else if (strcmp(resource, "gold") == 0){
		int newGold = (((previousGold + amount) < 0) ? 0 : previousGold + amount);
		fprintf(fp, "%d%s%d%s%d", previousManna, ",", newGold, ",", previousOccupied);
	}
	else if (strcmp(resource, "occupied") == 0){
		fprintf(fp, "%d%s%d%s%d", previousManna, ",", previousGold, ",", amount);
	}

	fclose(fp);
}




 //---------------------------------------- FUNCTION FOR USER'S INVALID INPUT   ------------------------------//
void invalidInput(int manna, int gold) {
	printf("<head> <link rel = 'stylesheet' href='css/style.css'> </head> <body> <h1 class='center'> The COMP206 Triumvirate Welcomes You, but You entered the wrong input. Dohhhhh! </h1> <div id = 'room'> <img src = 'https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg' width = '800' height = '500'>");

	mid_html(manna, gold);
	commands_html(manna, gold);

}

//---------------------------------------- DEATH SCREEN  ---------------------------------------//

void deathScreen (int manna, int gold){
	updateResource("manna", manna);		//room takes whatever is left of manna and gold
	updateResource("gold", gold);
	printf("<h1><p><center> You didn't have enough manna. <br> So you're dead. <br><img src ='http://images5.fanpop.com/image/photos/30100000/YOU-RE-DEAD-TO-ME-asdf-movie-30180010-476-282.jpg'></p></center></h1>"); 
}

//---------------------------------------- WIN SCREEN ---------------------------------------//
void winScreen(int manna, int gold) {
	printf("<h1><p><center>CONGRATS. <br> You won the entire game. <br> <img src='https://img.memesuper.com/ebb84f51fc79439a237cbaf8913f838d_best-jokes-continues-homer-simpson-woohoo-meme_788-500.jpeg' > </p></center></h1>");
}

//---------------------------------------- DROP SCREEN  ---------------------------------------//
void dropCommand (int manna, int gold, int drop_val){
	//need to update room CSV
	updateResource("gold", drop_val);	
	int p_gold=gold-drop_val;

	//update the room.html with new manna and gold
	header_html();
	mid_html(manna,gold);
	commands_html(manna,p_gold);
}


//---------------------------------------- REFRESH FUNCTION  ---------------------------------------//
void refreshCommand (int pManna, int pGold){
	//refresh the current page with same pManna and pGOld
	header_html();
	mid_html(pManna, pGold);
	commands_html(pManna, pGold);

	//do not need to update room CSV

}
//---------------------------------------- EXIT FUNCTION  ---------------------------------------//
void exitCommand(int pManna, int pGold ){
	  updateResource("manna", pManna);          //room will take what is left from the player
          updateResource("gold",pGold);
	printf("<h1><p><center> You pressed exit. <br> Sorry to see you go <br><img src ='http://images5.fanpop.com/image/photos/30100000/YOU-RE-DEAD-TO-ME-asdf-movie-30180010-476-282.jpg'></p></center></h1>");
}

//---------------------------------------- PLAY FUNCTION  ---------------------------------------//
void playCommand(int pManna, int pGold){
	/*char game [100];
	sprintf(game,"./challenge.cgi %d %d"i, pManna, pGold);
	system(game);
	*/
	 system("./challenge.cgi"); 	//player has won
	//	mid_html(pManna,pGold);
	//	challengeWin();
	
		
//if player won, show player room Manna and Gold. Let player select 5 total inv (manna/gold). Update player inventory and room inventory	

}

int main(){
//initialization of all variables 
	int rGold;
	int rMannna;
	
	char* dropVal = calloc(50, sizeof(char));

	int pGold;
	int pManna;
	int drop_val;
	
	int length = atoi(getenv("CONTENT_LENGTH"));
		
	
	char *url = calloc(length+1,sizeof(char));
	
//	scanf("%s", url);
	fgets(url, length+1,stdin);		
	
	//url format: room.cgi?command=drop+5&inventory=10%2C10
	//url format: room.cgi?command=refresh&inventory=10%2C10
	//url format: room.cgi?command=exit&inventory=10%2C10
	//url format: room.cgi?command=play&inventory=10%2C10
	

	//---------------------------------------- BEGINNING OF PARSING ------------------------------//
	url = strtok(url, "=");
	
	char *command = calloc(length, sizeof(char));
	char * inventory = calloc(length, sizeof(char));
	
	command = strtok(NULL, "&");
	
	char *invLabel= calloc(length,sizeof (char));
	invLabel=strtok(NULL, "=");
	
	inventory=strtok(NULL, " ");

	char * manna = calloc(length, sizeof(char));
	manna=strtok(inventory, "%2");
	
	char * gold = calloc(length, sizeof(char));
	gold =strtok(NULL, " ");
	gold++;
	gold++;

	pGold= atoi(gold);
	pManna=atoi(manna);



	printf("Content-type: text/html\n\n");
	printf("<!DOCTYPE html>");
	printf("<html>");


	//-------------------------------------- DEATH SCREEN ------------------------------------------//
	
	if (pManna <=0){	//if player has 0 manna, they're dead
		deathScreen(pManna,pGold);	
	}

	//------------------------------------ WIN SCREEN --------------------------------------------//
	if (pGold == 100) {	//if player has 100 gold, they win
		winScreen(pManna, pGold);
	}

	//---------------------------------------- DROP COMMAND ---------------------------------------------//
	char* dropCmd = calloc(strlen(command)+1, sizeof(char));	
	char* cmd = calloc(strlen(command)+1, sizeof(char));
	cmd =strcpy(cmd, command);
	
	if (strncmp(command, "DROP", 4)==0){
		dropCmd=strtok(command,"+");	//dropCmd = drop
		dropVal=strtok(NULL, " ");	 //dropVal = hold the char * of the integers of the drop command
	
	//determining if the user entered valid input using drop. If not 
		for (int i =0; dropVal[i]!='\0'; i++){
			if ((dropVal[i] >='a' && dropVal[i] <='z') || (dropVal[i] >='A' && dropVal[i] <= 'Z')){
				invalidInput(pManna, pGold);
			}
		}
	    drop_val=atoi(dropVal);
       		printf("%d\n", drop_val);        
	
	//---------------------------------PARSING IS DONE--------------------------------------------------//
		
		if (drop_val >= pGold){	 	//check if drop_val >= pGold
			invalidInput(pManna, pGold);
		}
		dropCommand(pManna, pGold, drop_val);
				
	}

	//------------------------------------ REFRESH COMMAND --------------------------------------------//
	else if (strcmp(cmd, "REFRESH")==0){
		refreshCommand(pManna, pGold);
				
	}
	
	//------------------------------------ EXIT COMMAND --------------------------------------------//
	else if (strcmp(cmd, "EXIT") ==0){
		exitCommand(pManna, pGold);
	} 

	//------------------------------------ PLAY COMMAND --------------------------------------------//

	else if (strcmp(cmd, "PLAY") == 0) {
		playCommand(pManna, pGold);
	}
	//------------------------------------ INVALID COMMAND -------------------------------------//
	else {
		header_html();
		mid_html(pManna, pGold);
		commands_html(pManna,pGold);
	  printf("</body>");
	 printf("</html>");

	}
// WILL NEED TO FREE SPACE AT THE END 
//free()
}
