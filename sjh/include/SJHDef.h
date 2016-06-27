/*-----------------------------------------------------------------------------------------------   
	Copyright (C), 1997-2007, ShuangJieHe Tech. Co., Ltd.    
	File name:   SJHDef.H       
	Author:		 SJHLPR  
	Mail: 		 service@shuangjiehe.com
	Version:	 V2.3	     
	Date:		 2007/10/29 	
	Description: 
		车牌识别模块SDK头文件, 常量定义, 结构定义             
  	Others:            
	Function List:         
	
	History:                
		1. Date: 29:10:2007   16:13        
		   Author:  SJHLPR       
		   Modification:  Create    
-----------------------------------------------------------------------------------------------*/
#ifndef SJH_DEF_H_20071029
#define SJH_DEF_H_20071029

#include "afx.h"


typedef long SJHHANDLE;
#define IN
#define OUT
#define INOUT
#define SJH_LPR_PLATE_NUM_LEN      (16)
#define SJH_LPR_COLOR_LEN          (8)
#define SJH_MAX_ROI                (4) 
#define SJH_NAME_LEN			   (24)
#define SJH_POINTS_COUNT		   (8)
#define SJH_VCLIST_LEN				(128)

// 错误类型
typedef DWORD SJHRESULT;

#define SJH_INVALIDE_KEY           (-9) 	//for pc 
#define SJH_ERROR_IMAG             (-8)
#define SJH_IKEY_ERROR             (-7)  	// for  dsp 
#define SJH_MEM_ERROR              (-6)
#define SJH_LPR_OK                 (0)

 
// 图像格式
typedef DWORD SJHIMGFORMAT;
#define SJH_LRPBGR                 (0x01)
#define SJH_LPRYUV420P             (0x02)
#define SJH_LPRYUV422P             (0x03)
#define SJH_LPRUYVY422             (0x04)
#define SJH_LPRYUV420SP       	   (0x05)


// 识别模式
typedef DWORD SJHLPRMODE;
#define SJH_RM_EFAST               (0x01)     // 快速识别 仅识别一定尺度的车牌 速度较快
#define SJH_RM_ENORMAL             (0x02)     // 正常识别 可识别范围较大的车牌 可能速度会相对fast慢
#define SJH_RM_EFINE               (0x03)     // 暂不支持


// 车牌类型 
typedef DWORD SJHPLATETYPE;
#define SJH_PT_NORMALBLUE          (0x01)    // 蓝牌
#define SJH_PT_NORMALYELLOW        (0x02)    // 黄牌
#define SJH_PT_DOBLEYELLOW         (0x03)    // 双层黄牌
#define SJH_PT_NORMALBLACK         (0x04)    // 港、澳牌
#define SJH_PT_WHITEPOLICE         (0x05)    // 警车
#define SJH_PT_OLD_JUN             (0x06)    // 老式军牌
#define SJH_PT_NEW_JUN             (0x07)    // 新式军牌
#define SJH_PT_OLD_WJ              (0x08)    // 老式武警
#define SJH_PT_NEW_WJ              (0x09)    // 新式武警
#define SJH_PT_MOTOR               (0x0A)    // 摩托车
#define SJH_PT_NONGYONG            (0x0B)    // 农用车牌

// 车牌颜色
typedef DWORD SJHPLATECOLOR;
#define SJH_PC_UNKNOWN             (0)    // 未知
#define SJH_PC_BLUE                (1)    // 蓝底白字
#define SJH_PC_YELLOW              (2)    // 黄底黑字
#define SJH_PC_WHITE               (3)    // 白底黑字
#define SJH_PC_BLACK               (4)    // 黑底白字     
#define SJH_PC_GREEN               (5)    // 绿底白字     


typedef DWORD SJHCOLORREF;
#define SJHRGB(r,g,b) ((SJHCOLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define SJHGetRValue(rgb)      ((BYTE)(rgb))
#define SJHGetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define SJHGetBValue(rgb)      ((BYTE)((rgb)>>16))


//  ---------- 下面的这两个需要合并 ---------------------------------------
typedef struct _tagSJHPoint
{
	int x;
	int y;
}SJHPoint, *PSJHPoint;


///识别区域 ROI   
typedef struct _tagSJHRectROI
{
	int left;
	int top;
	int right;
	int bottom;
}SJHRectROI, *PSJHRectROI;


typedef struct _tagSJHRectList
{
		int                     nROINum; 		 // 区域个数 0-4 
		SJHRectROI              aRectROI[SJH_MAX_ROI];   // 区域的位置 
		
		//车牌大小   
		//0 ->100-150     
		//1  -> 150-200  	
		//2--> 60-80   
		//3 -> 80-100    
		//4  --->  大于 200
		// 5  小于60
		
		// 如果没有设置 自动根据输入图片分辨率及车道数目来计算大概范围
		// 比如 1600*1200 两个识别区域 认为是两车道识别 车牌对应大小应该在 110 左右
		// 故对应的size 为0
		int                    nPlateSize[SJH_MAX_ROI]; // 每个区域对应的车牌大小范围
	
}SJHRectList ,*PSJHRectList;
	

typedef struct  _tagSJHPlateInfo
{
		char                   aPlateNum[SJH_LPR_PLATE_NUM_LEN];			// 车牌号码
		char                   aPlateColor[SJH_LPR_COLOR_LEN];  			// 车牌颜色
		char                   aCarColor[SJH_LPR_COLOR_LEN];  				// 车身颜色 /暂无
		float                  fPlateRealty;                                // 车牌置信度
		SJHRectROI             roiPlate;                                    // 车牌位置(left top right bottom)
		int                    nPlateType;			
		float                  fLetterRealty[SJH_LPR_PLATE_NUM_LEN];	    // 每一个字符的置信度
}SJHPlateInfo, *PSJHPlateInfo;											// 车牌信息



typedef struct _tagSJHVideoParam
{
		int          nMissFrame;   			    // 丢失的帧数  《默认3 ，识别到一次后 接着 识别不到的帧数 》
		int          nIntervalFrame;  	    // 前后帧间隔帧数  《默认20 根据实际帧率和车速设置  太大可能会漏车，太小的话占资源比较多》
		int          nUseMotion; 			      // 1 表示启用运动检测  0 表示不启用 <默认启用>
}SJHVideoParam, *PSJHVideoParam;


typedef struct _tagSJHVideoLPROut
{
		// 每个区域对应一个图像buffer
		unsigned char         *pImage[SJH_MAX_ROI];
		
		// 每个区域返回图像的宽度和高度
		int                   nWidth[SJH_MAX_ROI];
		int                   nHeight[SJH_MAX_ROI];
		
		// 每个区域对应的车牌信息
		SJHPlateInfo         aPlate[SJH_MAX_ROI];
		
		// 每个区域是否有抓拍的数据TRUE 有 FALSE 无
		BOOL                 bHaveResult[SJH_MAX_ROI];
}SJHVideoLPROut, *PSJHVideoLPROut;


typedef struct  _tagSJHLPRLoop
{
	BYTE  		bID; 							// 线圈编号
 	BYTE  		bEnable; 						// 线圈使能
 	BYTE  		bDraw; 							// 是否绘制线圈
 	BYTE  		bRes[1];						//  保留
 	char  		strName[SJH_NAME_LEN];			// 线圈名称
 	SJHPoint  	aPoints[SJH_POINTS_COUNT];		// 线圈点
}SJHLPRLoop, *PSJHLPRLoop;
	
    #ifdef WIN32
	
/*-----------------------------------------------------------------------------------------------!
* @brief                    回调函数声明
* @param    hLPR            识别句柄
* @param    pImage          视频识别抓拍的图片 暂时为BGR数据
* @param    nWidth          抓拍图的宽度
* @param    nHeight         抓拍图的高度
* @param    roiindex        抓拍图所对应的识别区域的id号实际对应车道
* @param    lprresult       识别结果
* @param    pUser           用户数据 <实际用户可以携带一些数据进去>

* @return  返回识别实例句柄 <=0 为初始化失败 此句柄传入识别函数中
* @备注:   回调函数中用户不应运行耗时过长的代码，如果需要压缩图片，请尽量将图片加入队列中
 在另外一线程中进行压缩,两个回调最好只用1个。
------------------------------------------------------------------------------------------------------*/
typedef long   (CALLBACK *SJHLPRResultFun)(IN SJHHANDLE hLPR, IN BYTE *pImage, IN int nWidth, IN int nHeight, 
                               IN int nROIIndex,  IN SJHPlateInfo *pLPRResult,    IN void * pUser);  //回调
typedef long (CALLBACK *SJHLPRResultFunEx)(IN SJHHANDLE hLPR, IN BYTE *pImage, IN int nWidth, IN int nHeight, 
                               IN int nROIIndex,  IN char *PlateNum,              IN char *sPlateColor, 
                               IN int nPlateLeft, IN int nPlateTop, IN int nPlateRight, IN int nPlateBottom, 
                               IN void * pUser);  //回调1

#endif 
#endif


