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



