#pragma once
#include"Event.h"
#include"Reply.h"
#include"Sale.h"
#include"Post.h"
#include<iostream>
using namespace std;
class UniLink
{
	Post** ptr;
	int NoPosts;
	Reply reply;
public:
	UniLink();
	void Menu();
	void MenuPrint();
	void Regrow();
};

