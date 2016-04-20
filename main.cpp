
#include <stdio.h>

#include "C\STLTest.h"
#include "STL\BasicSequenceOperations.h"
#include "STL/VectorOperations.h"
#include "STL/DequeOperations.h"

#include <sys\socket.h>
#include <pthread.h>
#include "STL/UnitTest/ValArrayOpsTest.h"

int main()
{
	printf("Hello DataStructures\n");

	ValArrayOpsTest<int> vtt;
	vtt.TestSuite();
	//DequeOpsTest();
	//VectorOpsTest();
	//STLBasicOpsTest();
	//ListTest();
	//MapTest();
	//VectorTest();
	//SizeOfTest();
	//system("pause");
	return 0;
}
