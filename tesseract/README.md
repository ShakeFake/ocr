# ocr
some use ocr package

# static compile
    git clone https://github.com/tesseract-ocr/tesseract
    cd tesseract
    mkdir build
    cd build
    cmake -DSTATIC=ON  ..

# head file path
    tesseract/include/tesseract

# static file path
    build/libtesseract.a
    build/src/training/libcommon_training.a
    build/src/training/libpango_training.a
    build/src/training/libunicharset_training.a

# compile
    g++ -o tesseract tesseract.cpp -llept -I include/ -lpthread -L lib -ltesseract -larchive

# 运行。保证 eng.traineddata 和 包在同一目录下。
    ./tesseract

# docker 运行和动态链接库的生成
    docker run -it --rm -v /tmp/githubTest/c++/:/root --network=host tvu_u_2204 /bin/bash
    apt-get install libarchive-dev
    apt-get install libleptonica-dev
