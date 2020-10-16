#include "iostream"

#include "ProcessingManager.h"

int main()
{
	// Create processingManager pointer
	auto processingManagerPtr = std::make_unique<ProcessingManager>();

	// Check pointer
	if (!processingManagerPtr)
	{
		std::cout << "processingManagerPtr is null !! " << std::endl;
		return 1;
	}

	// Initialize the application 
	processingManagerPtr->initialize();

	// Update application 
	while (1)
	{
		processingManagerPtr->updateApplication();
	}

	return 0;
}