#pragma once
#include "SaveCommand.h"
#include "MyString.h"

class SaveAsCommand : public SaveCommand
{
public:
	SaveAsCommand(const MyString& fileName);
	void execute() const override;
	Command* clone() const override;

private:
	const MyString fileName;
};