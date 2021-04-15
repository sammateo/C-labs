#include "Classes.h"
int main()
{
	Habitat H;
	H.intialization(50);
	H.showGrid();
	H.invasion(300);
	for (int x = 0; x < 10; x++)
	{
		H.ageAll();
		for (int x = 0; x < 52; x++)
		{
			H.feedAll();
		}
	}
	H.showGrid();
	H.getStatistics();
	H.printAll();
	return 0;
}