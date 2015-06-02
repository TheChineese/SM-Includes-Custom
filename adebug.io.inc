
/*
 *            __          __                          
 *           /\ \        /\ \                         
 *    __     \_\ \     __\ \ \____  __  __     __     
 *  /'__`\   /'_` \  /'__`\ \ '__`\/\ \/\ \  /'_ `\   
 * /\ \_\.\_/\ \_\ \/\  __/\ \ \_\ \ \ \_\ \/\ \_\ \  
 * \ \__/.\_\ \___,_\ \____\\ \_,__/\ \____/\ \____ \ 
 *  \/__/\/_/\/__,_ /\/____/ \/___/  \/___/  \/____\ \
 *                                             /\____/
 *                                             \_/__/    Text generated at http://www.network-science.de/ascii/
 *
 * adebug.io by Emp` http://adebug.io
 *
 * A robust and flexible library for scripters, testers, and admins to use, see, and log debug messages.
 * Employs transitional syntax - SourceMod 1.7 or newer is required to compile and run.
 *
 */

/*
 *                                 _      
 *   _____  ____ _ _ __ ___  _ __ | | ___ 
 *  / _ \ \/ / _` | '_ ` _ \| '_ \| |/ _ \
 * |  __/>  < (_| | | | | | | |_) | |  __/
 *  \___/_/\_\__,_|_| |_| |_| .__/|_|\___|
 *                          |_|           
 *
 * Below is an example of the adebug functions and the corresponding file output.

 public OnMapStart()
 {
	adebug_tierup( "OnMapStart" );
	PrecacheFiles()
	adebug_tierdown( "OnMapStart" );
 }
 PrecacheFiles()
 {
	adebug_tierup( "PrecacheFiles" );

	int iModels, iSounds;
	//...
	adebug( "Finished Precaching %d Models", iModels );
	//...
	adebug( "Finished Precaching %d Sounds", iSounds );

	adebug_tierdown( "PrecacheFiles( %d Models, %d Sounds )", iModels, iSounds );
 }

 * Example output (below) is logged to the file "addons\sourcemod\logs\adebug_YYYY_mm_dd_HH_MM.log"

 1+OnMapStart
  2+PrecacheFiles
   Finished Precaching 0 Models
   Finished Precaching 0 Sounds
  2-PrecacheFiles( 0 Models, 0 Sounds )
 1-OnMapStart

 */

/*
 *  _            _           _             
 * (_)_ __   ___| |_   _ ___(_) ___  _ __  
 * | | '_ \ / __| | | | / __| |/ _ \| '_ \ 
 * | | | | | (__| | |_| \__ \ | (_) | | | |
 * |_|_| |_|\___|_|\__,_|___/_|\___/|_| |_|
 *           _
 *         _|_|_      Hello! I am a crab with a hat.
 *    (\/)(Â°,,,Â°)(V)   I will be your guide through this file.
 *
 * To include adebug in your script, but not require it for compilation, copy the code below:

#define ADEBUG_OFF 1            //Set this to 0 to enable adebug, for more information go to http://adebug.io
#tryinclude adebug.io           //Use tryinclude to not require adebug
#if !defined _adebug_io         //If adebug is unavailable, the lines below replace adebug lines with an empty function
	#define adebug(%1)          adebug_null()
	#define adebug_tierup(%1)   adebug_null()
	#define adebug_tierdown(%1) adebug_null()
	#define adebug_end(%1)      adebug_null()
	adebug_null(){}
#endif

// If you prefer to use the UPPERCASE function names (ie. ADEBUG vs adebug) copy this instead:

#define ADEBUG_OFF 1            //Set this to 0 to enable adebug, for more information go to http://adebug.io
#tryinclude adebug.io           //Use tryinclude to not require adebug
#if !defined _adebug_io         //If adebug is unavailable, the lines below replace ADEBUG lines with an empty function
	#define ADEBUG(%1)          ADEBUG_NULL()
	#define ADEBUG_TIERUP(%1)   ADEBUG_NULL()
	#define ADEBUG_TIERDOWN(%1) ADEBUG_NULL()
	#define ADEBUG_END(%1)      ADEBUG_NULL()
	ADEBUG_NULL(){}
#endif

 *          _
 *        _|_|_       What helped the little mermaid pass her Sea++ class?
 *    (V)(Â°,,,Â°)(\/)   Her algae bra!
 *
 * If you copied correctly, your script should now look for this file.
 * If for some reason adebug is already included, we need this at the "top" of the file to stop:
 */
#if defined _adebug_io
	#endinput
#endif
#define _adebug_io "http://adebug.io"

/*
 *                                     _ 
 *  _ __ ___ _ __ ___   _____   ____ _| |
 * | '__/ _ \ '_ ` _ \ / _ \ \ / / _` | |
 * | | |  __/ | | | | | (_) \ V / (_| | |
 * |_|  \___|_| |_| |_|\___/ \_/ \__,_|_|
 *         _
 *       _|_|_      How did the crab not pay at the compiler?
 *  (\/)(Â°,,,Â°)(V)   He scuttled by Define!
 *
 * Define ADEBUG_OFF as 1 to remove debugging from plugin during compile.
 * This removes all adebug lines when compiling and removes warnings for empty statements.
 * If you copied correctly, this is defined above #tryinclude adebug.io
 */
#if defined ADEBUG_OFF
 #if ADEBUG_OFF > 0

	#define adebug(%1)          adebug_null()
	#define adebug_tierup(%1)   adebug_null()
	#define adebug_tierdown(%1) adebug_null()
	#define adebug_end(%1)      adebug_null()
	#define ADEBUG(%1)          adebug_null()
	#define ADEBUG_TIERUP(%1)   adebug_null()
	#define ADEBUG_TIERDOWN(%1) adebug_null()
	#define ADEBUG_END(%1)      adebug_null()
	adebug_null(){}             /* empty function */

	#endinput

 #endif
#endif

/*
 *      _       __ _                 
 *   __| | ___ / _(_)_ __   ___  ___ 
 *  / _` |/ _ \ |_| | '_ \ / _ \/ __|
 * | (_| |  __/  _| | | | |  __/\__ \
 *  \__,_|\___|_| |_|_| |_|\___||___/
 *        _
 *      _|_|_       Don't be shellfish, pre-define these in your scripts!
 *  (V)(Â°,,,Â°)(\/)
 *
 * Below are changeable settings; to distribute changes, define these before #tryinclude adebug.io
 */
#if !defined ADEBUG_LOCATION
	/** Debug file location (sub-folders allowed), default: "logs/" */
	#define ADEBUG_LOCATION "logs/"
#endif
#if !defined ADEBUG_PREFIX
	/** Prefix for debug messages and file names, default: "adebug" */
	#define ADEBUG_PREFIX "adebug"
#endif
#if !defined ADEBUG_TIMEFORMAT
	/** Time format for file names, default: "_%Y_%m_%d_%H_%M" */
		/* %Y-year, %m-month, %d-day, %H-hour, %M-minute */
	#define ADEBUG_TIMEFORMAT "_%Y_%m_%d_%H_%M"
#endif
#if !defined ADEBUG_EXTENSION
	/** File extension for log files, default: ".log" */
	#define ADEBUG_EXTENSION ".log"
#endif
#if !defined ADEBUG_SOURCEMODLOG
	/** Use SourceMod's log formatting, default: 2 */
		/* 0-no, 1-yes, 2-yes with plugin name */
	#define ADEBUG_SOURCEMODLOG 2
#endif
#if !defined ADEBUG_PREPENDCHAR
	/** Prepend this character for each tier, default: ' ' */
	#define ADEBUG_PREPENDCHAR ' '
#endif
#if !defined ADEBUG_TIER_START
	/** Tier starting value, default: 0 */
	#define ADEBUG_TIER_START 0
#endif
#if !defined ADEBUG_REMOVECOLORS
	/** Removes colors.inc codes from console and logs, default: 0 */
		/* Ignored if colors.inc not included - https://forums.alliedmods.net/showthread.php?t=96831 */
		/* Also works with morecolors.inc - https://forums.alliedmods.net/showthread.php?t=185016 */
	#define ADEBUG_REMOVECOLORS 0
#endif
#if !defined ADEBUG_ALWAYSCLOSE
	/** Close log file after each entry, default: 0 */
		/* 0-only close at start tier, 1-always close after writing */
	#define ADEBUG_ALWAYSCLOSE 0
#endif
#if !defined ADEBUG_DELETEITERATION
	/** Delete old log when _adebug_iTier == ADEBUG_TIER_START this many iterations, default: 64 */
	#define ADEBUG_DELETEITERATION 64
#endif
#if !defined ADEBUG_DELETESIZE
	/** Delete file when exceeding this size in bytes, default: 0 */
		/* 0-disabled, 1000000-megabyte, 1000000000-gigabyte*/
	#define ADEBUG_DELETESIZE 0
#endif

/*         _
 *       _|_|_       
 *  (\/)(Â°,,,Â°)(V)   
 *
 * Enabling ADEBUG_SUFFIX uses the first debug word as a file suffix
 * when _adebug_iTier == ADEBUG_TIER_START. This is useful to
 * split log files by the starting tier debug.
 */
#if !defined ADEBUG_SUFFIX
	/** Set > 0 to append suffixes to file names, default: 0 */
		/* 0-disabled, #-suffix length, 32-suggested length */
	#define ADEBUG_SUFFIX 0
#endif

/*        _
 *      _|_|_      
 *  (V)(Â°,,,Â°)(\/)   
 *
 * Enabling ADEBUG_ADMINCMD allows admins to filter debug messages to console/chat.
 * This also allows the server to filter messages being logged.
 *
 * @command		adebug
 * @showall		adebug *
 * @filter		adebug filter
 * @disable		adebug ""
 */
#if !defined ADEBUG_ADMINCMD
	/** Set to 1 to allow admins to use "adebug" command, default: 1 */
	#define ADEBUG_ADMINCMD 1
#endif
#if !defined ADEBUG_ADMINFLAG
	/** Admin flag required to use "adebug" command, default: Admin_Root */
		/* See AdminFlag enum in admin.inc */
	#define ADEBUG_ADMINFLAG Admin_Root
#endif
#if !defined ADEBUG_FILTERALL
	/** String used to show all debugs, default: "*" */
	#define ADEBUG_FILTERALL "*"
#endif
#if !defined ADEBUG_SERVERSTART
	/** Sets the server filter to this string on start, default: ADEBUG_FILTERALL */
		/* ""-disabled, "filter"-filter, ADEBUG_FILTERALL-all */
	#define ADEBUG_SERVERSTART ADEBUG_FILTERALL
#endif
#if !defined ADEBUG_ADMINCMD_FILTER_LEN
	/** Max length of adebug filter command, default: 32 */
	#define ADEBUG_ADMINCMD_FILTER_LEN 32
#endif

/*         _
 *       _|_|_
 *  (\/)(Â°,,,Â°)(V)
 *
 * Some extra defines I prefer to use
 */
#if !defined EOS
	/** String termination character, used to signify the End Of String. Yes, this is the same as 0, but it's a special 0. */
	#define EOS '\0'
#endif
#if !defined charsmax
	/** Max characters for a string, used as an alternative to sizeof. Back in my day, this used to be sizeof - 1. */
	#define charsmax sizeof
#endif
#if !defined MAX_PLAYERS
	/** Max players for game, used with adebug command, default: 32 */
	#define MAX_PLAYERS 32
#endif

/*
 *                  _ _        _                   __                              
 *   ___ __ _ _ __ (_) |_ __ _| |  _ __  _ __ ___ / _| ___ _ __ ___ _ __   ___ ___ 
 *  / __/ _` | '_ \| | __/ _` | | | '_ \| '__/ _ \ |_ / _ \ '__/ _ \ '_ \ / __/ _ \
 * | (_| (_| | |_) | | || (_| | | | |_) | | |  __/  _|  __/ | |  __/ | | | (_|  __/
 *  \___\__,_| .__/|_|\__\__,_|_| | .__/|_|  \___|_|  \___|_|  \___|_| |_|\___\___|
 *           |_|                  |_|                                              
 *         _
 *       _|_|_      Why was the lobster arrested at the capitol?
 *  (\/)(Â°,,,Â°)(V)   He looked shifty and Caps Lock was against the claw!
 *
 * This allows you to use UPPERCASE function names. Toe-may-toe, toe-maw-toe!
 */
#define ADEBUG              adebug
#define ADEBUG_TIERUP       adebug_tierup
#define ADEBUG_TIERDOWN     adebug_tierdown
#define ADEBUG_END          adebug_end

/*
 *        _       _           _                   _       _     _           
 *   __ _| | ___ | |__   __ _| | __   ____ _ _ __(_) __ _| |__ | | ___  ___ 
 *  / _` | |/ _ \| '_ \ / _` | | \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|
 * | (_| | | (_) | |_) | (_| | |  \ V / (_| | |  | | (_| | |_) | |  __/\__ \
 *  \__, |_|\___/|_.__/ \__,_|_|   \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
 *  |___/                                                                   
 *        _
 *      _|_|_       Where do global variables hide?
 *  (V)(Â°,,,Â°)(\/)   They stay in their shells!
 *
 * Let's create some global variables to use!
 */
char _adebug_szFile[ 128 ];             /* file string */
char _adebug_szMessage[ 128 ];          /* message string */
File _adebug_hFile;                     /* file handle */
int _adebug_iTier = ADEBUG_TIER_START;  /* tier int */

/*         _
 *       _|_|_
 *  (\/)(Â°,,,Â°)(V)
 *
 * Global variables only used when ADEBUG_SUFFIX > 0
 */
stock ArrayList _adebug_alSuffixes;     /* suffix array list */
stock StringMap _adebug_smSuffixes;     /* suffix string map */

/*         _
 *       _|_|_
 *  (\/)(Â°,,,Â°)(V)
 *
 * Global variables only used when ADEBUG_ADMINCMD > 0
 */
stock ReplySource _adebug_iAdminReply[ MAX_PLAYERS + 1 ];    /* admin reply array */
stock char _adebug_szAdminFilter[ MAX_PLAYERS + 1 ][ ADEBUG_ADMINCMD_FILTER_LEN ];    /* admin filter array */

/*
 *   __                  _   _                 
 *  / _|_   _ _ __   ___| |_(_) ___  _ __  ___ 
 * | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 * |  _| |_| | | | | (__| |_| | (_) | | | \__ \
 * |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
 *        _
 *      _|_|_
 *  (V)(Â°,,,Â°)(\/)
 *
 * These are the functions provided by adebug:
 *
 * @adebug()            Creates a debug message at the current tier.
 * @adebug_tierup()     Increases tier and creates a debug message at the new tier.
 * @adebug_tierdown()   Creates a debug message at the current tier and then decreases tier.
 * @adebug_end()        Deletes existing log file and updates file name with a new time.
 *
 */

/**
 * Creates a debug message at the current tier.
 *
 * @param szDebug       Formatting string for debug message.
 * @param ...           Optional formatting arguments for szDebug.
 *
 * @noreturn
 */
stock void adebug( char[] szDebug, any ... )
{
	int iLen = ( _adebug_iTier >= 0 ) ? ( _adebug_iTier + 1 ) : ( -_adebug_iTier - 1 );

	for ( int iCharNum = 0; iCharNum < iLen; iCharNum++ )
		_adebug_szMessage[ iCharNum ] = ADEBUG_PREPENDCHAR;

	VFormat( _adebug_szMessage[ iLen ], charsmax(_adebug_szMessage) - iLen, szDebug, 2 );

	adebug_open( _adebug_szMessage[ iLen ] );

	adebug_message();

#if ADEBUG_ALWAYSCLOSE > 0
		adebug_closefile();
#else
	if ( _adebug_iTier == ADEBUG_TIER_START )
		adebug_closefile();
#endif
}

/**
 * Increases _adebug_iTier and creates a debug message at the new tier.
 *
 * @param szDebug       Formatting string for debug message.
 * @param ...           Optional formatting arguments for szDebug.
 *
 * @noreturn
 */
stock void adebug_tierup( char[] szDebug, any ... )
{
	int iLen = ( _adebug_iTier >= 0 ) ? ( _adebug_iTier + 1 ) : ( -_adebug_iTier - 1 );

	if ( iLen >= charsmax( _adebug_szMessage ) )
	{
		LogMessage( "Error in debug, _adebug_iTier reached %d. Resetting.", iLen );

		iLen = ( _adebug_iTier = ADEBUG_TIER_START ) + 1;

	#if ADEBUG_SUFFIX > 0
		VFormat( _adebug_szMessage, charsmax(_adebug_szMessage), szDebug, 2 );
		adebug_updatefile( .bForce = true, .szSuffix = _adebug_szMessage );
	#else
		adebug_updatefile( .bForce = true );
	#endif
	}

	for ( int iCharNum = 0; iCharNum < iLen; iCharNum++ )
		_adebug_szMessage[ iCharNum ] = ADEBUG_PREPENDCHAR;

	iLen += FormatEx( _adebug_szMessage[ iLen ], charsmax(_adebug_szMessage) - iLen, "%d+", iLen );

	VFormat( _adebug_szMessage[ iLen ], charsmax(_adebug_szMessage) - iLen, szDebug, 2 );

	adebug_open( _adebug_szMessage[ iLen ] );

	_adebug_iTier++;

	adebug_message();

#if ADEBUG_ALWAYSCLOSE > 0
		adebug_closefile();
#else
	if ( _adebug_iTier == ADEBUG_TIER_START )
		adebug_closefile();
#endif
}

/**
 * Creates a debug message and then decreases _adebug_iTier.
 *
 * @param szDebug       Formatting string for debug message.
 * @param ...           Optional formatting arguments for szDebug.
 *
 * @noreturn
 */
stock void adebug_tierdown( char[] szDebug, any ... )
{
	int iLen = ( _adebug_iTier >= 0 ) ? ( _adebug_iTier ) : ( -_adebug_iTier );

	if ( iLen >= charsmax( _adebug_szMessage ) )
	{
		LogMessage( "Error in debug, _adebug_iTier reached %d. Resetting.", iLen );

		iLen = _adebug_iTier = ADEBUG_TIER_START;

	#if ADEBUG_SUFFIX > 0
		VFormat( _adebug_szMessage, charsmax(_adebug_szMessage), szDebug, 2 );
		adebug_updatefile( .bForce = true, .szSuffix = _adebug_szMessage );
	#else
		adebug_updatefile( .bForce = true );
	#endif
	}

	for ( int iCharNum = 0; iCharNum < iLen; iCharNum++ )
		_adebug_szMessage[ iCharNum ] = ADEBUG_PREPENDCHAR;

	iLen += FormatEx( _adebug_szMessage[ iLen ], charsmax(_adebug_szMessage) - iLen, "%d-", iLen );

	VFormat( _adebug_szMessage[ iLen ], charsmax(_adebug_szMessage) - iLen, szDebug, 2 );

	adebug_open( _adebug_szMessage[ iLen ] );

	adebug_message();

	_adebug_iTier--;

#if ADEBUG_ALWAYSCLOSE > 0
		adebug_closefile();
#else
	if ( _adebug_iTier == ADEBUG_TIER_START )
		adebug_closefile();
#endif
}

/**
 * Ends the current debug session and deletes file(s) for the current time.
 *
 * @param bTimeReset    Reset the debug time to now, default: true
 * @param bTierReset    Reset the debug tier to ADEBUG_TIER_START, default: true
 *
 * @note                Deletes all suffix files if ADEBUG_SUFFIX > 0.
 *
 * @noreturn
 */
stock void adebug_end( bool bTimeReset = true, bool bTierReset = true )
{
	adebug_closefile();

#if ADEBUG_SUFFIX > 0
	if ( _adebug_alSuffixes )
	{
		char szTempSuffix[ ADEBUG_SUFFIX ];
		for ( int iSuffix = 0, iSuffixes = _adebug_alSuffixes.Length;
			iSuffix < iSuffixes;
			iSuffix++
		){
			_adebug_alSuffixes.GetString( iSuffix, szTempSuffix, charsmax(szTempSuffix) );
			adebug_updatefile( .szSuffix = szTempSuffix );
			if ( FileExists( _adebug_szFile ) )
				DeleteFile( _adebug_szFile );
		}

		_adebug_alSuffixes.Clear();
		_adebug_smSuffixes.Clear();
	}
#else
	if ( FileExists( _adebug_szFile ) )
		DeleteFile( _adebug_szFile );
#endif

	if ( bTimeReset )
		adebug_updatefile( .bForce = true );
	if ( bTierReset )
		_adebug_iTier = ADEBUG_TIER_START;
}

/*  _       _                        _    __                  _   _                 
 * (_)_ __ | |_ ___ _ __ _ __   __ _| |  / _|_   _ _ __   ___| |_(_) ___  _ __  ___ 
 * | | '_ \| __/ _ \ '__| '_ \ / _` | | | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 * | | | | | ||  __/ |  | | | | (_| | | |  _| |_| | | | | (__| |_| | (_) | | | \__ \
 * |_|_| |_|\__\___|_|  |_| |_|\__,_|_| |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
 *         _
 *       _|_|_
 *  (\/)(Â°,,,Â°)(V)
 *
 * These are internal functions used by adebug.io
 * If you use these functions, you must require adebug and should not use #tryinclude
 */

/**
 * Creates all directories specified.
 *
 * @param szDir         Directories to create
 *
 * @noreturn
 */
stock void adebug_createdirs( char[] szDir )
{
	for ( int iChar, cChar, iLen = strlen( szDir ); iChar < iLen; iChar++ )
	{
		switch ( ( cChar = szDir[ iChar ] ) )
		{
			case '\\', '/':
			{
				szDir[ iChar ] = EOS;
				if ( !DirExists( szDir ) )
					CreateDirectory( szDir, FPERM_O_READ|FPERM_O_WRITE );
				szDir[ iChar ] = cChar;
			}
		}
	}
}

/**
 * Updates file string _adebug_szFile.
 *
 * @param bForce        Forces the file time to update; otherwise it uses the existing time, default: false
 * @param szSuffix      Suffix used for file name. Only used with ADEBUG_SUFFIX > 0
 *
 * @noreturn
 */
stock void adebug_updatefile( bool bForce = false, char[] szSuffix = "" )
{
#if ADEBUG_ADMINCMD > 0
	static bool bAdminInit = false;
	if ( !bAdminInit )
	{
		RegAdminCmd( "adebug", adebug_command, ( 1 << _:ADEBUG_ADMINFLAG ) );

		strcopy( _adebug_szAdminFilter[0], charsmax(_adebug_szAdminFilter[]), ADEBUG_SERVERSTART );

		bAdminInit = true;
	}
#endif

	adebug_closefile();

#if ADEBUG_SUFFIX > 0

	static char szFolder[ sizeof _adebug_szFile ];
	if ( szFolder[0] == EOS )
	{
		BuildPath( Path_SM, szFolder, charsmax(szFolder), ADEBUG_LOCATION );
		adebug_cleanfilename( szFolder, szFolder, .bAllowSolidi = true );
		adebug_createdirs( szFolder );

		if ( StrContains( ADEBUG_PREFIX, "/" ) != -1 || StrContains( ADEBUG_PREFIX, "\\" ) != -1 )
		{
			FormatEx( _adebug_szFile, charsmax(_adebug_szFile), "%s%s", szFolder, ADEBUG_PREFIX );
			adebug_cleanfilename( _adebug_szFile, _adebug_szFile, .bAllowSolidi = true );
			adebug_createdirs( _adebug_szFile );
		}
	}

	static char szDateTime[ 64 ];
	if ( szDateTime[0] == EOS || bForce )
	{
		FormatTime( szDateTime, charsmax(szDateTime), ADEBUG_TIMEFORMAT );

		adebug_cleanfilename( szDateTime, szDateTime, .bAllowSolidi = true );
		if ( StrContains( szDateTime, "/" ) != -1 || StrContains( szDateTime, "\\" ) != -1 )
		{
			FormatEx( _adebug_szFile, charsmax(_adebug_szFile), "%s%s%s", szFolder, ADEBUG_PREFIX, szDateTime );
			adebug_createdirs( _adebug_szFile );
		}
	}

	adebug_cleanfilename( szSuffix, szSuffix, .bAllowSolidi = false );
	FormatEx( _adebug_szFile, charsmax(_adebug_szFile), "%s%s%s%c%s%s", szFolder, ADEBUG_PREFIX, szDateTime, ADEBUG_PREPENDCHAR, szSuffix, ADEBUG_EXTENSION );

	if ( szSuffix[0] == EOS )
		return;

	if ( !_adebug_smSuffixes )
	{
		_adebug_smSuffixes = new StringMap();
		_adebug_alSuffixes = new ArrayList( ADEBUG_SUFFIX );
	}
	else
	{
		int iValue;
		_adebug_smSuffixes.GetValue( szSuffix, iValue );
		if ( iValue )
			return;
	}

	_adebug_alSuffixes.PushString( szSuffix );
	_adebug_smSuffixes.SetValue( szSuffix, !ADEBUG_DELETEITERATION );

#else

	if ( _adebug_szFile[0] == EOS || bForce )
	{
		#pragma unused szSuffix

		char szDateTime[ 64 ];
		FormatTime( szDateTime, charsmax(szDateTime), ADEBUG_TIMEFORMAT );

		BuildPath( Path_SM, _adebug_szFile, charsmax(_adebug_szFile), ADEBUG_LOCATION );

		Format( _adebug_szFile, charsmax(_adebug_szFile), "%s%s%s%s", _adebug_szFile, ADEBUG_PREFIX, szDateTime, ADEBUG_EXTENSION );

		adebug_cleanfilename( _adebug_szFile, _adebug_szFile, .bAllowSolidi = true );

		adebug_createdirs( _adebug_szFile );
	}

#endif
}

/**
 * Removes invalid characters from a file name. ':', '*', '?', '"', '<', '>', '|', '/', '\'
 *
 * @param szFile        File name to clean
 * @param szClean       Copies clean name here
 * @param bAllowSolidi  Set to true to allow '/' and '\', default: false
 *
 * @noreturn
 */
stock void adebug_cleanfilename( char[] szFile, char[] szClean, bool bAllowSolidi = false )
{
	for ( int iChar, cChar, iClean, iLen = strlen( szFile ); iChar <= iLen; iChar++ )
	{
		switch ( ( cChar = szFile[ iChar ] ) )
		{
			case ':', '*', '?', '"', '<', '>', '|':
			{
			}
			case '\\', '/':
			{
				if ( bAllowSolidi )
					szClean[ iClean++ ] = cChar;
			}
			default:
			{
				if ( ( szClean[ iClean++ ] = cChar ) == EOS )
					break;
			}
		}
	}
}

/**
 * Checks for active _adebug_hFile, opens _adebug_szFile if invalid.
 *
 * @param szDebug       Debug string for file suffix. Only used with ADEBUG_SUFFIX > 0
 *
 * @noreturn
 */
stock void adebug_open( char[] szDebug = "" )
{
	if ( _adebug_iTier == ADEBUG_TIER_START || !_adebug_hFile )
	{
	#if ADEBUG_SUFFIX > 0
		adebug_closefile();
		static char szSuffix[ ADEBUG_SUFFIX ];
		BreakString( szDebug, szSuffix, charsmax(szSuffix) );
		adebug_updatefile( .szSuffix = szSuffix );
	#else
		#pragma unused szDebug
		if ( _adebug_szFile[0] == EOS )
			adebug_updatefile();
	#endif

	#if ADEBUG_DELETEITERATION > 0
		static int iDeleteIteration;
		if ( _adebug_iTier == ADEBUG_TIER_START && FileExists( _adebug_szFile ) )
		{
		#if ADEBUG_SUFFIX > 0
			_adebug_smSuffixes.GetValue( szSuffix, iDeleteIteration );
			iDeleteIteration++;
			_adebug_smSuffixes.SetValue( szSuffix, iDeleteIteration );
		#else
			iDeleteIteration++;
		#endif

			if ( !( iDeleteIteration % ADEBUG_DELETEITERATION ) )
			{
				if ( _adebug_hFile )
					delete _adebug_hFile;
				DeleteFile( _adebug_szFile );
			}
		}
	#endif

	#if ADEBUG_DELETESIZE > 0
		if ( FileExists( _adebug_szFile ) && FileSize( _adebug_szFile ) > ADEBUG_DELETESIZE )
		{
			if ( _adebug_hFile )
				delete _adebug_hFile;
			DeleteFile( _adebug_szFile );
		}
	#endif

		if ( !_adebug_hFile )
			_adebug_hFile = OpenFile( _adebug_szFile, "a" );
	}
}

/**
 * Logs and displays _adebug_szMessage.
 *
 * @noreturn
 */
stock void adebug_message()
{
#if ADEBUG_ADMINCMD > 0

#if defined _colors_included && ADEBUG_REMOVECOLORS > 0
	static char szColorless[ sizeof _adebug_szMessage ];
	strcopy( szColorless, charsmax(szColorless), _adebug_szMessage );
	CRemoveTags( szColorless, charsmax(szColorless) );
#endif

	bool bShowMessage, bLogMessage = true;
	for ( int iClient = 0; iClient <= MAX_PLAYERS; iClient++ )
	{
		if ( !iClient || ( _adebug_szAdminFilter[ iClient ][ 0 ] != EOS && IsClientConnected( iClient ) && GetAdminFlag( GetUserAdmin(iClient), ADEBUG_ADMINFLAG ) ) )
		{
			bShowMessage = false;

			if ( StrEqual(_adebug_szAdminFilter[ iClient ], ADEBUG_FILTERALL ) )
			{
				bShowMessage = true;
			}
			else
			{
				static int iAdminTier[ MAX_PLAYERS + 1 ];
				if ( iAdminTier[ iClient ] && _adebug_iTier )
				{
					if ( _adebug_iTier > 0 )
						bShowMessage = ( iAdminTier[ iClient ] < _adebug_iTier );
					else
						bShowMessage = ( iAdminTier[ iClient ] > _adebug_iTier );
				}

				if ( !bShowMessage && StrContains( _adebug_szMessage, _adebug_szAdminFilter[ iClient ], false ) != -1 )
				{
					iAdminTier[ iClient ] = _adebug_iTier;
					bShowMessage = true;
				}
			}

			if ( bShowMessage )
			{
			#if defined _colors_included && ADEBUG_REMOVECOLORS > 0
				#define ADEBUG_MSG "[%s] %s",ADEBUG_PREFIX,_adebug_szMessage
				#define ADEBUG_MSG_NOCOLOR "[%s] %s",ADEBUG_PREFIX,szColorless
			#else
				#define ADEBUG_MSG "[%s] %s",ADEBUG_PREFIX,_adebug_szMessage
				#define ADEBUG_MSG_NOCOLOR ADEBUG_MSG
			#endif

				if ( iClient )
				{
					switch ( _adebug_iAdminReply[ iClient ] )
					{
						case SM_REPLY_TO_CONSOLE:
						{
							PrintToConsole( iClient, ADEBUG_MSG_NOCOLOR );
						}
						case SM_REPLY_TO_CHAT:
						{
						#if defined _colors_included
							CPrintToChat( iClient, ADEBUG_MSG );
						#else
							PrintToChat( iClient, ADEBUG_MSG );
						#endif
						}
					}
				}
				else
				{
					PrintToServer( ADEBUG_MSG_NOCOLOR );
				}
			}
			else if ( !iClient && _adebug_szAdminFilter[ iClient ][ 0 ] != EOS )
			{
				bLogMessage = false;
			}
		}
	}

	if ( !bLogMessage )
		return;
#endif

	if ( !_adebug_hFile )
		adebug_open( _adebug_szMessage );

#if ADEBUG_SOURCEMODLOG == 2

#if defined _colors_included && ADEBUG_REMOVECOLORS > 0
	LogToOpenFile( _adebug_hFile, szColorless );
#else
	LogToOpenFile( _adebug_hFile, _adebug_szMessage );
#endif

#elseif ADEBUG_SOURCEMODLOG == 1

#if defined _colors_included && ADEBUG_REMOVECOLORS > 0
	LogToOpenFileEx( _adebug_hFile, szColorless );
#else
	LogToOpenFileEx( _adebug_hFile, _adebug_szMessage );
#endif

#else

#if defined _colors_included && ADEBUG_REMOVECOLORS > 0
	_adebug_hFile.WriteLine( szColorless );
#else
	_adebug_hFile.WriteLine( _adebug_szMessage );
#endif

#endif
}

/**
 * Closes _adebug_hFile.
 *
 * @noreturn
 */
stock void adebug_closefile()
{
	if ( _adebug_hFile )
		delete _adebug_hFile;
}

/*            _           _                                                       _ 
 *   __ _  __| |_ __ ___ (_)_ __     ___ ___  _ __ ___  _ __ ___   __ _ _ __   __| |
 *  / _` |/ _` | '_ ` _ \| | '_ \   / __/ _ \| '_ ` _ \| '_ ` _ \ / _` | '_ \ / _` |
 * | (_| | (_| | | | | | | | | | | | (_| (_) | | | | | | | | | | | (_| | | | | (_| |
 *  \__,_|\__,_|_| |_| |_|_|_| |_|  \___\___/|_| |_| |_|_| |_| |_|\__,_|_| |_|\__,_|
 *        _
 *      _|_|_
 *  (V)(Â°,,,Â°)(\/)
 *
 * Enabling ADEBUG_ADMINCMD allows admins to filter debug messages to console/chat.
 * This also allows the server to filter messages being logged.
 * Everything is internal, no need to initialize anything.
 *
 * @command		adebug
 * @showall		adebug *
 * @filter		adebug filter
 * @disable		adebug ""
 */

#if ADEBUG_ADMINCMD > 0

/*         _
 *       _|_|_       How many hooks baited the crab?
 *  (\/)(Â°,,,Â°)(\/)   None, he handled them in a snap!
 *
 * Command hook only used when ADEBUG_ADMINCMD > 0
 */
public Action adebug_command( int iClient, int iArgCount )
{
	char szFilter[ ADEBUG_ADMINCMD_FILTER_LEN ];
	GetCmdArgString( szFilter, charsmax(szFilter) );
	StripQuotes( szFilter );
	TrimString( szFilter );

	if ( szFilter[ 0 ] == EOS )
	{
		_adebug_szAdminFilter[ iClient ][ 0 ] = EOS;

	#define ADEBUG_MSG_DISABLED "[%s] Debug messages disabled.",ADEBUG_PREFIX

	#if defined _colors_included
		CReplyToCommand( iClient, ADEBUG_MSG_DISABLED );
	#else
		ReplyToCommand( iClient, ADEBUG_MSG_DISABLED );
	#endif

	}
	else
	{
		strcopy( _adebug_szAdminFilter[ iClient ][ 0 ], charsmax(_adebug_szAdminFilter), szFilter );

		if ( StrEqual( szFilter, ADEBUG_FILTERALL ) )
		{

		#define ADEBUG_MSG_FILTERALL "[%s] Showing all debug messages.",ADEBUG_PREFIX

		#if defined _colors_included
			CReplyToCommand( iClient, ADEBUG_MSG_FILTERALL );
		#else
			ReplyToCommand( iClient, ADEBUG_MSG_FILTERALL );
		#endif

		}
		else
		{

		#define ADEBUG_MSG_FILTER "[%s] Showing debug messages with '%s'.",ADEBUG_PREFIX,szFilter

		#if defined _colors_included
			CReplyToCommand( iClient, ADEBUG_MSG_FILTER );
		#else
			ReplyToCommand( iClient, ADEBUG_MSG_FILTER );
		#endif

		}

		_adebug_iAdminReply[ iClient ] = GetCmdReplySource();
	}

	return Plugin_Handled;
}

#endif