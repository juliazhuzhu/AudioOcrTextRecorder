#include <iostream>
#include <stdio.h>
#include "CAudioTextRecorder.h"
int main() {
//    std::cout << "Hello, World!" << std::endl;
//1676446475
    char buf[256] = "112233|1676446475|ocr_1.log";
    char confid[32]={0};
    time_t start_time;

    char file_name[128] = {0};

    sscanf(buf, "%[^|]|%lld|%s", confid, &start_time,file_name);
    printf("%s\n", confid);
    printf("%lld\n", start_time);
//    printf("%d\n", duration);
    printf("%s\n",file_name);

    char buff[256] = {0};
    sprintf(buff, "%s|%lld|%s", confid, start_time, file_name);

    printf("%s\n", buff);


    CAudioTextRecorder ocr_record;

    ocr_record.initialize("/home/xiaoye/WorkHome/AudioOcrTextRecorder");

    ocr_record.newRecorderFile("1333322", time(NULL));


    return 0;
}
