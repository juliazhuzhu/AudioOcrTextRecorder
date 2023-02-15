//
// Created by xiaoye on 2023/2/15.
//

#include "CAudioTextRecorder.h"
#include<iostream>
#include <stdio.h>
#include <string.h>

static bool endWith(const string &str, const string &tail) {
    return str.compare(str.size() - tail.size(), tail.size(), tail) == 0;
}

CAudioTextRecorder::CAudioTextRecorder(){
    m_maxFileNum = 30;
}

void CAudioTextRecorder::initialize(string path){

    m_path = path;
    loadOcrTextDescriptionFile();

}

void CAudioTextRecorder::newRecorderFile(string confId, int64_t startTime){
    //filename
    //confId, startTime, filename update to ocr description file
    //open file and update fp

    OcrRecordDescription desc;
    desc.filename = "ocr_1.log";
    desc.confId = confId;
    desc.startTime = startTime;
    m_ocrTextDescriptionMap.insert(pair<time_t, OcrRecordDescription>(startTime, desc));
    updateOcrTextDescriptionFile();
}

void CAudioTextRecorder::appendOcrContent(const char* ocr_text, int len){

}

void CAudioTextRecorder::loadOcrTextDescriptionFile(){

    if (!endWith(m_path,"/")){
        m_path = m_path + "/";
    }

    string description_file_name = m_path + "ocr_description.hxt";
    ifstream ifs(description_file_name, ios::in);
    if(!ifs){
        printf("not found ocr_description.hxt \n");
        return ;
    }

    string content;
    while( getline(ifs,content))
    {
        cout<<content<<endl;
    }
    ifs.close();

    return ;
}

void CAudioTextRecorder::updateOcrTextDescriptionFile(){

    if (!endWith(m_path,"/")){
        m_path = m_path + "/";
    }

    string description_file_name = m_path + "ocr_description.hxt";

    m_ocrTextFp.open(description_file_name, std::ios_base::out|std::ios_base::app);
    for (map<time_t, OcrRecordDescription, MyCompare>::iterator it = m_ocrTextDescriptionMap.begin(); it != m_ocrTextDescriptionMap.end(); it++) {
        cout << "key:" << it->first << " value:" << it->second.confId << endl;
        char buf[1024] = {0};
        sprintf(buf, "%s|%lld|%s\n",it->second.confId.c_str(),it->second.startTime, it->second.filename.c_str());
        m_ocrTextFp.write(buf, strlen(buf) + 1);
    }

    m_ocrTextFp.flush();
    m_ocrTextFp.close();


}