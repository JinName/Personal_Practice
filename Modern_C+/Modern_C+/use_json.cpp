#include <fstream>
#include <iostream>

#include "json/json.h"

//int main()
//{
//    // root �� ����Ʈ ��带 ���� �����ϴ� ������� ����Ѵ�.
//    Json::Value root;
//
//    // root �� ���Ե� record ���
//    Json::Value record;
//
//    // ��� �ۼ�
//    record["index"] = "index";
//    record["location"] = "location1";
//
//    // root �� ����
//    root["recordList"].append(record);
//    root["recordList"].append(record);
//
//    Json::StreamWriterBuilder builder;
//    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
//
//    std::ofstream outfile("test.json", std::ios::out);
//
//    writer->write(root, &outfile);
//
//    return 0;
//}