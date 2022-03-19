#include "Job.h"

int Job::JobCount = 0;

Job::Job()
{
	this->proposed_price = 0;
	this->lowest_price = 0;
	this->valid_reply = 0;
	Job::JobCount++;
}

Job::Job(const string& t, const string& d, const string& c, const string& s, const double pp)
	:Post(t, d, c, s)
{
	this->proposed_price = pp;
	this->lowest_price = 0;
	this->PostId = "JOB-" + to_string(Job::JobCount);
	this->valid_reply = 0;
	Job::JobCount++;
}

void Job::SetProPrice(const double p)
{
	this->proposed_price = p;
}

void Job::SetLowPrice(const double p)
{
	this->lowest_price = p;
}

double Job::GerProPrice() const
{
	return this->proposed_price;
}

double Job::GetLowPrice() const
{
	return this->lowest_price;
}

string Job::GetPostDetails() const
{
	string temp;
	temp = Post::GetPostDetails();
	temp = temp + "\nProposed Price: " + "$" + to_string(this->proposed_price) + "\n";
	temp = temp + "Lowest Price: " + "$" + to_string(this->lowest_price) + "\n";
	return temp;
}

bool Job::HandleReply(const Reply& rep)
{
	if (this->replies == nullptr)
	{
		this->replies = new Reply * [1];
	}
	if (rep.GetValue() < this->proposed_price && (this->Status == "OPEN" || this->Status == "open"))
	{
		Reply** temp;
		temp = this->replies;
		this->replies = new Reply * [this->valid_reply + 1];
		for (int x = 0; x < this->valid_reply; x++)
		{
			this->replies[x] = temp[x];
		}
		temp = nullptr;
		this->replies[this->valid_reply] = new Reply(rep.GetValue(), rep.GetReplyId(), rep.GetPostId());
		this->valid_reply++;
		this->lowest_price = rep.GetValue();
		return true;
	}
	else
	{
		return false;
	}
}

string Job::GetReplyDetails()
{
	string temp;
	temp = this->GetPostDetails();
	temp = temp + "------------OFFER HISTORY--------------\n";
	if (this->valid_reply != 0)
	{
		for (int x = 0; x < this->valid_reply; x++)
		{
			temp = temp + this->replies[x]->GetReplyId() + ": " + "$" + to_string(this->replies[x]->GetValue()) + "\n";
		}
	}
	else
	{
		temp = temp + "No Offer History yet\n";
	}
	return temp;
}
