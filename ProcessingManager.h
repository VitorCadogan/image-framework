/**
 * \class ProcessingManager
 *
 * \brief Class to manage application initialization and workflow.
 *
 * This class handles application initialization and then maintains 
 * data acquisition, then processing then output update.
 *
 * \author Vitor de Castro $
 *
 * \date $Date: 2020/09/07 $
 *
 * Contact: oi.vitor@gmail.com
 *
 * Created on: Mon Sep 07 2020
 */
#pragma once

#include "iostream"

#include "Segmentation/Segmentation.h"
#include "Acquisition/ImageManager.h"

class ProcessingManager
{
public :
	/*! \brief Class default constructor.
	 */
	ProcessingManager();

	/*! \brief Does everything needed to initialize the application. Called only once normally
	 */
	void initialize();

	/*! \brief Handles application workflow.
	* 
	*   Intended to be called in every cycle of the application, this function updates acquisition,
	*   processing and outputs in every single cycle.
	 */
	void updateApplication();

private :
	/*! \brief Handles image acquisition and update the input.
	 */
	void updateAcquisition();

	/*! \brief Does all the necessary processing on the images and gives the processing results
	*   in the end.
	 */
	void updateProcessing();

	/*! \brief Update the outputs whichever they are.
	* 
	*  The outputs could be drawings on the image, different groups with a bunch of information
	*  that charcterize each one of them, etc.
	 */
	void updateOutput();

	std::unique_ptr<IAcquisitionManager> m_imageManagerPtr; //!< ImageManager pointer to get new data.
	std::unique_ptr<Segmentation> m_segmentationPtr;        //!< Segmntation pointer to get new data.

	cv::Mat m_image;                                        //!< Image to be processed.
	bool m_isImageValid;                                    //!< Boolean to indicate whether image is valid or not.
};