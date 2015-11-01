/* Copyright (C) 2015 evilbinary.
 * rootdebug@163.com
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HIGHLIGHT_APP
#define HIGHLIGHT_APP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cassert>
#include <memory>

#include "cmdlineoptions.h"
#include "datadir.h"
#include "codegenerator.h"

using namespace std;

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0


#define IO_ERROR_REPORT_LENGTH 5
#define SHEBANG_CNT 12


#if ANDROID
	#include <android/log.h>
	#ifndef TAG_NAME
		#define TAG_NAME "highliter"
	#endif
	#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, TAG_NAME, __VA_ARGS__))
	#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, TAG_NAME, __VA_ARGS__))
	#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, TAG_NAME, __VA_ARGS__))
	#define LOGV(...) ((void)__android_log_print(ANDROID_LOG_VERBOSE, TAG_NAME, __VA_ARGS__))
#else
	#define LOGI(...)
	#define LOGW(...)
	#define LOGE(...)
#endif


/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_evilbinary_highliter_parsers_SyntaxHighlight */

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_org_evilbinary_highliter_parsers_SyntaxHighlight_init
  (JNIEnv *, jobject,jstring);


JNIEXPORT jstring JNICALL Java_org_evilbinary_highliter_parsers_SyntaxHighlight_pase(
		JNIEnv *env, jobject obj, jstring code);



#ifdef __cplusplus
}
#endif

typedef map<string, string> StringMap;

class HighliterAndroid {

private:
	DataDir dataDir;
	StringMap extensions;
	StringMap scriptShebangs;
	stringstream cin_bufcopy;
	CmdLineOptions options;
	highlight::CodeGenerator* generator;
	vector<string> inFileList;

	bool formattingEnabled;
	bool styleFileWanted;

public:
	HighliterAndroid();

	int init(string dataDirPath);
	void destroy();
	int parse(string content, string &out);

	/** print version info*/
	void printVersionInfo();

	/** print configuration info*/
	void printConfigInfo();

	/** print error message*/
	void printBadInstallationInfo();

	/** print input and output errors */
	void printIOErrorReport(unsigned int numberErrorFiles,
			vector<string> & fileList, const string &action);

	/** list installed  files
	 \return true if files were found
	 */
	int printInstalledFiles(const string& where, const string& wildcard,
			const string& what, const string&option);

	/** list installed language definition files
	 \return true if lang files were found
	 */
	int printInstalledLanguages();

	/** print debug information
	 \param  lang language definition
	 \param langDefPath path to language definition
	 */
	void printDebugInfo(const highlight::SyntaxReader *lang,
			const string &langDefPath);

	string getFileSuffix(const string &fileName);

	string guessFileType(const string &suffix, const string &inputFile = "",
			bool useUserSuffix = false);

	int getNumDigits(int i);

	void printProgressBar(int total, int count);
	void printCurrentAction(const string&outfilePath, int total, int count,
			int countWidth);

	bool readInputFilePaths(vector<string> &fileList, string wildcard,
			bool recursiveSearch);

	string analyzeFile(const string& file);
	bool loadFileTypeConfig(const string& name, StringMap* map,
			StringMap* shebangMap);
	void printInstalledFiles();

	vector<string> collectPluginPaths(const vector<string>& plugins);

};

#endif
