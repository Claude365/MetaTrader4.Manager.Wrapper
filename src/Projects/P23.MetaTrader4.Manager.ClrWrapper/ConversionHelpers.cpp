#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"


#define COPY_STR(dst,src)  { strncpy_s(dst,src,sizeof(dst)-1); dst[sizeof(dst)-1]=0; }

P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConManager* configuration)
{
	P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ tManager = gcnew P23::MetaTrader4::Manager::Contracts::Configuration::Manager();
	tManager->Admin = configuration->admin;
	tManager->Broker = configuration->broker;
	tManager->Email = configuration->email;
	tManager->Groups = gcnew System::String(configuration->groups);
	tManager->InfoDepth = configuration->info_depth;
	tManager->IpFilter = configuration->ipfilter;
	tManager->IpFrom = configuration->ip_from;
	tManager->IpTo = configuration->ip_to;
	tManager->Login = configuration->login;
	tManager->Logs = configuration->logs;
	tManager->Mailbox = gcnew System::String(configuration->mailbox);
	tManager->ManagerRights = configuration->manager;
	tManager->MarketWatch = configuration->market_watch;
	tManager->Money = configuration->money;
	tManager->Name = gcnew System::String(configuration->name);
	tManager->News = configuration->news;
	tManager->Online = configuration->online;
	tManager->Plugins = configuration->plugins;
	tManager->Reports = configuration->reports;
	tManager->Riskman = configuration->riskman;

	tManager->SecGroups = gcnew System::Collections::Generic::List<P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^>();
	for (int i = 0; i < MAX_SEC_GROUPS; i++){
		tManager->SecGroups->Add(Convert(&configuration->secgroups[i]));
	}
	
	tManager->SeeTrades = configuration->see_trades;
	tManager->ServerReports = configuration->server_reports;
	tManager->Trades = configuration->trades;
	tManager->UserDetails = configuration->user_details;
	return tManager;
}

ConManager* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ configuration)
{
	ConManager* tManager = new ConManager();

	tManager->admin = configuration->Admin;
	tManager->broker = configuration->Broker;
	tManager->email = configuration->Email;

	char* groups = Convert(configuration->Groups);
	if (groups != NULL)
		COPY_STR(tManager->groups, groups);
	
	tManager->info_depth = configuration->InfoDepth;
	tManager->ipfilter = configuration->IpFilter;
	tManager->ip_from = (unsigned long)configuration->IpFrom;
	tManager->ip_to = (unsigned long)configuration->IpTo;
	tManager->login = configuration->Login;
	tManager->logs = configuration->Logs;

	char* mailbox = Convert(configuration->Mailbox);
	if (mailbox != NULL)
		COPY_STR(tManager->mailbox, mailbox);
	
	tManager->manager = configuration->ManagerRights;
	tManager->market_watch = configuration->MarketWatch;
	tManager->money = configuration->Money;

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(tManager->name, name);
	
	tManager->news = configuration->News;
	tManager->online = configuration->Online;
	tManager->plugins = configuration->Plugins;
	tManager->reports = configuration->Reports;
	tManager->riskman = configuration->Riskman;
	if (configuration->SecGroups->Count != MAX_SEC_GROUPS)
		throw gcnew ArgumentException("Invalid number of securities");
		
	for (int i = 0; i < MAX_SEC_GROUPS; i++){
		tManager->secgroups[i] = *Convert(configuration->SecGroups[i]);
	}

	tManager->see_trades = configuration->SeeTrades;
	tManager->server_reports = configuration->ServerReports;
	tManager->trades = configuration->Trades;
	tManager->user_details = configuration->UserDetails;
	return tManager;
}

ManagerSecurity^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConManagerSec* configuration)
{
	P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ sec = gcnew P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity();
	sec->Enable = configuration->enable;
	sec->MaximumLots = configuration->maximum_lots;
	sec->MinimumLots = configuration->minimum_lots;
	return sec;
}

ConManagerSec* P23::MetaTrader4::Manager::ClrWrapper::Convert(ManagerSecurity^ configuration)
{
	ConManagerSec* sec = new ConManagerSec();
	sec->enable = configuration->Enable;
	sec->maximum_lots = configuration->MaximumLots;
	sec->minimum_lots = configuration->MinimumLots;
	return sec;
}

Common^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConCommon* configuration)
{
	Common^ newConfiguration = gcnew Common();

	newConfiguration->Adapters = gcnew String(configuration->adapters);
	newConfiguration->Address = configuration->address;
	newConfiguration->AntiFlood = configuration->antiflood;
	for (int i = 0; i < 8; i++)
		newConfiguration->BindAdresses->Add(configuration->bind_adresses[i]);

	newConfiguration->DayLightCorrection = configuration->daylightcorrection;
	newConfiguration->EndHour = configuration->endhour;
	newConfiguration->EndMinute = configuration->endminute;
	newConfiguration->FeederTimeout = configuration->feeder_timeout;
	newConfiguration->FloodControl = configuration->floodcontrol;
	newConfiguration->KeepEmails = configuration->keepemails;
	newConfiguration->KeepTicks = configuration->keepticks;
	newConfiguration->LastLogin = configuration->lastlogin;
	newConfiguration->LastOrder = configuration->lastorder;
	newConfiguration->LiveUpdateMode = configuration->liveupdate_mode;
	newConfiguration->LostLogin = configuration->lostlogin;
	newConfiguration->MinClient = configuration->minclient;
	newConfiguration->MinApi = configuration->minapi;
	newConfiguration->MonthlyStateMode = configuration->monthly_state_mode;
	newConfiguration->Name = gcnew String(configuration->name);
	newConfiguration->OptimizationCounter = configuration->optimization_counter;
	newConfiguration->OptimizationLasttime = configuration->optimization_lasttime;
	newConfiguration->OptimizationTime = configuration->optimization_time;
	newConfiguration->OverMonthLastMonth = configuration->overmonth_last_month;
	newConfiguration->OverNightLastDay = configuration->overnight_last_day;
	newConfiguration->OverNightLastTime = configuration->overnight_last_time;
	newConfiguration->OverNightPrevTime = configuration->overnight_prev_time;
	newConfiguration->Owner = gcnew String(configuration->owner);
	newConfiguration->PathDatabase = gcnew String(configuration->path_database);
	newConfiguration->PathHistory = gcnew String(configuration->path_history);
	newConfiguration->PathLog = gcnew String(configuration->path_log);
	newConfiguration->Port = configuration->port;
	newConfiguration->RolloversMode = configuration->rollovers_mode;
	newConfiguration->ServerBuild = configuration->server_build;
	newConfiguration->ServerVersion = configuration->server_version;
	newConfiguration->StatementMode = configuration->statement_mode; 
	newConfiguration->StatementWeekend = configuration->statement_weekend;
	newConfiguration->TimeOfDemo = configuration->timeofdemo;
	newConfiguration->Timeout = configuration->timeout;
	newConfiguration->TimeSync = gcnew String(configuration->timesync);
	newConfiguration->TimeZone = configuration->timezone;
	newConfiguration->TypeOfDemo = configuration->typeofdemo;

	for (int i = 0; i < 8; i++)
		newConfiguration->WebAdresses->Add(configuration->web_adresses[i]);
			
	return newConfiguration;
}

ConCommon* P23::MetaTrader4::Manager::ClrWrapper::Convert(Common^ configuration)
{
	ConCommon* newConfiguration = new ConCommon();
	
	char* adapters = Convert(configuration->Adapters);
	if (adapters != NULL)
		COPY_STR(newConfiguration->adapters, adapters);

	newConfiguration->address = configuration->Address;
	newConfiguration->antiflood = configuration->AntiFlood;

	if (configuration->BindAdresses->Count > 8)
		throw gcnew ArgumentException("BindAddresses count exceed 8");
	for (int i = 0; i < configuration->BindAdresses->Count; i++)
		newConfiguration->bind_adresses[i] = configuration->BindAdresses[i];

	newConfiguration->daylightcorrection = configuration->DayLightCorrection;
	newConfiguration->endhour = configuration->EndHour;
	newConfiguration->endminute = configuration->EndMinute;
	newConfiguration->feeder_timeout = configuration->FeederTimeout;
	newConfiguration->floodcontrol = configuration->FloodControl;
	newConfiguration->keepemails = configuration->KeepEmails;
	newConfiguration->keepticks = configuration->KeepTicks;
	newConfiguration->lastlogin = configuration->LastLogin;
	newConfiguration->lastorder = configuration->LastOrder;
	newConfiguration->liveupdate_mode = configuration->LiveUpdateMode;
	newConfiguration->lostlogin = configuration->LostLogin;
	newConfiguration->minclient = configuration->MinClient;
	newConfiguration->minapi = configuration->MinApi;
	newConfiguration->monthly_state_mode = configuration->MonthlyStateMode;

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);
	
	newConfiguration->optimization_counter = configuration->OptimizationCounter;
	newConfiguration->optimization_lasttime = configuration->OptimizationLasttime;
	newConfiguration->optimization_time = configuration->OptimizationTime;
	newConfiguration->overmonth_last_month = configuration->OverMonthLastMonth;
	newConfiguration->overnight_last_day = configuration->OverNightLastDay;
	newConfiguration->overnight_last_time = configuration->OverNightLastTime;
	newConfiguration->overnight_prev_time = configuration->OverNightPrevTime;

	char* owner = Convert(configuration->Owner);
	if (owner != NULL)
		COPY_STR(newConfiguration->owner, owner);
	
	char* path_database = Convert(configuration->PathDatabase);
	if (path_database != NULL)
		COPY_STR(newConfiguration->path_database, path_database);
	
	char* path_history = Convert(configuration->PathHistory);
	if (path_history != NULL)
		COPY_STR(newConfiguration->path_history, path_history);
	
	char* path_log = Convert(configuration->PathLog);
	if (path_log != NULL)
		COPY_STR(newConfiguration->path_log, path_log);
	
	newConfiguration->port = configuration->Port;
	newConfiguration->rollovers_mode = configuration->RolloversMode;
	newConfiguration->server_build = configuration->ServerBuild;
	newConfiguration->server_version = configuration->ServerVersion;
	newConfiguration->statement_mode = configuration->StatementMode;
	newConfiguration->statement_weekend = configuration->StatementWeekend;
	newConfiguration->timeofdemo = configuration->TimeOfDemo;
	newConfiguration->timeout = configuration->Timeout;

	char* timesync = Convert(configuration->TimeSync);
	if (timesync != NULL)
		COPY_STR(newConfiguration->timesync, timesync);
	
	newConfiguration->timezone = configuration->TimeZone;
	newConfiguration->typeofdemo = configuration->TypeOfDemo;

	if (configuration->WebAdresses->Count > 8)
		throw gcnew ArgumentException("WebAdresses count exceed 8");
	for (int i = 0; i < configuration->WebAdresses->Count; i++)
		newConfiguration->web_adresses[i] = configuration->WebAdresses[i];
	
	return newConfiguration;
}

Time^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConTime* configuration)
{
	Time^ newConfiguration = gcnew Time();
	newConfiguration->Days = gcnew System::Collections::Generic::List<System::Collections::Generic::IList<int>^>();
	for (int day = 0; day < 7; day++){
		System::Collections::Generic::IList<int>^ dayValues = gcnew System::Collections::Generic::List<int>();
		for (int hour = 0; hour < 24; hour++)
			dayValues->Add(configuration->days[day][hour]);
		newConfiguration->Days->Add(dayValues);
	}
	
	return newConfiguration;
}

ConTime* P23::MetaTrader4::Manager::ClrWrapper::Convert(Time^ configuration)
{
	ConTime* newConfiguration = new ConTime();
	if (configuration->Days->Count != 7)
		throw gcnew ArgumentException("Invalid number of days");
	for (int day = 0; day < 7; day++){
		if (configuration->Days[day]->Count != 24)
			throw gcnew ArgumentException("Invalid number of hours");
		for (int hour = 0; hour < 24; hour++)
		{
			System::Collections::Generic::IList<int>^ intraDayValues = configuration->Days[day];
			newConfiguration->days[day][hour] = intraDayValues[hour];
		}		
	}
	return newConfiguration;
}

Backup^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConBackup* configuration)
{
	Backup^ newConfiguration = gcnew Backup();
	
	newConfiguration->ArchiveLastTime = configuration->archive_lasttime;
	newConfiguration->ArchivePeriod = configuration->archive_period;
	newConfiguration->ArchiveShift = configuration->archive_shift;
	newConfiguration->ArchiveStore = configuration->archive_store;
	newConfiguration->ExportLastTime = configuration->export_lasttime;
	newConfiguration->ExportPath = gcnew String( configuration->export_path);
	newConfiguration->ExportPeriod = configuration->export_period;
	newConfiguration->ExportSecurities = gcnew String(configuration->export_securities);
	newConfiguration->ExternalPath = gcnew String(configuration->external_path);
	newConfiguration->FullBackupLastTime = configuration->fullbackup_lasttime;
	newConfiguration->FullBackupPath = gcnew String(configuration->fullbackup_path);
	newConfiguration->FullBackupPeriod = configuration->fullbackup_period;
	newConfiguration->FullBackupShift = configuration->fullbackup_shift;
	newConfiguration->FullBackupStore = configuration->fullbackup_store;
	newConfiguration->WatchFailover = configuration->watch_failover;
	newConfiguration->WatchIp = configuration->watch_ip;
	newConfiguration->WatchLogin = configuration->watch_login;
	newConfiguration->WatchOpposite = gcnew String(configuration->watch_opposite);
	newConfiguration->WatchPassword = gcnew String(configuration->watch_password);
	newConfiguration->WatchRole = configuration->watch_role;
	newConfiguration->WatchState = configuration->watch_state;
	newConfiguration->WatchTimeout = configuration->watch_timeout;
	newConfiguration->WatchTimestamp = configuration->watch_timestamp;
	
	return newConfiguration;
}

ConBackup* P23::MetaTrader4::Manager::ClrWrapper::Convert(Backup^ configuration)
{
	ConBackup* newConfiguration = new ConBackup();

	newConfiguration->archive_lasttime = configuration->ArchiveLastTime;
	newConfiguration->archive_period = configuration->ArchivePeriod;
	newConfiguration->archive_shift = (char)configuration->ArchiveShift;
	newConfiguration->archive_store = configuration->ArchiveStore;
	newConfiguration->export_lasttime = configuration->ExportLastTime;

	char* export_path = Convert(configuration->ExportPath);
	if (export_path != NULL)
		COPY_STR(newConfiguration->export_path, export_path);
	
	newConfiguration->export_period = configuration->ExportPeriod;

	char* export_securities = Convert(configuration->ExportSecurities);
	if (export_securities != NULL)
		COPY_STR(newConfiguration->export_securities, export_securities);

	char* external_path = Convert(configuration->ExternalPath);
	if (external_path != NULL)
		COPY_STR(newConfiguration->external_path, external_path);
				
	newConfiguration->fullbackup_lasttime = configuration->FullBackupLastTime;

	char* fullbackup_path = Convert(configuration->FullBackupPath);
	if (fullbackup_path != NULL)
		COPY_STR(newConfiguration->fullbackup_path, fullbackup_path);
	
	newConfiguration->fullbackup_period = configuration->FullBackupPeriod;
	newConfiguration->fullbackup_shift = configuration->FullBackupShift;
	newConfiguration->fullbackup_store = configuration->FullBackupStore;
	newConfiguration->watch_failover = (char)configuration->WatchFailover;
	newConfiguration->watch_ip = configuration->WatchIp;
	newConfiguration->watch_login = configuration->WatchLogin;

	char* watch_opposite = Convert(configuration->WatchOpposite);
	if (watch_opposite != NULL)
		COPY_STR(newConfiguration->watch_opposite, watch_opposite);
	
	char* watch_password = Convert(configuration->WatchPassword);
	if (watch_password != NULL)
		COPY_STR(newConfiguration->watch_password, watch_password);
	
	newConfiguration->watch_role = configuration->WatchRole;
	newConfiguration->watch_state = (char)configuration->WatchState;
	newConfiguration->watch_timeout = configuration->WatchTimeout;
	newConfiguration->watch_timestamp = configuration->WatchTimestamp;

	return newConfiguration;
}

SymbolGroup^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConSymbolGroup* configuration)
{
	SymbolGroup^ newConfiguration = gcnew SymbolGroup();

	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Name = gcnew String(configuration->name);

	return newConfiguration;
}

ConSymbolGroup* P23::MetaTrader4::Manager::ClrWrapper::Convert(SymbolGroup^ configuration)
{
	ConSymbolGroup* newConfiguration = new ConSymbolGroup();
	
	char* description = Convert(configuration->Description);
	if (description != NULL)
		COPY_STR(newConfiguration->description, description);

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);
	
	return newConfiguration;
}

Access^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConAccess* configuration)
{
	Access^ newConfiguration = gcnew Access();

	newConfiguration->Action = configuration->action;
	newConfiguration->Comment = gcnew String(configuration->comment);
	newConfiguration->From = configuration->from;
	newConfiguration->To = configuration->to;
	
	return newConfiguration;
}

ConAccess* P23::MetaTrader4::Manager::ClrWrapper::Convert(Access^ configuration)
{
	ConAccess* newConfiguration = new ConAccess();

	char* comment = Convert(configuration->Comment);
	if (comment != NULL)
		COPY_STR(newConfiguration->comment, comment);

	newConfiguration->action = configuration->Action;
	newConfiguration->from = configuration->From;
	newConfiguration->to = configuration->To;

	return newConfiguration;
}

DataServer^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConDataServer* configuration)
{
	DataServer^ newConfiguration = gcnew DataServer();

	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Ip = configuration->ip;
	newConfiguration->IpInternal = configuration->ip_internal;
	newConfiguration->IsProxy = configuration->isproxy;
	newConfiguration->Loading = configuration->loading;
	newConfiguration->Priority = configuration->priority;
	newConfiguration->Server = gcnew String(configuration->server);

	return newConfiguration;
}

ConDataServer* P23::MetaTrader4::Manager::ClrWrapper::Convert(DataServer^ configuration)
{
	ConDataServer* newConfiguration = new ConDataServer();

	char* description = Convert(configuration->Description);
	if (description != NULL)
		COPY_STR(newConfiguration->description, description);

	char* server = Convert(configuration->Server);
	if (server != NULL)
		COPY_STR(newConfiguration->server, server);

	newConfiguration->ip = configuration->Ip;
	newConfiguration->ip_internal = configuration->IpInternal;
	newConfiguration->isproxy = configuration->IsProxy;
	newConfiguration->loading = configuration->Loading;
	newConfiguration->priority = configuration->Priority;

	return newConfiguration;
}

Holiday^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConHoliday* configuration)
{
	Holiday^ newConfiguration = gcnew Holiday();

	newConfiguration->Day = configuration->day;
	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Enable = configuration->enable;
	newConfiguration->From = configuration->from;
	newConfiguration->Month = configuration->month;
	newConfiguration->Symbol = gcnew String(configuration->symbol);
	newConfiguration->To = configuration->to;
	newConfiguration->Year = configuration->year;

	return newConfiguration;
}

ConHoliday* P23::MetaTrader4::Manager::ClrWrapper::Convert(Holiday^ configuration)
{
	ConHoliday* newConfiguration = new ConHoliday();

	char* description = Convert(configuration->Description);
	if (description != NULL)
		COPY_STR(newConfiguration->description, description);

	char* symbol = Convert(configuration->Symbol);
	if (symbol != NULL)
		COPY_STR(newConfiguration->symbol, symbol);

	newConfiguration->day = configuration->Day;
	newConfiguration->enable = configuration->Enable;
	newConfiguration->from = configuration->From;
	newConfiguration->month = configuration->Month;
	newConfiguration->to = configuration->To;
	newConfiguration->year = configuration->Year;

	return newConfiguration;
}

Symbol^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConSymbol* configuration)
{
	Symbol^ newConfiguration = gcnew Symbol();

	newConfiguration->AskTickValue = configuration->ask_tickvalue;
	newConfiguration->BackgroundColor = configuration->background_color;
	newConfiguration->BidTickValue = configuration->bid_tickvalue;
	newConfiguration->ContractSize = configuration->contract_size;
	newConfiguration->Count = configuration->count;
	newConfiguration->CountOriginal = configuration->count_original;
	newConfiguration->Currency = gcnew String(configuration->currency);
	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Digits = configuration->digits;
	newConfiguration->Exemode = configuration->exemode;
	newConfiguration->Expiration = configuration->expiration;
	newConfiguration->Filter = configuration->filter;
	newConfiguration->FilterCounter = configuration->filter_counter;
	newConfiguration->FilterLimit = configuration->filter_limit;
	newConfiguration->FilterSmoothing = configuration->filter_smoothing;
	newConfiguration->FreezeLevel = configuration->freeze_level;
	newConfiguration->GtcPendings = configuration->gtc_pendings;
	newConfiguration->InstantMaxVolume = configuration->instant_max_volume;
	newConfiguration->Logging = configuration->logging;
	newConfiguration->LongOnly = configuration->long_only;
	newConfiguration->MarginCurrency = gcnew String(configuration->margin_currency);
	newConfiguration->MarginDivider = configuration->margin_divider;
	newConfiguration->MarginHedged = configuration->margin_hedged;
	newConfiguration->MarginHedgedStrong = configuration->margin_hedged_strong;
	newConfiguration->MarginInitial = configuration->margin_initial;
	newConfiguration->MarginMaintenance = configuration->margin_maintenance;
	newConfiguration->MarginMode = configuration->margin_mode;
	newConfiguration->Multiply = configuration->multiply;
	newConfiguration->Name = gcnew String(configuration->symbol);
	newConfiguration->Point = configuration->point;
	newConfiguration->ProfitMode = configuration->profit_mode;
	newConfiguration->QuotesDelay = configuration->quotes_delay;
	newConfiguration->RealTime = configuration->realtime;

	for (int i = 0; i < 7; i++)
		newConfiguration->Sessions[i] = Convert(&configuration->sessions[i]);

	newConfiguration->Source = gcnew String(configuration->source);
	newConfiguration->Spread = configuration->spread;
	newConfiguration->SpreadBalance = configuration->spread_balance;
	newConfiguration->Starting = configuration->starting;
	newConfiguration->StopsLevel = configuration->stops_level;
	newConfiguration->SwapEnable = configuration->swap_enable;
	newConfiguration->SwapLong = configuration->swap_long;
	newConfiguration->SwapOpenPrice = configuration->swap_openprice;
	newConfiguration->SwapRollover3Days = configuration->swap_rollover3days;
	newConfiguration->SwapShort = configuration->swap_short;
	newConfiguration->SwapType = configuration->swap_type;
	newConfiguration->SwapVariationMargin = configuration->swap_variation_margin;
	newConfiguration->TickSize = configuration->tick_size;
	newConfiguration->TickValue = configuration->tick_value;
	newConfiguration->Trade = configuration->trade;
	newConfiguration->Type = configuration->type;
	newConfiguration->ValueDate = configuration->value_date;

	return newConfiguration;
}

ConSymbol* P23::MetaTrader4::Manager::ClrWrapper::Convert(Symbol^ configuration)
{
	if (configuration->Sessions->Count != 7)
		throw gcnew ArgumentException("Number sessions must be equal 7");

	ConSymbol* newConfiguration = new ConSymbol();

	newConfiguration->ask_tickvalue = configuration->AskTickValue;
	newConfiguration->background_color = configuration->BackgroundColor;
	newConfiguration->bid_tickvalue = configuration->BidTickValue;
	newConfiguration->contract_size = configuration->ContractSize;
	newConfiguration->count = configuration->Count;
	newConfiguration->count_original = configuration->CountOriginal;

	char* currency = Convert(configuration->Currency);
	if (currency != NULL)
		COPY_STR(newConfiguration->currency, currency);
	
	char* description = Convert(configuration->Description);
	if (description != NULL)
		COPY_STR(newConfiguration->description, description);

	newConfiguration->digits = configuration->Digits;
	newConfiguration->exemode = configuration->Exemode;
	newConfiguration->expiration = configuration->Expiration;
	newConfiguration->filter = configuration->Filter;
	newConfiguration->filter_counter = configuration->FilterCounter;
	newConfiguration->filter_limit = configuration->FilterLimit;
	newConfiguration->filter_smoothing = configuration->FilterSmoothing;
	newConfiguration->freeze_level = configuration->FreezeLevel;
	newConfiguration->gtc_pendings = configuration->GtcPendings;
	newConfiguration->instant_max_volume = configuration->InstantMaxVolume;
	newConfiguration->logging = configuration->Logging;
	newConfiguration->long_only = configuration->LongOnly;

	char* margin_currency = Convert(configuration->MarginCurrency);
	if (margin_currency != NULL)
		COPY_STR(newConfiguration->margin_currency, margin_currency);

	newConfiguration->margin_divider = configuration->MarginDivider;
	newConfiguration->margin_hedged = configuration->MarginHedged;
	newConfiguration->margin_hedged_strong = configuration->MarginHedgedStrong;
	newConfiguration->margin_initial = configuration->MarginInitial;
	newConfiguration->margin_maintenance = configuration->MarginMaintenance;
	newConfiguration->margin_mode = configuration->MarginMode;
	newConfiguration->multiply = configuration->Multiply;

	char* symbol = Convert(configuration->Name);
	if (symbol != NULL)
		COPY_STR(newConfiguration->symbol, symbol);

	newConfiguration->point = configuration->Point;
	newConfiguration->profit_mode = configuration->ProfitMode;
	newConfiguration->quotes_delay = configuration->QuotesDelay;
	newConfiguration->realtime = configuration->RealTime;

	for (int i = 0; i < 7; i++)
		newConfiguration->sessions[i] = *Convert(configuration->Sessions[i]);
		
	char* source = Convert(configuration->Source);
	if (source != NULL)
		COPY_STR(newConfiguration->source, source);

	newConfiguration->spread = configuration->Spread;
	newConfiguration->spread_balance = configuration->SpreadBalance;
	newConfiguration->starting = configuration->Starting;
	newConfiguration->stops_level = configuration->StopsLevel;
	newConfiguration->swap_enable = configuration->SwapEnable;
	newConfiguration->swap_long = configuration->SwapLong;
	newConfiguration->swap_openprice = configuration->SwapOpenPrice;
	newConfiguration->swap_rollover3days = configuration->SwapRollover3Days;
	newConfiguration->swap_short = configuration->SwapShort;
	newConfiguration->swap_type = configuration->SwapType;
	newConfiguration->swap_variation_margin = configuration->SwapVariationMargin;
	newConfiguration->tick_size = configuration->TickSize;
	newConfiguration->tick_value = configuration->TickValue;
	newConfiguration->trade = configuration->Trade;
	newConfiguration->type = configuration->Type;
	newConfiguration->value_date = configuration->ValueDate;

	return newConfiguration;
}

Sessions^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConSessions* configuration)
{
	Sessions^ newConfiguration = gcnew Sessions();
		
	for (int i = 0; i < 3; i++)
		newConfiguration->Quote[i] = Convert(&configuration->quote[i]);

	for (int i = 0; i < 3; i++)
		newConfiguration->Trade[i] = Convert(&configuration->trade[i]);

	return newConfiguration;
}

ConSessions* P23::MetaTrader4::Manager::ClrWrapper::Convert(Sessions^ configuration)
{
	ConSessions* newConfiguration = new ConSessions();

	if (configuration->Quote->Count > 3)
		throw gcnew ArgumentException("Number quote sessions exceeded 3");
	if (configuration->Trade->Count > 3)
		throw gcnew ArgumentException("Number trade sessions exceeded 3");

	for (int i = 0; i < configuration->Quote->Count; i++)
		newConfiguration->quote[i] = *Convert(configuration->Quote[i]);

	for (int i = 0; i < configuration->Trade->Count; i++)
		newConfiguration->trade[i] = *Convert(configuration->Trade[i]);

	return newConfiguration;
}

Session^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConSession* configuration)
{
	Session^ newConfiguration = gcnew Session();

	newConfiguration->CloseHour = configuration->close_hour;
	newConfiguration->CloseMin = configuration->close_min;
	newConfiguration->OpenHour = configuration->open_hour;
	newConfiguration->OpenMin = configuration->open_min;

	return newConfiguration;
}

ConSession* P23::MetaTrader4::Manager::ClrWrapper::Convert(Session^ configuration)
{
	ConSession* newConfiguration = new ConSession();

	newConfiguration->close_hour = configuration->CloseMin;
	newConfiguration->close_min = configuration->CloseMin;
	newConfiguration->open_hour = configuration->OpenHour;
	newConfiguration->open_min = configuration->OpenMin;

	return newConfiguration;
}

Group^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConGroup* configuration)
{
	Group^ newConfiguration = gcnew Group();

	newConfiguration->AdvSecurity = configuration->adv_security;
	newConfiguration->ArchiveMaxBalance = configuration->archive_max_balance;
	newConfiguration->ArchivePendingPeriod = configuration->archive_pending_period;
	newConfiguration->ArchivePeriod = configuration->archive_period;
	newConfiguration->CheckIePrices = configuration->check_ie_prices;
	newConfiguration->CloseFifo = configuration->close_fifo;
	newConfiguration->CloseReopen = configuration->close_reopen;
	newConfiguration->Company = gcnew String( configuration->company);
	newConfiguration->Copies = configuration->copies;
	newConfiguration->Credit = configuration->credit;
	newConfiguration->Currency = gcnew String(configuration->currency);
	newConfiguration->DefaultDeposit = configuration->default_deposit;
	newConfiguration->DefaultLeverage = configuration->default_leverage;
	newConfiguration->Enable = configuration->enable;
	newConfiguration->HedgeLargeLeg = configuration->hedge_largeleg;
	newConfiguration->HedgeProhibited = configuration->hedge_prohibited;
	newConfiguration->InterestRate = configuration->interestrate;
	newConfiguration->MarginCall = configuration->margin_call;
	newConfiguration->MarginMode = configuration->margin_mode;
	newConfiguration->MarginStopout = configuration->margin_stopout;
	newConfiguration->MarginType = configuration->margin_type;
	newConfiguration->MaxPositions = configuration->maxpositions;
	newConfiguration->MaxSecurities = configuration->maxsecurities;
	newConfiguration->Name = gcnew String(configuration->group);
	newConfiguration->News = configuration->news;

	newConfiguration->NewsLanguages = gcnew System::Collections::Generic::List<unsigned int>();
	for (int i = 0; i < (int)configuration->news_languages_total; i++)
		newConfiguration->NewsLanguages->Add(configuration->news_languages[i]);

	newConfiguration->Reports = configuration->reports;
	newConfiguration->Rights = configuration->rights;

	newConfiguration->SecGroups = gcnew System::Collections::Generic::List<GroupSecurity^>();
	for (int i = 0; i < MAX_SEC_GROUPS; i++)
		newConfiguration->SecGroups->Add(Convert(&configuration->secgroups[i]));

	newConfiguration->SecMargins = gcnew System::Collections::Generic::List<GroupMargin^>();
	for (int i = 0; i < MAX_SEC_GROPS_MARGIN; i++)
		newConfiguration->SecMargins->Add(Convert(&configuration->secmargins[i]));
	
	newConfiguration->SecMarginsTotal = configuration->secmargins_total;
	newConfiguration->Signature = gcnew String(configuration->signature);
	newConfiguration->SmtpLogin = gcnew String(configuration->smtp_login);
	newConfiguration->SmtpPassword = gcnew String(configuration->smtp_password);
	newConfiguration->SmtpServer = gcnew String(configuration->smtp_server);
	newConfiguration->StopOutSkipHedged = configuration->stopout_skip_hedged;
	newConfiguration->SupportEmail = gcnew String(configuration->support_email);
	newConfiguration->SupportPage = gcnew String(configuration->support_page);
	newConfiguration->Templates = gcnew String(configuration->templates);
	newConfiguration->Timeout = configuration->timeout;
	newConfiguration->UseSwap = configuration->use_swap;

	return newConfiguration;
}

ConGroup* P23::MetaTrader4::Manager::ClrWrapper::Convert(Group^ configuration)
{
	if (configuration->NewsLanguages->Count > 8)
		throw gcnew ArgumentException("Maximum allowed count of news languages: 8");
	if (configuration->SecGroups->Count > MAX_SEC_GROUPS)
		throw gcnew ArgumentException("Exceeded maximum number of allowed security groups");
	if (configuration->SecMargins->Count > MAX_SEC_GROPS_MARGIN)
		throw gcnew ArgumentException("Exceeded maximum number of allowed security group margins");

	ConGroup* newConfiguration = new ConGroup();

	newConfiguration->adv_security = configuration->AdvSecurity;
	newConfiguration->archive_max_balance = configuration->ArchiveMaxBalance;
	newConfiguration->archive_pending_period = configuration->ArchivePendingPeriod;
	newConfiguration->archive_period = configuration->ArchivePeriod;
	newConfiguration->check_ie_prices = configuration->CheckIePrices;
	newConfiguration->close_fifo = configuration->CloseFifo;
	newConfiguration->close_reopen = configuration->CloseReopen;

	char* company = Convert(configuration->Company);
	if (company != NULL)
		COPY_STR(newConfiguration->company, company);

	newConfiguration->copies = configuration->Copies;
	newConfiguration->credit = configuration->Credit;

	char* currency = Convert(configuration->Currency);
	if (currency != NULL)
		COPY_STR(newConfiguration->currency, currency);

	newConfiguration->default_deposit = configuration->DefaultDeposit;
	newConfiguration->default_leverage = configuration->DefaultLeverage;
	newConfiguration->enable = configuration->Enable;
	newConfiguration->hedge_largeleg = configuration->HedgeLargeLeg;
	newConfiguration->hedge_prohibited = configuration->HedgeProhibited;
	newConfiguration->interestrate = configuration->InterestRate;
	newConfiguration->margin_call = configuration->MarginCall;
	newConfiguration->margin_mode = configuration->MarginMode;
	newConfiguration->margin_stopout = configuration->MarginStopout;
	newConfiguration->margin_type = configuration->MarginType;
	newConfiguration->maxpositions = configuration->MaxPositions;
	newConfiguration->maxsecurities = configuration->MaxSecurities;

	char* group = Convert(configuration->Name);
	if (group != NULL)
		COPY_STR(newConfiguration->group, group);

	newConfiguration->news = configuration->News;
		
	for (int i = 0; i < configuration->NewsLanguages->Count; i++)
		newConfiguration->news_languages[i] = configuration->NewsLanguages[i];

	newConfiguration->news_languages_total = configuration->NewsLanguages->Count;
	newConfiguration->reports = configuration->Reports;
	newConfiguration->rights = configuration->Rights;
		
	for (int i = 0; i < configuration->NewsLanguages->Count; i++)
		newConfiguration->secgroups[i] = *Convert(configuration->SecGroups[i]);
		
	for (int i = 0; i < configuration->NewsLanguages->Count; i++)
		newConfiguration->secmargins[i] = *Convert(configuration->SecMargins[i]);

	newConfiguration->secmargins_total = configuration->SecMarginsTotal;

	char* signature = Convert(configuration->Signature);
	if (signature != NULL)
		COPY_STR(newConfiguration->signature, signature);

	char* smtp_login = Convert(configuration->SmtpLogin);
	if (smtp_login != NULL)
		COPY_STR(newConfiguration->smtp_login, smtp_login);

	char* smtp_password = Convert(configuration->SmtpPassword);
	if (smtp_password != NULL)
		COPY_STR(newConfiguration->smtp_password, smtp_password);

	char* smtp_server = Convert(configuration->SmtpServer);
	if (smtp_server != NULL)
		COPY_STR(newConfiguration->smtp_server, smtp_server);
	
	newConfiguration->stopout_skip_hedged = configuration->StopOutSkipHedged;

	char* support_email = Convert(configuration->SupportEmail);
	if (support_email != NULL)
		COPY_STR(newConfiguration->support_email, support_email);

	char* support_page = Convert(configuration->SupportPage);
	if (support_page != NULL)
		COPY_STR(newConfiguration->support_page, support_page);

	char* templates = Convert(configuration->Templates);
	if (templates != NULL)
		COPY_STR(newConfiguration->templates, templates);
	
	newConfiguration->timeout = configuration->Timeout;
	newConfiguration->use_swap = configuration->UseSwap;

	return newConfiguration;
}

GroupSecurity^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConGroupSec* configuration)
{
	GroupSecurity^ newConfiguration = gcnew GroupSecurity();

	newConfiguration->AutoCloseOutMode = configuration->autocloseout_mode;
	newConfiguration->CommAgent = configuration->comm_agent;
	newConfiguration->CommAgentLots = configuration->comm_agent_lots;
	newConfiguration->CommAgentType = configuration->comm_agent_type;
	newConfiguration->CommBase = configuration->comm_base;
	newConfiguration->CommLots = configuration->comm_lots;
	newConfiguration->CommTax = configuration->comm_tax;
	newConfiguration->CommType = configuration->comm_type;
	newConfiguration->Confirmation = configuration->confirmation;
	newConfiguration->Execution = configuration->execution;
	newConfiguration->FreeMarginMode = configuration->freemargin_mode;
	newConfiguration->IeDeviation = configuration->ie_deviation;
	newConfiguration->IeQuickMode = configuration->ie_quick_mode;
	newConfiguration->LotMax = configuration->lot_max;
	newConfiguration->LotMin = configuration->lot_min;
	newConfiguration->LotStep = configuration->lot_step;
	newConfiguration->Show = configuration->show;
	newConfiguration->SpreadDiff = configuration->spread_diff;
	newConfiguration->Trade = configuration->trade;
	newConfiguration->TradeRights = configuration->trade_rights;

	return newConfiguration;
} 

ConGroupSec* P23::MetaTrader4::Manager::ClrWrapper::Convert(GroupSecurity^ configuration)
{
	ConGroupSec* newConfiguration = new ConGroupSec();

	newConfiguration->autocloseout_mode = configuration->AutoCloseOutMode;
	newConfiguration->comm_agent = configuration->CommAgent;
	newConfiguration->comm_agent_lots = configuration->CommAgentLots;
	newConfiguration->comm_agent_type = configuration->CommAgentType;
	newConfiguration->comm_base = configuration->CommBase;
	newConfiguration->comm_lots = configuration->CommLots;
	newConfiguration->comm_tax = configuration->CommTax;
	newConfiguration->comm_type = configuration->CommType;
	newConfiguration->confirmation = configuration->Confirmation;
	newConfiguration->execution = configuration->Execution;
	newConfiguration->freemargin_mode = configuration->FreeMarginMode;
	newConfiguration->ie_deviation = configuration->IeDeviation;
	newConfiguration->ie_quick_mode = configuration->IeQuickMode;
	newConfiguration->lot_max = configuration->LotMax;
	newConfiguration->lot_min = configuration->LotMin;
	newConfiguration->lot_step = configuration->LotStep;
	newConfiguration->show = configuration->Show;
	newConfiguration->spread_diff = configuration->SpreadDiff;
	newConfiguration->trade = configuration->Trade;
	newConfiguration->trade_rights = configuration->TradeRights;
	
	return newConfiguration;
}

GroupMargin^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConGroupMargin* configuration)
{
	GroupMargin^ newConfiguration = gcnew GroupMargin();

	newConfiguration->MarginDivider = configuration->margin_divider;
	newConfiguration->SwapLong = configuration->swap_long;
	newConfiguration->SwapShort = configuration->swap_short;
	newConfiguration->Symbol = gcnew String(configuration->symbol);

	return newConfiguration;
}

ConGroupMargin* P23::MetaTrader4::Manager::ClrWrapper::Convert(GroupMargin^ configuration)
{
	ConGroupMargin* newConfiguration = new ConGroupMargin();

	newConfiguration->margin_divider = configuration->MarginDivider;
	newConfiguration->swap_long = configuration->SwapLong;
	newConfiguration->swap_short = configuration->SwapShort;

	char* symbol = Convert(configuration->Symbol);
	if (symbol != NULL)
		COPY_STR(newConfiguration->symbol, symbol);

	return newConfiguration;
}

Feeder^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConFeeder* configuration)
{
	Feeder^ newConfiguration = gcnew Feeder();

	newConfiguration->AttempsSleep = configuration->attemps_sleep;
	newConfiguration->Enable = configuration->enable;
	newConfiguration->File = gcnew String(configuration->file);
	newConfiguration->Keywords = gcnew String(configuration->keywords);
	newConfiguration->Login = gcnew String(configuration->login);
	newConfiguration->Mode = configuration->mode;
	newConfiguration->Name = gcnew String(configuration->name);
	newConfiguration->NewsLangId = configuration->news_langid;
	newConfiguration->Pass = gcnew String(configuration->pass);
	newConfiguration->Server = gcnew String(configuration->server);
	newConfiguration->TimeoutReconnect = configuration->timeout_reconnect;
	newConfiguration->Timeout = configuration->timeout;
	newConfiguration->TimeoutSleep = configuration->timeout_sleep;	

	return newConfiguration;
}

ConFeeder* P23::MetaTrader4::Manager::ClrWrapper::Convert(Feeder^ configuration)
{
	ConFeeder* newConfiguration = new ConFeeder();

	newConfiguration->attemps_sleep = configuration->AttempsSleep;
	newConfiguration->enable = configuration->Enable;

	char* file = Convert(configuration->File);
	if (file != NULL)
		COPY_STR(newConfiguration->file, file);

	char* keywords = Convert(configuration->Keywords);
	if (keywords != NULL)
		COPY_STR(newConfiguration->keywords, keywords);

	char* login = Convert(configuration->Login);
	if (login != NULL)
		COPY_STR(newConfiguration->login, login);

	newConfiguration->mode = configuration->Mode;

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);

	newConfiguration->news_langid = configuration->NewsLangId;

	char* pass = Convert(configuration->Pass);
	if (pass != NULL)
		COPY_STR(newConfiguration->pass, pass);

	char* server = Convert(configuration->Server);
	if (server != NULL)
		COPY_STR(newConfiguration->server, server);

	newConfiguration->timeout_reconnect = configuration->TimeoutReconnect;
	newConfiguration->timeout = configuration->Timeout;
	newConfiguration->timeout_sleep = configuration->TimeoutSleep;
	
	return newConfiguration;
}

LiveUpdate^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConLiveUpdate* configuration)
{
	LiveUpdate^ newConfiguration = gcnew LiveUpdate();

	newConfiguration->Build = configuration->build;
	newConfiguration->Company = gcnew String(configuration->company);
	newConfiguration->Connections = configuration->connections;
	newConfiguration->Enable = configuration->enable;

	newConfiguration->Files = gcnew System::Collections::Generic::List<FilesConfigurations^>();
	for (int i = 0; i < configuration->totalfiles; i++)
		newConfiguration->Files->Add(Convert(&configuration->files[i]));

	newConfiguration->MaxConnect = configuration->maxconnect;
	newConfiguration->Path = gcnew String(configuration->path);
	newConfiguration->Type = configuration->type;
	newConfiguration->Version = configuration->version;

	return newConfiguration;
}

ConLiveUpdate* P23::MetaTrader4::Manager::ClrWrapper::Convert(LiveUpdate^ configuration)
{
	ConLiveUpdate* newConfiguration = new ConLiveUpdate();

	newConfiguration->build = configuration->Build;

	char* company = Convert(configuration->Company);
	if (company != NULL)
		COPY_STR(newConfiguration->company, company);

	newConfiguration->connections = configuration->Connections;
	newConfiguration->enable = configuration->Enable;
		
	for (int i = 0; i < configuration->Files->Count; i++)
		newConfiguration->files[i] = *Convert(configuration->Files[i]);

	newConfiguration->maxconnect = configuration->MaxConnect;

	char* path = Convert(configuration->Path);
	if (path != NULL)
		COPY_STR(newConfiguration->path, path);

	newConfiguration->totalfiles = configuration->Files->Count;
	newConfiguration->type = configuration->Type;
	newConfiguration->version = configuration->Version;

	

	return newConfiguration;
}

Synchronization^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConSync* configuration)
{
	Synchronization^ newConfiguration = gcnew Synchronization();

	newConfiguration->Enable = configuration->enable;
	newConfiguration->From = configuration->from;
	newConfiguration->Login = gcnew String(configuration->login);
	newConfiguration->Mode = configuration->mode;
	newConfiguration->Password = gcnew String(configuration->password);
	newConfiguration->Securities = gcnew String(configuration->securities);
	newConfiguration->Server = gcnew String(configuration->server);
	newConfiguration->To = configuration->to;
	newConfiguration->UnusedPort = configuration->unusedport;

	return newConfiguration;
}

ConSync* P23::MetaTrader4::Manager::ClrWrapper::Convert(Synchronization^ configuration)
{
	ConSync* newConfiguration = new ConSync();

	newConfiguration->enable = configuration->Enable;
	newConfiguration->from = configuration->From;

	char* login = Convert(configuration->Login);
	if (login != NULL)
		COPY_STR(newConfiguration->login, login);

	newConfiguration->mode = configuration->Mode;

	char* password = Convert(configuration->Password);
	if (password != NULL)
		COPY_STR(newConfiguration->password, password);

	char* securities = Convert(configuration->Securities);
	if (securities != NULL)
		COPY_STR(newConfiguration->securities, securities);

	char* server = Convert(configuration->Server);
	if (server != NULL)
		COPY_STR(newConfiguration->server, server);

	newConfiguration->to = configuration->To;
	newConfiguration->unusedport = configuration->UnusedPort;	

	return newConfiguration;
}

FilesConfigurations^ P23::MetaTrader4::Manager::ClrWrapper::Convert(LiveInfoFile* configuration)
{
	FilesConfigurations^ newConfiguration = gcnew FilesConfigurations();

	newConfiguration->File = gcnew String(configuration->file);
	newConfiguration->Hash = gcnew String(configuration->hash);
	newConfiguration->Size = configuration->size;

	return newConfiguration;
}

LiveInfoFile* P23::MetaTrader4::Manager::ClrWrapper::Convert(FilesConfigurations^ configuration)
{
	LiveInfoFile* newConfiguration = new LiveInfoFile();

	char* file = Convert(configuration->File);
	if (file != NULL)
		COPY_STR(newConfiguration->file, file);

	char* hash = Convert(configuration->Hash);
	if (hash != NULL)
		COPY_STR(newConfiguration->hash, hash);

	newConfiguration->size = configuration->Size;
	
	return newConfiguration;
}

PluginWithParameters^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConPluginParam* configuration)
{
	PluginWithParameters^ newConfiguration = gcnew PluginWithParameters();
		
	newConfiguration->Parameters = gcnew System::Collections::Generic::List<PluginConfigurationParameter^>();
	for (int i = 0; i < configuration->total; i++)
		newConfiguration->Parameters->Add(Convert(&UnmanagedHelpers::GetPluginParameters(configuration, i)));
	
	newConfiguration->Plugin = Convert(&configuration->plugin);

	return newConfiguration;
}

ConPluginParam* P23::MetaTrader4::Manager::ClrWrapper::Convert(PluginWithParameters^ configuration)
{
	ConPluginParam* newConfiguration = new ConPluginParam();
		
	newConfiguration->plugin = *Convert(configuration->Plugin);
	newConfiguration->total = configuration->Parameters->Count;

	for (int i = 0; i < configuration->Parameters->Count; i++)
	{
		UnmanagedHelpers::AssignPluginParameters(newConfiguration, *Convert(configuration->Parameters[i]), i);		
	}

	return newConfiguration;
}

Plugin^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConPlugin* configuration)
{
	Plugin^ newConfiguration = gcnew Plugin();

	newConfiguration->Configurable = configuration->configurable;
	newConfiguration->Enabled = configuration->enabled;
	newConfiguration->File = gcnew String(configuration->file);
	newConfiguration->ManagerAccess = configuration->manager_access;
	newConfiguration->Info = Convert(&configuration->info);

	return newConfiguration;
}

ConPlugin* P23::MetaTrader4::Manager::ClrWrapper::Convert(Plugin^ configuration)
{
	ConPlugin* newConfiguration = new ConPlugin();

	
	newConfiguration->configurable = configuration->Configurable;
	newConfiguration->enabled = configuration->Enabled;

	char* file = Convert(configuration->File);
	if (file != NULL)
		COPY_STR(newConfiguration->file, file);

	newConfiguration->manager_access = configuration->ManagerAccess;
	newConfiguration->info = *Convert(configuration->Info);

	return newConfiguration;
}

PluginInformation^ P23::MetaTrader4::Manager::ClrWrapper::Convert(PluginInfo* configuration)
{
	PluginInformation^ newConfiguration = gcnew PluginInformation();

	newConfiguration->Copyright = gcnew String(configuration->copyright);
	newConfiguration->Name = gcnew String(configuration->name);
	newConfiguration->Version = configuration->version;

	return newConfiguration;
}

PluginInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(PluginInformation^ configuration)
{
	PluginInfo* newConfiguration = new PluginInfo();
	
	char* copyright = Convert(configuration->Copyright);
	if (copyright != NULL)
		COPY_STR(newConfiguration->copyright, copyright);

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);

	newConfiguration->version = configuration->Version;

	return newConfiguration;
}

PluginConfigurationParameter^ P23::MetaTrader4::Manager::ClrWrapper::Convert(PluginCfg* configuration)
{
	PluginConfigurationParameter^ newConfiguration = gcnew PluginConfigurationParameter();

	newConfiguration->Name = gcnew String(configuration->name);
	newConfiguration->Value = gcnew String(configuration->value);

	return newConfiguration;
}

PluginCfg* P23::MetaTrader4::Manager::ClrWrapper::Convert(PluginConfigurationParameter^ configuration)
{
	PluginCfg* newConfiguration = new PluginCfg();
		
	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);

	char* value = Convert(configuration->Value);
	if (value != NULL)
		COPY_STR(newConfiguration->value, value);

	return newConfiguration;
}

P23::MetaTrader4::Manager::Contracts::ServerFeed^  P23::MetaTrader4::Manager::ClrWrapper::Convert(ServerFeed* configuration)
{
	P23::MetaTrader4::Manager::Contracts::ServerFeed^ newConfiguration = gcnew P23::MetaTrader4::Manager::Contracts::ServerFeed();

	newConfiguration->File = gcnew String(configuration->file);
	newConfiguration->Feed = Convert(&configuration->feed);

	return newConfiguration;
}

P23::MetaTrader4::Manager::Contracts::FeedDescription^  P23::MetaTrader4::Manager::ClrWrapper::Convert(FeedDescription* configuration)
{
	P23::MetaTrader4::Manager::Contracts::FeedDescription^ newConfiguration = gcnew P23::MetaTrader4::Manager::Contracts::FeedDescription();

	newConfiguration->Copyright = gcnew String(configuration->copyright);
	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Email = gcnew String(configuration->email);
	newConfiguration->Modes = configuration->modes;
	newConfiguration->Module = gcnew String(configuration->module);
	newConfiguration->Name = gcnew String(configuration->name);
	newConfiguration->Server = gcnew String(configuration->server);
	newConfiguration->UserName = gcnew String(configuration->username);
	newConfiguration->UserPass = gcnew String(configuration->userpass);
	newConfiguration->Version = configuration->version;
	newConfiguration->Web = gcnew String(configuration->web);

	return newConfiguration;
}

P23::MetaTrader4::Manager::Contracts::PerformanceInfo^  P23::MetaTrader4::Manager::ClrWrapper::Convert(PerformanceInfo* configuration)
{
	P23::MetaTrader4::Manager::Contracts::PerformanceInfo^ newConfiguration = gcnew P23::MetaTrader4::Manager::Contracts::PerformanceInfo();

	newConfiguration->Cpu = configuration->cpu;
	newConfiguration->Ctm = configuration->ctm;
	newConfiguration->FreeMem = configuration->freemem;
	newConfiguration->Network = configuration->network;
	newConfiguration->Sockets = configuration->sockets;
	newConfiguration->Users = configuration->users;

	return newConfiguration;
}

P23::MetaTrader4::Manager::Contracts::BackupInfo^  P23::MetaTrader4::Manager::ClrWrapper::Convert(BackupInfo* input)
{
	P23::MetaTrader4::Manager::Contracts::BackupInfo^ output = gcnew P23::MetaTrader4::Manager::Contracts::BackupInfo();

	output->File = gcnew String(input->file);
	output->Size = input->size;
	output->Time = input->time;
	
	return output;
}

P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^  P23::MetaTrader4::Manager::ClrWrapper::Convert(TradeRestoreResult* input)
{
	P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^ output = gcnew P23::MetaTrader4::Manager::Contracts::TradeRestoreResult();

	output->Order = input->order;
	output->Res = input->res;

	return output;
}

P23::MetaTrader4::Manager::Contracts::UserRecord^  P23::MetaTrader4::Manager::ClrWrapper::Convert(UserRecord* input)
{
	P23::MetaTrader4::Manager::Contracts::UserRecord^ output = gcnew P23::MetaTrader4::Manager::Contracts::UserRecord();

	output->Address = gcnew String(input->address);
	output->AgentAccount = input->agent_account;
	output->Balance = input->balance;
	output->City = gcnew String(input->city);
	output->Comment = gcnew String(input->comment);
	output->Country = gcnew String(input->country);
	output->Credit = input->credit;
	output->Email = gcnew String(input->email);
	output->Enable = input->enable;
	output->EnableChangePassword = input->enable_change_password;
	output->EnableReadOnly = input->enable_read_only;
	output->Group = gcnew String(input->group);
	output->Id = gcnew String(input->id);
	output->InterestRate = input->interestrate;
	output->LastDate = input->lastdate;
	output->LastIp = input->last_ip;
	output->Leverage = input->leverage;
	output->Login = input->login;
	output->Mqid = input->mqid;
	output->Name = gcnew String(input->name);
	output->Password = gcnew String(input->password);
	output->PasswordInvestor = gcnew String(input->password_investor);
	output->PasswordPhone = gcnew String(input->password_phone);
	output->Phone = gcnew String(input->phone);
	output->PrevBalance = input->prevbalance;
	output->PrevEquity = input->prevequity;
	output->PrevMonthBalance = input->prevmonthbalance;
	output->PrevMonthEquity = input->prevmonthequity;
	output->PublicKey = gcnew String(input->publickey);
	output->Regdate = input->regdate;
	output->SendReports = input->send_reports;
	output->State = gcnew String(input->state);
	output->Status = gcnew String(input->status);
	output->Timestamp = input->timestamp;
	output->Taxes = input->taxes;
	output->UserColor = input->user_color;
	output->ZipCode = gcnew String(input->zipcode);

	return output;
}

UserRecord*  P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::UserRecord^ input)
{
	UserRecord* output = new UserRecord();

	char* address = Convert(input->Address);
	if (address != NULL)
		COPY_STR(output->address, address);

	output->agent_account = input->AgentAccount;
	output->balance = input->Balance;

	char* city = Convert(input->City);
	if (city != NULL)
		COPY_STR(output->city, city);

	char* comment = Convert(input->Comment);
	if (comment != NULL)
		COPY_STR(output->comment, comment);

	char* country = Convert(input->Country);
	if (country != NULL)
		COPY_STR(output->country, country);

	output->credit = input->Credit;

	char* email = Convert(input->Email);
	if (email != NULL)
		COPY_STR(output->email, email);

	output->enable = input->Enable;
	output->enable_change_password = input->EnableChangePassword;
	output->enable_read_only = input->EnableReadOnly;

	char* group = Convert(input->Group);
	if (group != NULL)
		COPY_STR(output->group, group);

	char* id = Convert(input->Id);
	if (id != NULL)
		COPY_STR(output->id, id);

	output->interestrate = input->InterestRate;
	output->lastdate = input->LastDate;
	output->last_ip = input->LastIp;
	output->leverage = input->Leverage;
	output->login = input->Login;
	output->mqid = input->Mqid;

	char* name = Convert(input->Name);
	if (name != NULL)
		COPY_STR(output->name, name);

	char* password = Convert(input->Password);
	if (password != NULL)
		COPY_STR(output->password, password);

	char* password_investor = Convert(input->PasswordInvestor);
	if (password_investor != NULL)
		COPY_STR(output->password_investor, password_investor);

	char* password_phone = Convert(input->PasswordPhone);
	if (password_phone != NULL)
		COPY_STR(output->password_phone, password_phone);

	char* phone = Convert(input->Phone);
	if (phone != NULL)
		COPY_STR(output->phone, phone);

	output->prevbalance = input->PrevBalance;
	output->prevequity = input->PrevEquity;
	output->prevmonthbalance = input->PrevMonthBalance;
	output->prevmonthequity = input->PrevMonthEquity;

	char* publickey = Convert(input->PublicKey);
	if (publickey != NULL)
		COPY_STR(output->publickey, publickey);

	output->regdate = input->Regdate;
	output->send_reports = input->SendReports;

	char* state = Convert(input->State);
	if (state != NULL)
		COPY_STR(output->state, state);

	char* status = Convert(input->Status);
	if (status != NULL)
		COPY_STR(output->status, status);

	output->timestamp = input->Timestamp;
	output->taxes = input->Taxes;
	output->user_color = input->UserColor;

	char* zipcode = Convert(input->ZipCode);
	if (zipcode != NULL)
		COPY_STR(output->zipcode, zipcode);

	return output;
}

P23::MetaTrader4::Manager::Contracts::TradeRecord^  P23::MetaTrader4::Manager::ClrWrapper::Convert(TradeRecord* input)
{
	P23::MetaTrader4::Manager::Contracts::TradeRecord^ output = gcnew P23::MetaTrader4::Manager::Contracts::TradeRecord();

	output->Activation = input->activation;
	output->ClosePrice = input->close_price;
	output->CloseTime = input->close_time;
	output->Cmd = input->cmd;
	output->Comment = gcnew String( input->comment);
	output->Commission = input->commission;
	output->CommissionAgent = input->commission_agent;
	
	output->ConvRates = gcnew List<double>();
	output->ConvRates->Add(input->conv_rates[0]);
	output->ConvRates->Add(input->conv_rates[1]);

	output->Digits = input->digits;
	output->Expiration = input->expiration;
	output->GwClosePrice = input->gw_close_price;
	output->GwOpenPrice = input->gw_open_price;
	output->GwOrder = input->gw_order;
	output->GwVolume = input->gw_volume;
	output->Login = input->login;
	output->Magic = input->magic;
	output->OpenPrice = input->open_price;
	output->OpenTime = input->open_time;
	output->Order = input->order;
	output->Profit = input->profit;
	output->Reason = input->reason;
	output->Sl = input->sl;
	output->State = input->state;
	output->Storage = input->storage;
	output->Symbol = gcnew String(input->symbol);
	output->Taxes = input->taxes;
	output->Timestamp = input->timestamp;
	output->Tp = input->tp;
	output->Volume = input->volume;

	return output;
}

TradeRecord*  P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::TradeRecord^ input)
{
	TradeRecord* output = new TradeRecord();
	
	output->activation = input->Activation;
	output->close_price = input->ClosePrice;
	output->close_time = input->CloseTime;
	output->cmd = input->Cmd;

	char* comment = Convert(input->Comment);
	if (comment != NULL)
		COPY_STR(output->comment, comment);
	
	output->commission = input->Commission;
	output->commission_agent = input->CommissionAgent;

	output->conv_rates[0] = input->CommissionAgent;
	output->conv_rates[1] = input->CommissionAgent;

	output->digits = input->Digits;
	output->expiration = input->Expiration;
	output->gw_close_price = input->GwClosePrice;
	output->gw_open_price = input->GwOpenPrice;
	output->gw_order = input->GwOrder;
	output->gw_volume = input->GwVolume;
	output->login = input->Login;
	output->magic = input->Magic;
	output->open_price = input->OpenPrice;
	output->open_time = input->OpenTime;
	output->order = input->Order;
	output->profit = input->Profit;
	output->reason = (char)input->Reason;
	output->sl = input->Sl;
	output->state = input->State;
	output->storage = input->Storage;

	char* symbol = Convert(input->Symbol);
	if (symbol != NULL)
		COPY_STR(output->symbol, symbol);

	output->taxes = input->Taxes;
	output->timestamp = input->Timestamp;
	output->tp = input->Tp;
	output->volume = input->Volume;

	return output;
}

P23::MetaTrader4::Manager::Contracts::SymbolInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(SymbolInfo* input)
{
	P23::MetaTrader4::Manager::Contracts::SymbolInfo^ output = gcnew P23::MetaTrader4::Manager::Contracts::SymbolInfo();
	
	output->Ask = input->ask;
	output->Bid = input->bid;
	output->Commission = input->commission;
	output->CommType = input->comm_type;
	output->Count = input->count;
	output->Digits = input->digits;
	output->Direction = input->direction;
	output->High = input->high;
	output->LastTime = input->lasttime;
	output->Low = input->low;
	output->Point = input->point;
	output->Spread = input->spread;
	output->SpreadBalance = input->spread_balance;
	output->Symbol = gcnew String(input->symbol);
	output->Type = input->type;
	output->UpdateFlag = input->updateflag;
	output->Visible = input->visible;

	return output;
}

P23::MetaTrader4::Manager::Contracts::MailBox^ P23::MetaTrader4::Manager::ClrWrapper::Convert(MailBox* input)
{
	P23::MetaTrader4::Manager::Contracts::MailBox^ output = gcnew P23::MetaTrader4::Manager::Contracts::MailBox();

	output->Body = gcnew String(UnmanagedHelpers::GetMailBody(input));
	output->BodyLen = input->bodylen;
	output->BuildMax = input->build_max;
	output->BuildMin = input->build_min;
	output->From = gcnew String(input->from);
	output->Readed = input->readed;
	output->Sender = input->sender;
	output->Subject = gcnew String(input->subject);
	output->Time = input->time;
	output->To = input->to;
	
	return output;
}

MailBox* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::MailBox^ input)
{
	MailBox* output = new MailBox();
	
	UnmanagedHelpers::SetMailBody(output, Convert(input->Body));
	
	output->bodylen = input->BodyLen;
	output->build_max = input->BuildMax;
	output->build_min = input->BuildMin;

	char* from = Convert(input->From);
	if (from != NULL)
		COPY_STR(output->from, from);

	output->readed = input->Readed;
	output->sender = input->Sender;

	char* subject = Convert(input->Subject);
	if (subject != NULL)
		COPY_STR(output->subject, subject);

	output->time = input->Time;
	output->to = input->To;

	return output;
}

P23::MetaTrader4::Manager::Contracts::NewsTopic^ P23::MetaTrader4::Manager::ClrWrapper::Convert(NewsTopic* input)
{
	P23::MetaTrader4::Manager::Contracts::NewsTopic^ output = gcnew P23::MetaTrader4::Manager::Contracts::NewsTopic();

	output->Body = gcnew String(UnmanagedHelpers::GetNewsBody(input));
	output->BodyLen = input->bodylen;
	output->Category = gcnew String(input->category);
	output->Ctm = gcnew String(input->ctm);
	output->Key = input->key;
	output->Keywords = gcnew String(input->keywords);
	output->LangId = input->langid;
	output->Priority = input->priority;
	output->Readed = input->readed;
	output->Time = input->time;
	output->Topic = gcnew String(input->topic);

	return output;
}

NewsTopic* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::NewsTopic^ input)
{
	NewsTopic* output = new NewsTopic();
	
	UnmanagedHelpers::SetNewsBody(output, Convert(input->Body));
	
	output->bodylen = input->BodyLen;

	char* category = Convert(input->Category);
	if (category != NULL)
		COPY_STR(output->category, category);

	char* ctm = Convert(input->Ctm);
	if (ctm != NULL)
		COPY_STR(output->ctm, ctm);

	output->key = input->Key;

	char* keywords = Convert(input->Keywords);
	if (keywords != NULL)
		COPY_STR(output->keywords, keywords);

	output->langid = input->LangId;
	output->priority = input->Priority;
	output->readed = input->Readed;
	output->time = input->Time;

	char* topic = Convert(input->Topic);
	if (topic != NULL)
		COPY_STR(output->topic, topic);

	return output;
}

P23::MetaTrader4::Manager::Contracts::ServerLog^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ServerLog* input)
{
	P23::MetaTrader4::Manager::Contracts::ServerLog^ output = gcnew P23::MetaTrader4::Manager::Contracts::ServerLog();

	output->Code = input->code;
	output->Ip = gcnew String(input->ip);
	output->Message = gcnew String(input->message);
	output->Time = gcnew String(input->time);

	return output;
}

TradeTransInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ input)
{
	TradeTransInfo* output = new TradeTransInfo();
		
	output->cmd = input->Cmd;

	char* comment = Convert(input->Comment);
	if (comment != NULL)
		COPY_STR(output->comment, comment);

	output->crc = input->Crc;
	output->expiration = input->Expiration;
	output->ie_deviation = input->IeDeviation;
	output->order = input->Order;
	output->orderby = input->OrderBy;
	output->price = input->Price;
	output->sl = input->Sl;

	char* symbol = Convert(input->Symbol);
	if (symbol != NULL)
		COPY_STR(output->symbol, symbol);

	output->tp = input->Tp;
	output->type = input->Type;
	output->volume = input->Volume;

	return output;
}
P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(TradeTransInfo* input)
{
	P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ output = gcnew P23::MetaTrader4::Manager::Contracts::TradeTransInfo();

	output->Cmd = input->cmd;	
	output->Comment = gcnew String(input->comment);
	output->Crc = input->crc;
	output->Expiration = input->expiration;
	output->IeDeviation = input->ie_deviation;
	output->Order = input->order;
	output->OrderBy = input->orderby;
	output->Price = input->price;
	output->Sl = input->sl;
	output->Symbol = gcnew String(input->symbol);
	output->Tp = input->tp;
	output->Type = input->type;
	output->Volume = input->volume;

	return output;
}

GroupCommandInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::GroupCommandInfo^ input)
{
	GroupCommandInfo* output = new GroupCommandInfo();	

	output->command = (char)input->Command;
	output->len = input->Len;
	output->leverage = input->Leverage;

	char* newgroup = Convert(input->NewGroup);
	if (newgroup != NULL)
		COPY_STR(output->newgroup, newgroup);

	return output;
}

P23::MetaTrader4::Manager::Contracts::OnlineRecord^ P23::MetaTrader4::Manager::ClrWrapper::Convert(OnlineRecord* input)
{
	P23::MetaTrader4::Manager::Contracts::OnlineRecord^ output = gcnew P23::MetaTrader4::Manager::Contracts::OnlineRecord();
	
	output->Counter = input->counter;
	output->Group = gcnew String(input->group);
	output->Ip = input->ip;
	output->Login = input->login;
	
	return output;
}

P23::MetaTrader4::Manager::Contracts::DailyReport^ P23::MetaTrader4::Manager::ClrWrapper::Convert(DailyReport* input)
{
	P23::MetaTrader4::Manager::Contracts::DailyReport^ output = gcnew P23::MetaTrader4::Manager::Contracts::DailyReport();

	output->Balance = input->balance;
	output->BalancePrev = input->balance_prev;
	output->Bank = gcnew String(input->bank);
	output->Credit = input->credit;
	output->Ctm = input->ctm;
	output->Deposit = input->deposit;
	output->Equity = input->equity;
	output->Group = gcnew String(input->group);
	output->Login = input->login;
	output->Margin = input->margin;
	output->MarginFree = input->margin_free;
	output->Profit = input->profit;
	output->ProfitClosed = input->profit_closed;

	return output;
}

ReportGroupRequest* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::ReportGroupRequest^ input)
{
	if (System::String::IsNullOrEmpty(input->Name))
		throw gcnew ArgumentNullException("Name");

	ReportGroupRequest* output = new ReportGroupRequest();
		
	output->from = input->From;

	char* name = Convert(input->Name);
	if (name != NULL)
		COPY_STR(output->name, name);
	
	output->to = input->To;

	return output;
}

DailyGroupRequest* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::DailyGroupRequest^ input)
{
	if (System::String::IsNullOrEmpty(input->Name))
		throw gcnew ArgumentNullException("Name");

	DailyGroupRequest* output = new DailyGroupRequest();

	output->from = input->From;

	char* name = Convert(input->Name);
	if (name != NULL)
		COPY_STR(output->name, name);

	output->to = input->To;
	
	return output;
}

P23::MetaTrader4::Manager::Contracts::RequestInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(RequestInfo* input)
{
	P23::MetaTrader4::Manager::Contracts::RequestInfo^ output = gcnew P23::MetaTrader4::Manager::Contracts::RequestInfo();

	output->Balance = input->balance;
	output->Credit = input->credit;
	output->Group = gcnew String(input->group);

	output->GwOrder = input->gw_order;
	output->GwPrice = input->gw_price;
	output->GwVolume = input->gw_volume;
	output->Id = input->id;
	output->Manager = input->manager;
	
	output->Prices = gcnew List<double>(2);
	output->Prices[0] = input->prices[0];
	output->Prices[1] = input->prices[1];
	
	output->Status = input->status;
	output->Time = input->time;
	output->Trade = Convert(&input->trade);

	return output;
}

RequestInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::RequestInfo^ input)
{
	RequestInfo* output = new RequestInfo();

	output->balance = input->Balance;
	output->credit = input->Credit;

	char* group = Convert(input->Group);
	if (group != NULL)
		COPY_STR(output->group, group);

	output->gw_order = input->GwOrder;
	output->gw_price = input->GwPrice;
	output->gw_volume = input->GwVolume;
	output->id = input->Id;
	output->manager = input->Manager;

	output->prices[0] = input->Prices[0];
	output->prices[1] = input->Prices[1];

	output->status = (char)input->Status;
	output->time = input->Time;
	output->trade = *Convert(input->Trade);

	return output;
}


P23::MetaTrader4::Manager::Contracts::MarginLevel^ P23::MetaTrader4::Manager::ClrWrapper::Convert(MarginLevel* input)
{
	P23::MetaTrader4::Manager::Contracts::MarginLevel^ output = gcnew P23::MetaTrader4::Manager::Contracts::MarginLevel();

	output->Balance = input->balance;
	output->Equity = input->equity;
	output->Group = gcnew String(input->group);
	output->Level = input->margin_level;

	output->LevelType = input->level_type;
	output->Leverage = input->leverage;
	output->Login = input->login;
	output->Margin = input->margin;
	output->MarginFree = input->margin_free;
	output->MarginType = input->margin_type;
	output->Updated = input->updated;
	output->Volume = input->volume;

	return output;
}

P23::MetaTrader4::Manager::Contracts::SymbolSummary^ P23::MetaTrader4::Manager::ClrWrapper::Convert(SymbolSummary* input)
{
	P23::MetaTrader4::Manager::Contracts::SymbolSummary^ output = gcnew P23::MetaTrader4::Manager::Contracts::SymbolSummary();

	output->BuyLots = input->buylots;
	output->BuyPrice = input->buyprice;
	output->Count = input->count;
	output->CovBuyLots = input->covbuylots;
	output->CovBuyPrice = input->covbuyprice;
	output->CovOrders = input->covorders;
	output->CovProfit = input->covprofit;
	output->CovSellLots = input->covselllots;
	output->CovSellPrice = input->covsellprice;
	output->Digits = input->digits;
	output->Orders = input->orders;

	output->Profit = input->profit;
	output->SellLots = input->selllots;
	output->SellPrice = input->sellprice;
	output->Symbol = gcnew String(input->symbol);
	output->Type = input->type;

	return output;
}

P23::MetaTrader4::Manager::Contracts::ExposureValue^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ExposureValue* input)
{
	P23::MetaTrader4::Manager::Contracts::ExposureValue^ output = gcnew P23::MetaTrader4::Manager::Contracts::ExposureValue();

	output->Clients = input->clients;
	output->Coverage = input->coverage;
	output->Currency = gcnew String(input->currency);

	return output;
}

P23::MetaTrader4::Manager::Contracts::RateInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(RateInfo* input)
{
	P23::MetaTrader4::Manager::Contracts::RateInfo^ output = gcnew P23::MetaTrader4::Manager::Contracts::RateInfo();

	output->Close = input->close;
	output->Ctm = input->ctm;
	output->High = input->high;
	output->Low = input->low;
	output->Open = input->open;
	output->Vol = input->vol;

	return output;
}

RateInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::RateInfo^ input)
{
	RateInfo* output = new RateInfo();

	output->close = input->Close;
	output->ctm = input->Ctm;
	output->high = input->High;
	output->low = input->Low;
	output->open = input->Open;
	output->vol = input->Vol;

	return output;
}

ChartInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::ChartInfo^ input)
{
	ChartInfo* output = new ChartInfo();

	output->end = input->End;
	output->mode = input->Mode;
	output->period = input->Period;
	output->start = input->Start;

	char* symbol = Convert(input->Symbol);
	if (symbol != NULL)
		COPY_STR(output->symbol, symbol);

	output->timesign = input->TimeSign;

	return output;
}

TickRequest* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::TickRequest^ input)
{
	TickRequest* output = new TickRequest();

	output->flags = (char)input->Flags;
	output->from = input->From;
	output->to = input->To;

	char* symbol = Convert(input->Symbol);
	if (symbol != NULL)
		COPY_STR(output->symbol, symbol);

	return output;
}

P23::MetaTrader4::Manager::Contracts::TickRecord^ P23::MetaTrader4::Manager::ClrWrapper::Convert(TickRecord* input)
{
	P23::MetaTrader4::Manager::Contracts::TickRecord^ output = gcnew P23::MetaTrader4::Manager::Contracts::TickRecord();

	output->Ask = input->ask;
	output->Bid = input->bid;
	output->Ctm = input->ctm;
	output->DataFeed = input->datafeed;
	output->Flags = input->flags;

	return output;
}
