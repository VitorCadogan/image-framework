/**
 * \class ImageListManager
 *
 * \brief Class to read a sequence of images within a folder.
 *
 * This class manages image acquisition from a sequence of images
 * through a path and provides image data one by one.
 *
 * \author Vitor de Castro $
 *
 * \date $Date: 2020/10/08 $
 *
 * Contact: oi.vitor@gmail.com
 *
 * Created on: Mon Oct 08 2020
 */
#pragma once

#include "IAcquisitionManager.h"

class ImageListManager : public IAcquisitionManager
{
public:
	/*! \brief Class default constructor.
	*/
	ImageListManager();

	/*! \brief Class constructor.
	* 
	*   \param[in] The path where the required images are.
	*/
	ImageListManager(cv::String imagesFolder);

	/*! \brief Read the current image using the parsed matrix in the parameter.
	* 
	*   Although the class intends to read a list of image, it reads one by one.
	*   A counter is incremented after each call of this function to keep a track of the already read images.
	*
	*   \param[out] A cv::Mat with the next image to be processed.
	*/
	void getLastImage(cv::Mat& image) override;

private:
	cv::String m_imagesFolder;           //!< Image path where the image might be found.
	std::vector<cv::String> m_filenames; //!< Vector containing the names of every file inside a given folder.
	double m_imageCounter;               //!< Counter to keep a track of how many images we've already read.
};
