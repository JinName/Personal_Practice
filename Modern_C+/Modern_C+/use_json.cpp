#include <fstream>
#include <iostream>

#include "json/json.h"

//int main()
//{
//    // root 에 리스트 노드를 만들어서 삽입하는 방식으로 사용한다.
//    Json::Value root;
//
//    // root 에 삽입될 record 노드
//    Json::Value record;
//
//    // 노드 작성
//    record["index"] = "index";
//    record["location"] = "location1";
//
//    // root 에 삽입
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