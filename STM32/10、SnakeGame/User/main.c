#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
static unsigned long seed = 1;
void srand(unsigned long new_seed);
unsigned long rand();
uint8_t rand_in_range(uint8_t min, uint8_t max);
int main(void)
{
	uint16_t score = 0;
	OLED_Init();
	OLED_ShowString(1, 1, "Score:");
	OLED_ShowNum(1, 7, score, 3);
	OLED_ShowString(1, 11, "Snake");
	uint16_t length = 0;
	Direction direction = Direction.Right;
	int8_t line = 1;	   // max=4
	int8_t column = 1;	   // max=18
	int8_t foodLine = 3;   // max=4
	int8_t foodColumn = 7; // max=18
	int8_t food = 0;
	while (1)
	{
		OLED_Clear();
		OLED_ShowString(1, 1, "Score:");
		OLED_ShowNum(1, 7, score, 3);
		OLED_ShowString(1, 11, "Snake");
		Direction key = Key_GetDirection();
		if (key != Direction.None)
		{
			direction = key;
		}
		if (food == 0)
		{
			foodLine=rand_in_range(2,4);
			foodColumn=rand_in_range(1,18);
			OLED_ShowString(foodLine, foodColumn, "0");
			food = 1;
		}

		switch (direction)
		{
		case Direction.Up:
			/* code */
			line--;
			break;
		case Direction.Down:
			line++;
			/* code */
			break;
		case Direction.Left:
			column--;
			/* code */
			break;
		case Direction.Right:
			column++;
			/* code */
			break;

		default:
			break;
		}
		if (line <= 1 || line > 4 || column < 1 || column > 18)
		{

			OLED_ShowString(2, 4, "Game Over");
			while (1)
			{
				/* code */
			}
		}
		if (line == foodLine && column == foodColumn)
		{
			score++; 
			food = 0;
		} 

		for (int i = 0; i < score + 1; i++)
		{
			switch (direction)
			{
			case Direction.Up:
				/* code */
				line--;
				break;
			case Direction.Down:
				line++;
				/* code */
				break;
			case Direction.Left:
				column--;
				/* code */
				break;
			case Direction.Right:
				column++;
				/* code */
				break;

			default:
				break;
			}
			OLED_ShowString(line, column, 'A');
		}
		Delay_s(200);
	}
}




void srand(unsigned long new_seed) {
    seed = new_seed;
}

unsigned long rand() {
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 32768;
}


uint8_t rand_in_range(uint8_t min, uint8_t max) {
    return min + rand() % (max - min + 1);
}