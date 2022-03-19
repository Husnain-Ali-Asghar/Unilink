#include "Event.h"

int Event::EventCount = 0;
Reply** Regrow(Reply** rep, int count)
{
	Reply** temp = new Reply * [count + 1];
	for (int x = 0; x < count; x++)
	{
		temp[x] = new Reply(rep[x]->GetValue(), rep[x]->GetReplyId(), rep[x]->GetPostId());
	}
	delete[]rep;
	rep = temp;
	temp = nullptr;
	return rep;
}

Event::Event()
{
	this->capacity = 0;
	this->attendees_count = 0;
}

Event::Event(const string& t, const string& d, const string& c, const string& s, const string& ven, const string& date, const int cap)
	:Post(t,d,c,s)
{
	this->venue = ven;
	this->date = date;
	this->capacity = cap;
	this->PostId = "Eve-" + to_string(Event::EventCount);
	Event::EventCount++;
}

bool Event::HandleReply(const Reply& rep)
{
	if (this->replies == nullptr)
	{
		this->replies = new Reply*[1];
	}
	if (this->attendees_count <= this->capacity && rep.GetValue() == 1.0 && (this->Status == "OPEN" || this->Status == "open"))
	{
		Reply** temp;
		temp = this->replies;
		this->replies = new Reply * [this->attendees_count + 1];
		for (int x = 0; x < this->attendees_count; x++)
		{
			this->replies[x] = temp[x];
		}
		temp = nullptr;
		this->replies[this->attendees_count] = new Reply(rep.GetValue(), rep.GetReplyId(), rep.GetPostId());
		this->attendees_count++;
		if (this->attendees_count >= this->capacity)
		{
			this->Status = "CLOSED";
		}
		return true;
	}
	else {
		return false;
	}
}

string Event::GetReplyDetails()
{
	string temp;
	temp = temp + this->GetPostDetails() + "\n";
	temp = temp + "Attendees Replies:\n";
	if (this->attendees_count == 0)
	{
		temp = temp + "list Empty" + "\n";
	}
	else
	{
		for (int x = 0; x < this->attendees_count; x++)
		{
			temp = temp + this->replies[x]->GetReplyId()+": ";
			temp = temp + to_string(this->replies[x]->GetValue()) + "\n";
		}
	}
	return temp;
}

string Event::GetPostDetails() const
{
	string temp;
	temp = Post::GetPostDetails();
	temp = temp + "\n" + "Venue: " + this->venue + "\n";
	temp = temp + "Date: " + this->date + "\n";
	temp = temp + "Capacity: " + to_string(this->capacity) + "\n";
	temp = temp + "Attendees: " + to_string(this->attendees_count) + "\n";
	return temp;
}
