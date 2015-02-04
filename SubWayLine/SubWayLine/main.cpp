#include "SubWayManager.h"

using namespace std;

int main()
{
	CSubWayManager subWayManager;
	subWayManager.Init();
	subWayManager.DisplayLine();
	subWayManager.TakeSubWay();

	return 0;
}