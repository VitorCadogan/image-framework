
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "iostream"
//#include "functional"

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
	

	/*
	auto imageManagerPtr = std::make_unique<ImageManager>();

	

	// Reading an image
	std::string image_path = cv::samples::findFile("data/game/niveau1.png"); // TODO : Check before if path exists

	if (!imageManagerPtr)
	{
		std::cout << "imageManagerPtr is null !! " << std::endl;
		return 1;
	}

	cv::Mat field = imageManagerPtr->getLastImage();

	if (field.empty())
	{
		std::cout << "Could not read the image: " << image_path << std::endl;
		return 1;
	}

	cv::imshow("Display window", field);
	int k = cv::waitKey(0); // Wait for a keystroke in the window

	if (k == 's')
	{
		cv::imwrite("segmented_field.png", field);
	}
	*/
	return 0;
}