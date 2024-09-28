// Student ID: 20558765
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include "Shapes.h"
using namespace std;

Screen::Screen(size_t w, size_t h): _w(w), _h(h){
    _pix.resize(h);
    for(size_t i = 0; i < h; i++){
        _pix[i].resize(w);
    }
}

void Screen::fill(char c){
    for(size_t i = 0; i < _h; i++){
        for(size_t j = 0; j < _w; j++){
            _pix[i][j] = c;
        }
    }
}


string Screen::to_string() const{
    string ss = "";
    for(int i = _h - 1; i >= 0; i--){
        for(size_t j = 0; j < _w; j++){
            ss = ss + _pix[i][j];
        }
        ss = ss + '\n';
    }
    return ss;
}

bool Point::draw(Screen &screen, char c){
    if(_x < screen.get_w() && _y < screen.get_h()){
        screen.get_pix()[_y][_x] = c;
        return true;
    }
    else {
        return false;
    }
}

bool Line::draw_by_x(Screen& scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2) {
    bool xdraw;
    if(x1 > scr.get_w() || x2 > scr.get_w()){
        xdraw = false;
    }
    if(y1 > scr.get_h() || y2 > scr.get_h()){
        xdraw = false;
    }
    if(x1 > x2){
        return draw_by_x(scr, ch, x2, y2, x1, y1);
    }

    double dy = ((double) y2 - y1) / ((double) x2 - x1);
    double x = x1, y = y1;
    while (x <= x2){
        Point((size_t)x, (size_t) y).draw(scr, ch);
        x += 1;
        y += dy;
    }
    return xdraw;
}

bool Line::draw_by_y(Screen& scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2) {
    bool ydraw;
    if(x1 > scr.get_w() || x2 > scr.get_w()){
        ydraw = false;
    }
    if(y1 > scr.get_h() || y2 > scr.get_h()){
        ydraw = false;
    }
    if(y1 > y2){
        return draw_by_y(scr, ch, x2, y2, x1, y1);
    }
    double dx = ((double) x2 - x1) / ((double) y2 - y1);
    double x = x1, y = y1;
    while (y <= y2){
        Point((size_t)x, (size_t) y).draw(scr, ch);
        y += 1;
        x += dx;
    }
    return ydraw;
}

bool Line::draw(Screen &scr, char ch) {
    size_t dx = _x2 > _x1 ? (_x2 - _x1) : (_x1 - _x2);
    size_t dy = _y2 > _y1 ? (_y2 - _y1) : (_y1 - _y2);

    if (dx >= dy) {
        return draw_by_x(scr, ch, _x1, _y1, _x2, _y2);
    } 
    else{
        return draw_by_y(scr, ch, _x1, _y1, _x2, _y2);
    }
}

bool Quadrilateral::draw(Screen &scr, char ch){
    bool first = Line(_x1, _y1, _x2, _y2).draw(scr, ch);
    bool second =  Line(_x2, _y2, _x3, _y3).draw(scr, ch);
    bool third =  Line(_x3, _y3, _x4, _y4).draw(scr, ch);
    bool fourth =  Line(_x4, _y4, _x1, _y1).draw(scr, ch);
    return first && second && third && fourth;
}


Stick_Man::Stick_Man(size_t x, size_t y, size_t w, size_t h){
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    if (_h <= 1) _h = DEFAULT_H;
    if (_w <= 1) _w = DEFAULT_W;

    _parts.clear();

    _parts.push_back(new Upright_Rectangle(x, y + h / 2, x + w - 1, y + h - 1)); // Head
    _parts.push_back(new Line(x + w / 2, y + h / 2, x + w / 2, y + h / 4)); // Torso
    _parts.push_back(new Line(x + w / 2, y + h / 2, x + w / 4, y + h / 4)); // Left arm
    _parts.push_back(new Line(x + w / 2, y + h / 2, x + 3 * w / 4, y + h / 4)); // Right arm
    _parts.push_back(new Line(x + w / 2, y + h / 4, x, y)); // Left leg
    _parts.push_back(new Line(x + w / 2, y + h / 4, x + w - 1, y)); // Right leg
}

bool Stick_Man::draw(Screen &scr, char ch) {
    // Draw the head
    bool first = Upright_Rectangle(_x, _y + _h / 2, _x + _w - 1, _y + _h - 1).draw(scr,ch);

    // Draw the torso
    bool second = Line(_x + _w / 2, _y + _h / 2, _x + _w / 2, _y + _h / 4).draw(scr,ch);

    // Draw the left arm
    bool third = Line(_x + _w / 2, _y + _h / 2, _x + _w / 4, _y + _h / 4).draw(scr,ch);


    // Draw the right arm
    bool fourth = Line(_x + _w / 2, _y + _h / 2, _x + 3 * _w / 4, _y + _h / 4).draw(scr,ch);

    // Draw the left leg
    bool fifth = Line(_x + _w / 2, _y + _h / 4, _x, _y).draw(scr,ch);

    // Draw the right leg
    bool sixth = Line(_x + _w / 2, _y + _h / 4, _x + _w - 1, _y).draw(scr,ch);

    return first && second && third && fourth && fifth && sixth;
}

Stick_Man::~Stick_Man() {
    for (size_t i = 0; i < _parts.size(); ++i) {
        delete _parts[i];
        _parts[i] = nullptr; 
    }
    _parts.clear();
}

