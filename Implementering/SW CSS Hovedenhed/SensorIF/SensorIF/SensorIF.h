/*
 * Klasse SensorIF
 *
 * Interface til lyddetektoren
 *
 *  Af Bjørn Sørensen
 */ 

#pragma once

#include "UC5DetekterLyd.h"


class SensorIF
{
public:
	SensorIF( );
	~SensorIF( );
	
	void alarmer( );
	void setUC5Ptr( UC5DetekterLyd * );
	
private:
	UC5DetekterLyd * UC5Ptr_;
	
};

extern SensorIF SensorIFObj;