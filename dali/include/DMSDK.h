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


#define SPEED_TRG_PAN	0	//水平
#define SPEED_TRG_TILT	1	//垂直

//颜色索引号
	//自动		0
	//黑		1
	//白		2
	//红		3
	//橙		4
	//黄		5
	//绿		6
	//蓝		7
	//灰		8
	//紫		9


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

//屏蔽区域结构体
typedef struct tagShieldRegion
{
	int Index;
	bool Enable;
	int StartX;
	int StartY;
	int EndX;
	int EndY;
}_tagShieldRegion;

//2012-01-22 add, 回调函数方式上传温度信息时使用该结构
typedef struct tagTempMessage
{
	int handle;
	int len;//temperInfo的个数
	char dvrIP[16];
	tagTemperature  temperInfo[10];
}_tagTempMessage;

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

//激光测距得到的距离
struct tagDistanceInfo 
{
	int distance1;
	int distance2;
	int distance3;
};

//DM6x机型的分辨率,2013-05-27 add
struct tagResolutionInfo 
{
	int width;
	int height;
};

typedef struct 
{
	WORD PresetIndex;		//预置位编号
	char PresetName[10];		//预置位名称
}PRESET_DM60,  *LPPRESET_DM60 ;

///Error ID
#define DM_SUCCESS						 0x00000000

//ErrType
#define DM_OPEN_DIR_ERROR				-0x00002003		///> Open Directory Fail
#define DM_SOCKET_ERROR					-0x00001000		///> Socket Disconnect
#define DM_COMMAND_ERROR				-0x00001003		///> Command Send Fail
#define DM_OPEN_ERROR					-0x00003001		///> Open device Fail

//OPEN_DIR ERROR　ID
#define DM_OPEN_FILE_ERROR				-0x00002001		///> Open File Fail
#define DM_CLOSE_FILE_ERROR				-0x00002002		///> Close File Fail

//SOCKET ERROR ID
#define DM_SOCKET_SEND_ERROR			-0x00001001		///> Send Data Fail
#define DM_SOCKET_RECV_ERROR			-0x00001002		///> Recv Data Fail
#define DM_SOCKET_RECONNECT				-0x00001004		///> reconnect device


///CMD ERROR　ID
#define CMD_CAPTURE_ERROR				-0x00004001     ///> Capture fail
#define CMD_TEMPATURE_ERROR				-0x00004002     ///> Tempature Fail

//Open device ERROR　ID
#define CMD_FORWARD_SUCCESS				 0x00004000     ///> Open Device front success
#define CMD_FORWARD_ERROR               -0x00004003     ///> Open Device front fail

//2010-12-02 add
#define DM_ERROR_LOCALLOGINMAX		-0x00005001	//本地登陆的DVR数已经最大
#define DM_ERROR_LOGIN			-0x00005002	//登陆DVR失败
#define DM_ERROR_LOGINHANDLE			-0x00005003	//错误的句柄
#define DM_ERROR_LOGINSTATUS			-0x00005004	//没有登陆
#define DM_ERROR_NOSUPPORT			-0x00005005	//不支持的函数接口

#define DM_ERROR_REALPLAYMAX	-0x00006001	//本地的实时监视数已经最大

#define WM_APP						0x8000
//网络出错通知
#define WM_DM_PLAYER_ERROR			(WM_APP + 0x1050)   ///> Video error

//wParam : 发生错误的句柄号
//lParam : SDK唯一标示ID,该ID由客户调用SetUniSDKID函数设定 2008-04-11 add

//回放结束通知消息
#define WM_PLAYBACK_OVER			(WM_APP + 0x1051)
//wParam : 发生错误的句柄号
//lParam : SDK唯一标示ID,该ID由客户调用SetUniSDKID函数设定 2008-04-11 add

//语音对讲异常消息
#define WM_TALK_ERROR				(WM_APP + 0x1052)
//wParam : 发生错误的对讲句柄号			
//lParam : SDK唯一标示ID,该ID由客户调用SetUniSDKID函数设定 2008-04-11 add

#define WM_DM_ERROR				(WM_APP + 0x3051)	//2010-09-07 add

#define WM_DM_CAPTURE_FRAME		(WM_APP + 0x3052)
//wParam 原始数据消息内容
//lParam	设备句柄

#define WM_DM_TEMP_VALUE            (WM_APP + 0x3053)
//wParam  温度消息内容
//lParam   设备句柄
//实时温度消息

#define WM_DM_TEMP_ALARM			(WM_APP + 0x3054)
//wParam  报警消息内容
//lParam   设备句柄
//温度报警

//原始数据采集结束通知消息
#define WM_CAPTUREINFRA_OVER			(WM_APP + 0x3055)

//告警图片采集结束通知消息
#define WM_ALARMJPEG_OVER			(WM_APP + 0x3056)

//执行 DM_OpenMonitor 成功后返回的监视消息
#define WM_DM_PLAYER				(WM_APP + 0x3061)	///> Video handle(//2010-09-07 add,openmonitor调用成功发该消息）


extern "C"   //以c编译器编译


#define		INFRA_DATA	0	//红外原始数据
#define		INFRA_PARA	 1 //红外参数
#define		INFRA_DATA_HEADER	2	//数据头,对应结构DLVParagraph
#define		INFRA_PARA_HEADER	 3 //文件头,对应结构DLVFileHeader

//DLV 文件头
struct DLVFileHeader
{
    int   nFileVer; //3
    int   nFrameTime;
    int   nWidth;  //edit by duke 2009.10.21 type error
    int   nHeight;
};

//帧头格式：
struct DLVParagraph
{
    unsigned int SyncFlag;        //0x66DDDD66
    unsigned int nTime;           //当前时间
    unsigned int nPriorLength;    //上一帧长度
    unsigned int nType;           //帧类型
    unsigned int nCurrentLength;  //本帧长度
};
typedef void(CALLBACK *fInfraDataCallBack) (long lHandle, unsigned long dwDataType, unsigned char *pBuffer, unsigned long dwBufSize);

/****************************************************************************************************************/
/* 网络设置和操作																								*/
/****************************************************************************************************************/
/*
 函数名称:	DM_Init
*函数说明:	连接初始化
*输入参数:  
*返回值:			
*/
void __stdcall DM_Init();

/*
 函数名称:	DM_Connect
*函数说明:	连接DM60仪器
*输入参数:  hwnd：		消息处理窗口句柄
			IPAddr：	仪器IP地址
			Port：		命令端口（默认端口80）

  *返回值:  > 0 连接到仪器后的操作句柄,用DM_Disconnect 释放。
		    <= 0 连接失败			
*/
int __stdcall DM_Connect(HWND hwnd, char *IPAddr, int Port);

/*
 函数名称:	DM_ConnectWithName
*函数说明:	连接DM60仪器
*输入参数:  hwnd：		消息处理窗口句柄
			IPAddr：	仪器IP地址
			Port：		命令端口（默认端口80）
			UserName:	登陆用户名
			Password:	登陆密码
  *返回值:  > 0 连接到仪器后的操作句柄,用DM_Disconnect 释放。
		    <= 0 连接失败			
*/
int __stdcall DM_ConnectWithName(HWND hwnd, char *IPAddr, int Port, char *UserName, char *Password);

/*
 函数名称:	DM_Disconnect
*函数说明:	断开连接
*输入参数:  handle：句柄
*返回值:  >= 0： 正确；< 0： 错误			
*/
int __stdcall DM_Disconnect(int handle);

/*
 函数名称:	DM_SetIsotherm
*函数说明:	设置等温区域
			仅对 DM6x 二期或以后的有效, 更早的型号只支持1个等温区域, 分别用 DM_SetISOColor、DM_SetISOTemp 和 DM_SetISOHight
*输入参数:  handle：		句柄
			iIndex： 		等温编号, 支持3个等温区域（0 - 2之间）
			iColorID:		等温色序号,  见颜色索引号, 0表示关闭
			iIsoTemp：		等温区域中点温度 * 100
			iHightTemp:		等温区域温度范围 * 100
*返回值:	>0 成功, <0失败			
*/
int __stdcall DM_SetIsotherm(int handle, int iIndex, int iColorID, int iIsoTemp, int iHightTemp);

/*
 函数名称:	DM_GetIsotherm
*函数说明:	获得等温区域信息
			仅对 DM6x 二期或以后的有效, 更早的型号只支持1个等温区域, 分别用 DM_GetISOColor、 DM_GetISOTemp 和 DM_GetISOHight
*输入参数:  handle：		句柄
			iIndex： 		等温编号, 支持3个等温区域（0 - 2之间）
*返回值:			
			iColorID:		等温色序号,  见颜色索引号, 0表示关闭
			iIsoTemp：		等温区域中点温度 * 100
			iHightTemp:		等温区域温度范围 * 100
*/
int __stdcall DM_GetIsotherm(int handle, int iIndex, int *iColorID, int *iIsoTemp, int *iHightTemp);

/*
 函数名称:	DM_SetAlarmInfo
*函数说明: 报警温度设置
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
			Type:			测温目标类型，0：点，1：线，2：矩形区域
			Index:			测温目标序号，每种测温目标类型的序号都是从1开始的，区域9为全屏最热点，区域10为全屏最冷点
			AlarmPower:		报警开关，0：关闭，1：打开
			AlarmType:		报警触发方式，0：大于报警温度触发，1：小于报警温度触发
			AlarmTemp：		报警温度 * 100
			AlarmColorID:	报警颜色序号，见颜色索引号, 0表示不显示报警色
			AlarmMessageType:	报警联动开关，0：不联动，1：联动方式1，2：联动方式2
*返回值:
*注：
*/
void __stdcall DM_SetAlarmInfo(int handle, int Type, int Index, int AlarmPower, int AlarmType, int AlarmTemp, int AlarmColorID, int AlarmMessageType);

/*
 函数名称:	DM_GetAlarmInfo
*函数说明:  获取当前仪器的报警温度
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
			Type:			测温目标类型，0：点，1：线，2：矩形区域
			Index:			测温目标序号，每种测温目标类型的序号都是从1开始的，区域9为全屏最热点，区域10为全屏最冷点
*输出参数:	
			AlarmPower:		报警开关，0：关闭，1：打开
			AlarmType:		报警触发方式，0：大于报警温度触发，1：小于报警温度触发
			AlarmTemp：		报警温度 * 100
			AlarmColorID:	报警颜色序号，见颜色索引号, 0表示不显示报警色
			AlarmMessageType:	报警联动开关，0：不联动，1：联动方式1，2：联动方式2
*注：	
*/
int __stdcall DM_GetAlarmInfo(int handle, int Type, int Index, int *AlarmPower, int *AlarmType, int *AlarmTemp, int *AlarmColorID, int *AlarmMessageType);

/*
 函数名称:	DM_SetPreset
*函数说明:	将镜头当前位置设置为 1 个预置点
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
			iIndex： 		预置点编号, 支持128个预置点（0 - 127之间）
			cPresetName:	预置点名称, 最长10个字符
*返回值:	>0 成功, <0失败		
*/
int __stdcall DM_SetPreset(int handle, int iIndex, char *cPresetName);

/*
 函数名称:	DM_CallPreset
*函数说明:	将镜头调焦到某预置点
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
			iIndex： 		预置点编号, 支持128个预置点（0 - 127之间）
*返回值:	>0 成功, <0失败		
*/
int __stdcall DM_CallPreset(int handle, int iIndex);

/*
 函数名称:	DM_ResetPresetName
*函数说明:	重命名某个预置点
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
			iIndex： 		预置点编号, 支持128个预置点（0 - 127之间）
			cPresetName:	预置点的新名称, 最长10个字符
*返回值:	>0 成功, <0失败		
*/
int __stdcall DM_ResetPresetName(int handle, int iIndex, char *cPresetName);

/*
 函数名称:	DM_GetAllPreset
*函数说明:	获得所有镜头预置点的信息
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
			pPreset: 		预置点数组(0 ~ 127)
*返回值:	>0 成功, <0失败		
*/
int __stdcall DM_GetAllPreset(int handle, PRESET_DM60 pPreset[]);

/*
 函数名称:	DM_DeletePreset
*函数说明:	删除镜头预置点
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
			iIndex： 		预置点编号, 支持128个预置点（0 - 127之间）, -1表示全部删除
*返回值:	>0 成功, <0失败		
*/
int __stdcall DM_DeletePreset(int handle, int iIndex);

/*
 函数名称:	DM_GetPos
*函数说明:	获得镜头当前位置值
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄

*返回值:	>-2000 成功, <=-2000失败		
*/
int __stdcall DM_GetPos(int handle);

/*
 函数名称:	DM_CallPos
*函数说明:	将镜头调焦到某位置
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
*返回值:	>0 成功, <0失败		
*/
int __stdcall DM_CallPos(int handle, int iPos);

/****************************************************************************************************************/
/* 测温对象的获取与设置                                                                                         */
/****************************************************************************************************************/

/*
 函数名称:	DM_SetSpot
*函数说明:	设置测温点
*输入参数:  handle：		句柄
			iPoint： 		点编号			支持4个测温点（1 - 4之间）
			x,y：			点坐标        范围 (0,0  ---  319 * 239)
			mode: 0-High/1-Low/2-Avg
			Emiss：		辐射率  		（0 - 100）一般在90-95之间
*返回值:			
*/
void  __stdcall DM_SetSpot(int handle,int iPoint,int x,int y, int Emiss = 90);

/*
 函数名称:	DM_SetLine
*函数说明:	设置测温线
*输入参数:  handle：	句柄
			iLine：	线编号, 目前支持一条线测温, 固定值 1
			x1,y1：	起始点坐标 	(0,0  ---  319 * 239)；
			x2,y2：	结束点坐标 	(0,0  ---  319 * 239)
			x3,y3：	线上测温点, 由用户指定的测温点
			lineType,测温线类型, //0-Hori; 1-Vert; 2-Slash
			mode, 测温模式,  0-High/1-Low/2-Avg
			Emiss：	比幅射率  		（0 - 100）一般在10 -- 100之间

*返回值:			
*/
void  __stdcall DM_SetLine(int handle,int iLine,int x1,int y1,int x2,int y2, int x3,int y3, int Emiss = 90);

/*
 函数名称:	DM_SetArea
*函数说明:	设置测温区域
*输入参数:  handle：		句柄
			iArea：  		区域编号		支持3个测温区域（1 - 3）
			x1,y1： 		左上角坐标		(0,0  ---  319 * 239)
			x2,y2： 		右下角坐标		(0,0  ---  319 * 239)
			Emiss： 		辐射率  		（0 - 100）一般在90-95之间
			MeasureType：	区域测温时的测温方式 （0： 最高 1：最低 2：平均）
*返回值:			
*/
void __stdcall  DM_SetArea(int handle,int iArea,int x1,int y1,int x2,int y2,int Emiss = 90,int MeasureType = 0);

/*
 函数名称:	DM_ClearSpot
*函数说明:	清除SpotID指定的测温点信息
*输入参数:  handle：		句柄
			SpotID： 		点编号		1 -- 4
*返回值:			
*/
void __stdcall  DM_ClearSpot(int handle,int SpotID);

/*
 函数名称:	DM_ClearLine
*函数说明:	清除LineID指定的测温点信息
*输入参数:  handle：	句柄
			LineID：  	线编号	1
*返回值:			
*/
void __stdcall  DM_ClearLine(int handle,int LineID);

/*
 函数名称:	DM_ClearArea
*函数说明:	清除AreaID指定的测温区域信息
*输入参数:  handle：	句柄
			AreaID：  	区域编号	1 -- 3

*返回值:			
*/
void __stdcall  DM_ClearArea(int handle,int AreaID);

/*
 函数名称:	DM_ClearAllSpot
*函数说明:	清除所有测温点
*输入参数:  handle：	句柄
*返回值:			
*/
void __stdcall  DM_ClearAllSpot(int handle);

/*
 函数名称:	DM_ClearAllLine
*函数说明:	清除所有测温线
*输入参数:  handle：	句柄
*返回值:			
*/
void __stdcall  DM_ClearAllLine(int handle);

/*
 函数名称:	DM_ClearAllArea
*函数说明:	清除所有测温区域
*输入参数:  handle：	句柄
*返回值:			
*/
void  __stdcall DM_ClearAllArea(int handle);

/*
 函数名称:	DM_GetSpotTemp
*函数说明:	获取测单个测温点温度
*输入参数:  handle：		句柄
			SpotID：		点编号(1--n)
			Mode：			0：返回一次温度
							1：连续返回温度, 间隔时间由仪器自动调节
*返回值:			
*/
void __stdcall  DM_GetSpotTemp(int handle,int SpotID=1,int Mode = 0);

/*
 函数名称:	DM_GetLineTemp
*函数说明:	获取测单个测温线上用户设定测温点的温度
*输入参数:  handle：		句柄
			LineID：		线编号 (1 -- n)
			Mode：			0：返回一次温度
							1：连续返回温度, 间隔时间由仪器自动调节
*返回值:			
*/
void __stdcall  DM_GetLineTemp(int handle,int LineID = 1,int Mode = 0);

/*
 函数名称:	DM_GetAreaTemp
*函数说明:	获取单个测温区域温度
*输入参数:  handle：		句柄
			AreaID：		区域编号(1-- n)
			Mode：			0：返回一次温度
							1：连续返回温度, 间隔时间由仪器自动调节。

*返回值:			
*/
void __stdcall  DM_GetAreaTemp(int handle,int AreaID = 1,int Mode = 0);

/*
 函数名称:	DM_GetTemp
*函数说明:	获取所有测温目标的测温结果
*输入参数:  handle：		句柄
			Mode：			0：返回一次温度
							1：连续返回温度, 间隔时间由仪器自动调节。
*返回值:			
*/
void  __stdcall DM_GetTemp (int handle,int Mode);

/*
 函数名称:	DM_StopTemp
*函数说明:	停止连续测温的返回数据
*输入参数:  handle：		句柄
*返回值:			
*/
void __stdcall  DM_StopTemp (int handle);

/*
 函数名称:	DM_GetTempParam
*函数说明:	获取指定类型和编号的测温参数
*输入参数:  handle：	句柄
			Type：		测温数据类型 (1： 点  2： 线  3： 区域)
			Number：	测温编号 (1 -- n)
*返回值:>0 成功			
*/
int __stdcall  DM_GetTempParam (int handle,int Type,int Number);


/****************************************************************************************************************/
/* 原始数据采集                                                                                                 */
/****************************************************************************************************************/
/*
 函数名称:	DM_CaptureInfraredFrame
*函数说明:	开始原始数据采集, 返回结果在消息 WM_DM_CAPTURE_FRAME 和 WM_CAPTUREINFRA_OVER 中处理
*输入参数:  handle：	句柄
			Path： 		保存文件的路径或文件名。如果是路径, 则系统以时间作文件名保存在此路径下；如果是文件名, 则系统直接以输入的文件名保存。
			Frame： 	帧数
			Time：		帧与帧之间的间隔时间(ms) >= 20ms, 且必须是20的倍数。
			注意：Frame * Time <= 8秒
*返回值:  采集句柄，用于消息 WM_DM_CAPTURE_FRAME 和 WM_CAPTUREINFRA_OVER 的处理
*/
int __stdcall  DM_CaptureInfraredFrame(int handle, char *Path,int Frame,int Time);

/*
 函数名称:	DM_CaptureInfraredFrameStop
*函数说明:	停止原始数据采集
*输入参数:  handle		句柄,DM_Connect()函数的返回值
*返回值:			
*/
int  __stdcall DM_CaptureInfraredFrameStop(int handle);

/*
 函数名称:	DM_RecvInfraredData
*函数说明:  打开红外原始数据的回调
*输入参数:  handle, 句柄
*			InfraDataCallback, 回调函数		
*输出参数:  无
*返回值:正数表示成功, 负数表示失败	
*/
long __stdcall DM_RecvInfraredData(LONG handle, fInfraDataCallBack InfraDataCallback);

/*
 函数名称:	DM_RecvInfraredData_EX
*函数说明:  打开红外原始数据的回调
*输入参数:  handle, 句柄
*			Frame, 采集的总帧数
*			Time,两帧的时间间隔, 单位毫秒
*			InfraDataCallback, 回调函数		
*输出参数:  无
*返回值:正数表示成功, 负数表示失败	
*/
LONG __stdcall DM_RecvInfraredData_EX(LONG handle, int Frame,int Time, fInfraDataCallBack InfraDataCallback);

/*
 函数名称:	DM_StopRecvInfraredData
*函数说明:  停止红外原始数据的回调
*输入参数:  lRealHandle, 句柄, 即DM_RecvInfraredData()或DM_RecvInfraredData_EX()的返回值	
*输出参数:  
*返回值:TRUE表示成功, FALSE表示失败	
*/
int __stdcall DM_StopRecvInfraredData(long lRealHandle);

/****************************************************************************************************************/
/*
 函数名称:	DM_CaptureInfraredFromStream, 需要先执行 DM_RecvInfrareData_EX
*函数说明:	开始原始数据采集, 返回结果在消息 WM_DM_CAPTURE_FRAME 和 WM_CAPTUREINFRA_OVER 中处理
*输入参数:  handle：	DM_RecvInfraredData_EX 返回的句柄
			Path： 		保存文件的路径或文件名。如果是路径, 则系统以时间作文件名保存在此路径下；如果是文件名, 则系统直接以输入的文件名保存。
			Frame： 	帧数
			Interval：	每几帧取一帧
			
*返回值:  >=0 成功，<0失败
*/
int __stdcall  DM_CaptureInfraredFromStream(int handle, char *Path, int Frame, int Interval);

/*
 函数名称:	DM_CaptureInfraredFromStreamStop
*函数说明:  停止从内存中保存红外原始数据
*输入参数:  lRealHandle, 句柄, 即DM_RecvInfraredData()或DM_RecvInfraredData_EX()的返回值	
*输出参数:  
*返回值:TRUE表示成功, FALSE表示失败	
*/
int __stdcall DM_CaptureInfraredFromStreamStop(long lRealHandle);

/******************************************************************************************************************/
/* 图像设置                                                                                                       */
/******************************************************************************************************************/

/*
 函数名称:	DM_SetPallette
*函数说明:	设置色标
*输入参数:  handle		句柄
			Type： 		色标号 (0 -- 9) 
			bPorarity： 		0、正相 1、反相
*返回值:			
*/
void  __stdcall DM_SetPallette(int handle,int Type,  bool bPorarity = 0);

/*
 函数名称:	DM_GetPallette
*函数说明:	获取红外仪器的伪彩色色标
*输入参数:  handle		句柄
*返回值:    当前色标号			
*/
int  __stdcall DM_GetPallette(int handle);

/*
 函数名称:	DM_SetVideoOutType
*函数说明:	设置仪器的视频输出格式
*输入参数:  handle：			句柄
			VideoOutType：  0：PAL;1： NTSC制
*返回值:			
*/
void  __stdcall DM_SetVideoOutType(int handle, VIDEO_OUT_TYPE VideoOutType);

/*
 函数名称:	DM_GetVideoOutType
*函数说明:	获取仪器的当前视频输出格式(0：PAL;1： NTSC制)
*输入参数:  handle：			句柄
*返回值:	当前视频输出格式(0：PAL;1： NTSC制)		
*/
int  __stdcall DM_GetVideoOutType(int handle);

/*
 函数名称:	DM_SetUpdateMeaTemp
*函数说明:	设置仪器测温结果的返回速度
*输入参数:  handle：			句柄
			Freq  1~100, 表示每秒1~100次, 实际有效值要看仪器的反应速度
*返回值:			
*/
void  __stdcall DM_SetUpdateMeaTemp(int handle, int Freq);

/*
 函数名称:	DM_GetUpdateMeaTemp
*函数说明:	获取仪器测温结果的返回速度
*输入参数:  handle：			句柄
*返回值:	速度, 单位为 次/秒		
*/
int  __stdcall DM_GetUpdateMeaTemp(int handle);

/*
 函数名称:	DM_SetVideoMode
*函数说明:	图像手动/自动模式切换
*输入参数:  handle：		句柄
			Mode：			模式(0、手动, 2、自动)
*返回值:		
*/
void __stdcall  DM_SetVideoMode(int handle,int Mode);

/*
 函数名称:	DM_AutoFocus
*函数说明:	仪器自动聚焦
*输入参数:  handle：		句柄
*返回值:		
*/
void  __stdcall DM_AutoFocus(int handle);

/*
 函数名称:	DM_FocusFar
*函数说明:	红外调焦, 拉远
*输入参数:  handle：		句柄
			Step： 		步长
*返回值:		
*/
void  __stdcall DM_FocusFar(int handle,int step = 1);

/*
 函数名称:	DM_FocusNear
*函数说明:		红外调焦, 拉近
*输入参数:  handle：		句柄
			Step： 		步长
*返回值:		
*/
void __stdcall  DM_FocusNear(int handle,int step = 1);

/*
 函数名称:	DM_StopFocus
*函数说明:	仪器停止调焦, 在使用DM_DurativeNear, DM_DurativeFar后有效
*输入参数:  handle：		句柄
*返回值:		
*/
void __stdcall  DM_StopFocus(int handle);

/*
 函数名称:	DM_DurativeNear
*函数说明:	仪器调焦,持续拉近, 直到调用DM_StopFocus停止调焦
*输入参数:  handle：		句柄
*返回值:		
*/
void  __stdcall DM_DurativeNear (int handle);

/*
 函数名称:	DM_DurativeFar
*函数说明:	仪器调焦, 持续拉远, 直到调用DM_StopFocus停止调焦
*输入参数:  handle：		句柄
*返回值:		
*/
void __stdcall DM_DurativeFar (int handle);

/*
 函数名称:	DM_ShowTempValueOnImage
*函数说明:	打开测温状态, 仪器上是否显示测温数据
*输入参数:  handle：		句柄
			bEnable：		0： 隐藏 1、显示
*返回值:		
*/
void __stdcall DM_ShowTempValueOnImage (int handle, bool bEnable);

/*
 函数名称:	DM_GetTempValueOnImageStatus
*函数说明:	获取仪器上是否显示测温数据
*输入参数:  handle：		句柄
			
*返回值:	0： 隐藏 1、显示	
*/
int __stdcall DM_GetTempValueOnImageStatus(int handle);

/*
 函数名称:	DM_SetISOTemp
*函数说明:	设置仪器的等温温度值, 在测温时需要使用
*输入参数:  handle：		句柄
			ThermTemp：		温度 * 100
*返回值:	
*/
void __stdcall DM_SetISOTemp(int handle,int ThermTemp);

/*
 函数名称:	DM_GetISOTemp
*函数说明:	获取仪器当前设置的等温温度
*输入参数:  handle：		句柄
*返回值:	等温温度
*/
int __stdcall DM_GetISOTemp(int handle);

/*
 函数名称:	DM_SetISOHight
*函数说明:	设置等温高度（等温色的温度范围）, 在测温时使
*输入参数:  handle：			句柄
			ThermHight：		高度*100

*返回值:	
*/
void __stdcall DM_SetISOHight(int handle,int ThermHight);

/*
 函数名称:	DM_GetISOHight
*函数说明:	获取当前仪器的等温高度
*输入参数:  handle：			句柄
			ThermHight：		高度*100


*返回值:	等温高度
*/
int __stdcall DM_GetISOHight(int handle);

/*
 函数名称:	DM_SetISOColor
*函数说明:	设置等温色, 在测温时使用
*输入参数:  handle：			句柄
			ColorID： 	等温色号（见颜色索引号）
*返回值:	等温高度
*/
void __stdcall DM_SetISOColor(int handle,int ColorID);

/*
 函数名称:	DM_GetISOColor
*函数说明:	获取当前仪器的等温色
*输入参数:  handle：句柄
*返回值:	等温色（见颜色索引号）
*/
int __stdcall DM_GetISOColor(int handle);

/*
 函数名称:	DM_SetTempUnit
*函数说明:	设置温度单位
*输入参数:  handle：		句柄
			Unit：			0：℃;1 ℉;2 K
*返回值:
*/
void __stdcall DM_SetTempUnit(int handle,int Unit);

/*
 函数名称:	DM_GetTempUnit
*函数说明:	获取仪器的温度单位
*输入参数:  handle：		句柄
*返回值:	温度单位（0：℃;1 ℉;2 K）
*/
int __stdcall DM_GetTempUnit(int handle);

/*
 函数名称:	DM_SetUpTempRange
*函数说明:	在手动调色标时使用, 用于设置温度上限
*输入参数:  handle	：句柄
			Offset ：在原来色标上限的基础上增减,值 -10、-1、+1、+10 之间, 单位为度

*返回值:	
*/
void __stdcall DM_SetUpTempRange(int handle,int Offset);

/*
 函数名称:	DM_SetDownTempRange
*函数说明:	在手动调色标时使用, 用于设置温度下限
*输入参数:  handle	：句柄
			Offset ：在原来色标上限的基础上增减,值 -10、-1、+1、+10 之间, 单位为度

*返回值:	
*/
void __stdcall DM_SetDownTempRange(int handle,int Offset);


/****************************************************************************************************************/
/* 测温参数配置                                                                                                 */
/****************************************************************************************************************/
over
/*
 函数名称:	DM_SetMeasureClass
*函数说明:	设置测温档位, 具体支持档位详见镜头说明
*输入参数:  handle：		句柄
			ParamValue ： 档位 （1-8）

*返回值:			
*/
void __stdcall DM_SetMeasureClass(int handle,int ParamValue);

/*
 函数名称:	DM_GetMeasureClass
*函数说明:	获取当前的测温档位
*输入参数:  handle：		句柄
*返回值:	当前的测温档位（档位值从1开始）		
*/
int __stdcall DM_GetMeasureClass(int handle);

/*
 函数名称:	DM_SetRefeType
*函数说明:	设置参考温度类型
*输入参数:  handle：		句柄
			ParamValue ： 0、关闭   
			1、	参考温度, 值由DM_SetRefeTemp设置   
			2 - 5 ：对应 点1--4 温度
			6 - 8 ： 对应 区域 1-3温度

*返回值:			
*/
void __stdcall DM_SetRefeType(int handle,int ParamValue);

/*
 函数名称:	DM_GetRefeType
*函数说明:	获取当前仪器的参考温度类型
*输入参数:  handle：		句柄		
*返回值:    仪器的参考温度类型			
*/
int __stdcall DM_GetRefeType(int handle);

/*
 函数名称:	DM_SetRefeTemp
*函数说明:	当选择参考类型为(1)参考温度时用到, 设置参考温度值
*输入参数:  
			handle：			句柄
			ParamValue ：  温度 * 100
*返回值:    仪器的参考温度类型			
*/
void __stdcall DM_SetRefeTemp (int handle,int ParamValue);

/*
 函数名称:	DM_GetRefeTemp
*函数说明:	当选择参考类型为(1)参考温度时用到, 设置参考温度值
*输入参数:  
			handle：			句柄
			ParamValue ：  温度 * 100
*返回值:    仪器的参考温度类型			
*/
int __stdcall DM_GetRefeTemp (int handle);

/*
 函数名称:	DM_SetAmbientTemp
*函数说明:	环境温度设置, 当外界环境温度与设置值相差超过5时, 需要重新设定环境温度
*输入参数:  
			handle：		句柄
			Temper：  	温度 * 100
*返回值:    			
*/
void __stdcall DM_SetAmbientTemp(int handle,int Temp);

/*
 函数名称:	DM_GetAmbientTemp
*函数说明:	获取当前仪器的环境温度
*输入参数:  
			handle：		句柄
*返回值:    环境温度			
*/
int __stdcall DM_GetAmbientTemp(int handle);

/*
 函数名称:	DM_SetObjDistance
*函数说明:	设置环境距离, 当图像目标与仪器的距离与设置值相差5m 以上时, 需要重新设定环境距离
*输入参数:  
			handle：		句柄
			Distance：	 	距离 (单位：厘米)
*返回值:    			
*/
void __stdcall DM_SetObjDistance(int handle,int Distance);

/*
 函数名称:	DM_GetObjDistance
*函数说明:	获取仪器设置的环境距离值
*输入参数:  
			handle：		句柄
*返回值:    环境距离			
*/
int __stdcall DM_GetObjDistance(int handle);

/*
 函数名称:	DM_SetAmbientHumidity
*函数说明:	设置环境湿度,根据具体的外界环境来设置湿度
*输入参数:  
			handle：		句柄
*返回值:    环境距离			
*/
void __stdcall DM_SetAmbientHumidity(int handle,int Humidity);

/*
 函数名称:	DM_GetAmbientHumidity
*函数说明:	获取仪器设置的环境湿度值
*输入参数:  
			handle：		句柄
*返回值:    环境湿度 湿度范围（0-100）			
*/
int __stdcall DM_GetAmbientHumidity(int handle);

/*
 函数名称:	DM_SetReviseParam
*函数说明:	设置修正系数
*输入参数:  
			handle			句柄
			ReviseParam		修正系数 * 100

*返回值:   			
*/
void __stdcall DM_SetReviseParam(int handle,int ReviseParam);

/*
 函数名称:	DM_GetReviseParam
*函数说明:	获取修正系数
*输入参数:  
			handle			句柄
			ReviseParam		修正系数 * 100
*返回值:   			
*/
int __stdcall DM_GetReviseParam(int handle);

/*
 函数名称:	DM_SetReviseTemp
*函数说明:	设置修正温度
*输入参数:  
			handle			句柄
			ReviseTemp		修正温度 * 100

*返回值:   			
*/
void __stdcall DM_SetReviseTemp(int handle,int ReviseTemp);

/*
 函数名称:	DM_GetReviseTemp
*函数说明:	获取修正温度
*输入参数:  
			handle			句柄
*返回值:   	修正温度		
*/
int __stdcall DM_GetReviseTemp(int handle);

/****************************************************************************************************************/
/* 报警设置                                                                                                     */
/****************************************************************************************************************/

/*
 函数名称:	DM_OpenAlarm
*函数说明:	打开仪器端报警功能, 报警信号的输出在消息WM_TEMP_ALARM (0)中处理
*输入参数:  handle：	句柄
*返回值:
**注：		
*/
void __stdcall DM_OpenAlarm(int handle);

/*
 函数名称:	DM_CloseAlarm
*函数说明: 关闭仪器端报警功能
*输入参数:  handle：	句柄
*返回值:
*注：	
*/
void __stdcall DM_CloseAlarm(int handle);

/*
 函数名称:	DM_SetAlarmTemp
*函数说明: 报警温度设置
*输入参数:  handle：		句柄
			Temper ：  	温度 * 100
*返回值:
*注：
*/
void __stdcall DM_SetAlarmTemp(int handle,int Temp);

/*
 函数名称:	DM_GetAlarmTemp
*函数说明:  获取当前仪器的报警温度
*输入参数:  handle：		句柄
*返回值:	报警温度
*注：	
*/
int __stdcall DM_GetAlarmTemp(int handle);

/*
 函数名称:	DM_SetAlarmColor
*函数说明:  设置报警色
*输入参数:  handle：		句柄
			ColorID ：	（见颜色索引号）
*返回值:	
*注：
*/
void __stdcall DM_SetAlarmColor(int handle,int ColorID);

/*
 函数名称:	DM_GetAlarmColor
*函数说明:  获取当前仪器的报警色
*输入参数:  handle：		句柄
*返回值:	报警颜色（见颜色索引号）
*注：
*/
int __stdcall DM_GetAlarmColor(int handle);

/*
 函数名称:	DM_OpenRemoteAlarm
*函数说明:  打开仪器端报警功能, 报警信号的输出在消息WM_TEMP_ALARM (0)中处理
*输入参数:  handle：		句柄
*返回值:	
*/
void __stdcall  DM_OpenRemoteAlarm(int handle);

/*
 函数名称:	DM_CloseRemoteAlarm
*函数说明:  关闭仪器端报警功能
*输入参数:  handle：		句柄
*返回值:	
*/
void __stdcall  DM_CloseRemoteAlarm(int handle);

/*
 函数名称:	DM_SetRemoteAlarmTemp
*函数说明:  报警温度设置
*输入参数:  handle：		句柄
			Temper ：  	温度 * 100
*返回值:	
*/
void __stdcall  DM_SetRemoteAlarmTemp(int handle,int Temp);

/*
 函数名称:	DM_GetRemoteAlarmTemp
*函数说明:  获取当前仪器的报警温度
*输入参数:  handle：		句柄
*返回值:	报警温度
*/
int __stdcall  DM_GetRemoteAlarmTemp(int handle);

/*
 函数名称:	DM_SetRemoteAlarmColor
*函数说明:  设置报警色
*输入参数:  handle：		句柄
			ColorID ：	（见颜色索引号）
*返回值:	
*/
void __stdcall  DM_SetRemoteAlarmColor(int handle,int ColorID);

/*
 函数名称:	DM_GetRemoteAlarmColor
*函数说明:  获取当前仪器的报警色
*输入参数:  handle：		句柄
*返回值:	报警颜色（见颜色索引号）
*/
int __stdcall  DM_GetRemoteAlarmColor(int handle);

/*
 函数名称:	DM_IOAlarm
*函数说明:  设置仪器报警IO口及报警使能
*输入参数:  handle：		句柄
*返回值:	报警颜色（见颜色索引号）
*/
void __stdcall DM_IOAlarm(int handle, int iIO, int iEnable);

/*************************************************************************************************************8****/
/*   系统配置设置                                                                                                 */
/******************************************************************************************************************/

/*
 函数名称:	DM_SetIPAddr
*函数说明:  设置仪器的IP地址
*输入参数:  handle：			句柄
			IP ： IP地址   格式 ： 192.168.0.1

*返回值:
*/
void __stdcall  DM_SetIPAddr(int handle, char *IP, char *SubMask, char *GateWay);

/*
 函数名称:	DM_SetMAC
*函数说明:  设置MAC地址
*输入参数:  handle：		句柄
			Mac ：		地址
*返回值:
*/
void __stdcall  DM_SetMAC(int handle,char *Mac);

/*
 函数名称:	DM_SetAutoAdjustTime
*函数说明:  设置自动校正间隔时间
*输入参数:  handle：		句柄
			Time ： 		时间（单位：秒）

*返回值:
*/
void __stdcall DM_SetAutoAdjustTime(int handle,int Time);

/*
 函数名称:	DM_GetAutoAdjustTime
*函数说明:  获取当前仪器的自动校正间隔时间
*输入参数:  handle：		句柄
			
*返回值:    间隔时间（秒）
*/
int __stdcall DM_GetAutoAdjustTime(int handle);

/*
 函数名称:	DM_SetDateTime
*函数说明:  调整仪器时间
*输入参数:  handle		句柄
			year			年
			month		月
			day			日
			hour		时
			min			分
			sec			秒
			
*返回值:    
*/
void  __stdcall DM_SetDateTime(int handle,int year,int month,int day,int hour,int min,int sec);

/*
 函数名称:	DM_GetDateTime
*函数说明:  获取仪器的当前时间
*输入参数:  handle		句柄
			
*输出参数:  字符串, 格式yyyy-mm-dd hh-mm-ss
			yyyy		年
			mm			月
			dd			日
			hh			时
			mm			分
			ss			秒
*/
void  __stdcall DM_GetDateTime(int handle,char *DateTime);

/*
 函数名称:	DM_LoadDefault
*函数说明:  恢复出厂设置
*输入参数:  handle		句柄
*返回值：无
*/
void  __stdcall DM_LoadDefault(int handle);

/*
 函数名称:	DM_GetSystemInfo
*函数说明:  获取仪器的系统信息, 生成日期和版本号
*输入参数:  handle		句柄
*输出参数：SysInfo		日期和版本号字符串
*返回值：无
*/
void __stdcall  DM_GetSystemInfo(int handle,char *SysInfo);


/********************************************************************************************************8*********/
/*  视频处理函数                                                                                               */
/******************************************************************************************************************/

/*
 函数名称:	DM_PlayerInit
*函数说明:	视频监控前的初始化。每套系统, 不管开了几个视频监控窗口, 本函数只能调用一次
*输入参数:  hwnd, 视频显示窗口句柄
*返回值:	=0  正确, 用DM_PlayerCleanup释放；
			<0  错误
*/
int __stdcall  DM_PlayerInit(HWND hwnd);

/*
 函数名称:	DM_OpenMonitor
*函数说明:	打开视频监控
*输入参数:  
			hwnd：　	视频显示窗口句柄
			ip ：  		仪器IP地址   
			port ：  		端口
			channel ：  	通道号, 目前只支持一个通道

*返回值:	>=0 连接成功，视频监控句柄通过 WM_DM_PLAYER 消息的 wParam 返回
			<0 连接失败
*/
//预留, netsdk暂时不提供此接口
int  __stdcall DM_OpenMonitor(HWND hwnd, char* ip,unsigned short port,int channel= 0);

/*
 函数名称:	DM_SetOSD
*函数说明:	设置视频的OSD
*输入参数:  
			handle：　	WM_DM_PLAYER 消息的 wParam 返回的句柄	
			OSDType :   	0X00 无
			0X01 主机时间
			0X02 码流速率
			0X04 主机IP地址


*返回值:	>0 成功 
			<0 失败
*注： 该接口暂时保留
*/
int __stdcall DM_SetOSD(int handle,int OSDType);

/*
 函数名称:	DM_CloseMonitor
*函数说明:	关闭视频监控
*输入参数:  
			handle：　WM_DM_PLAYER 消息的 wParam 返回的句柄
 *返回值:	>0 成功 
			<0 失败
*/
int  __stdcall DM_CloseMonitor(int handle);

/*
 函数名称:	DM_PlayerCleanup
*函数说明:	清除int __stdcall DM_PlayerInit配置的资源
*输入参数:  
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_PlayerCleanup();

/*
 函数名称:	DM_Record
*函数说明:	开始录像
*输入参数: 
            handle：　WM_DM_PLAYER 消息的 wParam 返回的句柄	
            path ：   保存文件路径
 
*返回值:	>=0 成功 
			<0 失败
*/
int __stdcall  DM_Record(int handle, char* path);

/*
*函数名称:	DM_StopRecord
*函数说明:	停止录像
*输入参数:  handle：　	WM_DM_PLAYER 消息的 wParam 返回的句柄 
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_StopRecord(int handle);

/*
*函数名称:	DM_Capture
*函数说明:	采集一幅图像
*输入参数:  handle：　	WM_DM_PLAYER 消息的 wParam 返回的句柄
			path ： 	保存文件路径

*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_Capture(int handle, char *path);

/*
*函数名称:	DM_PlayBack
*函数说明:	文件回放
*输入参数:  hwnd ：播放文件需要的窗口句柄
            file	录像文件
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_PlayBack(HWND hwnd, char *file);

/*
*函数名称:	DM_ClosePlayBack
*函数说明:	关闭文件回放
*输入参数:  handle	DM_PlayBack函数的返回值
            
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_ClosePlayBack(int handle);

/*
*函数名称:	DM_PlayBackPause
*函数说明:	暂停播放
*输入参数:  handle	DM_PlayBack函数的返回值
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_PlayBackPause(int handle);

/*
*函数名称:	DM_PlayBackContinue
*函数说明:	继续播放
*输入参数:  handle	DM_PlayBack函数的返回值
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_PlayBackContinue(int handle);

/*
*函数名称:	DM_PlayBackStop
*函数说明:  停止回放
*输入参数:  handle	DM_PlayBack函数的返回值
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_PlayBackStop(int handle);

/*
*函数名称:	DM_PlayBackSpeed
*函数说明:  步进播放
*输入参数:  
			handle	DM_PlayBack函数的返回值
			speed	步进速度
			-4     1/4倍速 
			-2     1/2倍速
			1      正常速度
			2      2倍速
			4      4倍速


*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_PlayBackSpeed(int handle,int speed);

/*
*函数名称:	DM_PlayBackStep
*函数说明:  单步播放
*输入参数:  
			handle	DM_PlayBack函数的返回值
*返回值:	>=0 成功 
			<0 失败
*/
int  __stdcall DM_PlayBackStep(int handle);

/******************************************************************************************************************/
/*  云台控制                                                                                                   */
/******************************************************************************************************************/
//云台协议
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
	DALI_KEY_STOP,			//停止
		DALI_KEY_LEFT,		//	向左
		DALI_KEY_RIGHT,		//	向右
		DALI_KEY_UP,		//		向上
		DALI_KEY_DOWN,	//	向下
		DALI_KEY_LEFT_UP,	//	左上
		DALI_KEY_LEFT_DOWN,//	左下
		DALI_KEY_RIGHT_UP,	//	右上
		DALI_KEY_RIGHT_DOWN,//右下
		DALI_KEY_ZOOM_IN,
		DALI_KEY_ZOOM_OUT,
		DALI_KEY_FOCUS_NEAR,
		DALI_KEY_FOCUS_FAR,
};

enum DALI_PRESET_DIR {
		DALI_KEY_PRESET_SAVE,	//保存、设置
		DALI_KEY_PRESET_CALL,	//调用
		DALI_KEY_PRESET_AUTO,	//自动
		DALI_KEY_PRESET_CLEAR,	//清除
		DALI_KEY_PRESET_ADD,	//	添加
};

/*
*函数名称:	DM_PTZSettings
*函数说明:  云台初始化设置
*输入参数:  
			handle：	句柄
			Protocol：	云台控制协议（参见DALI_PTZ_PROTOCOL中的定义, 目前支持Pelco_D 和 YAAN）
			NAddrID：	云台地址

*返回值:
*/
void  __stdcall DM_PTZSettings(int handle,DALI_PTZ_PROTOCOL Protocol = PELCO_D,int nAddrID = 1);

/*
*函数名称:	DM_PTZSpeed
*函数说明: 云台速度控制
*输入参数:  
			handle：			句柄
			nSpeedTrgID：   	运动方向	
			#define SPEED_TRG_PAN	0	//水平
			#define SPEED_TRG_TILT	1	//垂直
			nSpeed：			速度

*返回值:
*/
void  __stdcall DM_PTZSpeed(int handle,int nSpeedTrgID,int nSpeed = 1);

/*
*函数名称:	DM_PTZControl
*函数说明:  云台控制
*输入参数:  
			handle：		句柄
			ctrlCmd：		控制命令
			Movement		移动方向
*返回值:
*/
void  __stdcall DM_PTZControl(int handle,DALI_CONTROL_CMD_DIR ctrlCmd,DALI_MOVEMENT_DIR Movement);

/*
*函数名称:	DM_PTZPreset
*函数说明:  云台预置位控制
*输入参数:  
			handle：		句柄
			Preset：		DALI_PRESET_DIR中定义
			nPoint：		预置点
*返回值:
*/
void  __stdcall DM_PTZPreset(int handle, DALI_PRESET_DIR Preset, int nPoint);

/*****************************************************************************************************************/
/* 其他                                                                                                          */
/*****************************************************************************************************************/

/*
*函数名称:	DM_GetStatus
*函数说明:  获取仪器工作状态, 具体类型参见 enumTestDeviceStatus
*输入参数:  handle：		句柄
*返回值:    DM60的当前状态
*/
int __stdcall  DM_GetStatus(int handle);

/*
*函数名称:	DM_KBDControl
*函数说明:  仪器模拟键盘控制
*输入参数:  
			handle 句柄；
			nValue 值：
			7		保存键 	9		向左键 
			10		向上键   	11		取消键
			12		向右键 	13		向下键
			14		确定键

*返回值:
*/
void  __stdcall DM_KBDControl(int handle,int nValue);

/*
*函数名称:	DM_AutoAdjust
*函数说明:  触发仪器调零
*输入参数:  
			handle 句柄；
*返回值:	>0 成功			
*/
int  __stdcall DM_AutoAdjust(int handle);

/*	函数名称: DM_Open
 *	函数说明：打开仪器前端
 *   输入参数：	handle 句柄；
 *	返回值： >=0 成功
*/
int  __stdcall DM_Open(int handle);


/*	函数名称: DM_Close
 *	函数说明：关闭仪器前端
 *	输入参数：handle 句柄；
 *	返回值： >=0 成功
 */
int  __stdcall DM_Close(int handle);


/*	函数名称: DM_GetRemoteAlarm
 *	函数说明：获取仪器端报警状态, 
 *	输入参数：handle：		句柄
 *	返回值：器端报警状态(0：关闭, 1：打开)
 */
int  __stdcall DM_GetRemoteAlarm(int handle);


/*	函数名称: DM_GetVideoMode
 *	函数说明: 获取图像手动/自动模式
 *	输入参数:handle：		句柄
 *	返回值：模式(0、手动, 1、自动)
 */
int  __stdcall DM_GetVideoMode(int handle);

/*	函数名称: DM_GetMAC
*	函数说明：	获取MAC地址
*	输入参数：handle：	句柄
*			  Mac ：		地址
*	返回值： N/A
*/
void  __stdcall DM_GetMAC(int handle,char *Mac);

/*	函数名称: DM_GetRemoteLanguage
*	函数说明：获取仪器的语言
*	输入参数：handle		句柄
*	返回值： 仪器的语言(0：英文, 1：中文)
 */
int  __stdcall DM_GetRemoteLanguage(int handle);

/*	函数名称: DM_SetRemoteLanguage
*	函数说明：设置仪器的语言
*	输入参数：handle		句柄
*			  iLanguage    仪器的语言标致（0：英文, 1：中文）
*	返回值： >=0 成功
 */
int  __stdcall DM_SetRemoteLanguage(int handle, int iLanguage);

/*	函数名称: DM_Reset
*	函数说明：重启仪器
*	输入参数：handle		句柄
*	返回值： >=0 成功
 */
int  __stdcall DM_Reset(int handle);

//-----------------------------------------------------
//2010-11-01,以下接口为兼容老的DM60机型而特意增加

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

void __stdcall DM_GetVersion(char *Version);

/*
Description：	open local alram
Input：
handle		Handle
Return：
>=0:     Success
*/
int __stdcall DM_OpenLocalAlarm(int handle);

/*
Description：	close local alram
Input：
handle		Handle
Return：
>=0:     Success
*/
int __stdcall DM_CloseLocalAlarm(int handle);

/*
Description：	set local alram type
Input：
handle:		Handle
type:		0: Min 1: Max 2: Diff
Return：
>=0:     Success
*/
int __stdcall DM_SetLocalAlarmType(int handle,int type);

/*
Description：	get local alram type
Input：
handle		Handle
Return:
0: Min 1: Max 2: Diff
*/
int __stdcall DM_GetLocalAlarmType(int handle);

/*
Description：	set local alram mode
Input：
handle:		Handle
mode:		 0: > 1: <
Return：
>=0:     Success
*/
int __stdcall DM_SetLocalAlarmMode(int handle,int mode);

/*
Description：	get local alram mode
Input：
handle:		Handle
Return：
0: > 1: <
*/
int __stdcall DM_GetLocalAlarmMode(int handle);

/*
Description：	set local alram refe 
Input：
handle		Handle
refe：	
0、Close
1、	Refe Tempature, value by DM_SetLocalAlarmTemp
2 - 5 ：spot (1-4) tempature
6 - 8 ：area (1-3) tempature
Return：
>=0:     Success
*/
int __stdcall DM_SetLocalAlarmRefe(int handle,int refe);

/*
Description：	get local alram refe
Input：
handle:		Handle
Return：
0、Close
1、	Refe Tempature, value by DM_SetLocalAlarmTemp
2 - 5 ：spot (1-4) tempature
6 - 8 ：area (1-3) tempature
*/
int __stdcall DM_GetLocalAlarmRefe(int handle);

/*
Description：	set local alram tempature
Input：
handle:		Handle
temp:		tempature
Return：
>=0:     Success
*/
int __stdcall DM_SetLocalAlarmTemp(int handle,float temp);

/*
Description：	get local alram tempature
Input：
handle:		Handle
Return：
tempature
*/
float __stdcall DM_GetLocalAlarmTemp(int handle);

/*
Description：get device system info
Input：
handleL:	Handle
output：
SysInfo:	see tagSystemInfo
Return：
>=0:    Success
*/
void __stdcall DM_GetSysInfo(int handle,tagSystemInfo *SysInfo);

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
int __stdcall DM_ReceiveMonitorStream(char* ip, unsigned short port,int channel, STREAMCALL callback ,void *data );

/*
Input:	
handle:	  by DLDVR_ReceiveMonitorStream return
Return:
=0: success <0: fail
*/
int __stdcall DM_StopMonitorStream(int handle);

//下面几个接口尚未实现--------------------------------------------------------begin
//hWnd: WM_DM_PLAYER 消息的 wParam 返回的句柄
int __stdcall DM_OpenMonitorEX(HWND hWnd, int frameRate, int fmt, int rl);
int __stdcall DM_SetStreamBuf(int handle, BYTE *buf, int len);
int __stdcall DM_EmptyStreamBuf(int handle);
//上面几个接口尚未实现--------------------------------------------------------end

/*
Description：	Yuntai Control
Input：
handle		Handle
cmd   	Control command
len		command Len
Return：
>=0:     Success
*/	
int __stdcall DM_YTControl(int handle,char *cmd, int len);

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
Description：	init callback of real tempature
Input：
handle：		Handle
pFun：			CallBack function
Return：
NULL
*/
void __stdcall DM_GetRealTempObject(int handle, int(__stdcall *pFun)(int ,stTempDest[], int));

/*
Description：	enable natural termpature range
Input：
handle：		Handle
iEnable：		0: disable 1: enable
Return：
>=0:     Success
*/
int __stdcall DM_SetNaturalTempRangeEnable(int handle, int iEnable);

/*
Description：	get natural termpature range status
Input：
handle：		Handle
Return：
0: disable 1: enable
*/
int __stdcall DM_GetNaturalTempRangeEnable(int handle);

/*
Description：	set termpature range
Input：
handle：	Handle
HighTemp：	High tempature * 100
LowTemp:	Low Tempature * 100
Return：
>=0:     Success
*/
int __stdcall DM_SetNaturalTempRange(int handle, int LowTemp, int HighTemp);

/*
Description：	get termpature range
Input：
handle：	Handle
Return：
>=0:     Success
HighTemp：	High tempature * 100
LowTemp:	Low Tempature * 100
*/
int __stdcall DM_GetNaturalTempRange(int handle, int *LowTemp, int *HighTemp);

/*
Description：	enable intellect Measure Tempature
Input：
handle：	Handle
nIntellect:	0: diable 1: enbale
Return：
>=0:     Success
*/
int __stdcall DM_SetIntellectMeasureTemp(int handle,int nIntellect);

/*
Description：	get intelleect measure tempature
Input：
handle：	Handle
Return：
>=0:     Success
*/
int __stdcall DM_GetIntellectMeasureTemp(int handle);

/*
Description：	set Black Board Paramter
Input：
handle：		Handle
nStartX:		LeftUp X value
nStartY:		LeftUp Y value
nEndX:			RightDown X value
nEndY:			RightDown Y value
dblBlackTemp:	BlackBoard tempature * 100
dblBlackEmiss:	Emiss * 100
Return：
>=0:     Success
*/
int __stdcall DM_SetBlackBoardPara(int handle,int nStartX, int nStartY, int nEndX, int nEndY, 
						 int dblBlackTemp, int dblBlackEmiss);

/*
Description：	Get Black Board Paramter
Input：
	handle：	Handle
Return：
	>=0:     Success
	nStartX:		LeftUp X value
	nStartY:		LeftUp Y value
	nEndX:			RightDown X value
	nEndY:			RightDown Y value
	dblBlackTemp:	BlackBoard tempature * 100
	dblBlackEmiss:	Emiss * 100
*/
int __stdcall DM_GetBlackBoardPara(int handle, int *nStartX, int *nStartY, int *nEndX, int *nEndY, 
						 int *dblBlackTemp, int *dblBlackEmiss);

/*
Description：	set intellect tempature range
Input：
handle：	Handle
HighTemp:	High tempature * 100
nLowerTemp:	Lower Tempature * 100
Return：
>=0:     Success
*/
int __stdcall DM_SetIntellectTempRange(int handle,int HighTemp, int nLowerTemp);

/*
Description：	Get Intellect Tempature Range
Input：
handle：	Handle
Return：
>=0:     Success
*/
int __stdcall DM_GetIntellectTempRange(int handle);

/*
Description：	set shield Region
Input：
handle：	Handle
nID:		Area ID
nStatus:	0: disable 1: enable
nStartX,nStartY:	coordinate Leftup 
nEndX,nEndY:		coordinate RightDown 
Return：
>=0:     Success
*/
int __stdcall DM_SetShieldRegion(int handle, int nID, int nStatus, int nStartX, int nStartY, int nEndX, int nEndY);

/*
Description：	Get Shield Region
Input：
handle：	Handle
nID:		Area ID
Return：
>=0:     Success
nStatus:	0: disable 1: enable
nStartX,nStartY:	coordinate Leftup 
nEndX,nEndY:		coordinate RightDown 
*/
int __stdcall DM_GetShieldRegion(int handle,int nID, int *nStatus, int *nStartX, int *nStartY, int *nEndX, int *nEndY);

/*
Description：	Get All Shield Region
Input：
handle：	Handle
nCount:		Area Count
Return：
>=0:     Success
pShieldRegion:	All shield region info
*/
int __stdcall DM_GetShieldRegionAll(int handle, int *nCount, tagShieldRegion pShieldRegion[]);

/*
Description：	set pallette range
Input：
handle：		Handle
nHighTemp:		the upper tempature * 100
nLowTemp:		the lower tempature * 100
Return：
>=0:     Success
*/
int __stdcall DM_SetPalletteTempRange(int handle, int HighTemp, int nLowerTemp);

/*
Description：	get pallette range
Input：
handle：	Handle
Return：
>=0:     Success
*/
int __stdcall DM_GetPalletteTempRange(int handle);

/*
Description：	enable auto ambient tempature 
Input：
handle：	Handle
nStatus:	0: disable 1: enable
Return：
>=0:     Success
*/
int __stdcall DM_SetAutoAmbientTemp(int handle,int nStatus);

/*
Description：	enable auto ambient tempature 
Input：
handle：	Handle
nStatus:	0: disable 1: enable
Return：
>=0:     Success
*/
int __stdcall DM_GetAutoAmbientTempStatus(int handle);

//Test funciton,dont use 
int __stdcall DM_Test(int handle, unsigned char *Test,int nLen);

/**
@breif Open Active Test
@param handle : Handle
@retval >0 success
*/
int __stdcall DM_OpenActiveTest(int handle);

/**
@breif Close Active Test
@param handle : Handle
@retval >0 success
*/
int __stdcall DM_CloseActiveTest(int handle);

/**
@breif Get Lens ID
@param handle : Handle
@return return lens id
@retval >0 Lens ID
*/
int __stdcall DM_GetLensID(int handle);

/**
@breif Set Lens ID
@param handle : Handle
@param ParamValue : LENS ID
@return return lens id
@retval >0 Lens ID
*/
int __stdcall DM_SetLensID(int handle,int ParamValue);

int __stdcall DM_GetTempLimit( int handle );

int __stdcall DM_SetTempLimit( int handle, int HighTemp );

int __stdcall DM_SetEdgeradiiEnable( int handle, bool Enable );
bool __stdcall DM_GetEdgeradiiEnable( int handle );

int __stdcall DM_SetEdgeradii( int handle, int Edgeradii );

int __stdcall DM_GetEdgeradii( int handle );

/*
 函数名称:	DM_CheckOnline
*函数说明:	检测主机是否在线
*输入参数:  IPAddr：主机IP
			Port：主机端口 
*返回值:正数表示在线, 负数表示不在线			
*/
int  __stdcall DM_CheckOnline( char *IPAddr, int Port);

/*
 函数名称:	DM_ClearAllJpeg
*函数说明:	清除主机上的所有JPEG图片
*输入参数:  handle
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_ClearAllJpeg(int handle);

/*
 函数名称:	DM_BrightAdjust
*函数说明:	亮度调节
*输入参数:  handle
*           step,步长, +1, 表示增加1,  -1, 表示减小1
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_BrightAdjust(int handle, int step);

/*
 函数名称:	DM_ContrastAdjust
*函数说明:	增益调节
*输入参数:  handle
*           step,步长, +1, 表示增加1,  -1, 表示减小1
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_ContrastAdjust(int handle, int step);

/*
 函数名称:	DM_RemoteJpeg
*函数说明:	远程拍照
*输入参数:  handle
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_RemoteJpeg(int handle);

/*
函数名称:	DM_Zoom
*函数说明:	电子放大
*输入参数:  handle
*			value, 放大倍数。0-1倍； 1-2倍
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_Zoom(int handle, int value);


/*
函数名称:	DM_SetPalority
*函数说明:	设置热图像模式
*输入参数:  handle
*			value, 1-白热； 0-黑热
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_SetPalority(int handle, int value);

/*
函数名称:	DM_GetCapacity
*函数说明:	获取S730机型的容量
*输入参数:  handle
*返回值:容量值, 若返回负数表示失败		
*/
int  __stdcall DM_GetCapacity(int handle);

/*
函数名称:	DM_GetBright
*函数说明:	获取S730机型的亮度值
*输入参数:  handle
*返回值:亮度值, 范围在-2048-2048, 返回其它值为失败		
*/
int  __stdcall DM_GetBright(int handle);

/*
函数名称:	DM_GetContrast
*函数说明:	获取S730机型的对比度
*输入参数:  handle
*返回值:对比度, 范围在0-255, 返回其它值为失败		
*/
int  __stdcall DM_GetContrast(int handle);

/*
函数名称:	DM_GetZoomStatus
*函数说明:	获取图像放大倍数
*输入参数:  handle
*返回值:放大倍数。0-1倍； 1-2倍	
*/
int  __stdcall DM_GetZoomStatus(int handle);

/*
函数名称:	DM_GetPalority
*函数说明:	获取热图像模式
*输入参数:  handle
*返回值:1-白热； 0-黑热		
*/
int  __stdcall DM_GetPalority(int handle);


/*
函数名称:	DM_GetGFZ
*函数说明:	获取图像冻结状态
*输入参数:  handle
*返回值:0-冻结； 1-非冻结
*注意：S730和DM60-S机型适用	
*/
int  __stdcall DM_GetGFZ(int handle);

/*
 函数名称:	DM_SetEIS
*函数说明:	打开/关闭集成电子稳像功能
*输入参数:  handle
*           cmd,  1-打开   0-关闭
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_SetEIS(int handle, int cmd);

/*
 函数名称:	DM_GetDistance
*函数说明:  激光测距
*输入参数:  handle		句柄			
*输出参数:  status,仪器状态 0-准备好  1-正常测距  2-开机自检
*			distance, 距离, status=1时有效
*返回值:正数表示成功, 负数表示失败	
*/
int  __stdcall DM_GetDistance(int handle, int &status, tagDistanceInfo *distance);


/************************************************************************/
//   回调函数定义                                                                  
/************************************************************************/

//解码后的视频帧回调函数定义, dwFrameRate 表示帧率(1---25)
typedef void(CALLBACK *fYUVDataCallBack) (int handle, unsigned long dwFrameRate, unsigned char *pBuffer, 
										  unsigned long nWidth, unsigned long nHeight, int err, unsigned long dwUser);

/* 	功能说明:设置用于YUV视频回调的回调函数
*	输入参数: lRealHandle, 监视句柄, 即WM_DM_PLAYER 消息的 wParam 返回的句柄
yuvDataCallBack, 回调函数, 用于回调YUV数据
dwUser, 用户自定义数据
*	输出参数: 无
*	函数返回: TRUE：成功； FALSE：失败
*	说明:
*/
bool  __stdcall  DM_SetYUVDataCallBack(int lRealHandle, fYUVDataCallBack yuvDataCallBack,  unsigned long dwUser);

/*
 函数名称:	DM_AutoCheck
*函数说明:  激光测距自检
*输入参数:  handle		句柄			
*输出参数:  无
*返回值:正数表示成功, 负数表示失败	
*/
int  __stdcall DM_AutoCheck(int handle);


/*
 函数名称:	DM_VideoStable
*函数说明:  打开/关闭电子稳像处理
*输入参数:  lRealHandle, 监视句柄, 即WM_DM_PLAYER 消息的 wParam 返回的句柄
*			cmd, 1-打开电子稳像 0-关闭电子稳像			
*输出参数:  无
*返回值:正数表示成功, 负数表示失败	
*/
int  __stdcall DM_VideoStable(int lRealHandle, int cmd);

/*
 函数名称:	DM_SetGFZStatus
*函数说明:  打开/关闭图像冻结
*输入参数:  lRealHandle, 监视句柄, 即WM_DM_PLAYER 消息的 wParam 返回的句柄
*			cmd, 1-图像冻结 0-解除冻结			
*输出参数:  无
*返回值:正数表示成功, 负数表示失败	
*/
int  __stdcall DM_SetGFZStatus(int lRealHandle, int cmd);

BOOL __stdcall DM_SetTemperatureScope(int handle,  int dwValue1,int dwValue2);
BOOL __stdcall DM_GetTemperatureScope(int handle, int* dwValue1, int* dwValue2);

/*
 函数名称:	DM_GetIPAddress
*函数说明:  获取IP地址
*输入参数: handle：	句柄			
*输出参数:  IPAddress, IP地址
*返回值:TRUE表示成功, FALSE表示失败	
*/
int __stdcall DM_GetIPAddress(int handle,char *IPAddress);

/*
 函数名称:	DM_GetNetmask
*函数说明:  获取子网掩码
*输入参数: handle：	句柄			
*输出参数:  Netmask, 子网掩码
*返回值:TRUE表示成功, FALSE表示失败	
*/
int __stdcall DM_GetNetmask(int handle,char *Netmask);

/*
 函数名称:	DM_GetGateway
*函数说明:  获取网关
*输入参数: handle：	句柄			
*输出参数:  Gateway, 网关
*返回值:TRUE表示成功, FALSE表示失败	
*/
int __stdcall DM_GetGateway(int handle,char *Gateway);


void __stdcall DM_SetAllMessCallBack(void (CALLBACK *fMessCallBack)(int msg, char *pBuf, int dwBufLen, DWORD dwUser),  DWORD dwUser = 0);

/*
 函数名称:	DM_GetDM6xResolution
*函数说明:  获取DM6x机型的主机分辨率
*输入参数:  handle		句柄			
*输出参数:  resolution,主机分辨率
*返回值:>=0表示成功, 负数表示失败	
*/
int  __stdcall DM_GetDM6xResolution(int handle, tagResolutionInfo *resolution);

/*
 函数名称:	DM_ControlServoMotor
*函数说明:	控制舵机
*输入参数:  handle：		句柄
			int value: 		舵机目标状态（0：表示拉起, 1：表示挡下）
*返回值:正数表示成功, 负数表示失败		
*/
int  __stdcall DM_ControlServoMotor(int handle, int value);

//以下3个接口尚未实现
int __stdcall DM_OpenIfrVideo(HWND hwnd,  char* ip, unsigned short port, int( __stdcall  *pFun)(char *, int));
int __stdcall DM_SaveIfr( char *strFileName );
int __stdcall DM_StopIfr();

/*
 函数名称:	DM_ShowMenu
*函数说明:	显示调试菜单
			仅对 DM6x 二期或以后的有效
*输入参数:  handle：		句柄
*返回值:	>0 成功, <0失败		
*/
int __stdcall DM_ShowMenu(int handle);

/*
 函数名称:	DM_GetDeviceVer
*函数说明:	获取DM60大版本号
*输入参数:  handle		句柄
*返回值:    当前DM60大版本号		
*/
int  __stdcall DM_GetDeviceVer(int handle);

/*
Description：	Ajust tempature 
Input：
handle：	Handle
nStatus:	0: Manual 1: Auto
nTemp:		Tempature * 100
Return：
>=0:     Success
*/
int __stdcall DM_SetAjustTemp(int handle, int nStatus, int nTemp);

/*
Description：	Ajust Position 
Input：
handle：	Handle
nStatus:	0: DisEnable 1: Enable
IPCPos1X, IPCPos1Y:		CCD coordinate LeftUp
IPCPos2X, IPCPos2Y:		CCD coordinate RightDown
DMPos1X, DMPos1Y:		IR coordinate LeftUp
DMPos2X, DMPos2Y:		IR coordinate RightDown
Return：
>=0:     Success
*/
int __stdcall DM_SetAjustPosition(int handle, int nStatus, int IPCResolution, 
						int IPCPos1X, int IPCPos1Y, int IPCPos2X, int IPCPos2Y,
						int DMPos1X, int DMPos1Y, int DMPos2X, int DMPos2Y);

int __stdcall DM_SetAlarmSenseRadius(int handle, int nRadius);

int __stdcall DM_SetAlarmRadius(int handle, int nRadius);

int __stdcall DM_SetAlarmTime(int handle, int nTime);

int __stdcall DM_SetTimeOSD(int handle, int nStatus, int StartX, int StartY, int Size = 1);

int __stdcall DM_GetAjustTemp(int handle, int *nStatus, int *nTemp);

int __stdcall DM_GetAjustPosition(int handle, int *nStatus, int *IPCResolution, 
						int *IPCPos1X, int *IPCPos1Y, int *IPCPos2X, int *IPCPos2Y,
						int *DMPos1X, int *DMPos1Y, int *DMPos2X, int *DMPos2Y);
/*
return:
	>=0 时间
	<0 失败
*/
int __stdcall DM_GetAlarmTime(int handle);
int __stdcall DM_GetTimeOSD(int handle, int *nStatus, int *StartX, int *StartY, int *Size);

int __stdcall DM_GetPointTemp(int handle, int X, int Y, int *nTemp);

int __stdcall DM_RemoteUpdate(int handle, char* path); //Net Software

int __stdcall DM_UpdateConfig(int handle, char* path); //Net Software Config
													   /*
Type:
	#define UPDATEFILE_TYPE_DM60_MID		0
	#define UPDATEFILE_TYPE_DM60_FIREWARE	1
	#define UPDATEFILE_TYPE_DM60_DATA		2
*/
int __stdcall DM_UpdateDM60File(int handle, char* path, int Type); //Main Software

int __stdcall DM_DownloadMTC(int handle, char* path); //Download MTC

//hwnd: WM_DM_PLAYER 消息的 wParam 返回的句柄
int  __stdcall DM_OpenMonitor_Jpeg(HWND hwnd, char* ip, unsigned short port, int channel= 0); //JPEG Mode

int  __stdcall DM_CloseMonitor_Jpeg(int handle); //JPEG Mode

typedef void(CALLBACK *fTempAlarmCallBack) (unsigned char *pBuffer, unsigned long dwBufSize);//long lHandle, 

long __stdcall DM_TempAlarm(LONG handle, fTempAlarmCallBack TempAlarmCallBack);

//接收报警图片
int __stdcall  DM_ReceiveAlarmJpeg(int handle, char *Path);

int  __stdcall DM_GetUpgradePos(int handle);

bool __stdcall  DM_GetMeasureString(int handle, int type, int index, char* DMMeasureBuf);

int __stdcall  DM_SetTCPPort(int handle, int port);
int __stdcall  DM_SetUDPPort(int handle, int port);
int __stdcall  DM_SetListenPort(int handle, int port);
//--------------------------------------------------------
#endif