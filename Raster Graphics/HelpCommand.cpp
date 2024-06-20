#include "HelpCommand.h"
#include "Application.h"

void HelpCommand::execute() const
{
    Application& application = Application::getInstance();
    application.help();
}
