#include "UpgradeNodeCommand.h"

UpgradeNodeCommand::UpgradeNodeCommand(std::string code) : AbstractCommand()
{
	_code = code;
}

std::string UpgradeNodeCommand::getStatus()
{
	return "test";
}

std::string UpgradeNodeCommand::getError()
{
	return _code + " does not exist";
}

std::string UpgradeNodeCommand::getWarning()
{
	return "You cannot afford this upgrade";
}

exec_status UpgradeNodeCommand::execute()
{
	if (!_model->hasNode(_code))
	{
		return EXEC_ERR;
	}
	
	Node* node = _model->getNode(_code);

	if (node->getUpgradeCost() > _model->getCurrency())
	{
		return EXEC_WARN;
	}

	_model->subCurrency(node->getUpgradeCost());
	node->upgrade();

	return EXEC_CONT;
}

