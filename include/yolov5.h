/********************************************************************************
** @auth�� taify
** @date�� 2023/04/21
** @Ver :  V1.0.0
** @desc�� yolov5ͷ�ļ�
*********************************************************************************/


#pragma once


#include <iostream>
#include <opencv2/opencv.hpp>


const float INPUT_WIDTH = 640.0;			//��������ͼ����
const float INPUT_HEIGHT = 640.0;			//��������ͼ��߶�
const float SCORE_THRESHOLD = 0.5;			//�÷���ֵ
const float NMS_THRESHOLD = 0.5;			//nms��ֵ
const float CONFIDENCE_THRESHOLD = 0.5;		//���Ŷ���ֵ

const std::vector<std::string> class_name = {
	"person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light",
	"fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow",
	"elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
	"skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard",
	"tennis racket", "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple",
	"sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair", "couch",
	"potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote", "keyboard", "cell phone",
	"microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear",
	"hair drier", "toothbrush" };			//�������


/**
 * @brief pre_process	Ԥ����
 * @param input_image	����ͼ��
 * @param net			��������
 */
void pre_process(cv::Mat& image, cv::Mat& blob);


/**
 * @brief process	���紦��
 * @param blob		����ͼ��
 * @param net		��������
 * @param outputs	��������
 */
void process(cv::Mat& blob, cv::dnn::Net& net, std::vector<cv::Mat>& outputs);


/**
 * @brief scale_boxes	���ż���
 * @param box			����
 * @param size			���ųߴ�
 */
void scale_boxes(cv::Rect& box, cv::Size size);


/**
 * @brief post_process		����
 * @param origin_image		ԭʼͼ��
 * @param processed_image	������ͼ��
 */
std::vector<cv::Rect> post_process(cv::Mat& origin_image, std::vector<cv::Mat>& processed_image);