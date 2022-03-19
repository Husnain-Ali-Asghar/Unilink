#pragma once
#include"Post.h"
class Event :public Post
{
	string venue;
	string date;
	int capacity;
	int attendees_count;
	static int EventCount;
public:
	Event();
	Event(const string& t, const string& d, const string& c, const string& s,
		const string& ven,const string&date,const int cap);
	bool HandleReply(const Reply& rep);
	string GetReplyDetails();
	string GetPostDetails()const;
};

