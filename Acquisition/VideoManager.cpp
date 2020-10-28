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
}