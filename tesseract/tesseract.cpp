#include "baseapi.h"
#include <leptonica/allheaders.h>

int main()
{
    char *outText;

    // 初始化一个 tesseract 的调用。
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // 文件路径。这个格式要确定一下。
    Pix *image = pixRead("/tmp/githubTest/go/thirdParty/ocr/one.png");
    api->SetImage(image);
    // 获取 c++ 文件路径
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // 不知道啥意思，说是摧毁内存。
    api->End();
    delete api;
    delete [] outText;
    pixDestroy(&image);

    return 0;
}