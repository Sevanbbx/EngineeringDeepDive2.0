#include <iostream>

char matrix_3[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

// char matrix_8[8][8] = {
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//     {' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
//     {' ', ' ', ' ', '*', '*', ' ', ' ', ' '},
//     {' ', ' ', ' ', ' ', ' ', '*', ' ', ' '},
//     {' ', '*', '*', '*', ' ', ' ', ' ', ' '},
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
// };

int find_all_paths_count(char matrix[3][3]) {
    int count = 1;
    for (int col = 2; col > 0; --col) {
        for (int row = 2; row > 0; --row) {
            if (matrix[row][col] == '*') {
                continue;
            } else if (
                (row == 2 && col == 2) || 
                (matrix[row-1][col] == ' ' && matrix[row][col-1] == ' ')
            ) {
                count *= 2;
            }
        }
    }
    return count;
}

// int find_all_paths_count(char matrix[8][8]) {
//     int count = 1;
//     for (int col = 7; col > 0; --col) {
//         for (int row = 7; row > 0; --row) {
//             if (matrix[row][col] == '*') {
//                 continue;
//             } else if (
//                 (row == 7 && col == 7) || 
//                 (matrix[row-1][col] == ' ' && matrix[row][col-1] == ' ')
//             ) {
//                 count *= 2;
//             }
//         }
//     }
//     return count;
// }


int main() {
    std::cout << find_all_paths_count(matrix_3) << std::endl;
    return 0;
}