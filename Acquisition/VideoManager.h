/**
 * \class VideoManager
 *
 * \brief Class to read a video.
 *
 * This class manages image acquisition from a video file OR a camera stream.
 * For video files, call the constructor with the wished cv::String path of the video.
 * For camera stream, call the constructor with the camera index (int) as argument. 
 *
 * \author Vitor de Castro $
 *
 * \date $Date: 2020/10/28 $
 *
 * Contact: oi.vitor@gmail.com
 *
 * Created on: Wed Oct 28 2020
 */
#pragma once

#include "opencv2/opencv.hpp" // VideoCapture

#include "IAcquisitionManager.h"

class VideoManager : public IAcquisitionManager
{
public:
	/*! \brief Class default constructor.
	*/
	VideoManager();

	/*! \brief Class default destructor.
	*/
	~VideoManager();

	/*! \brief Class constructor overload for video files.
	*
	*   \param[in] The video path including extension.
	*/
	VideoManager(cv::String videoPath);

	/*! \brief Class constructor overload for camera stream.
	*
	*   \param[in] The camera index. When only one camera is connected --> cameraNumber = '0'.
	*/
	VideoManager(int cameraNumber);

	/*! \brief Read the current image using the parsed matrix in the parameter.
	*
	*   Reads and outputs the current frame one by one.
	*
	*   \param[out] A cv::Mat with the next image to be processed.
	*/
	void getLastImage(cv::Mat& image) override;

private:
	cv::VideoCapture m_captureObj; //!< VideoCapture object from OpenCV. It allows to manage easily videos.
	cv::Mat m_frame;               //!< Current grabbed frame.
};