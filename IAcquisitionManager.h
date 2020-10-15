/**
 * \class IAcquisitionManager
 *
 * \brief Interface to get last data
 * 
 * This class is meant to serve as a base class for other classes
 * that handle acquisition, as it could be from different manners,
 * like a single image, a video, a list of images/videos, a camera
 * flow.
 *
 * \author Vitor de Castro $
 *
 * \date $Date: 2020/08/31 $
 *
 * Contact: oi.vitor@gmail.com
 *
 * Created on: Mon Aug 31 2020
 */

#pragma once

#include <opencv2/core/core.hpp>

class IAcquisitionManager
{
public:
	/*! \brief Interface class destructor.
	 */
	virtual ~IAcquisitionManager() = default;

	/*! \brief A virtual function to get the last image available at the buffer.
	 *
	 * Intended to use polymorphism to handle different types of image entries.
	 * This image could be from a static image, a video or a camera flow.
	 *
	 * \param[out] A cv::Mat with the next image to be processed.
	 */
	virtual void getLastImage(cv::Mat& image) =0;
	
//protected:
//	int m_width;  /*!< Image width (x-axis). */
//	int m_height; /*!< Image height (y-axis). */
//	int m_type;   /*!< Type of the matrix element, like CV_16SC3 for 16-bit signed 3-channel array and so on.. */
//	
};
