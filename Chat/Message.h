#pragma once
#include "User.h"

class Message
{
	const std::string from_;
	const std::string to_;
	const std::string text_;
public:
	Message(const std::string& from, const std::string& to, const std::string& text)
		: from_(from), to_(to), text_(text)
	{ }
	const std::string getFrom() const
	{
		return from_;
	}
	const std::string getTo() const
	{
		return to_;
	}
	const std::string getText() const
	{
		return text_;
	}
};
