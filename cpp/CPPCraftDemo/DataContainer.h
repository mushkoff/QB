#pragma once
#include <list>
#include <unordered_map>
#include <string>

/*QBRecord not changed only initialized*/
 struct QBRecord
{
	unsigned int column0 = 0; // used for id (delete task)
	std::string column1 = "N/A";
	long column2 = 0;
	std::string column3 = "N/A";
} ;

 /*mapped string to column identity*/
 enum class Indentifier
 {
	 Column0 = 0x01,
	 Column1 = 0x02,
	 Column2 = 0x03,
	 Column3 = 0x04,
	 invalid
 };

 std::unordered_map<std::string, Indentifier> DataContainer =
 {
	 {"column0", Indentifier::Column0},
	 {"column1", Indentifier::Column1},
	 {"column2", Indentifier::Column2},
	 {"column3", Indentifier::Column3}
 };

 typedef std::list<QBRecord> QBRecordCollection;

