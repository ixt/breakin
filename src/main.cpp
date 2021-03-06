#include "breakout.h"

BreakOut game;

int main(){
    int finished = 0;
    // Controls 
    int key = ' ';
    while( !finished ){
        int key;
        if( ( key = getch() ) != ERR )
            switch( key ){
                case KEY_LEFT:
                case 'h':
                case 'H':
                    game.panel -> left();
                    break;
                case KEY_RIGHT:
                case 'l':
                case 'L':
                    game.panel -> right();
                    break;
                case ' ':
                    if (!game.ball -> started())
                    game.ball -> start(); 
                    break;
                case 'q':
                case 'Q':
                    game.end = true;
                    break;
            }
        game.update();
        game.draw();

        if(game.end){
            endwin();
            return 0;
        }
    }
    endwin();
}


