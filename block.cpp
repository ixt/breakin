#include "block.h"

Block::Block(bool fill, float yi, float xi, int ic): y(yi), x(xi) {
    filled = new bool(fill);
    COLOR = new int(ic);
}

Block::~Block(){
    delete filled;
    filled = nullptr;
}

void Block::draw(){}

int Block::getX(){
    return x;
}

int Block::getY(){
    return y;
}

bool Block::getFilled(){
    return *filled;
}

int Block::getColor(){
    return *COLOR;
}

Brick::Brick(bool fill, int y, int x, int w, int COLOR): Block(fill, y, x,COLOR), width(w), height(w){}

Brick::Brick(bool fill, int y, int x, int h, int w, int COLOR): Block(fill, y, x,COLOR), width(w), height(h){}

Brick::~Brick(){
    //cout << "Rectangle Destroyed" << endl;
}

void Brick::draw(){ attron(COLOR_PAIR(getColor()));
    int locY = getY();
    int locX = getX();
    int col = getColor();
    int endH = locY+height;
    int endW = locX+width;


    if (getFilled()){
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            mvaddch(locY+y,locX+x, (char)32);
        }
    }
    } else {
        mvhline(locY,locX,(char)32,width);
        mvhline(endH-1,locX,(char)32,width);
        mvvline(locY,locX,(char)32,height);
        mvvline(locY,endW-1,(char)32,height);
    }
    attroff(COLOR_PAIR(getColor()));
}

Circle::Circle(bool fill, int y, int x, int r, int COLOR): Block(fill, y, x,COLOR), radius(r) {
}

Circle::~Circle(){}

void Circle::draw(){ attron(COLOR_PAIR(getColor()));
    int locY = getY();
    int locX = getX();
    
    int x, y;
    int l;
    l = (int) radius * cos(M_PI / 4);

    if (!getFilled()){
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
        for( y = -radius; y <= radius; y++ )
            for( x = -radius; x <= radius; x++ )
                if (( x * x ) + ( y * y ) <= ( radius * radius ))
                    mvaddch( locY + y , locX + x , (char)32);
    }
    attroff(COLOR_PAIR(getColor()));

}

Panel::Panel(bool fill, int y, int x, int l): Block(fill,0,0,3), x(x), y(y), length(l) {}

Panel::~Panel(){}

void Panel::draw(){ 
    int col = getColor();
    getmaxyx(stdscr, maxY,maxX);
    mvhline( y , x , (char)32 , length );
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

Ball::Ball(int _y, int _x, signed int d, Panel * player): Block(true, _y, _x, 3), direction(d), y(_y), panel(player){
    
    x = panel -> x + (rand()%panel->length);

}

void Ball::draw(){
    int maxY, maxX;

    getmaxyx(stdscr, maxY,maxX);
    if ( x >= maxX-1 || ( x == panel -> x - 1 && y == panel -> y ))
        reflectRight();
    if ( x <= 1 || ( x == panel -> x + panel -> length + 1 && y == panel -> y ))
        reflectLeft();
    if ( y <= 1 || ( x >= panel -> x - 1  && x <= panel -> x + panel -> length + 1 && y == panel -> y + 1 && direction != 0))
        reflectTop();
    if ( y >= maxY-1 || ( x >= panel -> x - 1 && x <= panel -> x + panel -> length + 1 && y == panel -> y - 1 && moves > 3))
        reflectBottom();
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

    attron(COLOR_PAIR(1));
    mvaddch(y,x,(char)79);
    attroff(COLOR_PAIR(1));
}

void Ball::start(){
        direction = -1;
        moves++;
}

bool Ball::started(){
    if (direction !=0)
        return true;
    return false;
}

void Ball::reflectTop(){
    if (direction == 1)
        direction = 2;
    if (direction == -1)
        direction = -2;
}

void Ball::reflectLeft(){
    if (direction == -1)
        direction = 1;
    if (direction == -2)
        direction = 2;
}
void Ball::reflectRight(){
    if (direction == 1)
        direction = -1;
    if (direction == 2)
        direction = -2;
}
void Ball::reflectBottom(){
    if (direction == -2)
        direction = -1;
    if (direction == 2)
        direction = 1;
}

