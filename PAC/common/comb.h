//����� ��������.
//  �������� �������� ������, ������� ������������ ��� �������� ��������� 
//      �������� � ������ � �� �������� (����������), ��������� ��������� 
//      � �������� ��������� ��������.
//
//�������� DEFINE.
//  PLC   - ���������� ���������� ��� �����������.
//  WIN32 - ���������� ���������� ��� PC.

#ifndef _TCOMB_H_
#define _TCOMB_H_

#include "sys.h"
#include "sys_linux.h"

#include "PAC_dev.h"
#include "param_ex.h"
#include "tech_def.h"
//-------------------------------------------------------------------------
//--���������� �����.
struct comb_point
    {
    char x,y;
    int operator == ( comb_point p ) const 
        { 
        return ( x == p.x && y == p.y ); 
        }

    comb_point( char x = 0, char y = 0 ): x( x ), y( y )
        {
        }
    };
//-------------------------------------------------------------------------
//--������������� ��������.
#define MAX_PATH_COUNT 20   //������������ ����� �������� ���������

struct comb_path
    {
    enum PATH_TYPE
        {
        PT_STRAIGHT = 1,    //������ ��������.
        PT_G_TYPE,          //�-��������.
        };
    u_char     path_type;   //��� ��������.

    comb_point in;          //����� �����.
    comb_point turn;        //����� ��������.
    comb_point out;         //����� ������.
    comb_point in_;         //�����, ��������������� �����.
    comb_point out_;        //�����, ��������������� ������.

    tech_object *object;        //��������� �� ������.
    int         object_mode_n;  //����� ������ �������.
    u_int_4     start_time;     //����� ��������� ��������.
    u_int_4     finish_time;    //����� ���������� ��������.

    comb_path():in( ( char ) -1, ( char ) -1 ),out( ( char ) -1, ( char ) -1 )
        {
        }
    };
//-------------------------------------------------------------------------
//--������� �������.
struct comb_element
    {
    char type;			//��� ��������
    unsigned int id;    //������������� ����������
        
    // ������ �������� ����������. 
    enum CE_STATUS
        {        
        CES_NOT_USED,
        CES_USED,
        CES_MONOPOLY_USED,
        };    
    char status;

    unsigned int is_opened; // ���� �������� ( 0 - �������� � ������ ���������; 1 - ������� )
    i_DO_device *valve;			//��������� �� ������
    };
//-------------------------------------------------------------------------
//--��������.
class comb
    {
    public:
        //-��� �������� ������ � ������.
        u_int_4   cmd;                //�������.
        complex_device  *com_dev;
        //-��� �������� ������ � ������.-!>

        enum COMB_PARAMS
            {
            CP_ERRORS,                  //������.
            CP_CONFLICTED_OBJECT1_TYPE, //��� �������������� ������� 1.
            CP_CONFLICTED_OBJECT1_N,    //����� �������������� ������� 1.
            CP_CONFLICTED_OBJECT2_TYPE, //��� �������������� ������� 2.
            CP_CONFLICTED_OBJECT2_N,    //����� �������������� ������� 2.
            CP_SWICTH_TIME,             //����� ������������ �������, ����.
            };

        comb_path  *path_list;      // ������� �������� ���������.
        comb_path	current_path;   // ������� ����������� �������.

        char rows_cnt, columns_cnt; // ������� �������: ����� �����/��������.
        char pathCount;             // ���������� ���������� ��� �������� ���������.

        run_time_params_u_int_4 rt_par_uint;///< ������� ���������, ��� u_int.

        comb_element** mMatrix;		// [rows_cnt][columns_cnt]. ������� ��������� ��������.

        //	��������:
        //		�����������. ������������� ��� �������� path_list � current_path � -1, ��������
        //       ������ ��� �������� ������ �������.
        //	���������:
        //		rows - ����� ����� ��������
        //		cols - ����� �������� ��������
        //
        comb( char rows, char cols );	

        //	��������:
        //		��������� ������������� ���������� ������� � �.�.
        //		    
        void init();

        //	��������:
        //		�������� � �������� ���������� ��������.
        //	������������ ��������:
        //		COMB_ERROR.
        //	���������:
        //		[x1, y1] - ���������� �������� �������� ��������
        //		[x2, y2] - ���������� ��������� �������� ��������,
        //       [�������, ������]
        //      object_type   - ��� �������, �������� ����������� �������;
        //      object        - ��������� �� ������;
        //      object_mode_n - ����� ������ �������.
        //    
        int open_path( char x1, char y1, char x2, char y2,
            tech_object *object, int object_mode_n );

        //	��������:
        //		�������� ��������.
        //	������������ ��������:
        //		COMB_ERROR.
        //	���������:
        //		[x1, y1] - ���������� �������� �������� ��������
        //		[x2, y2] - ���������� ��������� �������� ��������,
        //    
        int close_path( char x1, char y1, char x2, char y2 );

        //	��������:
        //		�������� ����������� �������� � ���������� ���������� ��������.
        //	������������ ��������:
        //		COMB_ERROR.
        //	���������:
        //		[x1, y1] - ���������� �������� �������� ��������
        //		[x2, y2] - ���������� ��������� �������� �������� [�������, ������]
        //
        int check_path( char x1, char y1, char x2, char y2 );

        //	��������:
        //		� ������������ � ������� �������� ���������
        //      ��������/��������� ����������� �������.
        //	���������:
        //
        void refresh();    

        //	��������:
        //      � ����������� �� ���� ������ ������� ��� �������, �������� Clipping
        //		� ���������� ����������� ( ��� ���� ����� ��������� ��������� Clipping )
        //	���������:
        //      baseX, baseY	- ���������� �������� ( ��� �������� )
        //
    	void Clip( char baseY, char baseX );
    
    
        //	��������:
        //		�������� �� ���� �������� ( baseX, baseY ) � ��������� �������� �������,
        //			����� ������� �� ����� ���� �� ����...
        //		��� ���� �� ���������� ���������� ���� ��������, ��� ��������� �������� �
        //			������������������ ��������� � ������ ������.
        //		���� ����������� ����������� ���� 23, 24, 25, 26, �� �� ������ ��������
        //			� �� ����� ����������� � ��������� �������� �������;
        // 	���������:
        //      y, x - ���������� �������� �������� ( ��� baseY � baseX );
        //      reg  - ��������� �� X ��� �� Y ������������ ������;
        //      increment 		-	��������� ����������� ������� ( 1 ��� -1 );
        //		tube1 - tube5	-	����� ��� ������� � �������� �������� � ������
        //								����������� �����������;
        //
        void Clipping(	char y, char x, char reg, int increment,
                        int tube1, int tube2, int tube3, int tube4, int tube5 ); 

        //	��������:
        //		������� �� ����� ��������� � ���������� ������� ������� ������.
        //	���������:
        //      type - ���� 1, �� ������� �� ����� ������ ������� ��������� ��������.
        //
        void print( int type = 0 );

    private:
        enum COMB_ERROR
            {
            GE_OK = 0,              //  0 - ��� ��;
            GE_BLOCK_MODE = 2,      //  2 - ������� ����������� �����;
            GE_PATH_ALREADY_USED,   //  3 - ������� ��� ������������ (������);
            GE_INCORRECT_PATH,      //  4 - ������� ����� �� �����;
            GE_PATH_TABLE_IS_FULL,  //  5 - ��� ��������� ������ � ������� ���������;
            GE_IS_NOT_OPEN_PATH,    //  6 - �������� ��� � ������ �������� ���������.
            };

        //	��������:
        //		������������ ��������� ��������.
        enum COMB_ELEMENT
            {
            COMB_NULL 	 	  	= 0,	//	������� �����������;
            COMB_T_VERTICAL		= 1,	//	������������ �����;
            COMB_T_HORIZ	  	= 2,	//	�������������� �����;
            COMB_T_HORIZ_UP		= 3,	//	�������������� ����� � ������������ � ����;
            COMB_T_VERTIC_RIGHT	= 4,	//	������������ ����� � ������������ � �����;
            COMB_T_HORIZ_DOWN	= 5,	//	�������������� ����� � ������������ � ���;
            COMB_T_VERTIC_LEFT	= 6,	//	������������ ����� � ������������ � ����;
            COMB_T_CROSS_MIX	= 7,	//	����������� ���� �� �����������;
            COMB_T_CROSS_SELF	= 8,    //	����������� ���� ( ������ ���� �� ���� );
            COMB_STUB	 	  	= 9,	//	��������;
            
            COMB_V_CLOSE	  	= 11,	//	������ �������� ��������� ��������;
            COMB_V_OPEN			= 12,	//  ������ �������� ��������� ��������;
            COMB_V_DRAIN_CLOSE	= 13,	//  ������ ��������� ��������� ��������;
            COMB_V_DRAIN_OPEN 	= 14,	//  ������ ��������� ��������� ��������;
            COMB_V_MIX_PROOF  	= 15,	//  ������ ��������;
            
            COMB_TANK			= 21,	//  ����;
            COMB_IN     		= 22,	//	����� ��������;
            COMB_OUT	    	= 23,	//	���������� �������;
            COMB_MCA_IN	 	  	= 24,	//	���� �����;
            COMB_MCA_OUT		= 25,	//	����� �����;
            COMB_DRAINAGE		= 26,	//	����������� (������);
            COMB_WATER  		= 27,	//	������� ����;
            COMB_POST			= 28	//	����;            
            };

        //	��������:
        //      �������� ������������ ������� ��������.
        //      � ����������� �� ���� ������ ������� ��� �������, �������� mark_path_elements
        //		� ���������� �����������.
        //	���������:
        //      marked_path - �������;
        //      is_unmark   - ������ ������� � ��������� �������� (��� ����������).
        //
        void mark_path( comb_path *marked_path, char is_unmark = 0 ); 

        //	��������:
        //		�������� �� ������� [ x1, y1 ] - [ x2, y2 ] � ��������(������� �������)
        //      ������������ �������. ��������� (���������) �������� �������.
        // 	���������:
        //      x1, y1      - ���������� ������ �������;
        //      x2, y2      - ���������� ����� �������;
        //      is_open     - ��������� �� �������� �������;
        //      is_unmark   - ������� �� ������� � ������������� ��������.
        //
        int mark_path_elements( char x1, char y1, char x2, char y2, 
            char is_open, char is_unmark = 0 );

        //	��������:
        //  	������� ���������� ������ � ����� ��������, �� ������� ������� �������.
        //	���������:
        //      in	- ����� �����;
        //		out	- ����� ������;
        //
        int get_path_points( comb_point in, comb_point out );

        //	��������:
        //  	������� ������������ ����������� �������.
        // 	���������:
        //      x1, y1  - ����� �����;
        //		x2, y2  - ����� ������;
        //      is_open - ���� 1, �� ���� �������� �������� �������;
        //
        int find_block_element( char x1, char y1, char x2, char y2, char is_open );       
        
    };	 
#endif
