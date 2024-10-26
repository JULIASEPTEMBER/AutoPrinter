#pragma once 


#define DX_DRAWLINE			1//���ߺ���
#define DX_GYROSCOPE		2//�����Ǵ��������κ���
#define DX_XBOXCTRL			3//XBOX���������Ϣ
#define DX_ERAZEANGLE		4//�����״��е�һ�νǶȻ�������
#define DX_GPSOUTPUT		5//�����״��е�һ�νǶȻ�������
#define OT_DRIVECAR			6//��3d������������ƶ������ź�writer-��byte nLen
#define CTRL_MOTION			7//λ��̨����
#define CTRL_FREQ_T			8//��������ʼ���
#define CTRL_FREQ_R			9//���յ��������ظ�
#define CTRL_FREQ_R2		10//���յ��������ظ�
#define CTRL_FREQ_R3		11//���յ��������ظ�
#define CTRL_GETGPSPOS_DX	12//dxͨ���������gps
#define CTRL_RECEIVE		13//������λ��������Ϣ
#define TESTANGLE_FORRUN	14//���Գ����Ӧ�ٶȺ���תʱ����ת�����Ƕ�
#define CTRL_RECEIVEBACK	15//�ܿض˷���������Ϣ
#define OT_DRIVECAR2		16//��3d������������ƶ������ź�writer-��byte nLen
#define OT_DRIVECAR3		17//��3d������������ƶ������ź�writer-��byte nLen
#define CTRL_TCP_IP_T		18//ͨѶ�ص�//�ͻ��˷���
#define CTRL_TCP_IP_R		19//ͨѶ�ص�
#define CRece_From_Client	20//�ӿͻ��˶�ȡ��Ϣ
#define CTRL_TCP_IP_T_Ser	21//ͨѶ�ص�
#define CRece_From_Server	22//ͨѶ�ص�
#define CROOM_TEST_INFO		23//����������
#define CROOM_TEST_BACK		24//��ͼ�е��,�ӻ�ȥ,�̳е�ǰ������λ����Ϣ




#define DEBUG_STATE				 1 //���е���״̬�����뼤���״�����ǡ��ֱ���Ϣ�����С������ָ�
#define PC_STATE				 2// ��λ������ָ�Ԫ���ֱ��źţ� ���ΪС������ָ��
#define CAR_STATE				 3//С������ģʽ������Ϊ��λ�������źţ����ΪС������ָ��
#define NODX_STATE				 4//С������ģʽ������Ϊ��λ�������źţ����ΪС������ָ����dxģʽ
#define PIC_STATE				 5//����ģʽ,����ǰ�����״�����ݽ�������
#define PIC_READ_STATE			 6//����ģʽ,����ǰ�����״��������ݽ�����ʾ
#define PIC_STATE_CTRLMODE		 7//����ģʽ,����С����������,pc��
#define PIC_STATE_CTRLMODE_Car	 8//����ģʽ,����С����������,С����
#define PIC_STATE_COMMUNI		 9//ͨѶģʽ
#define PIC_STATE_SUBCOMMUNI	 10//ͨѶģʽС��
#define GPS_CTRL_MODE_PC		 11//·������ģʽ���԰�
#define GPS_CTRL_MODE_CAR		 12//·������ģʽС����
#define MOTION_XY				 13//λ��̨
#define BEZIERMODE				 14//���������߲���
#define HONEY_ROBOT				 15//С��������
#define FREQUENCY				 16//�ٶ�����frequency Spectrogram
#define EARS_TWO				 17//˫��ЧӦ����
#define FREQUENCY2				 18//���л���
#define HONEY_CLOSE_LOOP		 19//С���ջ�����
#define TOTALLY_CTRL			 20//��������(������·���,���¼���1234���Զ���·���в��)
#define CHECK_COMMUNICATE		 21//����Э�鹦��(�����ƶ�\��������\����������ⶨ)
#define CALCULATE_POS			 22//һ����ͼ(��������)���ƻ����������Ŀ�������λ��
#define TWOSIDE_ONEORDER		 23//˫·����һ������(�°涨λ)
#define DARLING_CTRL_GPS		 24//����С�������˲��ҽ���gps��λ����
#define DARLING_GPS_PC			 25//����С�������˰���gps���������˶�
#define DARLING_GPS_CAR			 26//�����˽��������ķ������(���ƺ����˶�)
#define DARLING_TEST_ANGLE_PC	 27//�ⶨת��
#define DARLING_TEST_ANGLE_CAR	 28//�ⶨת�ǳ����
#define DARLING_GPSGO_ANGLE_PC	 29//��׼gps����
#define DARLING_GPSGO_ANGLE_CAR	 30//��׼gps����
#define NewUltrasonic_8Out		 31//8·����ź�
#define DoubleRoll_Running_CAR	 32//����ʽת�ǿ���
#define GET_ONE_ORDER			 33//��λ�����ճ��������Ϣpad��ȡ��ǰ�����Ϣ��TWOSIDE_ONEORDER����ƥ��
#define Ctrl_MotorDish			 34//�ϲ˵��
#define TestTCPIP_Opera			 35//����ͨѶ
#define Leading_PC				 36//�����°�
#define Leading_Pad				 37//������λ��
#define Calculate_RollTime		 38//����ת��ʱ��//����ģʽ
#define Leading_Pad2			 39//������λ���°����һ
#define SpeakLoud				 40//��������
#define AUTO_Dish				 41//�Զ����Ͳ�ѭ��
#define Mapping_Details			 42//���������Զ�ת��
#define DrawSurroundings		 43//������Χ����
#define GoAgain					 44//�ظ�֮ǰ�˶��켣
#define CompareWith				 45//�������������ݲɼ��Ա�
#define SendTCP_SER				 46//tcp  
#define SendTCP_CLI				 47//tcp  
#define Compare5Line			 48// �������ݱȶ�
#define RunDeltaStep			 49//�ƶ��ݶȻ�ȡ(��һ���ݶȵ���ʱֹͣ�˶�)����������Զ���
#define SetTestPlatform			 50//������Ʒ�ڷ�����
#define OutputOrderAndGetDis	 51//�������һ�ȡ����
#define OutputOrderAndGetDiscar	 52//�������һ�ȡ����
#define ORDER_TO_GO_WAY			 53//�趨����·����ʻ�������ó���������ͨ���Ծ�����Ϣ���н���
#define ORDER_TO_GIVEBACK		 54//�趨����·����ʻ�������ó���������ͨ���Ծ�����Ϣ���н���
#define TCP_CLI_RUN				 55//��ǰͨѶ��������  
#define Gyroscope_Give			 56//��ȡ��������Ϣ  
#define MicroWave				 57//���¯����ѡ����  
#define SendTest_Ul				 58//���Ե�ǰ̽ͷ����ź�,�����ܻظ�  
#define go_surroundings			 59//��ʻ��̽ͷλ��(�೵��)
#define HanNuo					 60
#define SendGoUltra				 61//�°湦�ܶ�λ
#define SendPathGo				 62//����λ�������˶�����//ͨѶ���̼�ص�ǰ����̽ͷ����
#define Communicate_SetUl		 63//����λ�������˶�����
#define Communicate_GetUl		 64//����λ�������˶�����
#define Communicate_GetUl2		 65//����λ�������˶�����
#define Robot_byMrWangAndMrHuang 66//������Ѱ·
#define RobSend					 67//������Ѱ·
#define RobotHeadIcon			 68//������Ѱ·
#define GoTheMostMessagebox		 69//��ʾ�����˴��������ʻ��������
#define TcpAll_demo				 70//��ʾ�����˴��������ʻ��������
#define SendGoStraight			 71//����o���������ǰ��
#define GoAndout				 72//����źŲ����������ź�
#define Tcp_Send_Map			 73//������
#define Tcp_Get_Map				 74//�ͻ���
#define OutputInfo				 75//�ͻ���
#define CGoStraight				 76//�ͻ���
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



typedef int (CALLBACK* PLCIDECALLBACK)(int *pInfo);//��������PLCIDECALLBACK



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





