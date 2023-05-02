/********************************************************************************
** @auth�� taify
** @date�� 2023/04/21
** @Ver :  V1.0.0
** @desc�� kalmanboxtrackerͷ�ļ�
*********************************************************************************/


#pragma once


#include <iostream>
#include <opencv2/opencv.hpp>


/**
 * @brief KalmanBoxTracker	������������
 */
class KalmanBoxTracker
{
public:
	/**
	 * @brief KalmanBoxTracker	�������������๹�캯��
	 * @param bbox				����
	 */
	KalmanBoxTracker(std::vector<int> bbox);
	
	/**
	 * @brief update	ͨ���۲�ļ������ϵͳ״̬
	 * @param bbox		����
	 */
	void update(std::vector<int> bbox);	
	
	/**
	 * @brief predict	����Ԥ��ı߽��
	 */
	std::vector<float> predict();
	
	/**
	 * @brief get_state	���ص�ǰ����״̬
	 */
	std::vector<float> get_state();
	
public:
	/**
	 * @param m_kf	�������˲���
	 */
	cv::KalmanFilter* m_kf;

	/**
	 * @param m_time_since_update	�Ӹ��¿�ʼ��ʱ�䣨֡����
	 */
	int m_time_since_update;

	/**
	 * @param count	�������������ĸ���
	 */
	static int count;

	/**
	 * @param m_id	��������������id
	 */
	int m_id;

	/**
	 * @param m_history	��ʷ����Ĵ���
	 */
	std::vector<std::vector<float>> m_history;

	/**
	 * @param m_hits
	 */
	int m_hits;

	/**
	 * @param m_hit_streak	����Ŀ���ʼ������֡
	 */
	int m_hit_streak;

	/**
	 * @param m_age	predict�����õĴ�������
	 */
	int m_age;
};