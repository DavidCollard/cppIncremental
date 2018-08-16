#include "UpgradeNodeCommand.h"

UpgradeNodeCommand::UpgradeNodeCommand(std::string code, int amount) : AbstractCommand()
{
	_code = code;
	_amount = amount;
}

std::string UpgradeNodeCommand::getStatus()
{
	return "Upgraded " + _code + "!";
}

std::string UpgradeNodeCommand::getError()
{
	return "That upgrade is impossible. Check your command syntax or arguments.";
}

std::string UpgradeNodeCommand::getWarning()
{
	return "You cannot afford this upgrade";
}

exec_status UpgradeNodeCommand::execute()
{
	if (!_model->hasNode(_code) || _amount < 1)
	{
		return EXEC_ERR;
	}
	
	Node* node = _model->getNode(_code);

	if (node->getUpgradeCost(_amount) > _model->getCurrency())
	{
		return EXEC_WARN;
	}

	_model->subCurrency(node->getUpgradeCost(_amount));
	node->upgrade(_amount);

	return EXEC_CONT;
}

