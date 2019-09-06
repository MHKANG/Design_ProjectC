#pragma once
#include <iostream>
#include"NPAlgorithm.h"
#include"SPAlgorithm.h"

using namespace std;


class DeliverSystem
{
public:
	DeliverSystem(void);
	~DeliverSystem(void);
	void Run();
private:
	NPAlgorithm NP;
	SPAlgorithm SP;
};

