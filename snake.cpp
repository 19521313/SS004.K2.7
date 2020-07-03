#include <iostream>
using namespace std;

#define 	MINW 		20
#define 	MINH 		20
#define 	MAXW 		420
#define 	MAXH 		220
#define 	MINX 		20
#define 	MINY 		20
#define 	MAXX 		420
#define 	MAXY 		220

//Khởi tạo tọa độ con rắn
struct Point 
{
	int x,y; // lưu vị trí đốt hiện tại
	int x0,y0; // lưu vị trí trước đó của đốt hiện tại
};

bool endGame;
int snakeLength;
Point snake[100];
Point direction; // hướng đi hiện tại của con rắn
Point food; // khởi tạo đối tượng thức ăn
const int DIRECTION	= 10; // khoảng cách di chuyển

bool checkPoint ()  // kiểm tra sụ trùng lặp khi tạo mới đối tượng food
{
	for (int i = 0;i < snakeLength;i++){
		if (food.x == snake[i].x && food.y == snake[i].y)
		return false;
	}
	return true;
}

void Run(){
	for (int i = 0;i < snakeLength;i++){
		// nếu là đầu rắn
		if (i == 0){
			snake[0].x0 = snake[0].x;snake[0].y0 = snake[0].y;
			snake[0].x += direction.x;
			snake[0].y += direction.y;
		}
		else {
			snake[i].x0 = snake[i].x;snake[i].y0 = snake[i].y;
			snake[i].x = snake[i-1].x0;snake[i].y = snake[i-1].y0;
		}
		if (snake[0].x < MINX+5 || snake[0].y < MINY+5 || snake[0].x > MAXX-5 || snake[0].y > MAXY - 5 )
			endGame = true;
		if (i != 0 && snake[0].x == snake[i].x && snake[0].y == snake[i].y)	 endGame = true;
	}
	if (snake[0].x == food.x && snake[0].y == food.y){
		snake[snakeLength].x = snake[snakeLength-1].x0;snake[snakeLength].y = snake[snakeLength-1].y0;
		snakeLength++;
		// tái tạo lại thức ăn nếu con rắn đã ăn nó
		srand ( time(NULL));
		do{
        	food.x = (rand() % (39) + 3)*10;
    		food.y = (rand() % (19) + 3)*10;
		}while (checkPoint() == false);
	}
}

void changeDirecton (int x) // hàm di chuyển con rắn
{
	switch(x){
                case 72: 
                    if (direction.y != DIRECTION) {
            			direction.y = -DIRECTION; direction.x = 0;
        			}
                    break;
                case 80: 
                	if (direction.y != -DIRECTION) {
            			direction.y = DIRECTION; direction.x = 0;
        			}
                   break;
                case 77:
                    if (direction.x != -DIRECTION) {
            			direction.x = DIRECTION; direction.y = 0;
        			}
                    break;
                case 75:
                    if (direction.x != DIRECTION) {
            			direction.x = -DIRECTION; direction.y = 0;
        			}
                    break;
                case 27:
                	endGame = true;
					break;
            }
}