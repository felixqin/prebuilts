/*-----------------------------------------------------------------------------------------------   
	Copyright (C), 1997-2007, ShuangJieHe Tech. Co., Ltd.    
	File name:   SJHDef.H       
	Author:		 SJHLPR  
	Mail: 		 service@shuangjiehe.com
	Version:	 V2.3	     
	Date:		 2007/10/29 	
	Description: 
		����ʶ��ģ��SDKͷ�ļ�, ��������, �ṹ����             
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

// ��������
typedef DWORD SJHRESULT;

#define SJH_INVALIDE_KEY           (-9) 	//for pc 
#define SJH_ERROR_IMAG             (-8)
#define SJH_IKEY_ERROR             (-7)  	// for  dsp 
#define SJH_MEM_ERROR              (-6)
#define SJH_LPR_OK                 (0)

 
// ͼ���ʽ
typedef DWORD SJHIMGFORMAT;
#define SJH_LRPBGR                 (0x01)
#define SJH_LPRYUV420P             (0x02)
#define SJH_LPRYUV422P             (0x03)
#define SJH_LPRUYVY422             (0x04)
#define SJH_LPRYUV420SP       	   (0x05)


// ʶ��ģʽ
typedef DWORD SJHLPRMODE;
#define SJH_RM_EFAST               (0x01)     // ����ʶ�� ��ʶ��һ���߶ȵĳ��� �ٶȽϿ�
#define SJH_RM_ENORMAL             (0x02)     // ����ʶ�� ��ʶ��Χ�ϴ�ĳ��� �����ٶȻ����fast��
#define SJH_RM_EFINE               (0x03)     // �ݲ�֧��


// �������� 
typedef DWORD SJHPLATETYPE;
#define SJH_PT_NORMALBLUE          (0x01)    // ����
#define SJH_PT_NORMALYELLOW        (0x02)    // ����
#define SJH_PT_DOBLEYELLOW         (0x03)    // ˫�����
#define SJH_PT_NORMALBLACK         (0x04)    // �ۡ�����
#define SJH_PT_WHITEPOLICE         (0x05)    // ����
#define SJH_PT_OLD_JUN             (0x06)    // ��ʽ����
#define SJH_PT_NEW_JUN             (0x07)    // ��ʽ����
#define SJH_PT_OLD_WJ              (0x08)    // ��ʽ�侯
#define SJH_PT_NEW_WJ              (0x09)    // ��ʽ�侯
#define SJH_PT_MOTOR               (0x0A)    // Ħ�г�
#define SJH_PT_NONGYONG            (0x0B)    // ũ�ó���

// ������ɫ
typedef DWORD SJHPLATECOLOR;
#define SJH_PC_UNKNOWN             (0)    // δ֪
#define SJH_PC_BLUE                (1)    // ���װ���
#define SJH_PC_YELLOW              (2)    // �Ƶ׺���
#define SJH_PC_WHITE               (3)    // �׵׺���
#define SJH_PC_BLACK               (4)    // �ڵװ���     
#define SJH_PC_GREEN               (5)    // �̵װ���     


typedef DWORD SJHCOLORREF;
#define SJHRGB(r,g,b) ((SJHCOLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define SJHGetRValue(rgb)      ((BYTE)(rgb))
#define SJHGetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define SJHGetBValue(rgb)      ((BYTE)((rgb)>>16))


//  ---------- �������������Ҫ�ϲ� ---------------------------------------
typedef struct _tagSJHPoint
{
	int x;
	int y;
}SJHPoint, *PSJHPoint;


///ʶ������ ROI   
typedef struct _tagSJHRectROI
{
	int left;
	int top;
	int right;
	int bottom;
}SJHRectROI, *PSJHRectROI;


typedef struct _tagSJHRectList
{
		int                     nROINum; 		 // ������� 0-4 
		SJHRectROI              aRectROI[SJH_MAX_ROI];   // �����λ�� 
		
		//���ƴ�С   
		//0 ->100-150     
		//1  -> 150-200  	
		//2--> 60-80   
		//3 -> 80-100    
		//4  --->  ���� 200
		// 5  С��60
		
		// ���û������ �Զ���������ͼƬ�ֱ��ʼ�������Ŀ�������ŷ�Χ
		// ���� 1600*1200 ����ʶ������ ��Ϊ��������ʶ�� ���ƶ�Ӧ��СӦ���� 110 ����
		// �ʶ�Ӧ��size Ϊ0
		int                    nPlateSize[SJH_MAX_ROI]; // ÿ�������Ӧ�ĳ��ƴ�С��Χ
	
}SJHRectList ,*PSJHRectList;
	

typedef struct  _tagSJHPlateInfo
{
		char                   aPlateNum[SJH_LPR_PLATE_NUM_LEN];			// ���ƺ���
		char                   aPlateColor[SJH_LPR_COLOR_LEN];  			// ������ɫ
		char                   aCarColor[SJH_LPR_COLOR_LEN];  				// ������ɫ /����
		float                  fPlateRealty;                                // �������Ŷ�
		SJHRectROI             roiPlate;                                    // ����λ��(left top right bottom)
		int                    nPlateType;			
		float                  fLetterRealty[SJH_LPR_PLATE_NUM_LEN];	    // ÿһ���ַ������Ŷ�
}SJHPlateInfo, *PSJHPlateInfo;											// ������Ϣ



typedef struct _tagSJHVideoParam
{
		int          nMissFrame;   			    // ��ʧ��֡��  ��Ĭ��3 ��ʶ��һ�κ� ���� ʶ�𲻵���֡�� ��
		int          nIntervalFrame;  	    // ǰ��֡���֡��  ��Ĭ��20 ����ʵ��֡�ʺͳ�������  ̫����ܻ�©����̫С�Ļ�ռ��Դ�Ƚ϶ࡷ
		int          nUseMotion; 			      // 1 ��ʾ�����˶����  0 ��ʾ������ <Ĭ������>
}SJHVideoParam, *PSJHVideoParam;


typedef struct _tagSJHVideoLPROut
{
		// ÿ�������Ӧһ��ͼ��buffer
		unsigned char         *pImage[SJH_MAX_ROI];
		
		// ÿ�����򷵻�ͼ��Ŀ�Ⱥ͸߶�
		int                   nWidth[SJH_MAX_ROI];
		int                   nHeight[SJH_MAX_ROI];
		
		// ÿ�������Ӧ�ĳ�����Ϣ
		SJHPlateInfo         aPlate[SJH_MAX_ROI];
		
		// ÿ�������Ƿ���ץ�ĵ�����TRUE �� FALSE ��
		BOOL                 bHaveResult[SJH_MAX_ROI];
}SJHVideoLPROut, *PSJHVideoLPROut;


typedef struct  _tagSJHLPRLoop
{
	BYTE  		bID; 							// ��Ȧ���
 	BYTE  		bEnable; 						// ��Ȧʹ��
 	BYTE  		bDraw; 							// �Ƿ������Ȧ
 	BYTE  		bRes[1];						//  ����
 	char  		strName[SJH_NAME_LEN];			// ��Ȧ����
 	SJHPoint  	aPoints[SJH_POINTS_COUNT];		// ��Ȧ��
}SJHLPRLoop, *PSJHLPRLoop;
	
    #ifdef WIN32
	
/*-----------------------------------------------------------------------------------------------!
* @brief                    �ص���������
* @param    hLPR            ʶ����
* @param    pImage          ��Ƶʶ��ץ�ĵ�ͼƬ ��ʱΪBGR����
* @param    nWidth          ץ��ͼ�Ŀ��
* @param    nHeight         ץ��ͼ�ĸ߶�
* @param    roiindex        ץ��ͼ����Ӧ��ʶ�������id��ʵ�ʶ�Ӧ����
* @param    lprresult       ʶ����
* @param    pUser           �û����� <ʵ���û�����Я��һЩ���ݽ�ȥ>

* @return  ����ʶ��ʵ����� <=0 Ϊ��ʼ��ʧ�� �˾������ʶ������
* @��ע:   �ص��������û���Ӧ���к�ʱ�����Ĵ��룬�����Ҫѹ��ͼƬ���뾡����ͼƬ���������
 ������һ�߳��н���ѹ��,�����ص����ֻ��1����
------------------------------------------------------------------------------------------------------*/
typedef long   (CALLBACK *SJHLPRResultFun)(IN SJHHANDLE hLPR, IN BYTE *pImage, IN int nWidth, IN int nHeight, 
                               IN int nROIIndex,  IN SJHPlateInfo *pLPRResult,    IN void * pUser);  //�ص�
typedef long (CALLBACK *SJHLPRResultFunEx)(IN SJHHANDLE hLPR, IN BYTE *pImage, IN int nWidth, IN int nHeight, 
                               IN int nROIIndex,  IN char *PlateNum,              IN char *sPlateColor, 
                               IN int nPlateLeft, IN int nPlateTop, IN int nPlateRight, IN int nPlateBottom, 
                               IN void * pUser);  //�ص�1

#endif 
#endif


