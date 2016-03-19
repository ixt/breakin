#include "breakout.h"

BreakOut game;

int main(){
    int finished = 0;
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
                case 'p':
                case 'P':
                    game.addTile();
                    break;
                case 'q':
                case 'Q':
                    endwin();
                    return 0;
                    break;
            }
        game.draw();
    }
    endwin();
}


