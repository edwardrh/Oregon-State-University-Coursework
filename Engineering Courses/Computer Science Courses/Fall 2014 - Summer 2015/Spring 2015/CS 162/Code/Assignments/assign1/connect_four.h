#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

struct game{
   char **board;
   int r, c, p;
   char p1;
   char p2;
};

bool is_valid_arguments(char *info[]);
void set_game_info(game *, char *info[]);
char** create_table(int, int);
void play_game(game *);
bool check_winner(game);
void delete_table(game *);
int main(int argc, char *argv[]);

#endif
