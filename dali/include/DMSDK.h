#ifndef _SDK_DM_INTERFACE_H
#define _SDK_DM_INTERFACE_H

/*
#ifdef	DM_SDK_EXPORTS 
	#define DM_SDK_API _declspec(dllexport) //__stdcall
#else
	#define DM_SDK_API _declspec(dllimport) //__stdcall		
#endif
*/
#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef long LONG;

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;


#define SPEED_TRG_PAN	0	//ˮƽ
#define SPEED_TRG_TILT	1	//��ֱ

//��ɫ������
	//�Զ�		0
	//��		1
	//��		2
	//��		3
	//��		4
	//��		5
	//��		6
	//��		7
	//��		8
	//��		9


//Yuntai command
enum DALI_CONTROL_CMD_DIR {
	DALI_YUN_CONTROL,	//Yuntai
		DALI_LENS_CONTROL,	//Lens
		DALI_IRIS_CONTROL,	//Aperture
};

enum VIDEO_OUT_TYPE {
	PAL = 0,
		NTSC,
};

typedef struct tagTemperature
{
    int type;
    int number;
    int temper;
}_tagTemperature;

typedef struct tagTempHandle
{
	int handle;
	int len;
}_tagTempHandle;


//2012-01-22 add, �ص�������ʽ�ϴ��¶���Ϣʱʹ�øýṹ
typedef struct tagTempMessage
{
	int handle;
	int len;//temperInfo�ĸ���
	char dvrIP[16];
	tagTemperature  temperInfo[10];
}_tagTempMessagee;

typedef struct tagAlarm {
	int AlarmID;
}_tagAlarm;

///Capture Message
typedef struct tagCaptureFrame {
	int TotalNum;
	int CurrNum;
}_tagCaptureFrame;

///Error Message
struct  tagError {
	int ErrorType;
	int ErrorID;
};

///System Info
struct tagSystemInfo 
{
	char SDKVer[50];
	char NETVer[50];
	char DSPVer[50];
	char FPGAVer[50];
};

//������õ��ľ���
struct tagDistanceInfo 
{
	int distance1;
	int distance2;
	int distance3;
};

//DM6x���͵ķֱ���,2013-05-27 add
struct tagResolutionInfo 
{
	int width;
	int height;
};


///Error ID
#define DM_SUCCESS						 0x00000000

//ErrType
#define DM_OPEN_DIR_ERROR				-0x00002003		///> Open Directory Fail
#define DM_SOCKET_ERROR					-0x00001000		///> Socket Disconnect
#define DM_COMMAND_ERROR				-0x00001003		///> Command Send Fail
#define DM_OPEN_ERROR					-0x00003001		///> Open device Fail

//OPEN_DIR ERROR��ID
#define DM_OPEN_FILE_ERROR				-0x00002001		///> Open File Fail
#define DM_CLOSE_FILE_ERROR				-0x00002002		///> Close File Fail

//SOCKET ERROR ID
#define DM_SOCKET_SEND_ERROR			-0x00001001		///> Send Data Fail
#define DM_SOCKET_RECV_ERROR			-0x00001002		///> Recv Data Fail
#define DM_SOCKET_RECONNECT				-0x00001004		///> reconnect device


///CMD ERROR��ID
#define CMD_CAPTURE_ERROR				-0x00004001     ///> Capture fail
#define CMD_TEMPATURE_ERROR				-0x00004002     ///> Tempature Fail

//Open device ERROR��ID
#define CMD_FORWARD_SUCCESS				 0x00004000     ///> Open Device front success
#define CMD_FORWARD_ERROR               -0x00004003     ///> Open Device front fail

//2010-12-02 add
#define DM_ERROR_LOCALLOGINMAX		-0x00005001	//���ص�½��DVR���Ѿ����
#define DM_ERROR_LOGIN			-0x00005002	//��½DVRʧ��
#define DM_ERROR_LOGINHANDLE			-0x00005003	//����ľ��
#define DM_ERROR_LOGINSTATUS			-0x00005004	//û�е�½
#define DM_ERROR_NOSUPPORT			-0x00005005	//��֧�ֵĺ����ӿ�

#define DM_ERROR_REALPLAYMAX	-0x00006001	//���ص�ʵʱ�������Ѿ����

#define WM_APP						0x8000
//�������֪ͨ
#define WM_DM_PLAYER_ERROR			(WM_APP + 0x1050)   ///> Video error

//wParam : ��������ľ����
//lParam : SDKΨһ��ʾID,��ID�ɿͻ�����SetUniSDKID�����趨 2008-04-11 add

//�طŽ���֪ͨ��Ϣ
#define WM_PLAYBACK_OVER			(WM_APP + 0x1051)
//wParam : ��������ľ����
//lParam : SDKΨһ��ʾID,��ID�ɿͻ�����SetUniSDKID�����趨 2008-04-11 add

//�����Խ��쳣��Ϣ
#define WM_TALK_ERROR				(WM_APP + 0x1052)
//wParam : ��������ĶԽ������			
//lParam : SDKΨһ��ʾID,��ID�ɿͻ�����SetUniSDKID�����趨 2008-04-11 add

#define WM_DM_ERROR				(WM_APP + 0x3051)	//2010-09-07 add

#define WM_DM_CAPTURE_FRAME		(WM_APP + 0x3052)
//wParam ԭʼ������Ϣ����
//lParam	�豸���

#define WM_DM_TEMP_VALUE            (WM_APP + 0x3053)
//wParam  �¶���Ϣ����
//lParam   �豸���
//ʵʱ�¶���Ϣ

#define WM_DM_TEMP_ALARM			(WM_APP + 0x3054)
//wParam  ������Ϣ����
//lParam   �豸���
//�¶ȱ���

//ԭʼ���ݲɼ�����֪ͨ��Ϣ
#define WM_CAPTUREINFRA_OVER			(WM_APP + 0x3055)

#define WM_DM_PLAYER				(WM_APP + 0x3061)	///> Video handle(//2010-09-07 add,openmonitor���óɹ�������Ϣ��


extern "C"   //��c����������
{

//add by ludc 2012-02-08
BOOL  __stdcall DM_SetTemperatureScope(int handle,  int dwValue1, int dwValue2);
BOOL  __stdcall DM_GetTemperatureScope(int handle,  int* dwValue1, int* dwValue2);


/****************************************************************************************************************/
/* �������úͲ���																								*/
/****************************************************************************************************************/
/*
 ��������:	DM_Init
*����˵��:	���ӳ�ʼ��
*�������:  
*����ֵ:			
*/
void __stdcall DM_Init();

/*
 ��������:	DM_Connect
*����˵��:	����DM60����
*�������:  hwnd��		��Ϣ�����ھ��
			IPAddr��	����IP��ַ
			Port��		����˿ڣ�Ĭ�϶˿�80��

  *����ֵ:  > 0 ���ӵ�������Ĳ������,��DM_Disconnect �ͷš�
		    <= 0 ����ʧ��			
*/
int __stdcall DM_Connect(HWND hwnd, char *IPAddr, int Port);

/*
 ��������:	DM_Disconnect
*����˵��:	�Ͽ�����
*�������:  handle�����
*����ֵ:  1�� ��ȷ��0�� ����			
*/
int __stdcall DM_Disconnect(int handle);

/****************************************************************************************************************/
/* ���¶���Ļ�ȡ������                                                                                         */
/****************************************************************************************************************/

/*
 ��������:	DM_SetSpot
*����˵��:	���ò��µ�
*�������:  handle��		���
			iPoint�� 		����			֧��4�����µ㣨1 - 4֮�䣩
			x,y��			������        ��Χ (0,0  ---  319 * 239)
			mode: 0-High/1-Low/2-Avg
			Emiss��		������  		��0 - 100��һ����90-95֮��
*����ֵ:			
*/
void  __stdcall DM_SetSpot(int handle,int iPoint,int x,int y, int Emiss = 90);

/*
 ��������:	DM_SetLine
*����˵��:	���ò�����
*�������:  handle��	���
			iLine��	�߱�ţ�Ŀǰ֧��һ���߲��£��̶�ֵ 1
			x1,y1��	��ʼ������ 	(0,0  ---  319 * 239)��
			x2,y2��	���������� 	(0,0  ---  319 * 239)
			x3,y3��	���ϲ��µ㣬���û�ָ���Ĳ��µ�
			lineType,���������ͣ�//0-Hori; 1-Vert; 2-Slash
			mode������ģʽ�� 0-High/1-Low/2-Avg
			Emiss��	�ȷ�����  		��0 - 100��һ����10 -- 100֮��

*����ֵ:			
*/
void  __stdcall DM_SetLine(int handle,int iLine,int x1,int y1,int x2,int y2, int x3,int y3, int Emiss = 90);

/*
 ��������:	DM_SetArea
*����˵��:	���ò�������
*�������:  handle��		���
			iArea��  		������		֧��3����������1 - 3��
			x1,y1�� 		���Ͻ�����		(0,0  ---  319 * 239)
			x2,y2�� 		���½�����		(0,0  ---  319 * 239)
			Emiss�� 		������  		��0 - 100��һ����90-95֮��
			MeasureType��	�������ʱ�Ĳ��·�ʽ ��0�� ��� 1����� 2��ƽ����
*����ֵ:			
*/
void __stdcall  DM_SetArea(int handle,int iArea,int x1,int y1,int x2,int y2,int Emiss = 90,int MeasureType = 0);

/*
 ��������:	DM_ClearSpot
*����˵��:	���SpotIDָ���Ĳ��µ���Ϣ
*�������:  handle��		���
			SpotID�� 		����		1 -- 4
*����ֵ:			
*/
void __stdcall  DM_ClearSpot(int handle,int SpotID);

/*
 ��������:	DM_ClearLine
*����˵��:	���LineIDָ���Ĳ��µ���Ϣ
*�������:  handle��	���
			LineID��  	�߱��	1
*����ֵ:			
*/
void __stdcall  DM_ClearLine(int handle,int LineID);

/*
 ��������:	DM_ClearArea
*����˵��:	���AreaIDָ���Ĳ���������Ϣ
*�������:  handle��	���
			AreaID��  	������	1 -- 3

*����ֵ:			
*/
void __stdcall  DM_ClearArea(int handle,int AreaID);

/*
 ��������:	DM_ClearAllSpot
*����˵��:	������в��µ�
*�������:  handle��	���
*����ֵ:			
*/
void __stdcall  DM_ClearAllSpot(int handle);

/*
 ��������:	DM_ClearAllLine
*����˵��:	������в�����
*�������:  handle��	���
*����ֵ:			
*/
void __stdcall  DM_ClearAllLine(int handle);

/*
 ��������:	DM_ClearAllArea
*����˵��:	������в�������
*�������:  handle��	���
*����ֵ:			
*/
void  __stdcall DM_ClearAllArea(int handle);

/*
 ��������:	DM_GetSpotTemp
*����˵��:	��ȡ�ⵥ�����µ��¶�
*�������:  handle��		���
			SpotID��		����(1--n)
			Mode��			0������һ���¶�
							1�����������¶ȣ����ʱ���������Զ�����
*����ֵ:			
*/
void __stdcall  DM_GetSpotTemp(int handle,int SpotID=1,int Mode = 0);

/*
 ��������:	DM_GetLineTemp
*����˵��:	��ȡ�ⵥ�����������û��趨���µ���¶�
*�������:  handle��		���
			LineID��		�߱�� (1 -- n)
			Mode��			0������һ���¶�
							1�����������¶ȣ����ʱ���������Զ�����
*����ֵ:			
*/
void __stdcall  DM_GetLineTemp(int handle,int LineID = 1,int Mode = 0);

/*
 ��������:	DM_GetAreaTemp
*����˵��:	��ȡ�������������¶�
*�������:  handle��		���
			AreaID��		������(1-- n)
			Mode��			0������һ���¶�
							1�����������¶ȣ����ʱ���������Զ����ڡ�

*����ֵ:			
*/
void __stdcall  DM_GetAreaTemp(int handle,int AreaID = 1,int Mode = 0);

/*
 ��������:	DM_GetTemp
*����˵��:	��ȡ���в���Ŀ��Ĳ��½��
*�������:  handle��		���
			Mode��			0������һ���¶�
							1�����������¶ȣ����ʱ���������Զ����ڡ�
*����ֵ:			
*/
void  __stdcall DM_GetTemp (int handle,int Mode);

/*
 ��������:	DM_StopTemp
*����˵��:	ֹͣ�������µķ�������
*�������:  handle��		���
*����ֵ:			
*/
void __stdcall  DM_StopTemp (int handle);

/*
 ��������:	DM_GetTempParam
*����˵��:	��ȡָ�����ͺͱ�ŵĲ��²���
*�������:  handle��	���
			Type��		������������ (1�� ��  2�� ��  3�� ����)
			Number��	���±�� (1 -- n)
*����ֵ:>0 �ɹ�			
*/
int __stdcall  DM_GetTempParam (int handle,int Type,int Number);


/****************************************************************************************************************/
/* ԭʼ���ݲɼ�                                                                                                 */
/****************************************************************************************************************/
/*
 ��������:	DM_CaptureInfraredFrame
*����˵��:	��ʼԭʼ���ݲɼ������ؽ������ϢWM_DM_CAPTURE_FRAME��3.1.2���д���
*�������:  handle��	���
			Path�� 		�����ļ���·�����ļ����������·������ϵͳ��ʱ�����ļ��������ڴ�·���£�������ļ�������ϵͳֱ����������ļ������档
			Frame�� 	֡��
			Time��		֡��֮֡��ļ��ʱ��(ms) >= 20ms���ұ�����20�ı�����
			ע�⣺Frame * Time <= 8��
*����ֵ:			
*/
int __stdcall  DM_CaptureInfraredFrame(int handle, char *Path,int Frame,int Time);

/*
 ��������:	DM_CaptureInfraredFrameStop
*����˵��:	ֹͣԭʼ���ݲɼ�
*�������:  handle		���,DM_CaptureInfraredFrame()�����ķ���ֵ
*����ֵ:			
*/
int  __stdcall DM_CaptureInfraredFrameStop(int handle);

/******************************************************************************************************************/
/* ͼ������                                                                                                       */
/******************************************************************************************************************/

/*
 ��������:	DM_SetPallette
*����˵��:	����ɫ��
*�������:  handle		���
			Type�� 		ɫ��� (0 -- 9) 
			bPorarity�� 		0������ 1������
*����ֵ:			
*/
void  __stdcall DM_SetPallette(int handle,int Type,  bool bPorarity = 0);

/*
 ��������:	DM_GetPallette
*����˵��:	��ȡ����������α��ɫɫ��
*�������:  handle		���
*����ֵ:    ��ǰɫ���			
*/
int  __stdcall DM_GetPallette(int handle);

/*
 ��������:	DM_SetVideoOutType
*����˵��:	������������Ƶ�����ʽ
*�������:  handle��			���
			VideoOutType��  0��PAL;1�� NTSC��
*����ֵ:			
*/
void  __stdcall DM_SetVideoOutType(int handle, VIDEO_OUT_TYPE VideoOutType);

/*
 ��������:	DM_GetVideoOutType
*����˵��:	��ȡ�����ĵ�ǰ��Ƶ�����ʽ(0��PAL;1�� NTSC��)
*�������:  handle��			���
*����ֵ:	��ǰ��Ƶ�����ʽ(0��PAL;1�� NTSC��)		
*/
int  __stdcall DM_GetVideoOutType(int handle);

/*
 ��������:	DM_SetVideoMode
*����˵��:	ͼ���ֶ�/�Զ�ģʽ�л�
*�������:  handle��		���
			Mode��			ģʽ(0���ֶ���2���Զ�)
*����ֵ:		
*/
void __stdcall  DM_SetVideoMode(int handle,int Mode);

/*
 ��������:	DM_AutoFocus
*����˵��:	�����Զ��۽�
*�������:  handle��		���
*����ֵ:		
*/
void  __stdcall DM_AutoFocus(int handle);

/*
 ��������:	DM_FocusFar
*����˵��:	�����������Զ
*�������:  handle��		���
			Step�� 		����
*����ֵ:		
*/
void  __stdcall DM_FocusFar(int handle,int step = 1);

/*
 ��������:	DM_FocusNear
*����˵��:		�������������
*�������:  handle��		���
			Step�� 		����
*����ֵ:		
*/
void __stdcall  DM_FocusNear(int handle,int step = 1);

/*
 ��������:	DM_StopFocus
*����˵��:	����ֹͣ��������ʹ��DM_DurativeNear��DM_DurativeFar����Ч
*�������:  handle��		���
*����ֵ:		
*/
void __stdcall  DM_StopFocus(int handle);

/*
 ��������:	DM_DurativeNear
*����˵��:	��������,����������ֱ������DM_StopFocusֹͣ����
*�������:  handle��		���
*����ֵ:		
*/
void  __stdcall DM_DurativeNear (int handle);

/*
 ��������:	DM_DurativeFar
*����˵��:	����������������Զ��ֱ������DM_StopFocusֹͣ����
*�������:  handle��		���
*����ֵ:		
*/
void __stdcall DM_DurativeFar (int handle);

/*
 ��������:	DM_ShowTempValueOnImage
*����˵��:	�򿪲���״̬���������Ƿ���ʾ��������
*�������:  handle��		���
			bEnable��		0�� ���� 1����ʾ
*����ֵ:		
*/
void __stdcall DM_ShowTempValueOnImage (int handle, bool bEnable);

/*
 ��������:	DM_GetTempValueOnImageStatus
*����˵��:	��ȡ�������Ƿ���ʾ��������
*�������:  handle��		���
			
*����ֵ:	0�� ���� 1����ʾ	
*/
int __stdcall DM_GetTempValueOnImageStatus(int handle);

/*
 ��������:	DM_SetISOTemp
*����˵��:	���������ĵ����¶�ֵ���ڲ���ʱ��Ҫʹ��
*�������:  handle��		���
			ThermTemp��		�¶� * 100
*����ֵ:	
*/
void __stdcall DM_SetISOTemp(int handle,int ThermTemp);

/*
 ��������:	DM_GetISOTemp
*����˵��:	��ȡ������ǰ���õĵ����¶�
*�������:  handle��		���
*����ֵ:	�����¶�
*/
int __stdcall DM_GetISOTemp(int handle);

/*
 ��������:	DM_SetISOHight
*����˵��:	���õ��¸߶ȣ�����ɫ���¶ȷ�Χ�����ڲ���ʱʹ
*�������:  handle��			���
			ThermHight��		�߶�*100

*����ֵ:	
*/
void __stdcall DM_SetISOHight(int handle,int ThermHight);

/*
 ��������:	DM_GetISOHight
*����˵��:	��ȡ��ǰ�����ĵ��¸߶�
*�������:  handle��			���
			ThermHight��		�߶�*100


*����ֵ:	���¸߶�
*/
int __stdcall DM_GetISOHight(int handle);

/*
 ��������:	DM_SetISOColor
*����˵��:	���õ���ɫ���ڲ���ʱʹ��
*�������:  handle��			���
			ColorID�� 	����ɫ�ţ�����ɫ�����ţ�
*����ֵ:	���¸߶�
*/
void __stdcall DM_SetISOColor(int handle,int ColorID);

/*
 ��������:	DM_GetISOColor
*����˵��:	��ȡ��ǰ�����ĵ���ɫ
*�������:  handle�����
*����ֵ:	����ɫ������ɫ�����ţ�
*/
int __stdcall DM_GetISOColor(int handle);

/*
 ��������:	DM_SetTempUnit
*����˵��:	�����¶ȵ�λ
*�������:  handle��		���
			Unit��			0����;1 �H;2 K
*����ֵ:
*/
void __stdcall DM_SetTempUnit(int handle,int Unit);

/*
 ��������:	DM_GetTempUnit
*����˵��:	��ȡ�������¶ȵ�λ
*�������:  handle��		���
*����ֵ:	�¶ȵ�λ��0����;1 �H;2 K��
*/
int __stdcall DM_GetTempUnit(int handle);

/*
 ��������:	DM_SetUpTempRange
*����˵��:	���ֶ���ɫ��ʱʹ�ã����������¶�����
*�������:  handle	�����
			Offset ����ԭ��ɫ�����޵Ļ���������,ֵ -10��-1��+1��+10 ֮�䣬��λΪ��

*����ֵ:	
*/
void __stdcall DM_SetUpTempRange(int handle,int Offset);

/*
 ��������:	DM_SetDownTempRange
*����˵��:	���ֶ���ɫ��ʱʹ�ã����������¶�����
*�������:  handle	�����
			Offset ����ԭ��ɫ�����޵Ļ���������,ֵ -10��-1��+1��+10 ֮�䣬��λΪ��

*����ֵ:	
*/
void __stdcall DM_SetDownTempRange(int handle,int Offset);


/****************************************************************************************************************/
/* ���²�������                                                                                                 */
/****************************************************************************************************************/

/*
 ��������:	DM_SetMeasureClass
*����˵��:	���ò��µ�λ������֧�ֵ�λ�����ͷ˵��
*�������:  handle��		���
			ParamValue �� ��λ ��1-8��

*����ֵ:			
*/
void __stdcall DM_SetMeasureClass(int handle,int ParamValue);

/*
 ��������:	DM_GetMeasureClass
*����˵��:	��ȡ��ǰ�Ĳ��µ�λ
*�������:  handle��		���
*����ֵ:	��ǰ�Ĳ��µ�λ����λֵ��1��ʼ��		
*/
int __stdcall DM_GetMeasureClass(int handle);

/*
 ��������:	DM_SetRefeType
*����˵��:	���òο��¶�����
*�������:  handle��		���
			ParamValue �� 0���ر�   
			1��	�ο��¶ȣ�ֵ��DM_SetRefeTemp����   
			2 - 5 ����Ӧ ��1--4 �¶�
			6 - 8 �� ��Ӧ ���� 1-3�¶�

*����ֵ:			
*/
void __stdcall DM_SetRefeType(int handle,int ParamValue);

/*
 ��������:	DM_GetRefeType
*����˵��:	��ȡ��ǰ�����Ĳο��¶�����
*�������:  handle��		���		
*����ֵ:    �����Ĳο��¶�����			
*/
int __stdcall DM_GetRefeType(int handle);

/*
 ��������:	DM_SetRefeTemp
*����˵��:	��ѡ��ο�����Ϊ(1)�ο��¶�ʱ�õ�, ���òο��¶�ֵ
*�������:  
			handle��			���
			ParamValue ��  �¶� * 100
*����ֵ:    �����Ĳο��¶�����			
*/
void __stdcall DM_SetRefeTemp (int handle,int ParamValue);

/*
 ��������:	DM_GetRefeTemp
*����˵��:	��ѡ��ο�����Ϊ(1)�ο��¶�ʱ�õ�, ���òο��¶�ֵ
*�������:  
			handle��			���
			ParamValue ��  �¶� * 100
*����ֵ:    �����Ĳο��¶�����			
*/
int __stdcall DM_GetRefeTemp (int handle);

/*
 ��������:	DM_SetAmbientTemp
*����˵��:	�����¶����ã�����绷���¶�������ֵ����5ʱ����Ҫ�����趨�����¶�
*�������:  
			handle��		���
			Temper��  	�¶� * 100
*����ֵ:    			
*/
void __stdcall DM_SetAmbientTemp(int handle,int Temp);

/*
 ��������:	DM_GetAmbientTemp
*����˵��:	��ȡ��ǰ�����Ļ����¶�
*�������:  
			handle��		���
*����ֵ:    �����¶�			
*/
int __stdcall DM_GetAmbientTemp(int handle);

/*
 ��������:	DM_SetObjDistance
*����˵��:	���û������룬��ͼ��Ŀ���������ľ���������ֵ���5m ����ʱ����Ҫ�����趨��������
*�������:  
			handle��		���
			Distance��	 	���� (��λ������)
*����ֵ:    			
*/
void __stdcall DM_SetObjDistance(int handle,int Distance);

/*
 ��������:	DM_GetObjDistance
*����˵��:	��ȡ�������õĻ�������ֵ
*�������:  
			handle��		���
*����ֵ:    ��������			
*/
int __stdcall DM_GetObjDistance(int handle);

/*
 ��������:	DM_SetAmbientHumidity
*����˵��:	���û���ʪ��,���ݾ������绷��������ʪ��
*�������:  
			handle��		���
*����ֵ:    ��������			
*/
void __stdcall DM_SetAmbientHumidity(int handle,int Humidity);

/*
 ��������:	DM_GetAmbientHumidity
*����˵��:	��ȡ�������õĻ���ʪ��ֵ
*�������:  
			handle��		���
*����ֵ:    ����ʪ�� ʪ�ȷ�Χ��0-100��			
*/
int __stdcall DM_GetAmbientHumidity(int handle);

/*
 ��������:	DM_SetReviseParam
*����˵��:	��������ϵ��
*�������:  
			handle			���
			ReviseParam		����ϵ�� * 100

*����ֵ:   			
*/
void __stdcall DM_SetReviseParam(int handle,int ReviseParam);

/*
 ��������:	DM_GetReviseParam
*����˵��:	��ȡ����ϵ��
*�������:  
			handle			���
			ReviseParam		����ϵ�� * 100
*����ֵ:   			
*/
int __stdcall DM_GetReviseParam(int handle);

/*
 ��������:	DM_SetReviseTemp
*����˵��:	���������¶�
*�������:  
			handle			���
			ReviseTemp		�����¶� * 100

*����ֵ:   			
*/
void __stdcall DM_SetReviseTemp(int handle,int ReviseTemp);

/*
 ��������:	DM_GetReviseTemp
*����˵��:	��ȡ�����¶�
*�������:  
			handle			���
*����ֵ:   	�����¶�		
*/
int __stdcall DM_GetReviseTemp(int handle);

/****************************************************************************************************************/
/* ��������                                                                                                     */
/****************************************************************************************************************/

/*
 ��������:	DM_OpenAlarm
*����˵��:	�������˱������ܣ������źŵ��������ϢWM_TEMP_ALARM (0)�д���
*�������:  handle��	���
*����ֵ:
**ע��		
*/
void __stdcall DM_OpenAlarm(int handle);

/*
 ��������:	DM_CloseAlarm
*����˵��: �ر������˱�������
*�������:  handle��	���
*����ֵ:
*ע��	
*/
void __stdcall DM_CloseAlarm(int handle);

/*
 ��������:	DM_SetAlarmTemp
*����˵��: �����¶�����
*�������:  handle��		���
			Temper ��  	�¶� * 100
*����ֵ:
*ע��
*/
void __stdcall DM_SetAlarmTemp(int handle,int Temp);

/*
 ��������:	DM_GetAlarmTemp
*����˵��:  ��ȡ��ǰ�����ı����¶�
*�������:  handle��		���
*����ֵ:	�����¶�
*ע��	
*/
int __stdcall DM_GetAlarmTemp(int handle);

/*
 ��������:	DM_SetAlarmColor
*����˵��:  ���ñ���ɫ
*�������:  handle��		���
			ColorID ��	������ɫ�����ţ�
*����ֵ:	
*ע��
*/
void __stdcall DM_SetAlarmColor(int handle,int ColorID);

/*
 ��������:	DM_GetAlarmColor
*����˵��:  ��ȡ��ǰ�����ı���ɫ
*�������:  handle��		���
*����ֵ:	������ɫ������ɫ�����ţ�
*ע��
*/
int __stdcall DM_GetAlarmColor(int handle);

/*
 ��������:	DM_OpenRemoteAlarm
*����˵��:  �������˱������ܣ������źŵ��������ϢWM_TEMP_ALARM (0)�д���
*�������:  handle��		���
*����ֵ:	
*/
void __stdcall  DM_OpenRemoteAlarm(int handle);

/*
 ��������:	DM_CloseRemoteAlarm
*����˵��:  �ر������˱�������
*�������:  handle��		���
*����ֵ:	
*/
void __stdcall  DM_CloseRemoteAlarm(int handle);

/*
 ��������:	DM_SetRemoteAlarmTemp
*����˵��:  �����¶�����
*�������:  handle��		���
			Temper ��  	�¶� * 100
*����ֵ:	
*/
void __stdcall  DM_SetRemoteAlarmTemp(int handle,int Temp);

/*
 ��������:	DM_GetRemoteAlarmTemp
*����˵��:  ��ȡ��ǰ�����ı����¶�
*�������:  handle��		���
*����ֵ:	�����¶�
*/
int __stdcall  DM_GetRemoteAlarmTemp(int handle);

/*
 ��������:	DM_SetRemoteAlarmColor
*����˵��:  ���ñ���ɫ
*�������:  handle��		���
			ColorID ��	������ɫ�����ţ�
*����ֵ:	
*/
void __stdcall  DM_SetRemoteAlarmColor(int handle,int ColorID);

/*
 ��������:	DM_GetRemoteAlarmColor
*����˵��:  ��ȡ��ǰ�����ı���ɫ
*�������:  handle��		���
*����ֵ:	������ɫ������ɫ�����ţ�
*/
int __stdcall  DM_GetRemoteAlarmColor(int handle);

/*
 ��������:	DM_IOAlarm
*����˵��:  ������������IO�ڼ�����ʹ��
*�������:  handle��		���
*����ֵ:	������ɫ������ɫ�����ţ�
*/
void __stdcall DM_IOAlarm(int handle, int iIO, int iEnable);

/*************************************************************************************************************8****/
/*   ϵͳ��������                                                                                                 */
/******************************************************************************************************************/

/*
 ��������:	DM_SetIPAddr
*����˵��:  ����������IP��ַ
*�������:  handle��			���
			IP �� IP��ַ   ��ʽ �� 192.168.0.1

*����ֵ:
*/
void __stdcall  DM_SetIPAddr(int handle, char *IP, char *SubMask, char *GateWay);

/*
 ��������:	DM_SetMAC
*����˵��:  ����MAC��ַ
*�������:  handle��		���
			Mac ��		��ַ
*����ֵ:
*/
void __stdcall  DM_SetMAC(int handle,char *Mac);

/*
 ��������:	DM_SetAutoAdjustTime
*����˵��:  �����Զ�У�����ʱ��
*�������:  handle��		���
			Time �� 		ʱ�䣨��λ���룩

*����ֵ:
*/
void __stdcall DM_SetAutoAdjustTime(int handle,int Time);

/*
 ��������:	DM_GetAutoAdjustTime
*����˵��:  ��ȡ��ǰ�������Զ�У�����ʱ��
*�������:  handle��		���
			
*����ֵ:    ���ʱ�䣨�룩
*/
int __stdcall DM_GetAutoAdjustTime(int handle);

/*
 ��������:	DM_SetDateTime
*����˵��:  ��������ʱ��
*�������:  handle		���
			year			��
			month		��
			day			��
			hour		ʱ
			min			��
			sec			��
			
*����ֵ:    
*/
void  __stdcall DM_SetDateTime(int handle,int year,int month,int day,int hour,int min,int sec);

/*
 ��������:	DM_GetDateTime
*����˵��:  ��ȡ�����ĵ�ǰʱ��
*�������:  handle		���
			
*�������:  �ַ�������ʽyyyy-mm-dd hh-mm-ss
			yyyy		��
			mm			��
			dd			��
			hh			ʱ
			mm			��
			ss			��
*/
void  __stdcall DM_GetDateTime(int handle,char *DateTime);

/*
 ��������:	DM_LoadDefault
*����˵��:  �ָ���������
*�������:  handle		���
*����ֵ����
*/
void  __stdcall DM_LoadDefault(int handle);

/*
 ��������:	DM_GetSystemInfo
*����˵��:  ��ȡ������ϵͳ��Ϣ���������ںͰ汾��
*�������:  handle		���
*���������SysInfo		���ںͰ汾���ַ���
*����ֵ����
*/
void __stdcall  DM_GetSystemInfo(int handle,char *SysInfo);


/********************************************************************************************************8*********/
/*  ��Ƶ������                                                                                               */
/******************************************************************************************************************/

/*
 ��������:	DM_PlayerInit
*����˵��:	��Ƶ���ǰ�ĳ�ʼ����ÿ��ϵͳ�����ܿ��˼�����Ƶ��ش��ڣ�������ֻ�ܵ���һ��
*�������:  hwnd����Ƶ��ʾ���ھ��
*����ֵ:	=0  ��ȷ����DM_PlayerCleanup�ͷţ�
			<0  ����
*/
int __stdcall  DM_PlayerInit(HWND hwnd);

/*
 ��������:	DM_OpenMonitor
*����˵��:	����Ƶ���
*�������:  
			hwnd����	��Ƶ��ʾ���ھ��
			ip ��  		����IP��ַ   
			port ��  		�˿�
			channel ��  	ͨ���ţ�Ŀǰֻ֧��һ��ͨ��

*����ֵ:	>=0 ���Ӿ��
			<0 ����ʧ��
*/
//Ԥ����netsdk��ʱ���ṩ�˽ӿ�
int  __stdcall DM_OpenMonitor(HWND hwnd, char* ip,unsigned short port,int channel= 0);

/*
 ��������:	DM_SetOSD
*����˵��:	������Ƶ��OSD
*�������:  
			handle����	DM_OpenMonitor���ص����Ӿ��	
			OSDType :   	0X00 ��
			0X01 ����ʱ��
			0X02 ��������
			0X04 ����IP��ַ


*����ֵ:	>0 �ɹ� 
			<0 ʧ��
*ע�� �ýӿ���ʱ����
*/
int __stdcall DM_SetOSD(int handle,int OSDType);

/*
 ��������:	DM_CloseMonitor
*����˵��:	�ر���Ƶ���
*�������:  
			handle����DM_OpenMonitor���ص����Ӿ��
 *����ֵ:	>0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_CloseMonitor(int handle);

/*
 ��������:	DM_PlayerCleanup
*����˵��:	���int DM_PlayerInit���õ���Դ
*�������:  
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_PlayerCleanup();

/*
 ��������:	DM_Record
*����˵��:	��ʼ¼��
*�������: 
            handle����DM_OpenMonitor���ص����Ӿ��	
            path ��   �����ļ�·��
 
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int __stdcall  DM_Record(int handle, char* path);

/*
*��������:	DM_StopRecord
*����˵��:	ֹͣ¼��
*�������:  handle����	DM_OpenMonitor���ص����Ӿ�� 
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_StopRecord(int handle);

/*
*��������:	DM_Capture
*����˵��:	�ɼ�һ��ͼ��
*�������:  handle����	DM_OpenMonitor���ص����Ӿ��
			path �� 	�����ļ�·��

*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_Capture(int handle, char *path);

/*
*��������:	DM_PlayBack
*����˵��:	�ļ��ط�
*�������:  hwnd �������ļ���Ҫ�Ĵ��ھ��
            file	¼���ļ�
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_PlayBack(HWND hwnd, char *file);

/*
*��������:	DM_ClosePlayBack
*����˵��:	�ر��ļ��ط�
*�������:  handle	DM_PlayBack�����ķ���ֵ
            
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_ClosePlayBack(int handle);

/*
*��������:	DM_PlayBackPause
*����˵��:	��ͣ����
*�������:  handle	DM_PlayBack�����ķ���ֵ
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_PlayBackPause(int handle);

/*
*��������:	DM_PlayBackContinue
*����˵��:	��������
*�������:  handle	DM_PlayBack�����ķ���ֵ
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_PlayBackContinue(int handle);

/*
*��������:	DM_PlayBackStop
*����˵��:  ֹͣ�ط�
*�������:  handle	DM_PlayBack�����ķ���ֵ
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_PlayBackStop(int handle);

/*
*��������:	DM_PlayBackSpeed
*����˵��:  ��������
*�������:  
			handle	DM_PlayBack�����ķ���ֵ
			speed	�����ٶ�
			-4     1/4���� 
			-2     1/2����
			1      �����ٶ�
			2      2����
			4      4����


*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_PlayBackSpeed(int handle,int speed);

/*
*��������:	DM_PlayBackStep
*����˵��:  ��������
*�������:  
			handle	DM_PlayBack�����ķ���ֵ
*����ֵ:	>=0 �ɹ� 
			<0 ʧ��
*/
int  __stdcall DM_PlayBackStep(int handle);

/******************************************************************************************************************/
/*  ��̨����                                                                                                   */
/******************************************************************************************************************/
//��̨Э��
enum DALI_PTZ_PROTOCOL {
		PELCO_D = 1,
		PELCO_P1,
		PELCO_P2,
		PELCO_P3,
		DL_0001,
		FASTRAX,
		PANASONIC,
		ELEC,
		SAMSUNG,
		KATATEL,
		HD_600,
		T3609HD, 
		LILIN,
		PELCO9760,
		KRE301,
		PIH_1016,
		PD_CONST,
		PD_NW,
		JC4116,
		SONY,
		YAAN,
		ENKEL,
		PLD,  
};

//
enum DALI_MOVEMENT_DIR {
	DALI_KEY_STOP,			//ֹͣ
		DALI_KEY_LEFT,		//	����
		DALI_KEY_RIGHT,		//	����
		DALI_KEY_UP,		//		����
		DALI_KEY_DOWN,	//	����
		DALI_KEY_LEFT_UP,	//	����
		DALI_KEY_LEFT_DOWN,//	����
		DALI_KEY_RIGHT_UP,	//	����
		DALI_KEY_RIGHT_DOWN,//����
		DALI_KEY_ZOOM_IN,
		DALI_KEY_ZOOM_OUT,
		DALI_KEY_FOCUS_NEAR,
		DALI_KEY_FOCUS_FAR,
};

enum DALI_PRESET_DIR {
		DALI_KEY_PRESET_SAVE,	//���桢����
		DALI_KEY_PRESET_CALL,	//����
		DALI_KEY_PRESET_AUTO,	//�Զ�
		DALI_KEY_PRESET_CLEAR,	//���
		DALI_KEY_PRESET_ADD,	//	���
};

/*
*��������:	DM_PTZSettings
*����˵��:  ��̨��ʼ������
*�������:  
			handle��	���
			Protocol��	��̨����Э�飨�μ�DALI_PTZ_PROTOCOL�еĶ��壬Ŀǰ֧��Pelco_D �� YAAN��
			NAddrID��	��̨��ַ

*����ֵ:
*/
void  __stdcall DM_PTZSettings(int handle,DALI_PTZ_PROTOCOL Protocol = PELCO_D,int nAddrID = 1);

/*
*��������:	DM_PTZSpeed
*����˵��: ��̨�ٶȿ���
*�������:  
			handle��			���
			nSpeedTrgID��   	�˶�����	
			#define SPEED_TRG_PAN	0	//ˮƽ
			#define SPEED_TRG_TILT	1	//��ֱ
			nSpeed��			�ٶ�

*����ֵ:
*/
void  __stdcall DM_PTZSpeed(int handle,int nSpeedTrgID,int nSpeed = 1);

/*
*��������:	DM_PTZControl
*����˵��:  ��̨����
*�������:  
			handle��		���
			ctrlCmd��		��������
			Movement		�ƶ�����
*����ֵ:
*/
void  __stdcall DM_PTZControl(int handle,DALI_CONTROL_CMD_DIR ctrlCmd,DALI_MOVEMENT_DIR Movement);

/*
*��������:	DM_PTZPreset
*����˵��:  ��̨Ԥ��λ����
*�������:  
			handle��		���
			Preset��		DALI_PRESET_DIR�ж���
			nPoint��		Ԥ�õ�
*����ֵ:
*/
void  __stdcall DM_PTZPreset(int handle, DALI_PRESET_DIR Preset, int nPoint);

/*****************************************************************************************************************/
/* ����                                                                                                          */
/*****************************************************************************************************************/

/*
*��������:	DM_GetStatus
*����˵��:  ��ȡ��������״̬���������Ͳμ�enumTestDeviceStatus
*�������:  handle��		���
*����ֵ:    DM60�ĵ�ǰ״̬
*/
int __stdcall  DM_GetStatus(int handle);

/*
*��������:	DM_KBDControl
*����˵��:  ����ģ����̿���
*�������:  
			handle �����
			nValue ֵ��
			7		����� 	9		����� 
			10		���ϼ�   	11		ȡ����
			12		���Ҽ� 	13		���¼�
			14		ȷ����

*����ֵ:
*/
void  __stdcall DM_KBDControl(int handle,int nValue);

/*
*��������:	DM_AutoAdjust
*����˵��:  ������������
*�������:  
			handle �����
*����ֵ:	>0 �ɹ�			
*/
int  __stdcall DM_AutoAdjust(int handle);

/*	��������: DM_Open
 *	����˵����������ǰ��
 *   ���������	handle �����
 *	����ֵ�� >=0 �ɹ�
*/
int  __stdcall DM_Open(int handle);


/*	��������: DM_Close
 *	����˵�����ر�����ǰ��
 *	���������handle �����
 *	����ֵ�� >=0 �ɹ�
 */
int  __stdcall DM_Close(int handle);


/*	��������: DM_GetRemoteAlarm
 *	����˵������ȡ�����˱���״̬��
 *	���������handle��		���
 *	����ֵ�����˱���״̬(0���رգ�1����)
 */
int  __stdcall DM_GetRemoteAlarm(int handle);


/*	��������: DM_GetVideoMode
 *	����˵��: ��ȡͼ���ֶ�/�Զ�ģʽ
 *	�������:handle��		���
 *	����ֵ��ģʽ(0���ֶ���1���Զ�)
 */
int  __stdcall DM_GetVideoMode(int handle);

/*	��������: DM_GetMAC
*	����˵����	��ȡMAC��ַ
*	���������handle��	���
*			  Mac ��		��ַ
*	����ֵ�� N/A
*/
void  __stdcall DM_GetMAC(int handle,char *Mac);

/*	��������: DM_GetRemoteLanguage
*	����˵������ȡ����������
*	���������handle		���
*	����ֵ�� ����������(0��Ӣ�ģ�1������)
 */
int  __stdcall DM_GetRemoteLanguage(int handle);

/*	��������: DM_SetRemoteLanguage
*	����˵������������������
*	���������handle		���
*			  iLanguage    ���������Ա��£�0��Ӣ�ģ�1�����ģ�
*	����ֵ�� >=0 �ɹ�
 */
int  __stdcall DM_SetRemoteLanguage(int handle, int iLanguage);

/*	��������: DM_Reset
*	����˵������������
*	���������handle		���
*	����ֵ�� >=0 �ɹ�
 */
int  __stdcall DM_Reset(int handle);

//-----------------------------------------------------
//2010-11-01,���½ӿ�Ϊ�����ϵ�DM60���Ͷ���������

/*
input:
handle: 	Handle
stream:		stream buffer pointer
len:		buffer length
err:		error code 
0	//success
1	//stop by user
2	//stop by receive
data:		user define, in DM_ReceiveMonitorStream
*/
typedef int (__stdcall *STREAMCALL)( int handle,int dataType, BYTE *stream, int len, int err, void *cbpara );

void DM_GetVersion(char *Version);

/*
Description��	open local alram
Input��
handle		Handle
Return��
>=0:     Success
*/
int DM_OpenLocalAlarm(int handle);

/*
Description��	close local alram
Input��
handle		Handle
Return��
>=0:     Success
*/
int DM_CloseLocalAlarm(int handle);

/*
Description��	set local alram type
Input��
handle:		Handle
type:		0: Min 1: Max 2: Diff
Return��
>=0:     Success
*/
int DM_SetLocalAlarmType(int handle,int type);

/*
Description��	get local alram type
Input��
handle		Handle
Return:
0: Min 1: Max 2: Diff
*/
int DM_GetLocalAlarmType(int handle);

/*
Description��	set local alram mode
Input��
handle:		Handle
mode:		 0: > 1: <
Return��
>=0:     Success
*/
int DM_SetLocalAlarmMode(int handle,int mode);

/*
Description��	get local alram mode
Input��
handle:		Handle
Return��
0: > 1: <
*/
int DM_GetLocalAlarmMode(int handle);

/*
Description��	set local alram refe 
Input��
handle		Handle
refe��	
0��Close
1��	Refe Tempature��value by DM_SetLocalAlarmTemp
2 - 5 ��spot (1-4) tempature
6 - 8 ��area (1-3) tempature
Return��
>=0:     Success
*/
int DM_SetLocalAlarmRefe(int handle,int refe);

/*
Description��	get local alram refe
Input��
handle:		Handle
Return��
0��Close
1��	Refe Tempature��value by DM_SetLocalAlarmTemp
2 - 5 ��spot (1-4) tempature
6 - 8 ��area (1-3) tempature
*/
int DM_GetLocalAlarmRefe(int handle);

/*
Description��	set local alram tempature
Input��
handle:		Handle
temp:		tempature
Return��
>=0:     Success
*/
int DM_SetLocalAlarmTemp(int handle,float temp);

/*
Description��	get local alram tempature
Input��
handle:		Handle
Return��
tempature
*/
float DM_GetLocalAlarmTemp(int handle);

/*
Description��get device system info
Input��
handleL:	Handle
output��
SysInfo:	see tagSystemInfo
Return��
>=0:    Success
*/
void DM_GetSysInfo(int handle,tagSystemInfo *SysInfo);

/*
input:
ip:			ip address
port:		port
channel:	channel id
callback:	see STREAMCALL
data:		uer data, STREAMCALL paramter
Return:
=0: success 1:fail
*/
int DM_ReceiveMonitorStream(char* ip, unsigned short port,int channel, STREAMCALL callback ,void *data );

/*
Input:	
handle:	  by DLDVR_ReceiveMonitorStream return
Return:
=0: success <0: fail
*/
int DM_StopMonitorStream(int handle);

//���漸���ӿ���δʵ��--------------------------------------------------------begin
int DM_OpenMonitorEX(HWND hWnd, int frameRate, int fmt, int rl);
int DM_SetStreamBuf(int handle, BYTE *buf, int len);
int DM_EmptyStreamBuf(int handle);
//���漸���ӿ���δʵ��--------------------------------------------------------end

/*
Description��	Yuntai Control
Input��
handle		Handle
cmd   	Control command
len		command Len
Return��
>=0:     Success
*/	
int DM_YTControl(int handle,char *cmd, int len);

//tempature struct
struct stTempDest
{
	int iType;  
	int iNumber; 
	int iPointX;	
	int iPointY;
	double dblTemp;
};

/*
Description��	init callback of real tempature
Input��
handle��		Handle
pFun��			CallBack function
Return��
NULL
*/
void DM_GetRealTempObject(int handle, int(__stdcall *pFun)(int ,stTempDest[], int));

/*
Description��	enable natural termpature range
Input��
handle��		Handle
iEnable��		0: disable 1: enable
Return��
>=0:     Success
*/
int DM_SetNaturalTempRangeEnable(int handle, int iEnable);

/*
Description��	get natural termpature range status
Input��
handle��		Handle
Return��
0: disable 1: enable
*/
int DM_GetNaturalTempRangeEnable(int handle);

/*
Description��	set termpature range
Input��
handle��	Handle
HeightTemp��Height tempature * 100
LowTemp:	Low Tempature * 100
Return��
>=0:     Success
*/
int DM_SetNaturalTempRange(int handle, double HeightTemp, double LowTemp);

/*
Description��	get termpature range
Input��
handle��	Handle
Return��
>=0:     Success
*/
int DM_GetNaturalTempRange(int handle);

/*
Description��	enable intellect Measure Tempature
Input��
handle��	Handle
nIntellect:	0: diable 1: enbale
Return��
>=0:     Success
*/
int DM_SetIntellectMeasureTemp(int handle,int nIntellect);

/*
Description��	get intelleect measure tempature
Input��
handle��	Handle
Return��
>=0:     Success
*/
int DM_GetIntellectMeasureTemp(int handle);

/*
Description��	set Black Board Paramter
Input��
handle��		Handle
nOutStartX:		LeftUp X value
nOutStartY:		LeftUp Y value
nOutHeight:		Height
nOutWidth:		Width
nInStartX:		LeftUp X value
nInStartY:		LeftUp Y value
nInHeight:		Height
nInWidth:		width
dblBlackTemp:	BlackBoard tempature * 100
dblBlackEmiss:	Emiss
Return��
>=0:     Success
*/
int DM_SetBlackBoardPara(int handle,int nOutStartX, int nOutStartY, int nOutHeight, int nOutWidth,
						 int nInStartX,int nInStartY,int nInHeight, int nInWidth,
						 double dblBlackTemp,double dblBlackEmiss);

/*
Description��	Get Black Board Paramter
Input��
	handle��	Handle
Return��
	>=0:     Success
*/
int DM_GetBlackBoardPara(int handle);

/*
Description��	set intellect tempature range
Input��
handle��	Handle
HeightTemp:	Height tempature * 100
nLowerTemp:	Lower Tempature * 100
Return��
>=0:     Success
*/
int DM_SetIntellectTempRange(int handle,double HeightTemp, double nLowerTemp);

/*
Description��	Get Intellect Tempature Range
Input��
handle��	Handle
Return��
>=0:     Success
*/
int DM_GetIntellectTempRange(int handle);

/*
Description��	set shield area
Input��
handle��	Handle
nID:		Area ID
nStatus:	0: disable 1: enable
nStartX,nStartY:	coordinate Leftup 
nWidth:		Width
nHeight:	Height
Return��
>=0:     Success
*/
int DM_SetShieldArea(int handle,int nID,int nStatus, int nStartX,int nStartY, int nWidth,int nHeight);

/*
Description��	Get Shield Area
Input��
handle��	Handle
nID:		Area ID
Return��
>=0:     Success
*/
int DM_GetShieldArea(int handle,int nID);

/*
Description��	set pallette range
Input��
handle��		Handle
nHeightTemp:	the upper tempature * 100
nLowTemp:		the lower tempature * 100
Return��
>=0:     Success
*/
int DM_SetPalletteTempRange(int handle,double nHeightTemp,double nLowerTemp);

/*
Description��	get pallette range
Input��
handle��	Handle
Return��
>=0:     Success
*/
int DM_GetPalletteTempRange(int handle);

/*
Description��	enable auto ambient tempature 
Input��
handle��	Handle
nStatus:	0: disable 1: enable
Return��
>=0:     Success
*/
int DM_SetAutoAmbientTemp(int handle,int nStatus);

/*
Description��	enable auto ambient tempature 
Input��
handle��	Handle
nStatus:	0: disable 1: enable
Return��
>=0:     Success
*/
int DM_GetAutoAmbientTempStatus(int handle);

//Test funciton,dont use 
int DM_Test(int handle, unsigned char *Test,int nLen);

/**
@breif Open Active Test
@param handle : Handle
@retval >0 success
*/
int DM_OpenActiveTest(int handle);

/**
@breif Close Active Test
@param handle : Handle
@retval >0 success
*/
int DM_CloseActiveTest(int handle);

/**
@breif Get Lens ID
@param handle : Handle
@return return lens id
@retval >0 Lens ID
*/
int DM_GetLensID(int handle);

/**
@breif Set Lens ID
@param handle : Handle
@param ParamValue : LENS ID
@return return lens id
@retval >0 Lens ID
*/
int DM_SetLensID(int handle,int ParamValue);

int DM_GetTempLimit( int handle );

int DM_SetTempLimit( int handle, int HeightTemp );

int DM_SetEdgeradiiEnable( int handle, bool Enable );
bool DM_GetEdgeradiiEnable( int handle );

int DM_SetEdgeradii( int handle, int Edgeradii );

int DM_GetEdgeradii( int handle );

/*
 ��������:	DM_CheckOnline
*����˵��:	��������Ƿ�����
*�������:  IPAddr������IP
			Port�������˿� 
*����ֵ:������ʾ���ߣ�������ʾ������			
*/
int  __stdcall DM_CheckOnline( char *IPAddr, int Port);

/*
 ��������:	DM_ClearAllJpeg
*����˵��:	��������ϵ�����JPEGͼƬ
*�������:  handle
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_ClearAllJpeg(int handle);

/*
 ��������:	DM_BrightAdjust
*����˵��:	���ȵ���
*�������:  handle
*           step,������+1, ��ʾ����1�� -1, ��ʾ��С1
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_BrightAdjust(int handle, int step);

/*
 ��������:	DM_ContrastAdjust
*����˵��:	�������
*�������:  handle
*           step,������+1, ��ʾ����1�� -1, ��ʾ��С1
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_ContrastAdjust(int handle, int step);

/*
 ��������:	DM_RemoteJpeg
*����˵��:	Զ������
*�������:  handle
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_RemoteJpeg(int handle);

/*
��������:	DM_Zoom
*����˵��:	���ӷŴ�
*�������:  handle
*			value���Ŵ�����0-1���� 1-2��
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_Zoom(int handle, int value);


/*
��������:	DM_SetPalority
*����˵��:	������ͼ��ģʽ
*�������:  handle
*			value��1-���ȣ� 0-����
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_SetPalority(int handle, int value);

/*
��������:	DM_GetCapacity
*����˵��:	��ȡS730���͵�����
*�������:  handle
*����ֵ:����ֵ�������ظ�����ʾʧ��		
*/
int  __stdcall DM_GetCapacity(int handle);

/*
��������:	DM_GetBright
*����˵��:	��ȡS730���͵�����ֵ
*�������:  handle
*����ֵ:����ֵ����Χ��-2048-2048����������ֵΪʧ��		
*/
int  __stdcall DM_GetBright(int handle);

/*
��������:	DM_GetContrast
*����˵��:	��ȡS730���͵ĶԱȶ�
*�������:  handle
*����ֵ:�Աȶȣ���Χ��0-255����������ֵΪʧ��		
*/
int  __stdcall DM_GetContrast(int handle);

/*
��������:	DM_GetZoomStatus
*����˵��:	��ȡͼ��Ŵ���
*�������:  handle
*����ֵ:�Ŵ�����0-1���� 1-2��	
*/
int  __stdcall DM_GetZoomStatus(int handle);

/*
��������:	DM_GetPalority
*����˵��:	��ȡ��ͼ��ģʽ
*�������:  handle
*����ֵ:1-���ȣ� 0-����		
*/
int  __stdcall DM_GetPalority(int handle);


/*
��������:	DM_GetGFZ
*����˵��:	��ȡͼ�񶳽�״̬
*�������:  handle
*����ֵ:0-���᣻ 1-�Ƕ���
*ע�⣺S730��DM60-S��������	
*/
int  __stdcall DM_GetGFZ(int handle);

/*
 ��������:	DM_SetEIS
*����˵��:	��/�رռ��ɵ���������
*�������:  handle
*           cmd�� 1-��   0-�ر�
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_SetEIS(int handle, int cmd);

/*
 ��������:	DM_GetDistance
*����˵��:  ������
*�������:  handle		���			
*�������:  status,����״̬ 0-׼����  1-�������  2-�����Լ�
*			distance�����룬status=1ʱ��Ч
*����ֵ:������ʾ�ɹ���������ʾʧ��	
*/
int  __stdcall DM_GetDistance(int handle, int &status, tagDistanceInfo *distance);


/************************************************************************/
//   �ص���������                                                                  
/************************************************************************/

//��������Ƶ֡�ص���������, dwFrameRate ��ʾ֡��(1---25)
typedef void(CALLBACK *fYUVDataCallBack) (int handle, unsigned long dwFrameRate, unsigned char *pBuffer, 
										  unsigned long nWidth, unsigned long nHeight, int err, unsigned long dwUser);

/* 	����˵��:��������YUV��Ƶ�ص��Ļص�����
*	�������: lRealHandle�����Ӿ������DM_OpenMonitor()�ķ���ֵ
yuvDataCallBack���ص����������ڻص�YUV����
dwUser���û��Զ�������
*	�������: ��
*	��������: TRUE���ɹ��� FALSE��ʧ��
*	˵��:
*/
bool  __stdcall  DM_SetYUVDataCallBack(int lRealHandle, fYUVDataCallBack yuvDataCallBack,  unsigned long dwUser);

/*
 ��������:	DM_AutoCheck
*����˵��:  �������Լ�
*�������:  handle		���			
*�������:  ��
*����ֵ:������ʾ�ɹ���������ʾʧ��	
*/
int  __stdcall DM_AutoCheck(int handle);


/*
 ��������:	DM_VideoStable
*����˵��:  ��/�رյ���������
*�������:  lRealHandle�����Ӿ������DM_OpenMonitor()�ķ���ֵ
*			cmd��1-�򿪵������� 0-�رյ�������			
*�������:  ��
*����ֵ:������ʾ�ɹ���������ʾʧ��	
*/
int  __stdcall DM_VideoStable(int lRealHandle, int cmd);

/*
 ��������:	DM_SetGFZStatus
*����˵��:  ��/�ر�ͼ�񶳽�
*�������:  lRealHandle�����Ӿ������DM_OpenMonitor()�ķ���ֵ
*			cmd��1-ͼ�񶳽� 0-�������			
*�������:  ��
*����ֵ:������ʾ�ɹ���������ʾʧ��	
*/
int  __stdcall DM_SetGFZStatus(int lRealHandle, int cmd);

BOOL __stdcall DM_SetTemperatureScope(int handle,  int dwValue1,int dwValue2);
BOOL __stdcall DM_GetTemperatureScope(int handle, int* dwValue1, int* dwValue2);

#define		INFRA_DATA	0	//����ԭʼ����
#define		INFRA_PARA	 1 //�������
#define		INFRA_DATA_HEADER	2	//����ͷ,��Ӧ�ṹDLVParagraph
#define		INFRA_PARA_HEADER	 3 //�ļ�ͷ,��Ӧ�ṹDLVFileHeader

//DLV �ļ�ͷ
struct DLVFileHeader
{
    int   nFileVer; //3
    int   nFrameTime;
    int   nWidth;  //edit by duke 2009.10.21 type error
    int   nHeight;
};

//֡ͷ��ʽ��
struct DLVParagraph
{
    unsigned int SyncFlag;        //0x66DDDD66
    unsigned int nTime;           //��ǰʱ��
    unsigned int nPriorLength;    //��һ֡����
    unsigned int nType;           //֡����
    unsigned int nCurrentLength;  //��֡����
};
typedef void(CALLBACK *fInfraDataCallBack) (long lHandle, unsigned long dwDataType, unsigned char *pBuffer, unsigned long dwBufSize);
/*
 ��������:	DM_RecvInfraredData
*����˵��:  �򿪺���ԭʼ���ݵĻص�
*�������:  lUserID�����
*			InfraDataCallback���ص�����		
*�������:  ��
*����ֵ:������ʾ�ɹ���������ʾʧ��	
*/
long __stdcall DM_RecvInfraredData(long lUserID, fInfraDataCallBack InfraDataCallback);

/*
 ��������:	DM_StopRecvInfraredData
*����˵��:  ֹͣ����ԭʼ���ݵĻص�
*�������:  lRealHandle���������DM_RecvInfraredData()��DM_RecvInfraredData_EX()�ķ���ֵ	
*�������:  
*����ֵ:TRUE��ʾ�ɹ���FALSE��ʾʧ��	
*/
int __stdcall DM_StopRecvInfraredData(long lRealHandle);

/*
 ��������:	DM_GetIPAddress
*����˵��:  ��ȡIP��ַ
*�������: handle��	���			
*�������:  IPAddress��IP��ַ
*����ֵ:TRUE��ʾ�ɹ���FALSE��ʾʧ��	
*/
int __stdcall DM_GetIPAddress(int handle,char *IPAddress);

/*
 ��������:	DM_GetNetmask
*����˵��:  ��ȡ��������
*�������: handle��	���			
*�������:  Netmask����������
*����ֵ:TRUE��ʾ�ɹ���FALSE��ʾʧ��	
*/
int __stdcall DM_GetNetmask(int handle,char *Netmask);

/*
 ��������:	DM_GetGateway
*����˵��:  ��ȡ����
*�������: handle��	���			
*�������:  Gateway������
*����ֵ:TRUE��ʾ�ɹ���FALSE��ʾʧ��	
*/
int __stdcall DM_GetGateway(int handle,char *Gateway);


void __stdcall DM_SetAllMessCallBack(void (CALLBACK *fMessCallBack)(int msg, char *pBuf, int dwBufLen, DWORD dwUser),  DWORD dwUser = 0);

/*
 ��������:	DM_RecvInfraredData
*����˵��:  �򿪺���ԭʼ���ݵĻص�
*�������:  lUserID�����
*			Frame���ɼ�����֡��
*			Time,��֡��ʱ��������λ����
*			InfraDataCallback���ص�����		
*�������:  ��
*����ֵ:������ʾ�ɹ���������ʾʧ��	
*/
LONG __stdcall DM_RecvInfraredData_EX(LONG lUserID, int Frame,int Time, fInfraDataCallBack InfraDataCallback);

/*
 ��������:	DM_GetDM6xResolution
*����˵��:  ��ȡDM6x���͵������ֱ���
*�������:  handle		���			
*�������:  resolution,�����ֱ���
*����ֵ:>=0��ʾ�ɹ���������ʾʧ��	
*/
int  __stdcall DM_GetDM6xResolution(int handle, tagResolutionInfo *resolution);


/*
 ��������:	DM_ControlServoMotor
*����˵��:	���ƶ��
*�������:  handle��		���
			int value: 		���Ŀ��״̬��0����ʾ����1����ʾ���£�
*����ֵ:������ʾ�ɹ���������ʾʧ��		
*/
int  __stdcall DM_ControlServoMotor(int handle, int value);

//����3���ӿ���δʵ��
int DM_OpenIfrVideo(HWND hwnd,  char* ip, unsigned short port, int( __stdcall  *pFun)(char *, int));
int DM_SaveIfr( char *strFileName );
int DM_StopIfr();
//--------------------------------------------------------
}

#endif
