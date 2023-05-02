/********************************************************************************
** @auth�� taify
** @date�� 2023/04/21
** @Ver :  V1.0.0
** @desc�� sortԴ�ļ�
*********************************************************************************/


#pragma once


#include <iostream>
#include <opencv2/opencv.hpp>

#include "utils.h"
#include "kalmanboxtracker.h"


/**
 * @brief Sort	Sort�㷨
 */
class Sort
{
public:
	/**
	 * @brief Sort 			���캯��
	 * @param max_age		δ����ʱ������
	 * @param min_hits		δ����ʱ������
	 * @param iou_threshold iou��ֵ
	 */
	Sort(int max_age, int min_hits, float iou_threshold);

	/**
	 * @brief update	���¼���
	 * @param dets		����
	 */
	std::vector<std::vector<float>> update(std::vector<cv::Rect> dets);

private:
	/**
	 * @param m_max_age		δ����ʱ������
	 */
	int m_max_age;

	/**
	 * @param m_min_hits	δ����ʱ������
	 */
	int m_min_hits;

	/**
	 * @param m_iou_threshold	iou��ֵ
	 */
	float m_iou_threshold;

	/**
	 * @param m_trackers	�������������ļ���
	 */
	std::vector<KalmanBoxTracker> m_trackers;

	/**
	 * @param m_frame_count	֡��
	 */
	int m_frame_count;
};