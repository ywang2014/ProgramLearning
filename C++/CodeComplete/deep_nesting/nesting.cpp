/**
	19章：19.4驯服危险的深层嵌套
	
	把深层嵌套的代码抽取出来放进单独的子程序
*/

// 实例1：代码本身结构已经很优秀
while (!TransactionsComplete())
{
	// read transaction record
	transaction = ReadTransaction();
	
	// process transaction depending on type of transaction
	if (transaction.Type == TransactionType_Deposit)
	{
		// process a deposit
		if (transaction.AccountType == AccountType_Checking)
		{
			if (transaction.AccountSubType == AccountSubType_Business)
			{
				MakeBusinessCheckDep(transaction.AccountNum, transaction.Amount);
			}
			else if (transaction.AccountSubType == AccountSubType_Personal)
			{
				MakePersonalCheckDep(transaction.AccountNum, transaction.Amount);
			}
			else if (transaction.AccountSubType == AccountSubType_School)
			{
				MakeSchoolCheckDep(transaction.AccountNum, transaction.Amount);
			}
		}
		else if (transaction.AccountType == AccountType_Savings)
		{
			MakeSavingsDep(transaction.AccountNum, transaction.Amount);
		}
		else if (transaction.AccountType == AccountType_DebitCard)
		{
			MakeDebitCardDep(transaction.AccountNum, transaction.Amount);
		}
		else if (transaction.AccountType == AccountType_MoneyMarket)
		{
			MakeMoneyMarketDep(transaction.AccountNum, transaction.Amount);
		}
		else if (transaction.AccountType == AccountType_Cd)
		{
			MakeCDDep(transaction.AccountNum, transaction.Amount);
		}
	}
	else if (transaction.Type == TransactionType_Withdrawal)
	{
		// process a withdrawal
		if (transaction.AccountType == AccountType_Checking)
		{
			MakeCheckingWithdrawal(transaction.AccountNum, transaction.Amount);
		}
		else if (transaction.AccountType == AccountType_Savings)
		{
			MakeSavingsWithdrawal(transaction.AccountNum, transaction.Amount);
		}
		else if (transaction.AccountType == AccountType_DebitCard)
		{
			MakeDebitCardWithdrawal(transaction.AccountNum, transaction.Amount);
		}
	}
	else if (transaction.Type == TransactionType_Transfer)
	{
		MakeFundsTransfer(transaction.SourceAccountType, transaction.TargetAccountType, transaction.AccountNum, transaction.Amount);
	}
	else 
	{
		// process unknown kind of transaction 
		LogTransactionError("Unknown Transaction Type", transaction);
	}
}

/*
	优化：将嵌套代码分解到子程序后 --- 抽取优化
	
	减少嵌套层次、缩短代码结构，容易阅读、修改、调试
	模块化
	方便进一步优化
	
*/
while (!TransactionsComplete())
{
	// read transaction record
	transacion = ReadTransaction();
	
	// process transaction depending on type of transaction 
	if (transaction.Type == TransactionType_Deposit)
	{
		ProcessDeposit(transacion.AccountType, transaction.AccountSubType, transacion.AccountNum, transaction.Amount);
	}
	else if (transaction.Type == TransactionType_Withdrawal)
	{
		ProcessWithdrawal(transacion.AccountType, transacion.AccountNum, transaction.Amount);
	}
	else if (transacion.Type == TransactionType_Transfer)
	{
		MakeFundsTransfer(transacion.SourceAccountType, transaction.TargetAccountType, transacion.AccountNum, transaction.Amount);
	}
	else 
	{
		// process unknown transacion type
		LogTransactionError("Unknown Transaction Type", transacion);
	}
}

/*
	优化：使用case语句

*/
while (!TransactionsComplete())
{
	// read transaction record
	transaction = ReadTransaction();
	
	// process transaction depending on type of transaction
	switch (transaction.Type)
	{
		case TransactionType_Deposit:
			ProcessDeposit(transacion.AccountType, transaction.AccountSubType, transacion.AccountNum, transaction.Amount);
			break;
		
		case TransactionType_Withdrawal:
			ProcessWithdrawal(transacion.AccountType, transacion.AccountNum, transaction.Amount);
			break;
			
		case TransactionType_Transfer:
			MakeFundsTransfer(transacion.SourceAccountType, transaction.TargetAccountType, transacion.AccountNum, transaction.Amount);
			break;
			
		default:
			LogTransactionError("Unknown Transaction Type", transacion);
			break;
	}
}

/*
	使用更加面向对象的方法
	
	多态机制
		抽象基类 Transaction 
		派生类：Deposit Withdrawal Transfer 
*/
TransactionData transactionData;
Transaction *transacion;

while(!TransactionsComplete())
{
	// read transaction record
	transactionData = ReadTransaction();
	
	// create transaction object, depending on type of transaction
	switch (transactionData.Type)
	{
		case (TransactionType_Deposit):
			transaction = new Deposit(transactionData);
			break;
			
		case (TransactionType_Withdrawal):
			transaction = new Withdrawal(transactionData);
			break;
			
		case (TransactionType_Transfer):
			transaction = new Transfer(transactionData);
			break;
			
		default:
			// process unknown transaction type 
			LogTransactionError("Unknown Transaction Type", transacionData);
			return;
	}
	transaction->Complete();
	delete transaction;
}

/*
	使用多态机制和Object Factory模式
	用Factory Method模式替换switch语句
*/
TransactionData transactionData;
Transaction *transaction;

while (!TransactionsComplete())
{
	// read tranaction record and complete transaction 
	transactionData = ReadTransaction();
	transaction = TransactionFactory.Create(transactionData);
	transaction->Complete();
	delete transaction;
}

// Object Factory 的代码
Transaction *TransactionFactory::Create(TransactionData transactionData)
{
	// create transaction object, depending on type of transaction 
	switch (transactionData.Type)
	{
		case TransactionType_Deposit:
			return new Deposit(transactionData);
			break;
			
		case TransactionType_Withdrawal:
			return new Withdrawal(transactionData);
			break;
			
		case TransactionType_Transfer:
			return new Transfer(transactionData);
			break;
			
		default:
			// process unknown transaction type 
			LogTransactionError("Unknown Transaction Type", transactionData);
			return NULL;
	}
}