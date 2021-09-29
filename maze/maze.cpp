#include <iostream>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>

char OriginalMaze[100][100];
char VisionMaze[100][100];

struct xy {int x; int y;};
xy player, startpoint, endpoint, SizeofMaze;
int VisionDistance;

void setCurserPosition(int x, int y);
void readMap();
void synchro();
void preTEST();
void Go1(char a);
int getCommand();
void GameEnd();





void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}





void readMap()
{
    std::ifstream file;
    file.open("./Maze.txt");
    std::string firstline;
    std::getline(file,firstline);
    std::stringstream ss(firstline);
    ss>>SizeofMaze.x>>SizeofMaze.y>>VisionDistance;

    for(int i=0;i<SizeofMaze.y;i++){
        std::string oneline;
        std::getline(file, oneline);
        std::cout<<oneline<<std::endl;
        for(int j=0;j<SizeofMaze.x;j++){
            OriginalMaze[i][j]=oneline[j];
        }
    }
    file.close();
}






void synchro()
{
    for(int i=0;i<SizeofMaze.y;i++)
    {
        for(int j=0;j<SizeofMaze.x;j++) VisionMaze[i][j]=' ';
    }
    for(int i=0;i<SizeofMaze.y;i++)
    {
        for(int j=0;j<SizeofMaze.x;j++) if(sqrt((pow(player.x-j,2))+(pow(player.y-i,2))) <= VisionDistance) VisionMaze[i][j]=OriginalMaze[i][j];
    }
    VisionMaze[player.y][player.x]='P';
    VisionMaze[endpoint.y][endpoint.x]='E';
    setCursorPosition(0,0);
    //for(int i=0;i<SizeofMaze*(SizeofMaze+1);i++) printf("\b");
    //system("cls");

    for(int i=0;i<SizeofMaze.y;i++)
    {
        for(int j=0;j<SizeofMaze.x;j++) std::cout<<VisionMaze[i][j]<<" ";
        std::cout<<" "<<std::endl;
    }
}





void preTEST()
{
    readMap();
    for(int i=0;i<SizeofMaze.y;i++)
    {
        for(int j=0;j<SizeofMaze.x;j++)
        {
            if(OriginalMaze[i][j]=='S') {startpoint.x=j; startpoint.y=i;}
            if(OriginalMaze[i][j]=='E') {endpoint.x=j; endpoint.y=i;}
        }
    }
    player.x=startpoint.x; player.y=startpoint.y;
    synchro();
}





void Go1(char a)
{
    if(a==119)
    {
        if(OriginalMaze[player.y-1][player.x]==' '||OriginalMaze[player.y-1][player.x]=='S'||OriginalMaze[player.y-1][player.x]=='E') player.y-=1;
        synchro();
    }
    else if(a==97)
    {
        if(OriginalMaze[player.y][player.x-1]==' '||OriginalMaze[player.y][player.x-1]=='S'||OriginalMaze[player.y][player.x-1]=='E') player.x-=1;
        synchro();
    }
    else if(a==115)
    {
        if(OriginalMaze[player.y+1][player.x]==' '||OriginalMaze[player.y+1][player.x]=='S'||OriginalMaze[player.y+1][player.x]=='E') player.y+=1;
        synchro();
    }
    else if(a==100)
    {
        if(OriginalMaze[player.y][player.x+1]==' '||OriginalMaze[player.y][player.x+1]=='S'||OriginalMaze[player.y][player.x+1]=='E') player.x+=1;
        synchro();
    }
}





int getCommand()
{
    if(_kbhit()) {
        return _getch();
    }

    return -1;
}





void GameEnd()
{
    setCursorPosition(0,0);
    for(int i=0;i<SizeofMaze.y;i++)
    {
        for(int j=0;j<SizeofMaze.x;j++) std::cout<<OriginalMaze[i][j]<<" ";
        std::cout<<" "<<std::endl;
    }
    Sleep(3000);
}





int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    system("MODE CON COLS=150 LINES=100");


    preTEST();

    for(;;)
    {
        Go1(getCommand());
        if(player.x==endpoint.x&&player.y==endpoint.y) break;
    }

    GameEnd();
}
