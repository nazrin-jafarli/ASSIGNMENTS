#include<stdio.h>

void printMaze(char **maze,const int HT,const int WD);//prints the maze


int solveMaze(char **maze,const int HT,const int WD,int x,int y);//draws a path to the exit on the maze string




int main(){
	char mazeStr[]="  ##############"
		       "#     #     ####"
		       "# ####* ### ####"
		       "#    ###### ####"
		       "#### # #### ####"
		       "#    # #### ####"
		       "#### # #### ####"
		       "####        ####"
		       "################";
	const int HT=9;
	const int WD=16;
	char *maze[HT];


	for(int i=0;i<HT;i++)//filling 2d array

		maze[i]=&mazeStr[i*WD];

	solveMaze(maze,HT,WD,0,0);


	printMaze(maze,HT,WD);


	return 0;
}


//the starting position (0,0)
//obstacles contain '#' symbol
//correct path will be marked with '.'
//the goal is '*' symbol



int solveMaze(char **maze,const int HT,const int WD,int x,int y){

	if(x<0 || x>=WD || y<0 || y>=HT){
		return 0;      //if (x,y) outside maze return false

	}

	
	        if(maze[y][x]=='*'){
			return 1;//if (x,y) is goal return true
	}

		if(maze[y][x]=='#' || maze[y][x]=='.'){

			return 0;//if (x,y) is blocked by '#' or '.'
	}

	maze[y][x]='.';//a path in the maze wil be marked by the '.' symbol

	if(solveMaze(maze,HT,WD,x,y-1)==1){//Go North


		return 1;
	}
	if(solveMaze(maze,HT,WD,x+1,y)==1){//Go East
		return 1;
	}

	if(solveMaze(maze,HT,WD,x,y+1)==1){//Go South
		return 1;
	}
	if(solveMaze(maze,HT,WD,x-1,y)==1){//Go West
		return 1;
	}
	maze[y][x]=' ';

	return 0;
}




void printMaze(char **maze,const int HT,const int WD){
	for(int i=0;i<HT;i++){
		for(int j=0;j<WD-1;j++)
			printf("%c",maze[i][j]);
		printf("%c\n",maze[i][WD-1]);
	}
}


