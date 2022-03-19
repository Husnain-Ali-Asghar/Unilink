#pragma once
#include"Post.h"
class Job: public Post
{
	double proposed_price;
	double lowest_price;
	int valid_reply;
	static int JobCount;
public:
	Job();
	Job(const string& t, const string& d, const string& c, const string& s, const double pp);
	void SetProPrice(const double p);
	void SetLowPrice(const double p); 
	double GerProPrice()const;
	double GetLowPrice()const;
	string GetPostDetails()const;
	bool HandleReply(const Reply& rep);
	string GetReplyDetails();
};

