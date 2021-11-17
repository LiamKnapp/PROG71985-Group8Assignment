#pragma once
#include "Structure.c"

//operation functions
char addappointment(Calendar* date);
char deleteappointment(Calendar* date);
char updateappointment(Calendar* date);
char searchappointment(Calendar* date);

//display functions
char display();
char AllAppt(Calendar* date);
char RangeAppt(Calendar* date);
char SingleAppt(Calendar* date);