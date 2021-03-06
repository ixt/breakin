#include "block.h"

Block::Block(bool fill, float yi, float xi, int ic): y(yi), x(xi) {
    filled = new bool(fill);
    COLOR = new int(ic);
}

void Brick::draw(){ 
    attron(COLOR_PAIR(getColor()));
    int locY = getY();
    int locX = getX();
    int col = getColor();
    int endH = locY+height;
    int endW = locX+width;

    if (getFilled()){
        for(int y = 0; y < height; y++)
            for(int x = 0; x < width; x++)
                mvaddch(locY+y,locX+x, (char)32);
    } else {
        mvhline(locY,locX,(char)32,width);
        mvhline(endH-1,locX,(char)32,width);
        mvvline(locY,locX,(char)32,height);
        mvvline(locY,endW-1,(char)32,height);
    }
    attroff(COLOR_PAIR(getColor()));
}

void Circle::draw(){ 
    // Drawing circles in the console is fun, but disappointing
    attron(COLOR_PAIR(getColor()));
    int locY = getY();
    int locX = getX();
    
    int x, y;
    int l;
    l = (int) radius * cos(M_PI / 4);

    if (!getFilled()){
        // empty circle, draw in quadrents 
        for ( x = 0; x<=l; x++ ){
            y = (int) sqrt((radius * radius) - (x*x));
            mvaddch( locY + y , locX + x , (char)32);
            mvaddch( locY - y , locX + x , (char)32);
            mvaddch( locY - y , locX - x , (char)32);
            mvaddch( locY + y , locX - x , (char)32);
            mvaddch( locY + x , locX + y , (char)32);
            mvaddch( locY - x , locX + y , (char)32);
            mvaddch( locY - x , locX - y , (char)32);
            mvaddch( locY + x , locX - y , (char)32);
        }
    } else {
        // filled just put all of the characters down in that radius
        for( y = -radius; y <= radius; y++ )
            for( x = -radius; x <= radius; x++ )
                if (( x * x ) + ( y * y ) <= ( radius * radius ))
                    mvaddch( locY + y , locX + x , (char)32);
    }
    attroff(COLOR_PAIR(getColor()));
}

void Panel::draw(){ 
    int col = getColor();
    attron(COLOR_PAIR(col));
    mvhline( y , x , (char)32 , length );
    attroff(COLOR_PAIR(col));
}

void Panel::left(){
    int start = x;
    if( start != 2 )
        x--;
}
void Panel::right(){
    int end = x+length;
    if( end != maxX-2 )
        x++;
}

void Ball::draw(){

    if (!started()){
        x = panel -> x + panel -> length /2;
        y = panel -> y - 1;
    }

    if ( x >= *frameX-3 || ( x == panel -> x - 1 && y == panel -> y ))
        reflect(1);
    if ( x <= 2 || ( x == panel -> x + panel -> length + 1 && y == panel -> y ))
        reflect(3);
    if ( y <= 1 || ( x >= panel -> x - 1  && x <= panel -> x + panel -> length + 1 && y == panel -> y + 1 && direction != 0))
        reflect(0);
    if ( y >= *frameY-2 || ( x >= panel -> x - 1 && x <= panel -> x + panel -> length + 1 && y == panel -> y - 1 && moves > 3))
        reflect(2);

    switch(direction){
        case 1:
            x++;
            y--;
            moves++;
            break;
        case 2:
            x++;
            y++;
            moves++;
            break;
        case -1:
            x--;
            y--;
            moves++;
            break;
        case -2:
            x--;
            y++;
            moves++;
            break;
        case 0:
            break;
    }

    attron(COLOR_PAIR(col));
    mvaddch(y,x,(char)79);
    attroff(COLOR_PAIR(col));
}

void Ball::reflect(int side){
    if (side == 0){
        if (direction == 1)
            direction = 2;
        if (direction == -1)
            direction = -2;
    }
    if (side == 3){
        if (direction == -1)
            direction = 1;
        if (direction == -2)
            direction = 2;
    }
    if (side == 1){
        if (direction == 1)
            direction = -1;
        if (direction == 2)
            direction = -2;
    }
    if (side == 2){
        if (direction == -2)
            direction = -1;
        if (direction == 2)
            direction = 1;
    }
}

void Tile::draw(){
    if (gone)
        return;
    attron(COLOR_PAIR(col));
    mvhline(y,x,(char)32,3);
    attroff(COLOR_PAIR(col));
}

int Tile::reflectDirection(int _y, int _x){
    if ( _y > y && _x <= x+3 && _x > x-1 )
        return 2;
    if ( _y < y && _x <= x+3 && _x > x-1 )
        return 0;
    if ( _x < x-1 && _y == y)
        return 3;
    return 1;
}
