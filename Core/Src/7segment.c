#include "GPIO.h"
#include "_7segment.h"

void _7segment_display(int num)
{
	GPIO_Init('B', 0 , OUTPUT, PUSH_PULL); //a
	GPIO_Init('B', 1 , OUTPUT, PUSH_PULL); //b
	GPIO_Init('B', 2 , OUTPUT, PUSH_PULL); //c
	GPIO_Init('B', 5 , OUTPUT, PUSH_PULL); //d
	GPIO_Init('B', 6 , OUTPUT, PUSH_PULL); //e
	GPIO_Init('B', 7 , OUTPUT, PUSH_PULL); //f
	GPIO_Init('B', 8 , OUTPUT, PUSH_PULL); //g
	GPIO_Init('B', 9 , OUTPUT, PUSH_PULL); //dp

	switch(num)
    {
        case 0:
	      //0
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 1);
		  GPIO_WritePin('B', 6, 1);
		  GPIO_WritePin('B', 7, 1);
		  GPIO_WritePin('B', 8, 0);

        case 1:
		  //1
		  GPIO_WritePin('B', 0, 0);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 0);
		  GPIO_WritePin('B', 6, 0);
		  GPIO_WritePin('B', 7, 0);
		  GPIO_WritePin('B', 8, 0);

        case 2:
		  //2
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 0);
		  GPIO_WritePin('B', 5, 1);
		  GPIO_WritePin('B', 6, 1);
		  GPIO_WritePin('B', 7, 0);
		  GPIO_WritePin('B', 8, 1);

        case 3:
		  //3
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 1);
		  GPIO_WritePin('B', 6, 0);
		  GPIO_WritePin('B', 7, 0);
		  GPIO_WritePin('B', 8, 1);

        case 4:
		  //4
		  GPIO_WritePin('B', 0, 0);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 0);
		  GPIO_WritePin('B', 6, 0);
		  GPIO_WritePin('B', 7, 1);
		  GPIO_WritePin('B', 8, 1);

        case 5:
		  //5
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 0);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 1);
		  GPIO_WritePin('B', 6, 0);
		  GPIO_WritePin('B', 7, 1);
		  GPIO_WritePin('B', 8, 1);

        case 6:
		  //6
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 0);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 1);
		  GPIO_WritePin('B', 6, 1);
		  GPIO_WritePin('B', 7, 1);
		  GPIO_WritePin('B', 8, 1);

        case 7:
		  //7
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 0);
		  GPIO_WritePin('B', 6, 0);
		  GPIO_WritePin('B', 7, 0);
		  GPIO_WritePin('B', 8, 0);

        case 8:
		  //8
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 1);
		  GPIO_WritePin('B', 6, 1);
		  GPIO_WritePin('B', 7, 1);
		  GPIO_WritePin('B', 8, 1);

        case 9:
		  //9
		  GPIO_WritePin('B', 0, 1);
		  GPIO_WritePin('B', 1, 1);
		  GPIO_WritePin('B', 2, 1);
		  GPIO_WritePin('B', 5, 1);
		  GPIO_WritePin('B', 6, 0);
		  GPIO_WritePin('B', 7, 1);
		  GPIO_WritePin('B', 8, 1);



    }


}
void _7segment_TurnOff(void)
{
	  GPIO_WritePin('B', 0, 0);
	  GPIO_WritePin('B', 1, 0);
	  GPIO_WritePin('B', 2, 0);
	  GPIO_WritePin('B', 5, 0);
	  GPIO_WritePin('B', 6, 0);
	  GPIO_WritePin('B', 7, 0);
	  GPIO_WritePin('B', 8, 0);
}
