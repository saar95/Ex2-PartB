
#include <string>
#include <iostream>
#include <limits.h>
#include <map>  
#include "Direction.hpp"

using namespace std;

namespace ariel {
    class Board {

        unsigned int min_row;
        unsigned int min_col;
        unsigned int max_row;
        unsigned int max_col;
        map <unsigned int ,map<unsigned int,char>> board;

    public:
        Board() { 
        min_row = UINT_MAX;
        min_col = UINT_MAX;
        max_row = 0;
        max_col = 0;
           }
        void setMinRow(unsigned int r) { this->min_row = r; }
        void setMinCol(unsigned int c) { this->min_col = c; }
        unsigned int getMinRow() { return this->min_row; }
        unsigned int getMinCol() { return this->min_col; }
        void setMaxRow(unsigned int r) { this->max_row = r; }
        void setMaxCol(unsigned int c) { this->max_col = c; }
        unsigned int getMaxRow() { return this->max_row; }
        unsigned int getMaxCol() { return this->max_col; }

        void post(unsigned int r, unsigned int c, Direction d, std::string s);

        std::string read(unsigned int r, unsigned int c, Direction d, unsigned int l);

        void show();

        ~Board();
    };
}
