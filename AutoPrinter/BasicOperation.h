#pragma once 


#define DX_DRAWLINE			1//画线函数
#define DX_GYROSCOPE		2//陀螺仪传输三角形函数
#define DX_XBOXCTRL			3//XBOX传输操作信息
#define DX_ERAZEANGLE		4//激光雷达中的一段角度绘制清零
#define DX_GPSOUTPUT		5//激光雷达中的一段角度绘制清零
#define OT_DRIVECAR			6//在3d类中输出车体移动控制信号writer-〉byte nLen
#define CTRL_MOTION			7//位移台控制
#define CTRL_FREQ_T			8//超声波开始测距
#define CTRL_FREQ_R			9//接收到超声波回复
#define CTRL_FREQ_R2		10//接收到超声波回复
#define CTRL_FREQ_R3		11//接收到超声波回复
#define CTRL_GETGPSPOS_DX	12//dx通过主类调用gps
#define CTRL_RECEIVE		13//接收上位机串口信息
#define TESTANGLE_FORRUN	14//测试车体对应速度和旋转时间所转动过角度
#define CTRL_RECEIVEBACK	15//受控端返回主机信息
#define OT_DRIVECAR2		16//在3d类中输出车体移动控制信号writer-〉byte nLen
#define OT_DRIVECAR3		17//在3d类中输出车体移动控制信号writer-〉byte nLen
#define CTRL_TCP_IP_T		18//通讯回调//客户端发送
#define CTRL_TCP_IP_R		19//通讯回调
#define CRece_From_Client	20//从客户端读取信息
#define CTRL_TCP_IP_T_Ser	21//通讯回调
#define CRece_From_Server	22//通讯回调
#define CROOM_TEST_INFO		23//屋内添加情况
#define CROOM_TEST_BACK		24//在图中点击,加回去,继承当前的所有位置信息




#define DEBUG_STATE				 1 //自行调试状态（输入激光雷达、陀螺仪、手柄信息、输出小车运行指令）
#define PC_STATE				 2// 上位机简易指令单元，手柄信号， 输出为小车运行指令
#define CAR_STATE				 3//小车运行模式，输入为上位机控制信号，输出为小车运行指令
#define NODX_STATE				 4//小车运行模式，输入为上位机控制信号，输出为小车运行指令无dx模式
#define PIC_STATE				 5//拍照模式,将当前激光雷达的内容进行拍照
#define PIC_READ_STATE			 6//拍照模式,将当前激光雷达拍照内容进行显示
#define PIC_STATE_CTRLMODE		 7//拍照模式,控制小车进行拍照,pc端
#define PIC_STATE_CTRLMODE_Car	 8//拍照模式,控制小车进行拍照,小车端
#define PIC_STATE_COMMUNI		 9//通讯模式
#define PIC_STATE_SUBCOMMUNI	 10//通讯模式小车
#define GPS_CTRL_MODE_PC		 11//路径控制模式电脑版
#define GPS_CTRL_MODE_CAR		 12//路径控制模式小车版
#define MOTION_XY				 13//位移台
#define BEZIERMODE				 14//贝塞尔曲线测试
#define HONEY_ROBOT				 15//小宝机器人
#define FREQUENCY				 16//速度谱线frequency Spectrogram
#define EARS_TWO				 17//双耳效应测试
#define FREQUENCY2				 18//空中画笔
#define HONEY_CLOSE_LOOP		 19//小宝闭环控制
#define TOTALLY_CTRL			 20//整机控制(含有两路测距,按下键盘1234可以对两路进行测距)
#define CHECK_COMMUNICATE		 21//测试协议功能(车体移动\霍尔返回\超声波距离测定)
#define CALCULATE_POS			 22//一键绘图(两发两收)绘制机器人相对于目标桌面的位置
#define TWOSIDE_ONEORDER		 23//双路发送一声号令(新版定位)
#define DARLING_CTRL_GPS		 24//控制小宝机器人并且进行gps定位操作
#define DARLING_GPS_PC			 25//控制小宝机器人按照gps导航进行运动
#define DARLING_GPS_CAR			 26//机器人进行自主的方向矫正(控制后轮运动)
#define DARLING_TEST_ANGLE_PC	 27//测定转角
#define DARLING_TEST_ANGLE_CAR	 28//测定转角车体版
#define DARLING_GPSGO_ANGLE_PC	 29//标准gps导航
#define DARLING_GPSGO_ANGLE_CAR	 30//标准gps导航
#define NewUltrasonic_8Out		 31//8路输出信号
#define DoubleRoll_Running_CAR	 32//两轮式转角控制
#define GET_ONE_ORDER			 33//下位机接收超声测距信息pad读取当前测距信息和TWOSIDE_ONEORDER进行匹配
#define Ctrl_MotorDish			 34//上菜电机
#define TestTCPIP_Opera			 35//网络通讯
#define Leading_PC				 36//导航新版
#define Leading_Pad				 37//导航下位机
#define Calculate_RollTime		 38//计算转角时间//两轮模式
#define Leading_Pad2			 39//导航下位机新版二合一
#define SpeakLoud				 40//大声讲话
#define AUTO_Dish				 41//自动化送菜循环
#define Mapping_Details			 42//绘制谱线自动转角
#define DrawSurroundings		 43//绘制周围场景
#define GoAgain					 44//重复之前运动轨迹
#define CompareWith				 45//超声波两次数据采集对比
#define SendTCP_SER				 46//tcp  
#define SendTCP_CLI				 47//tcp  
#define Compare5Line			 48// 五组数据比对
#define RunDeltaStep			 49//移动梯度获取(在一个梯度诞生时停止运动)这个过程是自动的
#define SetTestPlatform			 50//屋内物品摆放设置
#define OutputOrderAndGetDis	 51//输出命令并且获取距离
#define OutputOrderAndGetDiscar	 52//输出命令并且获取距离
#define ORDER_TO_GO_WAY			 53//设定按照路线行驶包括设置超声波接收通道对距离信息进行交互
#define ORDER_TO_GIVEBACK		 54//设定按照路线行驶包括设置超声波接收通道对距离信息进行交互
#define TCP_CLI_RUN				 55//当前通讯控制两用  
#define Gyroscope_Give			 56//获取陀螺仪信息  
#define MicroWave				 57//电磁炉波形选择功率  
#define SendTest_Ul				 58//测试当前探头输出信号,并接受回复  
#define go_surroundings			 59//行驶到探头位置(多车体)
#define HanNuo					 60
#define SendGoUltra				 61//新版功能定位
#define SendPathGo				 62//向下位机发送运动步骤//通讯过程监控当前超声探头距离
#define Communicate_SetUl		 63//向下位机发送运动步骤
#define Communicate_GetUl		 64//向下位机发送运动步骤
#define Communicate_GetUl2		 65//向下位机发送运动步骤
#define Robot_byMrWangAndMrHuang 66//机器人寻路
#define RobSend					 67//机器人寻路
#define RobotHeadIcon			 68//机器人寻路
#define GoTheMostMessagebox		 69//显示机器人大概外框和行驶控制内容
#define TcpAll_demo				 70//显示机器人大概外框和行驶控制内容
#define SendGoStraight			 71//按下o键车体就往前走
#define GoAndout				 72//输出信号并翻译其中信号
#define Tcp_Send_Map			 73//服务器
#define Tcp_Get_Map				 74//客户端
#define OutputInfo				 75//客户端
#define CGoStraight				 76//客户端
#define ScanOutLine				 77//scan outline of car


 
#define MSG_CTRL_BEGIN   	0
#define MSG_CTRL_ID   		1
#define MSG_CTRL_TYPE   	2
#define MSG_CTRL_BUFF0   	3
#define MSG_CTRL_BUFF1   	4
#define MSG_CTRL_BUFF2   	5
#define MSG_CTRL_BUFF3   	6
#define MSG_CTRL_BUFF4   	7
#define MSG_CTRL_BUFF5   	8
#define MSG_CTRL_SUM   		9
#define MSG_CTRL_END   		10

#define MAX_SPEED 22

#define call_GYROSCOPE_Ang 1
#define call_GYROSCOPE_Mag 2



typedef int (CALLBACK* PLCIDECALLBACK)(int *pInfo);//定义类型PLCIDECALLBACK



// CBasicOperation
#define OUTPUT_INFO					0
#define ON_PROP_VIEW				1
#define ON_PROP_CHANGE				2
#define ON_PROP_OUTPUT				3
#define ON_PROP_BACKSEND			4
#define ON_SAVE_FILE				5
#define ON_OPEN_FILE				6
#define ON_POP_PROP_DLG				7
#define ON_Add_Item_Info			8 
#define ON_SHOW_ITEMDLG				9 
#define ON_SEL_DRAWVIEW				10 
#define ON_NEW_PROJ					11
#define ON_INSERT_BLOCK				12
#define ON_NEW_ITEM_WITHMAT			13
#define ON_VIEW_ALL_ITEMS			14
#define ON_BACK_ALL_ITEMS			15
#define ON_ADD_POLYGON				16
#define ON_ADD_THICKNESS			17
#define ON_EDIT_POLYGON				18
#define ON_EDIT_THICKNESS			19
#define ON_INSERT_LIST				20
#define ON_COMPILE_SAVE				21
#define ON_COMPILE_READ				22


#define ITEM_LINE						1
#define ITEM_NORMAL						2
#define ITEM_ROT_DIR					3
#define ITEM_ROT_MAT					4
#define ITEM_POINT						5
#define ITEM_PLANE						6
#define ITEM_RANGE1						7
#define ITEM_RANGE2						8

#define PROP_TYPE_STANDARD							5	
#define PROP_TYPE_LINE								6	
#define PROP_TYPE_DRAW_PLATFORM						7	
#define PROP_ITEM_BASIC_SURFACE_FRONT				8
#define PROP_ITEM_BASIC_SURFACE_SIDE				9
#define PROP_ITEM_BASIC_SURFACE_TOP					10
#define PROP_POLYGON								11
#define PROP_THICKNESS_POLYGON						12
#define PROP_COMPILE_POINT							13


static const int ITEM_LEN[8] = {24, 12, 12, 64, 12, 36, 4, 4};


struct TranslateInformation{
	UINT nType;
	UINT nLen;
	BYTE* bt;
};

struct SaveTreeViewBuffer{ 
	int nPriority;
	int nProp;
	WCHAR wcName[255];
	WCHAR wcDescription[255];
	int nIcon, nSelIcon;
	BYTE* btBuffer;
};

struct ITEM_LINE_STRUCT{
	UINT nType;// = ITEM_LINE
	float fFromX, fFromY, fFromZ;
	float fToX, fToY, fToZ;
};

struct ITEM_MATRIX_STRUCT{
	UINT nType;// = ITEM_LINE
	float _11, _12, _13, _14, _21, _22, _23, _24, _31, _32, _33, _34, _41, _42, _43, _44;
};

struct ITEM_POINT_STRUCT{
	UINT nType;// = ITEM_POINT
	float x, y, z;
};

struct ITEM_ROT_DIR_STRUCT{
	UINT nType;// = ITEM_POINT
	float x, y, z;
};

struct ITEM_PLANE_STRUCT{
	UINT nType;// = ITEM_PLANE
	float x1, y1, z1, x2, y2, z2, x3, y3, z3;
};
 
struct ITEM_RANGE_STRUCT{
	UINT nType;// = ITEM_PLANE
	float range;
}; 

struct ITEM_POINTER
{
	int* MainView;
	int nThread;
	int* MainProj, *Gyros, * Radar;
	int nFlagGyros, nFlagRadar;
}; 

struct FPoint{float x, y;};



class CBasicOperation  
{ 

public:
	CBasicOperation();
	virtual ~CBasicOperation();
	 
public:

	static void SaveFile_InPath(WCHAR* csPath, BYTE* bt, UINT nLen);//
	static void ReadFile_InPath(WCHAR* csPath, BYTE* bt, UINT &nLen);//
	static void c2w(wchar_t *pwstr,size_t &len,const char *str);//change char into wchar
	static int w2c(char *pcstr,const wchar_t *pwstr, size_t& len);//change wide char into char
	static CString GetComState(WCHAR* csPath);//get path state from file
	static int fArrayStrFind(WCHAR*wcBf,int nLen1,  WCHAR *wcCtr, int nLen2);//seek buffer in target    
	static BOOL CreateFolderPath(WCHAR* strPath);//create folder
	static BOOL FolderPathExist(WCHAR* strPath);//find folder
	static UINT TransformToHex(WCHAR* csInput, BYTE* Result, UINT& nLen);//succeed return 1 else return 0
	static int TransformSingleToHex(WCHAR wc, BYTE* btResult);//get result from string 
	static int GetIntFromEdit(CEdit* edit);
	static void SetIntFromEdit(CEdit* edit, int info);
};





