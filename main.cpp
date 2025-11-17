#include <iostream>
#include <vector>
#include <thread>

struct Point{
    int x, y;
};

class Board{
    public:
        int width, height;
        Board (int w, int h) : width(w), height(h) {}
        std :: vector<std :: vector<char>> create_board(){
            int padded_height = height + 2;
            int padded_width = width + 2;
            return std :: vector<std :: vector<char>>(padded_height, std :: vector<char>(padded_width, ' '));
        }
        void add_cells(std :: vector<std :: vector<char>>& game, std :: vector<Point>& points){
            for(const auto& p : points){
                game[p.y + 1][p.x + 1] = 'o'; 
            }

        }

        void print_game(std :: vector<std :: vector<char>>const& game){
            for(int row = 1; row <= height; row++){
                for(int col = 1; col <= width; col++){
                    std :: cout << game[row][col];
                }
                std :: cout << '\n';
            }
        }

        std :: vector<std :: vector<char>> update(std :: vector<std :: vector<char>>& game, int width, int height) {
            std::vector<std::vector<char>> new_game = game;
            for(int row = 1; row <= height; row++){
                for(int column = 1; column <= width; column++){
                        int alive_count = 0;
                        for(int i = -1; i <= 1; i++){
                            for(int j = -1; j <= 1; j++)
                                if (game[row + i][column + j] == 'o') alive_count++;
                            }
                        
                        if (game[row][column] != 'o') {
                            if (alive_count == 3) new_game[row][column] = 'o';
                        }
                        else{
                            alive_count--;
                            if (alive_count < 2 || alive_count > 3) new_game[row][column] = ' ';
                        }
                }
            }
        return new_game;   
        } 
};



int main(){
    
    Board board(20, 20);
    std :: vector<std :: vector<char>> game = board.create_board();

    std::vector<Point> glider = {
    {1, 2},
    {2, 3},
    {3, 1},
    {3, 2},
    {3, 3}
    };

    board.add_cells(game, glider);

    while(1){
        system("clear");
        game = board.update(game, board.width, board.height);
        board.print_game(game);
        std :: this_thread::sleep_for(std :: chrono::milliseconds(1000));
    }


    return 0;
}