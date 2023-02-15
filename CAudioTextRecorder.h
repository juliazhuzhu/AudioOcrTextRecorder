//
// Created by xiaoye on 2023/2/15.
//

#ifndef AUDIOOCRTEXTRECORDER_CAUDIOTEXTRECORDER_H
#define AUDIOOCRTEXTRECORDER_CAUDIOTEXTRECORDER_H


#include <string>
#include <map>
#include <fstream>
using namespace std;

class CAudioTextRecorder {
public:
    CAudioTextRecorder();
    void initialize(string path);
    void newRecorderFile(string confId, int64_t startTime);
    void appendOcrContent(const char* ocr_text, int len);
private:
    typedef struct _OcrRecordDescription {
        string  filename;
        int64_t startTime;
        string confId;
    }OcrRecordDescription;
    class MyCompare {
    public:
        bool operator()(time_t v1, time_t v2) {
            return v1 >= v2;
        }
    };
    void loadOcrTextDescriptionFile();
    void updateOcrTextDescriptionFile();
    map<time_t, OcrRecordDescription,MyCompare> m_ocrTextDescriptionMap;
    string m_path;
    int m_maxFileNum;
    ofstream m_ocrTextFp;
};


#endif //AUDIOOCRTEXTRECORDER_CAUDIOTEXTRECORDER_H
