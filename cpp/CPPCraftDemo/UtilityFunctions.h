#pragma once
#include "DataContainer.h"
namespace UtilityFunc
{
    /*
    Utility to populate a record collection
    prefix - prefix for the string value for every record
    numRecords - number of records to populate in the collection
    */

    QBRecordCollection populateDummyData(const std::string& strPrefix, unsigned int numRecords)
    {
        //changed QBRecordCollection to a std::list instead of using std::vector
        QBRecordCollection data;
        for (unsigned int i = 0; i < numRecords; i++)
        {
            QBRecord rec = { i, strPrefix + std::to_string(i), i % 100, std::to_string(i) + strPrefix };
            data.emplace_back(rec);
        }
        return data;
    }
 
    /*
    Return records that contains a string in the StringValue field
    records - the initial set of records to filter
    matchString - the string to search for
    */

    QBRecordCollection QBFindMatchingRecords(const QBRecordCollection& records, const std::string& columnName, 
        const std::string& matchString)
    {
        QBRecordCollection result;
        Indentifier& columnID = DataContainer[columnName];
        for (const auto& rec : records)
        {
            if (columnID != Indentifier::invalid)
            {
                if (columnID == Indentifier::Column0)
                {
                    const auto& matchValue = std::stoi(matchString);
                    if (matchValue == rec.column0)
                    {
                        result.emplace_back(rec);
                        break;
                    }
                }
                else if (columnID == Indentifier::Column1)
                {
                    if (strcmp(matchString.c_str(), rec.column1.c_str()))
                    {
                        result.emplace_back(rec);
                        break;
                    }
                }
                else if (columnID == Indentifier::Column2)
                {
                    const auto& matchValue = std::stol(matchString);
                    if (matchValue == rec.column2)
                    {
                        result.emplace_back(rec);
                        break;
                    }
                }
                else if (columnID == Indentifier::Column3)
                {
                    if (strcmp(matchString.c_str(), rec.column3.c_str()))
                    {
                        result.emplace_back(rec);
                        break;
                    }
                }
            }
            else 
            {
                std::cout << "ERROR: Invalid data logged !" << std::endl;
            }
        }
        return result;
    } 
     
    void DeleteRecordByID(QBRecordCollection& records, const unsigned int& unID)
    {
        std::list<QBRecord>::iterator it = records.begin();
        for (const auto& rec : records)
        {
            //column0 (int id) to be deleted
            if (rec.column0 == unID)
            {
                records.erase(it);
                break;
            }
            it++;
        }
    }
};

