/*-----------------------------------------------------------------------------------------------   
	Copyright (C), 1997-2007, ShuangJieHe Tech. Co., Ltd.    
	File name:   SJHModule.h       
	Author:		 SJHLPR    
	Mail: 		 service@shuangjiehe.com
	Version:	 V2.3	     
	Date:		 2007/10/29
	Description: 
		����ʶ��Ľӿڡ�             
  	Others:            
	Function List:         
	
	History:                
		1. Date: 29:10:2007   16:13        
		   Author:  SJHLPR       
		   Modification:  Create    
-----------------------------------------------------------------------------------------------*/
#ifndef SJH_MODULE_H_20071029
#define SJH_MODULE_H_20071029

#ifdef WIN32 
#define  SJHAPI  __declspec(dllexport)       
#else
#define SJHAPI
#endif

#include "SJHDef.h"
#ifdef __cplusplus
extern "C" {
#endif


/*-----------------------------------------------------------------------------------------------!
* @brief                        ��ʼ��ʶ��
* @param    nWidth              ��ʶ��ͼ�������
* @param    nHeight             ��ʶ��ͼ�����߶�
* @param    sPassword           Ϊʶ����֤���к�<����DSP��Ч>
* @return                       ����ʶ��ʵ����� <=0 Ϊ��ʼ��ʧ�� �˾������ʶ������
------------------------------------------------------------------------------------------------------*/
SJHAPI SJHHANDLE SJHLPRCreateEngine(IN int nWidth, IN int nHeight, IN char *sPassword);


/*-----------------------------------------------------------------------------------------------------!
* @brief     �ͷ�ʶ���
* @return     
------------------------------------------------------------------------------------------------------*/
SJHAPI void SJHLPRDestoryEngine(IN SJHHANDLE hLPR);

/*-----------------------------------------------------------------------------------------------!
* @brief                      ��֡ʶ����
* @param    hLPR              ʶ��ʵ�����
* @param    pImage            ʶ��ͼ������
* @param    nWidth            ʶ��ͼ�������
* @param    nHeight           ʶ��ͼ�����߶�
* @param    nRecMode          ʶ��ģʽ �ο��궨��
* @param    nFrametype        �����ͼ���ʽ �ο��궨��
* @param    roiRect           ʶ������
* @param    pPlateResult      ʶ����
* @param    pPlateNum         ������Ҫʶ��ĳ��Ƹ��� ���ʵ��ʶ�𵽵ĳ��Ƹ���
* @return                     ʵ��ʶ�𵽵ĳ��Ƹ���
------------------------------------------------------------------------------------------------------*/
SJHAPI int SJHLPRRecogPhoto(IN SJHHANDLE hLPR, IN unsigned char *pImage, IN int nWidth, IN int nHeight, 
                            IN SJHLPRMODE nRecMode, IN SJHIMGFORMAT nFrametype, IN SJHRectROI roiRect, 
						    OUT SJHPlateInfo *pPlateResult, INOUT int *pPlateNum);



SJHAPI int SJHLPRRecogPhotoEx(IN SJHHANDLE hLPR, IN unsigned char *pImage, IN int nWidth, IN int nHeight, 
                             IN SJHIMGFORMAT nFrametype,  IN float  vertratio ,IN float horzratio ,IN SJHRectROI roiRect, 
						    OUT SJHPlateInfo *pPlateResult, INOUT int *pPlateNum);




SJHAPI int SJHLPRLPRRecogVideoEx(IN SJHHANDLE hLPR, IN unsigned char  *pImage, IN int nWidth, IN int nHeight, 
                              IN SJHIMGFORMAT nFrametype,  IN float  vertratio ,IN float horzratio ,IN SJHRectROI roiRect, 
						    OUT SJHPlateInfo *pPlateResult, INOUT int *pPlateNum);





#ifdef WIN32

/*-----------------------------------------------------------------------------------------------!
* @brief                      ע��ص����� ����Ƶʶ����Ч
* @param    hLPR              ʶ��ʵ�����
* @param    pFun              �ص�������ڵ�ַ
* @param    pUser             �û�����
* @return                     1 Ϊ�ɹ�  ����Ϊʧ��
------------------------------------------------------------------------------------------------------*/
SJHAPI SJHRESULT    SJHLPRRegCallBack(IN SJHHANDLE hLPR, IN SJHLPRResultFun pFun,   IN void *pUser);
SJHAPI SJHRESULT  SJHLPRRegCallBackEx(IN SJHHANDLE hLPR, IN SJHLPRResultFunEx pFun, IN void *pUser); 

#endif 



/*-----------------------------------------------------------------------------------------------!
* @brief                      ��Ƶʶ����
* @param    hLPR              ʶ��ʵ�����
* @param    pImage            ʶ��ͼ������
* @param    nWidth            ʶ��ͼ�������
* @param    nHeight           ʶ��ͼ�����߶�
* @param    nFrametype        �����ͼ���ʽ �ο��궨��
* @param    rlRegion          ʶ���������� �ο�����
* @return                     ʵ��ʶ�𵽵ĳ��Ƹ���
------------------------------------------------------------------------------------------------------*/
SJHAPI int SJHLPRLPRRecogVideo(IN SJHHANDLE hLPR, IN unsigned char  *pImage, IN int nWidth, IN int nHeight, 
                               IN SJHIMGFORMAT nFrametype, IN SJHRectList rlRegion);

/*-----------------------------------------------------------------------------------------------------!
* @brief                    ��ȡʶ���İ汾��
* @return                   �汾��(32λ�޷�����),�緵��0x010203131011,���ʾ��ǰ�汾Ϊv1.2.3 ʱ�� 2013-10-11
------------------------------------------------------------------------------------------------------*/
SJHAPI unsigned int SJHLPRGetVision();     


/*-----------------------------------------------------------------------------------------------------!
* @brief                      ������Ƶʶ��Ĳ���
* @param    lprid             ʶ����
* @param    pVideoParam       ʶ����� �ο�����
* @return     
------------------------------------------------------------------------------------------------------*/
SJHAPI SJHRESULT SJHLPRSetVideoRecogParam(IN SJHHANDLE hLPR, IN SJHVideoParam * pVideoParam);


#ifdef DSP
	// DSP�»�ȡ�����ID�� 12 BIT
	SJHAPI SJHRESULT SJHLPFGetCamID(IN unsigned char *pCamID);
	
	
	// ��ʼ��������� ����Roseek_SysParamInit �е���
	SJHAPI BOOL SJHLPRInitCamEvn() ;
#endif 



	/*!
	���º������û����� ����2�μ���
	*/


	/*!
	* @brief     ��ȡ���ܹ�Ψһ��ID��  
	* @param	id            ��ȡ��ID��   �û�������Ψһ��id�Ž��м���
	* @return     >0 ��ʾ��ȡID�ŵ�λ����<=0 ��ʾδ��ȡ�� ��Ĭ�����Ϊ12λ
	*/
	SJHAPI int   SJHGetUniqueID( unsigned char *id   ) ;


	/*!
	* @brief    д���û�����
	* @param	password : �û����õ�password����д��ʱ ָ��password������ʱ����һ�� ���������������          
	* @param	passwordlen   : �û����볤��  8 �ֽ� ����8�ֽ�ȡǰ8�ֽ�
	* @param	dataid   : �û�д������ݵ�ID��
	* @param	userdata   : �û�д������ݣ� 
	* @param	datalen   : �û�д������ݵĳ��� ��� 32 �ֽ� �� 
	* @return     >=0 ��ʾд��ɹ� <0  ��ʾд��ʧ��

	���飺 ��ҪƵ��д���ܹ���2��ʹ��ʱ��  һ��д��̶����ݺ� ��ʼ��������ȡ�Ϳ�����

	dataid     ����   0x0A01 -- 0x0A20     ÿһ�������ļ�ID����Ҫ��һ��  id ���ٴ˷�Χ���޷�д��
	*/
	SJHAPI int   SJHWriteUserData( unsigned char *password  , int  dataid , unsigned char *userdata ,int datalen   ) ;

	/*!
	* @brief    �����û�����
	* @param	password : �û�д����ʱ��password��  
	* @param	passwordlen   : �û����볤��  <=8 ���>8 ȡ ǰ8�ֽ�
	* @param	userdata   : �û����������ݣ� 
	* @param	datalen   : �û���Ҫ���������ݳ��� <= 32 �ֽ�
	* @return     >=0 ��ʾд��ɹ� <0  ��ʾд��ʧ��
	*/

	SJHAPI int   SJHReadUserData(unsigned  char *password  , int   dataid ,unsigned char *userdata ,int  datalen   ) ;




#ifdef __cplusplus
}
#endif /* extern "C" */

#endif 
