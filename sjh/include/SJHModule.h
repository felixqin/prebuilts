/*-----------------------------------------------------------------------------------------------   
	Copyright (C), 1997-2007, ShuangJieHe Tech. Co., Ltd.    
	File name:   SJHModule.h       
	Author:		 SJHLPR    
	Mail: 		 service@shuangjiehe.com
	Version:	 V2.3	     
	Date:		 2007/10/29
	Description: 
		车牌识别的接口。             
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
* @brief                        初始化识别
* @param    nWidth              待识别图像最大宽度
* @param    nHeight             待识别图像最大高度
* @param    sPassword           为识别认证序列号<仅对DSP有效>
* @return                       返回识别实例句柄 <=0 为初始化失败 此句柄传入识别函数中
------------------------------------------------------------------------------------------------------*/
SJHAPI SJHHANDLE SJHLPRCreateEngine(IN int nWidth, IN int nHeight, IN char *sPassword);


/*-----------------------------------------------------------------------------------------------------!
* @brief     释放识别库
* @return     
------------------------------------------------------------------------------------------------------*/
SJHAPI void SJHLPRDestoryEngine(IN SJHHANDLE hLPR);

/*-----------------------------------------------------------------------------------------------!
* @brief                      单帧识别函数
* @param    hLPR              识别实例句柄
* @param    pImage            识别图像数据
* @param    nWidth            识别图像最大宽度
* @param    nHeight           识别图像最大高度
* @param    nRecMode          识别模式 参考宏定义
* @param    nFrametype        输入的图像格式 参考宏定义
* @param    roiRect           识别区域
* @param    pPlateResult      识别结果
* @param    pPlateNum         输入需要识别的车牌个数 输出实际识别到的车牌个数
* @return                     实际识别到的车牌个数
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
* @brief                      注册回调函数 对视频识别有效
* @param    hLPR              识别实例句柄
* @param    pFun              回调函数入口地址
* @param    pUser             用户数据
* @return                     1 为成功  其他为失败
------------------------------------------------------------------------------------------------------*/
SJHAPI SJHRESULT    SJHLPRRegCallBack(IN SJHHANDLE hLPR, IN SJHLPRResultFun pFun,   IN void *pUser);
SJHAPI SJHRESULT  SJHLPRRegCallBackEx(IN SJHHANDLE hLPR, IN SJHLPRResultFunEx pFun, IN void *pUser); 

#endif 



/*-----------------------------------------------------------------------------------------------!
* @brief                      视频识别函数
* @param    hLPR              识别实例句柄
* @param    pImage            识别图像数据
* @param    nWidth            识别图像最大宽度
* @param    nHeight           识别图像最大高度
* @param    nFrametype        输入的图像格式 参考宏定义
* @param    rlRegion          识别区域数组 参考定义
* @return                     实际识别到的车牌个数
------------------------------------------------------------------------------------------------------*/
SJHAPI int SJHLPRLPRRecogVideo(IN SJHHANDLE hLPR, IN unsigned char  *pImage, IN int nWidth, IN int nHeight, 
                               IN SJHIMGFORMAT nFrametype, IN SJHRectList rlRegion);

/*-----------------------------------------------------------------------------------------------------!
* @brief                    获取识别库的版本号
* @return                   版本号(32位无符号数),如返回0x010203131011,则表示当前版本为v1.2.3 时间 2013-10-11
------------------------------------------------------------------------------------------------------*/
SJHAPI unsigned int SJHLPRGetVision();     


/*-----------------------------------------------------------------------------------------------------!
* @brief                      设置视频识别的参数
* @param    lprid             识别句柄
* @param    pVideoParam       识别参数 参考定义
* @return     
------------------------------------------------------------------------------------------------------*/
SJHAPI SJHRESULT SJHLPRSetVideoRecogParam(IN SJHHANDLE hLPR, IN SJHVideoParam * pVideoParam);


#ifdef DSP
	// DSP下获取相机的ID号 12 BIT
	SJHAPI SJHRESULT SJHLPFGetCamID(IN unsigned char *pCamID);
	
	
	// 初始化相机环境 ，在Roseek_SysParamInit 中调用
	SJHAPI BOOL SJHLPRInitCamEvn() ;
#endif 



	/*!
	以下函数对用户开放 用于2次加密
	*/


	/*!
	* @brief     获取加密狗唯一的ID号  
	* @param	id            获取的ID号   用户可以用唯一的id号进行加密
	* @return     >0 表示获取ID号的位数，<=0 表示未获取到 ，默认情况为12位
	*/
	SJHAPI int   SJHGetUniqueID( unsigned char *id   ) ;


	/*!
	* @brief    写入用户数据
	* @param	password : 用户设置的password，在写入时 指定password，读出时必须一致 ，否则读不出数据          
	* @param	passwordlen   : 用户密码长度  8 字节 超过8字节取前8字节
	* @param	dataid   : 用户写入的数据的ID号
	* @param	userdata   : 用户写入的数据， 
	* @param	datalen   : 用户写入的数据的长度 最大 32 字节 ， 
	* @return     >=0 表示写入成功 <0  表示写入失败

	建议： 不要频繁写加密狗，2次使用时候  一般写入固定数据后 初始化仅仅读取就可以了

	dataid     规则   0x0A01 -- 0x0A20     每一个数据文件ID号需要不一样  id 不再此范围将无法写入
	*/
	SJHAPI int   SJHWriteUserData( unsigned char *password  , int  dataid , unsigned char *userdata ,int datalen   ) ;

	/*!
	* @brief    读出用户数据
	* @param	password : 用户写数据时的password，  
	* @param	passwordlen   : 用户密码长度  <=8 如果>8 取 前8字节
	* @param	userdata   : 用户读出的数据， 
	* @param	datalen   : 用户需要读出的数据长度 <= 32 字节
	* @return     >=0 表示写入成功 <0  表示写入失败
	*/

	SJHAPI int   SJHReadUserData(unsigned  char *password  , int   dataid ,unsigned char *userdata ,int  datalen   ) ;




#ifdef __cplusplus
}
#endif /* extern "C" */

#endif 
