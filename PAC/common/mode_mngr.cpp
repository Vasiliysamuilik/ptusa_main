/// @file  mode_mngr.cpp
/// @brief �������� ���������� ������� mode_mngr.h.
/// 
/// @author  ������ ������� ���������.
///
/// @par �������� �������� �������������:
// @c USE_NO_COMB - ���������� ��� �������� (������� g_greb).@n
/// @c DEBUG       - ���������� ���������� � ������� �������������� ���������� 
/// � �������.
/// 
/// @par ������� ������:
/// @$Rev$.@n
/// @$Author$.@n
/// @$Date::                     $.

#include "mode_mngr.h"
//-----------------------------------------------------------------------------
step_path::step_path(): start_time( 0 )
    {   
    }
//-----------------------------------------------------------------------------
int step_path::add_closed_dev( device *dev )
    {
    close_devices.push_back( dev );
    
    return 0;
    }
//-----------------------------------------------------------------------------
int step_path::add_opened_dev( device *dev )
    {
    open_devices.push_back( dev );
    
    return 0;
    }
//-----------------------------------------------------------------------------
int step_path::init()
    {
    start_time = get_millisec();

    if ( !wash_seats.is_null() )
        {
        wash_seats->init();
        }

    return 0;
    }
//-----------------------------------------------------------------------------
int step_path::evaluate() const
    {   
    // ��������� �������� ������� ��������� (����� ��������� ����� ���������).
    for ( u_int i = 0; i < open_devices.size(); i++ )
        {
        open_devices[ i ]->on();
        }
    for ( u_int i = 0; i < close_devices.size(); i++ )
        {
        close_devices[ i ]->off();
        }

    // ������ � ������� ���������, ���������� ��� ������� ��.
    for ( u_int i = 0; i < FB_group_devices.size(); i++ )
        {
        const FB_group_dev &group = FB_group_devices[ i ];
        for ( u_int j = 0; j < group.open_devices.size(); j++ )
            {
            if ( group.fb->is_active() )
                {
                group.open_devices[ j ]->on();
                }
            else
                {
                group.open_devices[ j ]->off();
                }            
            }
        }

    if ( !wash_seats.is_null() )
        {
        wash_seats->eval();
        }

    return 0;
    }
//-----------------------------------------------------------------------------
int step_path::final()
    {
    for ( u_int i = 0; i < open_devices.size(); i++ )
        {
        open_devices[ i ]->off();
        }
    start_time = 0;

    // ������ � ������� ���������, ���������� ��� ������� ��.
    for ( u_int i = 0; i < FB_group_devices.size(); i++ )
        {
        const FB_group_dev &group = FB_group_devices[ i ];
        for ( u_int j = 0; j < group.open_devices.size(); j++ )
            {
            group.open_devices[ j ]->off();
            }
        }
    return 0;

    if ( !wash_seats.is_null() )
        {
        wash_seats->final();
        }
    }
//-----------------------------------------------------------------------------
void step_path::print() const
    {    
    if ( open_devices.size() )
        {        
        Print( "\t\ton =\n" );
        Print( "\t\t\t{\n" );

        for ( u_int i = 0; i < open_devices.size(); i++ )
            {
            Print( "\t\t\t" );
            open_devices[ i ]->print();  
            Print( "\n" );
            }      
        Print( "\t\t\t}\n" );
        }

    if ( close_devices.size() )
        {
        Print( "\t\toff =\n" );
        Print( "\t\t\t{\n" );

        for ( u_int i = 0; i < close_devices.size(); i++ )
            {
            Print( "\t\t\t" );
            close_devices[ i ]->print();  
            Print( "\n" );
            }        
        Print( "\t\t\t}\n" );
        }

    if ( FB_group_devices.size() )
        {
        Print( "\t\tFB groups =\n" );
        for ( u_int i = 0; i < FB_group_devices.size(); i++ )
            {            
            Print( "\t\t\t" );
            FB_group_devices[ i ].fb->print();  
            Print( "->" );
            for ( u_int j = 0; j < FB_group_devices[ i ].open_devices.size(); j++ )
                {  
                Print( " " );
                FB_group_devices[ i ].open_devices[ j ]->print();    
                Print( "; " );
                }
            Print( "\n" );
            } 
        }

    if ( !wash_seats.is_null() )
        {
        wash_seats->print();
        }
    }
//-----------------------------------------------------------------------------
u_int_4 step_path::get_start_time() const
    {
    return start_time;
    }
//-----------------------------------------------------------------------------
void step_path::set_start_time( u_int_4 start_time ) 
    {
    this->start_time = start_time;
    }
//-----------------------------------------------------------------------------
int step_path::add_FB_group( device *control_FB_dev )
    {
    FB_group_dev group( control_FB_dev );

    FB_group_devices.push_back( group );
    return FB_group_devices.size() - 1;
    }
//-----------------------------------------------------------------------------
int step_path::add_pair_dev( u_int pair_n, device *open_dev )
    {
    try 
        {
        FB_group_devices.at( pair_n ).open_devices.push_back( open_dev );
        }
    catch(...) 
        {
#ifdef DEBUG
        Print( "Error add_pair_dev - pair_n = %d, dev = %s[%d]\n", 
            pair_n, open_dev->get_name(), open_dev->get_n() );
#endif // DEBUG
        }    

    return 0;
    }
//-----------------------------------------------------------------------------
int step_path::add_wash_seats_valves_group( i_mix_proof::STATES state )
    {
    if ( wash_seats.is_null() )
        {
        wash_seats = new wash_step();
        }

    return wash_seats->add_valves_group( state );
    }

int step_path::add_wash_seat_valve( u_int group, device *v )
    {
    if ( wash_seats.is_null() )
        {
#ifdef DEBUG
        Print( "error - step_path::add_wash_seat_valve(...) - no wash seats"
            "group!\n" );
#endif // DEBUG

        return -1;
        }

    
    return wash_seats->add_valve( group, v );
    }
//-----------------------------------------------------------------------------
void step_path::init_params()
    {
    if ( !wash_seats.is_null() )
        {
        wash_seats->init_params();
        }
    }
//-----------------------------------------------------------------------------
int step_path::save( int n, char *buff )
    {

    int res = 0;

    if ( !wash_seats.is_null() )
        {
        if ( n > -1 )
            {
            sprintf( buff + res, "[%d]={", n );
            res = strlen( buff + res );
            }
       
        res += wash_seats->save( buff + res );

        if ( n > -1 )
            {            
            sprintf( buff + res, " }" );
            res += strlen( buff + res );
            }

        sprintf( buff + res, "," );
        res += strlen( buff + res );
        }

    return res;
    }
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
wash_step::wash_step(): active_group_n( 0 ), active_group( 0 ),
    par ( C_MAX_GROUP ),
    phase( P_WAIT ),
    start_cycle_time( 0 ),
    wait_time( 0 ),
    wash_time( 0 )
    {
    }
//-----------------------------------------------------------------------------
void wash_step::init()
    {
    if ( 0 == wash_seat_devices.size() ) return;

    start_cycle_time  = get_millisec();
    phase             = P_WAIT;

    wait_time = ( *( PAC_info::get_instance()->par ) )
        [ PAC_info::P_MIX_FLIP_PERIOD ] * 1000;


    if ( wash_seat_devices.size() > 1 )
        {
        wait_time /= wash_seat_devices.size();
        }

    active_group_n = 0;     
    active_group   = 0;
    }
//-----------------------------------------------------------------------------
void wash_step::eval()
    {
    if ( 0 == wash_seat_devices.size() ) return;

    switch ( phase )
        {
    case P_WAIT:
        // ���� ��������� ����� ������.
        if ( get_delta_millisec( start_cycle_time ) > wait_time )
            {
            phase            = P_OPEN;
            start_cycle_time = get_millisec();
            active_group     = &wash_seat_devices.at( active_group_n );
            wash_time        = par[ active_group_n ];            
            } 
        break;

    case P_OPEN:
        if ( get_delta_millisec( start_cycle_time ) < wash_time )
            {
            active_group->eval();
            }
        else //����� �������� ����� �����.
            {
            active_group->final();
            active_group = 0;

            phase            = P_WAIT;
            start_cycle_time = get_millisec();

            //������� � ��������� ������.
            active_group_n++;
            if ( active_group_n >= wash_seat_devices.size() )
                {
                active_group_n = 0;
                }
            }

        break;
        }
    }
//-----------------------------------------------------------------------------
void wash_step::final()
    {
    if ( 0 == wash_seat_devices.size() ) return;

    if ( active_group == 0 )
        {
        return;
        }

    active_group->final();
    active_group = 0;
    }
//-----------------------------------------------------------------------------
int wash_step::add_valve( u_int group, device *v )
    {
    if ( group < wash_seat_devices.size() )
        {
        wash_seat_devices.at( group ).add_dev( v );
        }
    else
        {
#ifdef DEBUG
        Print( "error - wash_step::add_valve(..) - no group %d!\n",
            group );
#endif // DEBUG

        return -1;
        }

    return 0;
    }
//-----------------------------------------------------------------------------
int wash_step::add_valves_group( i_mix_proof::STATES state )
    {
    if ( wash_seat_devices.size() < C_MAX_GROUP )
        {
        dev_group tmp;
        tmp.state = state;

        wash_seat_devices.push_back( tmp );
        return wash_seat_devices.size() - 1;
        }       

    return -1;
    }
//-----------------------------------------------------------------------------
int wash_step::save( char *buff )
    {
    sprintf( buff, "%s", "WASH_SEAT_GROUP_TIME={" );

    int answer_size = strlen( buff );

    for ( u_int i = 0; i < wash_seat_devices.size(); i++ )
        {
        sprintf( buff + answer_size, "%d, ", par[ i ] );
        answer_size += strlen( buff + answer_size );
        }

    //������� ��������� �������.
    if ( wash_seat_devices.size() )
        {
        answer_size -= 2;
        }

    sprintf( buff + answer_size, "}" );
    answer_size += strlen( buff + answer_size );

    return answer_size;
    }
//-----------------------------------------------------------------------------
void wash_step::print()
    {
    Print( "\t\topen seat v = \n" );
    Print( "\t\t\t{\n" );    

    for ( u_int i = 0; i < wash_seat_devices.size(); i++ )
        {
        Print( "\t\t\t" );
        wash_seat_devices.at( i ).print();
        Print( "\n" );
        }
    Print( "\t\t\t}\n" );
    }
//-----------------------------------------------------------------------------
void wash_step::init_params()
    {
    for ( u_int i = 0; i < par.get_count(); i++ )
        {
        par[ i ] = 1000; //1000 ����
        }
    }
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void wash_step::dev_group::add_dev( device* dev )
    {
    devices.push_back( dev );
    }
//-----------------------------------------------------------------------------
void wash_step::dev_group::final()
    {
    for ( u_int j = 0; j < devices.size(); j++ )
        {
        devices.at( j )->off();
        }
    }
//-----------------------------------------------------------------------------
void wash_step::dev_group::eval()
    {
    for ( u_int j = 0; j < devices.size(); j++ )
        {
        devices.at( j )->set_state( state );
        }
    }
//-----------------------------------------------------------------------------
void wash_step::dev_group::print()
    {
    switch ( this->state )
        {
    case i_mix_proof::ST_UPPER_SEAT:
        Print( "upper = ");
        break;

    case i_mix_proof::ST_LOWER_SEAT:
        Print( "lower = ");
        break;
        }

    Print( "{ " );

    for ( u_int i = 0; i < devices.size(); i++ )
        {
        Print( "%d, ", devices.at( i )->get_n() );
        }
    Print( "}, " );
    }
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
mode_manager::mode_manager( u_int_2 new_modes_cnt
                           ): par( 0 ),                           
                           step_duration_par_n( 0 ),
                           next_step_n( 0 ),
                           modes_cnt( new_modes_cnt ),
                           steps_cnt( 0 ),                           
                           steps( 0 ),
                           active_step( 0 )
    {
    if ( 0 == new_modes_cnt )
        {
#ifdef DEBUG
        Print( "Error! mode_manager constructor - new_modes_cnt = 0!\n" );
#endif // DEBUG
        return;    
        }
    step_duration_par_n = new u_char*[ new_modes_cnt ];
    next_step_n = new u_char*[ new_modes_cnt ];
    for ( int i = 0; i < new_modes_cnt; i++ )
    	{
        step_duration_par_n[ i ] = 0;
        next_step_n[ i ] = 0;
    	}


    steps_cnt = new u_char[ new_modes_cnt ];
    active_step = new u_char[ new_modes_cnt ];
    memset( steps_cnt, 0, new_modes_cnt );
    memset( active_step, 0, new_modes_cnt );

    steps = new step_path*[ new_modes_cnt ];
    for ( int i = 0; i < new_modes_cnt; i++ )
    	{
        steps[ i ] = 0;
    	}

    is_active_mode = new u_char[ new_modes_cnt ];
    memset( is_active_mode, 0, new_modes_cnt );

    for ( int i = 0; i < new_modes_cnt; i++ )
    	{        
        modes_devices.push_back( new step_path() );

        modes_start_time.push_back( 0 );

        // �������� ����� ��� ��������� ������.
        std::vector < device* > fb;
        modes_on_FB.push_back( fb );
    	}
    modes_start_time.push_back( 0 );
    }
//-----------------------------------------------------------------------------
 mode_manager::~mode_manager()
    {
    for ( u_int i = 0; i < modes_devices.size(); i++ )
        {
        delete modes_devices.at( i );
        }


    for ( int i = 0; i < modes_cnt; i++ )
        {
        delete [] next_step_n[ i ];
        next_step_n[ i ] = 0;

        delete [] step_duration_par_n[ i ];
        step_duration_par_n[ i ] = 0;

        delete [] steps[ i ];
        steps[ i ] = 0;
        }
    delete [] next_step_n;
    next_step_n = 0;
    delete [] step_duration_par_n;
    step_duration_par_n = 0;
    delete [] steps;
    steps = 0;

    delete [] steps_cnt;
    steps_cnt = 0;
    delete []  active_step;
    active_step = 0;
    delete []  is_active_mode;
    is_active_mode = 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::init( u_int_2 mode, u_char start_step )
    {
    // �� ������������ ����� ������ �� ��������� ( ��� �������� � 
    // int tech_object::set_mode( u_int mode, int newm )).

    modes_devices.at( mode )->init();

    if ( 0 == steps_cnt[ mode ] )
        {
        return 0;
        }
    if ( check_correct_step_n( mode, start_step ) )
        {
        return -1;
        }

    active_step[ mode ] = start_step;  
    is_active_mode[ mode ] = 1;
    steps[ mode ][ active_step[ mode ] ].init(); 

#ifdef DEBUG
    Print( " INIT STEP [ %d ]\n", active_step[ mode ] );
    steps[ mode ][ active_step[ mode ] ].print();
    Print( " NEXT STEP -> %d \n", 
        next_step_n[ mode ][ active_step[ mode ] ] );        
#endif      

    modes_start_time.at( mode + 1 ) = get_millisec();

    return 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::final( u_int_2 mode )
    {
    // �� ������������ ����� ������ �� ��������� ( ��� �������� � 
    // int tech_object::set_mode( u_int mode, int newm )).

    modes_devices.at( mode )->final();

    if ( 0 == steps_cnt[ mode ] )
        {
        return 0;
        }
    if ( check_correct_step_n( mode, active_step[ mode ] ) )
        {
        return -1;
        }

#ifdef DEBUG
    Print( " FINAL ACTIVE STEP [ %d ] \n", active_step[ mode ] );
#endif 

    is_active_mode[ mode ] = 0;
    steps[ mode ][ active_step[ mode ] ].final();

    active_step[ mode ] = 0;

    modes_start_time.at( mode + 1 ) = get_millisec();
    modes_start_time.at( 0 ) = get_millisec();
    
    return 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::evaluate( u_int_2 mode )
    {
    // �� ������������ ����� ������ �� ��������� ( ��� �������� � 
    // int tech_object::set_mode( u_int mode, int newm )).

    modes_devices.at( mode )->evaluate();
   
    if ( 0 == steps_cnt[ mode ] )
        {
        return 0;
        }
    if ( check_correct_step_n( mode, active_step[ mode ] ) ) 
        {
        return -1;
        }
    u_char step_n = active_step[ mode ];
    steps[ mode ][ step_n ].evaluate();

    // [ 1 ] ���� �������� ������������ �����.
    // [ 2 ] ���� �������� ������������ ��� ����� ����.
    if ( par != 0 &&                                    // 1                                          
        step_duration_par_n[ mode ][ step_n ] != 0 &&   // 2       
        get_millisec() - steps[ mode ][ step_n ].get_start_time() > 
        par[ 0 ][ step_duration_par_n[ mode ][ step_n ] ] * 1000L &&
        next_step_n[ mode ][ step_n ] < 255 )
        {
        final( mode );  
        init( mode, next_step_n[ mode ][ step_n ] );

        evaluate( mode );
        }

    return 0;
    } 
//-----------------------------------------------------------------------------
int mode_manager::check_correct_step_n( u_int_2 mode, u_char step )
    {
    //�������� �� ���������� ����� ������.
    if ( mode >= modes_cnt )
        {
#ifdef DEBUG
        Print( "Error! mode_manager:: mode number >= modes count - \
               [%u] >= [%u]",
               mode, modes_cnt );
#endif // DEBUG
        return -2;    
        }

    //�������� �� ���������� ����� ����.
    if ( step >= steps_cnt[ mode ] )
        {
#ifdef DEBUG
        Print( "Error! mode_manager:: step number >= steps count - \
               [%u] >= [%u]",
               step, steps_cnt[ mode ] );
#endif // DEBUG
        return -1;    
        }

    return 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::set_param( saved_params_u_int_4 *par )
    {
    this->par = par;
    return 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::set_mode_config( u_int_2 mode, u_char new_steps_cnt )
    {
    if ( 0 == new_steps_cnt )
        {
#ifdef DEBUG
        Print( "ERROR! mode_manager::set_mode_config - new_steps_cnt[%d] = 0!", 
            new_steps_cnt );
#endif // DEBUG
        return -1;
        }

    // �������� �� ���������� ����� ������.
    if ( mode >= modes_cnt )
        {
#ifdef DEBUG
        Print( "Error! mode_manager::set_mode_config mode number >= modes \
               count - [%u] >= [%u]",
               mode, modes_cnt );
#endif // DEBUG
        return -2;    
        }

    steps_cnt[ mode ] = new_steps_cnt;

    steps[ mode ] = new step_path[ new_steps_cnt ];   
    step_duration_par_n[ mode ] = new u_char[ new_steps_cnt ];    
    next_step_n[ mode ] = new u_char[ new_steps_cnt ];

    for ( int i = 0; i < new_steps_cnt; i++ )
        {
        step_duration_par_n[ mode ][ i ] = 0;
        next_step_n[ mode ][ i ] = 0;
        }
    return 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::to_step( u_int_2 mode, u_char new_step )
    {
    if ( check_correct_step_n( mode, new_step - 1 ) ) return -1;

    final( mode );
    init( mode, new_step - 1 );
    evaluate( mode );

    return 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::add_closed_dev( u_int_2 mode, u_char step, device *dev )
    {
    if ( check_correct_step_n( mode, step ) ) 
        {
        return -1;
        }
    
    return steps[ mode ][ step ].add_closed_dev( dev );
    }
//-----------------------------------------------------------------------------
int mode_manager::add_opened_dev( u_int_2 mode, u_char step, device *dev )
    {
    if ( check_correct_step_n( mode, step ) ) 
        {
        return -1;
        }
    return steps[ mode ][ step ].add_opened_dev( dev );
    }
//-----------------------------------------------------------------------------
void mode_manager::print()
    {
    Print( "mode_manager[%u]\n", modes_cnt );
    for ( int j = 0; j < modes_cnt; j++ )
        {     
        Print( "\t[ %d ] =\n", j );            

        if ( modes_on_FB.at( j ).size() )
            {
            Print( "\t\trequired FB = { " );

            for ( u_int i = 0; i < modes_on_FB.at( j ).size(); i++ )
                {
                Print( "%d, ",  modes_on_FB.at( j ).at( i )->get_n() );
                }
            Print( "}\n" ); 
            }

        modes_devices.at( j )->print();

        if ( steps_cnt[ j ] > 0 )
            {
            Print( "     steps count - %u \n", steps_cnt[ j ] );
            for ( int i = 0; i < steps_cnt[ j ]; i++ )
                {
                Print( "    [%2d], time step par[%d]; next step[%d]\n", 
                    i + 1, step_duration_par_n[ j ][ i ], next_step_n[ j ][ i ] );                                                
                steps[ j ][ i ].print();
                }

            Print( "\n" );
            }
        }             
    }
//-----------------------------------------------------------------------------
u_int mode_manager::get_active_step( u_int mode )
    {
    return is_active_mode[ mode ] ? 1 + active_step[ mode ] : 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::is_current_step_evaluation_time_left( u_int_2 mode )
    {
    if ( 0 == steps_cnt[ mode ] )
        {
        return 0;
        }
    if ( check_correct_step_n( mode, active_step[ mode ] ) ) 
        {
        return -1;
        }
    u_char step_n = active_step[ mode ];

    // [ 1 ] ���� �������� ������������ �����.
    // [ 2 ] ���� �������� ������������ ��� ����� ����.
    if ( par != 0 &&                                    // 1                                     
        step_duration_par_n[ mode ][ step_n ] != 0 &&   // 2  
        get_millisec() - steps[ mode ][ step_n ].get_start_time() > 
        par[ 0 ][ step_duration_par_n[ mode ][ step_n ] ] * 1000L )
        {
        return 1;
        }

    return 0;
    }
//-----------------------------------------------------------------------------
unsigned long mode_manager::get_current_step_evaluation_time( u_int_2 mode )
    {
    if ( 0 == steps_cnt[ mode ] )
        {
        return 0;
        }
    if ( check_correct_step_n( mode, active_step[ mode ] ) ) 
        {
        return 0;
        }
    u_char step_n = active_step[ mode ];

    return get_millisec() - steps[ mode ][ step_n ].get_start_time();
    }
//-----------------------------------------------------------------------------
int mode_manager::add_mode_closed_dev( u_int_2 mode, device *dev )
    {
    if ( mode >= modes_cnt )
    	{
#ifdef DEBUG
        Print( "Error! mode_manager:: mode[ %u ] >= modes count[ %u ]!\n",
               mode, modes_cnt );
#endif // DEBUG
        return 2;
    	}   

    try
        {
        modes_devices.at( mode)->add_closed_dev( dev );
        }
    catch (...)
        {
#ifdef PAC_PC
        debug_break;
#endif // PAC_PC
        return 1;
        }

    return 0;
    }
//-----------------------------------------------------------------------------
int mode_manager::add_mode_opened_dev( u_int_2 mode, device *dev )
    {
    if ( mode >= modes_cnt )
        {
#ifdef DEBUG
        Print( "Error! mode_manager:: mode[ %u ] >= modes count[ %u ]!\n",
            mode, modes_cnt );
#endif // DEBUG
        return 2;
        }

    try
    	{
        modes_devices.at( mode)->add_opened_dev( dev );
    	}
    catch (...)
    	{
#ifdef PAC_PC
        debug_break;
#endif // PAC_PC
    	return 1;
    	}
       
    return 0;
    }
//-----------------------------------------------------------------------------
unsigned long mode_manager::get_mode_evaluation_time( u_int mode )
    {
    if ( mode >= 0 && mode < modes_cnt )
        {
        return get_millisec() - modes_start_time.at( mode + 1 );
        }        

    return 0;
    }
//-----------------------------------------------------------------------------
unsigned long mode_manager::get_idle_time()
    {
    return get_millisec() - modes_start_time.at( 0 );
    }
//-----------------------------------------------------------------------------
int mode_manager::add_mode_on_FB( u_int_2 mode, device *dev )
    {
    if ( mode >= modes_cnt )
        {
#ifdef DEBUG
        Print( "Error! mode_manager::add_mode_on_FB(...) mode[ %u ] >= "
            "modes count[ %u ]!\n",
            mode, modes_cnt );
#endif // DEBUG
        return 2;
        }

    try
        {
        modes_on_FB.at( mode).push_back( dev );
        }
    catch (...)
        {
#ifdef PAC_PC
        debug_break;
#endif // PAC_PC
        return 1;
        }

    return 0;
    }
//-----------------------------------------------------------------------------
bool mode_manager::check_on_mode( u_int_2 mode )
    {
    // �� ������������ ����� ������ �� ��������� ( ��� �������� � 
    // int tech_object::set_mode( u_int mode, int newm )).

    u_int on_FB_cnt = modes_on_FB.at( mode ).size();
    if ( on_FB_cnt )
        {
        for ( u_int i = 0; i < on_FB_cnt; i++ )
            {
            if ( modes_on_FB.at( mode ).at( i )->is_active() == false )
                {
#ifdef DEBUG
                Print( "No FB[ %d ]!\n",
                    modes_on_FB.at( mode ).at( i )->get_n() );
#endif // DEBUG
                return false;
                }
            }
        }

    return true;
    }
//-----------------------------------------------------------------------------
int mode_manager::add_mode_FB_group( int mode, device *control_FB_dev )
    {
    return modes_devices.at( mode )->add_FB_group( control_FB_dev );
    }
//-----------------------------------------------------------------------------
int mode_manager::add_mode_pair_dev( int mode, u_int pair_n, device *open_dev )
    {
    return modes_devices.at( mode )->add_pair_dev( pair_n, open_dev );
    }
//-----------------------------------------------------------------------------
int mode_manager::add_wash_seats_valves_group( int mode, u_char step, 
    i_mix_proof::STATES state )
    {

    int group;
    if ( 0 == step )
        {
        group = modes_devices[ mode ]->add_wash_seats_valves_group( state );
        }
    else
        {
        step --;
        if ( check_correct_step_n( mode, step ) )
            {
            return -1;
            }

        group = steps[ mode ][ step ].add_wash_seats_valves_group( state );
        }

    return group;
    }
//-----------------------------------------------------------------------------
int mode_manager::add_wash_seat_valve( int mode, u_char step, u_int group, 
    device *v )
    {
    if ( 0 == step )
        {
        modes_devices[ mode ]->add_wash_seat_valve( group, v );
        }
    else
        {
        step--;
        if ( check_correct_step_n( mode, step ) )
            {
            return -1;
            }

        steps[ mode ][ step ].add_wash_seat_valve( group, v );
        }

    return 0;
    }
//-----------------------------------------------------------------------------
void mode_manager::init_params()
    {
    for ( u_int i = 0; i < modes_cnt; i++ )
        {
        modes_devices[ i ]->init_params();

        for ( u_int j = 0; j < steps_cnt[ i ]; j++ )
            {
            steps[ i ][ j ].init_params();
            }
        }
    }
//-----------------------------------------------------------------------------
int mode_manager::save( char *buff )
    {
    int str_size = 0;

    sprintf( buff + str_size, "\tMODE = \n\t\t{ \n" );
    str_size += strlen( buff + str_size );

    for ( u_int i = 0; i < modes_cnt; i++ )
        {
        sprintf( buff + str_size, "\t\t[%d] = { ", i + 1 );
        str_size += strlen( buff + str_size );

        str_size += modes_devices[ i ]->save( -1, buff + str_size );

        sprintf( buff + str_size, "STEP = { " );
        str_size += strlen( buff + str_size );
        for ( u_int j = 0; j < steps_cnt[ i ]; j++ )
            {
            str_size += steps[ i ][ j ].save( j + 1, buff + str_size );            
            }
        sprintf( buff + str_size, "}, " );
        str_size += strlen( buff + str_size );


        sprintf( buff + str_size, " },\n" );
        str_size += strlen( buff + str_size );
        }

    sprintf( buff + str_size, "\t\t},\n" );
    str_size += strlen( buff + str_size );

    return str_size;
    }
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
