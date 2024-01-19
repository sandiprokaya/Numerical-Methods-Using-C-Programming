#include <iostream>
#include<conio.h>
#include<ctime>

#include "snake.h"
#include "Food.h"
using namespace std;

// these are the Constant values define with the macros
#define width  50
#define height 25


// make the snake object
// Snake will start from the center with the velosity of 1
Snake snake({width/2, height/2},1);


//Make a Food Object
Food food;

int score;

void board(){
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    vector<COORD> snake_body = snake.get_body();

    cout<<"Your Score Is:= "<<score<<"\n\n\n\n";
    for( int i=0; i<height ; i++){
        cout << "\t\t#";
        for(int j=0; j<width-2 ; j++){
            if(i==0 || i==height-1) cout<<'#';
            else if (i==snake_pos.Y && j+1==snake_pos.X) cout<<'0';
            else if (i==food_pos.Y && j+1==food_pos.X) cout<<'@';
            else {
                bool isbodypart = false;
                for(int k=0; k<snake_body.size()-1; k++){
                    if(i==snake_body[k].Y && j+1 == snake_body[k].X){
                        cout<<'o';
                        isbodypart = true;
                        break;
                    }
                }
                if(!isbodypart) cout<<' ';
            }
        }
        cout <<"#\n";
    }

}


int main(){
    score =0;
    srand(time(NULL)); // seeding a random function
    food.gen_food();
    bool game_over = false;

    while(!game_over){
        board();
        if(kbhit()){
            //mapping the keys to get the direction
            switch(getch()){
                case 'w':snake.change_dir('u'); break;
                case 's':snake.change_dir('d'); break;
                case 'a':snake.change_dir('l'); break;
                case 'd':snake.change_dir('r'); break;
            }
        }
        // cheack the snake has eaten the food od not
        if(snake.eaten(food.get_pos())){
            food.gen_food();
            snake.grow();
            score++;
        }
        if(snake.collided()){ game_over = true;}
        snake.move_snake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    }
}
