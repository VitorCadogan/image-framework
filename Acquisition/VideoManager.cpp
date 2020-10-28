#include "VideoManager.h"

VideoManager::VideoManager()
	: m_captureObj(),
	  m_frame()
{
}

VideoManager::~VideoManager()
{
	m_captureObj.release();
}

VideoManager::VideoManager(cv::String videoPath)
	: m_captureObj(videoPath),
	  m_frame()
{
}

VideoManager::VideoManager(int cameraNumber)
	: m_captureObj(cameraNumber),
	  m_frame()
{
}

void VideoManager::getLastImage(cv::Mat& image)
{
	// Check if Capture object is properly initialized.
	if (!m_captureObj.isOpened())
	{
		std::cout << "Error opening video file" << std::endl;
		return;
	}

	// Capture frame
	m_captureObj >> m_frame;

	if (m_frame.empty())
	{
		std::cout << "Error while reading image! Image matrix is empty !" << std::endl;
		return;
	}

	image = m_frame;
}