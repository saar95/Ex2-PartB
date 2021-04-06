#include <string>
#include <iostream>
#include <limits.h>
#include <map>
#include "Direction.hpp"
#include "Board.hpp"

using namespace std;

namespace ariel {
    string Board::read(unsigned int r, unsigned int c, Direction d, unsigned int l){
        string ans = "";
        if (d == Direction::Horizontal) {
            for (unsigned int i = 0; i < l; i++)
            {
                if(board[r][c+i]!=0)
                    ans += board[r][c+i];
                else
                ans+='_';
            }
        }
        if (d == Direction::Vertical) {
            for (unsigned int i = 0; i < l; i++)
            {
                if(board[r+i][c]!=0)
                    ans += board[r+i][c];
                else
                ans+='_';
            }
        }
        return ans;
    }

    void Board::post(unsigned int r, unsigned int c, Direction d, string s){
        if (d == Direction::Horizontal) {
                setMaxCol(max(c+unsigned(s.length()),getMaxCol()));
                setMinCol(min(c,getMinCol()));
                setMaxRow(max(r,getMaxRow()));
                setMinRow(min(r,getMinRow()));
                for (unsigned int i = 0; i < s.length(); i++)
                {
                    board[r][c + i] = s[i];
                }
        }
        if (d == Direction::Vertical) {
                setMaxRow(max(r+unsigned(s.length()),getMaxRow()));
                setMinRow(min(r,getMinRow()));
                setMaxCol(max(c,getMaxCol()));
                setMinCol(min(c,getMinCol()));
            
                for (unsigned int i = 0; i < s.length(); i++)
                {
                    board[r+i][c] = s[i];
                }
         }
        }
    

    void Board::show(){
        for (unsigned int i = getMinRow(); i < getMaxRow()+1; i++)
        {
            for (unsigned int j = getMinCol(); j < getMaxCol()+1; j++)
            {
                if(board[i][j]!=0)
                    cout << board[i][j];
                else{
                cout<<'_';
            }
            }
           cout<<endl; 
        }        
    }
    Board::~Board(){}
}

