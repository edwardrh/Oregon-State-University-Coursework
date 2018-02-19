#include<cstdlib>
#include <iostream>
#include"./AverageRoomba.h"

/*void AverageRoomba::clean_floor(Floor &f){
	int r, c, i, j, p;
	r = f.get_row();
	c = f.get_col();
	while(f.obj_col > col){
		f.move_up();
	}
	while(f.obj_row > row){
		f.move_left();
	}
	for(i = 0; i < c; i++){
		j = 0;
		k = 0;
		for(p = 0; p < r; p++){
			while(j < c - i){
				f.move_right();
				j++;
			}
			while(k < r - p){
				f.move_down();
				k++;
			}
		}
		j = 0;
		k = 0;
		while(j < c - i){
			f.move_left();
			j++;
		}
		while(k < r - p){
			f.move_up();
			k++;
		}
	}
}*/