/// @file i_tech_def.h
/// @brief ����������� ��������� ��������� ��������, ����������� ���������������
/// ������� - ���� (��������������� �������), �������� (������������ ��������)
/// � �.�.
///
/// @author  ������ ������� ���������.
///
/// @par �������� �������� �������������:
/// @c DEBUG   - ���������� c ������� ���������� ���������� � �������.
///
/// @par ������� ������:
/// @$Rev: 868 $.\n
/// @$Author: id $.\n
/// @$Date:: 2013-12-26 10:29:25#$.
#ifndef I_TECH_H
#define I_TECH_H

#include "s_types.h"
//-----------------------------------------------------------------------------
/// @brief ������ � ��������������� ��������.
///
/// ������� ������������ ����� ��� ���������������� ������� (�����, ��������). 
/// �������� �������� ������ ������ - ������ � �������� � �.�.
///
class i_tech_object
    {
    
    public:
    /// @brief ���������/���������� ������.
    ///
    /// @param mode      - �����.
    /// @param new_state - ����� ��������� ������.
    ///
    /// @return  0 - ����� ������� (��������).
    /// @return  1 - ����� ����� ��� ������� (��������).
    /// @return  3 - ��� ������ ������.
    virtual int set_mode( u_int mode, int new_state ) = 0;
    };

#endif // I_TECH_H
